#include <iostream>

int main(int argc, char **argv)
{

    float x=0;
    for (int i=0;i<10;i++)
    {
        x+=0.1;
            }
    std::cout.precision(7);
    std::cout.setf(std::ios::scientific);
    std::cout<<x<<"\n";

    return 0;
}
