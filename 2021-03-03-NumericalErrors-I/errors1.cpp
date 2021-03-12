#include <iostream>

int main(int argc, char **argv)
{

    float x=0;
    for (int i=0;i<10;i++)
    {
        x+=0.1;
            }
    std::cout.precision(7);// defino la precision con la que quiero ver los resultados
    std::cout.setf(std::ios::scientific);// muestra el resultado en notacion cientifica
    std::cout<<x<<"\n";

    return 0;
}
