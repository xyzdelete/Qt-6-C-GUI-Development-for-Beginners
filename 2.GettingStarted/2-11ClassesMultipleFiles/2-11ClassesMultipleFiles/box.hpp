#pragma once
#include "rectangle.hpp"
#include <iostream>

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

inline Box::Box(double width, double length, double height) noexcept
    : m_rectangle{ width, length }
    , m_height{ height }
{
    std::cout << "Parameter c-tor called" << std::endl;
}

inline double Box::get_volume() const noexcept
{
    return m_rectangle.get_area() * m_height;
}
