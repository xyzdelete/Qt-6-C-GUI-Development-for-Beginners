#include <iostream>

constexpr int add(int a, int b) noexcept;
constexpr float add(float a, float b) noexcept;
constexpr double add(double a, double b) noexcept;

void sayHi() noexcept;

int main()
{
    double a{ 3.8f };
    double b{ 7.3f };
    double c{ 34.f };

    auto result{ add(a, b) };

    std::cout << "result: " << result << std::endl;

    auto result1{ add(a, c) };

    std::cout << "result1: " << result1 << std::endl;

    for (int i{}; i < 20; ++i)
    {
        sayHi();
    }

    return 0;
}

constexpr int add(int a, int b) noexcept
{
    return a + b;
}

constexpr float add(float a, float b) noexcept
{
    return a + b;
}

constexpr double add(double a, double b) noexcept
{
    return a + b;
}

void sayHi() noexcept
{
    std::cout << "Hi" << std::endl;
}
