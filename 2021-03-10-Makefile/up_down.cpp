#include<iostream>
#include<cmath>
#include<cstdlib>

typedef float REAL;

REAL SUMu (int Nmax);
REAL SUMd (int Nmax);

int main(int argc, char **argv)
{
    int n= std::atoi(argv[1]);
    std::cout.precision(8);
    std::cout.setf(std::ios::scientific);

    for (int ii=1;ii<=n; ii++){
        REAL pres=std::fabs(SUMu(ii)-SUMd(ii))/SUMu(ii);
     std::cout<<ii<<"\t"<< SUMu(ii)<<"\t"<<SUMd(ii)<<"\t"<<pres<<"\n";
    }

    return 0;
}

REAL SUMu (int Nmax){
    REAL sumu=0.0;
    for (int n=1; n<=Nmax;n++){
        sumu=sumu+1.0/n;
    }
    return sumu;
}

REAL SUMd (int Nmax){
    REAL sumd=0.0;
    for (int n=0; n<Nmax;n++){
        sumd+=1.0/(Nmax-n);
    }
    return sumd;
}
