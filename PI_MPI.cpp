#include <iostream>
#include <cstdlib>
#include <cmath>
#include <random>
#include "mpi.h"

int count_nc(int pid, int np, int N);
void Pi_aprox(int Ncparcial, int pid, int np, int N);

int main(int argc, char **argv)
{
  MPI_Init(&argc, &argv); /* Mandatory */

  int pid;                 /* rank of process */
  int np;                 /* number of processes */

  MPI_Comm_size(MPI_COMM_WORLD, &np);
  MPI_Comm_rank(MPI_COMM_WORLD, &pid);

  int N = std::atoi(argv[1]);
  
  int ncpcl= count_nc(pid, np, N);
  Pi_aprox(ncpcl, pid, np, N);
  
  MPI_Finalize(); /* Mandatory */
  
  return 0;
}


int count_nc( int pid, int np, int N)
{
    int count = 0;
    int seed = pid; // use pid for seed when in parallel
    int Nlocal = N/np;
    std::mt19937 gen(seed);
    std::uniform_real_distribution<double> dis(-1.0, 1.0);
    for (int ii = 0; ii < Nlocal; ++ii) {
    double rx = dis(gen);
    double ry = dis(gen);
    if (rx*rx + ry*ry < 1)
      count++;
  }
  return count; 
}

void Pi_aprox(int Ncparcial, int pid, int np, int N)
{
  int tag = 0;
  double Nc;
  if (pid != 0) {
    // enviar val a pid 0
    int dest = 0;
    MPI_Send(&Ncparcial, 1, MPI_INT, dest, tag, MPI_COMM_WORLD);
  } else { // pid ==0
    // recibir de pid 1, 2, 3, 4, 5, ... , np-1
     Nc = Ncparcial;
    for (int ipid = 1; ipid < np; ++ipid) {
      MPI_Recv(&Ncparcial, 1, MPI_DOUBLE, ipid, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      Nc += Ncparcial;
    }
    // imprimir
    double Pi=4.0*(Nc/N);
     std::cout << "Valor aproximado de pi: " << Pi << std::endl;
  }
}
