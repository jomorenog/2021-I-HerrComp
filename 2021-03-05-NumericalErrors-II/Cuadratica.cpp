#include<iostream>
#include<cmath>
#include<cstdlib>

typedef float REAL;

int main(int argc, char** argv)
{

    REAL a=1.0;
    REAL b=1.0;
    REAL c=1.0;
    int n=std::atoi(argv[1]);

    for (int ii=0; ii<n; ii++){

    
    REAL x1=(-b+sqrt(b*b-4*a*c))/(2*a);
    REAL x2=(-b-sqrt(b*b-4*a*c))/(2*a);
    REAL x3=(-2*c)/(b+sqrt(b*b-4*a*c));
    REAL x4=(-2*c)/(b-sqrt(b*b-4*a*c));

    std::cout<< ii <<"\t" << x1<<"\t" << x2 << "\t"<< x3 << "\t"<< x4 <<"\n";
    c=c/10;
    }
    return 0;
}
