#include <iostream>

class Rectangle
{
public:
    Rectangle() noexcept = default;
    Rectangle(double width, double height) noexcept;

    void set_width(double width) noexcept;
    void set_height(double height) noexcept;
    double get_area() const noexcept;

private:
    double m_width{};
    double m_height{};
};

class Box
{
public:
    Box() noexcept = default;
    Box(double width, double length, double height) noexcept;

    double get_volume() const noexcept;

private:
    Rectangle m_rectangle{};
    double m_height{};
};

int main()
{
    Rectangle r{ 10.0, 20.0 };
    std::cout << "area: " << r.get_area() << std::endl;

    Box b{ 10, 20, 30 };
    std::cout << "volume: " << b.get_volume() << std::endl;

    return 0;
}

Rectangle::Rectangle(double width, double height) noexcept
    : m_width{ width }
    , m_height{ height }
{
}

void Rectangle::set_width(double width) noexcept
{
    m_width = width;
}

void Rectangle::set_height(double height) noexcept
{
    m_height = height;
}

double Rectangle::get_area() const noexcept
{
    return m_width * m_height;
}

Box::Box(double width, double length, double height) noexcept
    : m_rectangle{ width, length }
    , m_height{ height }
{
    std::cout << "Parameter c-tor called" << std::endl;
}

double Box::get_volume() const noexcept
{
    return m_rectangle.get_area() * m_height;
}
