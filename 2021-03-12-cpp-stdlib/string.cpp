#include<iostream>
#include<iostream>

int main (int argc, char **argv)
{
    std::string firstname, Lastname, fullname;
    firstname = "Johan";
    Lastname = "Moreno";
    fullname = firstname + Lastname;

    std::cout << "Hola: " << fullname << "\n";
    std::cout << firstname[4] << "\n";
    std::cout << firstname.size() << "\n";
    std::cout << firstname.max_size() << "\n";

    return 0;
}
