#include <iostream>

int main()
{
    std::cout << "Hello World!" << std::endl;

    std::cerr << "Hello Problem!" << std::endl;

    std::clog << "Hello Log!" << std::endl;

    std::string name;
    std::cout << "Please enter your firstname: ";
    std::cin >> name;

    std::cout << "Your firstname is: " << name << std::endl;

    return 0;
}
