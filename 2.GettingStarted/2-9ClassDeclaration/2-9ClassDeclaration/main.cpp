#include <iostream>

class Rectangle
{
public:
    void set_width(double width) noexcept;
    void set_height(double height) noexcept;
    double get_area() const noexcept;

private:
    double m_width{};
    double m_height{};
};

int main()
{
    Rectangle r{};
    r.set_width(10.0);
    r.set_height(20.0);
    std::cout << "area: " << r.get_area() << std::endl;

    return 0;
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
