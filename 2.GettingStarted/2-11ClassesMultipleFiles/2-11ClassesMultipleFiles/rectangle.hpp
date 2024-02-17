#pragma once

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

inline Rectangle::Rectangle(double width, double height) noexcept
    : m_width{ width }
    , m_height{ height }
{
}

inline void Rectangle::set_width(double width) noexcept
{
    m_width = width;
}

inline void Rectangle::set_height(double height) noexcept
{
    m_height = height;
}

inline double Rectangle::get_area() const noexcept
{
    return m_width * m_height;
}
