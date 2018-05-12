#include <iostream>
#include <type_traits>

template<bool TureOrFalse, typename T>
class IfConstExprCpp98;

template<typename T>
void FuncA(T a)
{
    std::cout << __func__ << " " << a << std::endl;
}

template<typename T>
void FuncB(T b)
{
    std::cout << __func__ << " " << b << std::endl;
}

template<typename T>
struct IfConstExprCpp98<true, T>
{
    static void Run(T a)
    {
        FuncA(a);
    }
};

template<typename T>
struct IfConstExprCpp98<false, T>
{
    static void Run(T b)
    {
        FuncB(b);
    }
};


int main()
{
    //is_integeral is in C++11 but you can easy write yourself one.
    //see it in http://en.cppreference.com/w/cpp/types/is_integral
    int x = 1;
    double y = 2.3;
    IfConstExprCpp98<std::is_integral<decltype(x)>::value, decltype(x)>::Run(x);
    IfConstExprCpp98<std::is_integral<decltype(y)>::value, decltype(y)>::Run(y);
}
