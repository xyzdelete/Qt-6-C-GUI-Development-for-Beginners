#include "box.hpp"
#include "rectangle.hpp"
#include <iostream>

int main()
{
    Rectangle r{ 10.0, 20.0 };
    std::cout << "area: " << r.get_area() << std::endl;

    Box b{ 10, 20, 30 };
    std::cout << "volume: " << b.get_volume() << std::endl;

    return 0;
}
