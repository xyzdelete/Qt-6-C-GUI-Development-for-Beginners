#include <iostream>

int main()
{
    // auto func = []() { std::cout << "Hello World!" << std::endl; };
    // func();

    // []() { std::cout << "Hello World!" << std::endl; }();

    // [](int a, int b) { std::cout << "a + b = " << a + b << std::endl; }(7, 3);

    // auto func = [](int a, int b) { std::cout << "a + b = " << a + b << std::endl; };
    // func(7, 3);

    // auto func = [](int a, int b) -> int { return a + b; };
    // auto value = func(7, 3);
    // std::cout << "The sum is: " << value << std::endl;

    // std::cout << "The sum is: " << [](int a, int b) -> int { return a + b; }(7, 3) << std::endl;

    // int a{ 7 };
    // int b{ 3 };
    // [a, b]() { std::cout << "a + b = " << a + b << std::endl; }();

    // int c{ 42 };
    // auto func = [c]() { std::cout << "The inner value of c is: " << c << std::endl; };
    // for (int i{ 1 }; i < 5; i++)
    // {
    //     std::cout << "The outer value of c is: " << c << std::endl;
    //     func();
    //     c++;
    // }

    // int c{ 42 };
    // auto func = [&c]() { std::cout << "The inner value of c is: " << c << std::endl; };
    // for (int i{ 1 }; i < 5; i++)
    // {
    //     std::cout << "The outer value of c is: " << c << std::endl;
    //     func();
    //     c++;
    // }

    // int c{ 42 };
    // int d{ 6 };
    // auto func = [=]()
    // {
    //     std::cout << "The inner value of c is: " << c << std::endl;
    //     std::cout << "The inner value of d is: " << d << std::endl;
    // };
    // for (int i{ 1 }; i < 5; i++)
    // {
    //     std::cout << "The outer value of c is: " << c << std::endl;
    //     func();
    //     c++;
    // }

    int c{ 42 };
    int d{ 6 };
    auto func = [&]()
    {
        std::cout << "The inner value of c is: " << c << std::endl;
        std::cout << "The inner value of d is: " << d << std::endl;
    };
    for (int i{ 1 }; i < 5; i++)
    {
        std::cout << "The outer value of c is: " << c << std::endl;
        func();
        c++;
    }

    return 0;
}
