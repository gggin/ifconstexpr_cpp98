### IfConstExprCpp98

I hope this project will help someone that first go into TMP(template meta program). It's not difficult but cute.

`
//in c++17 it's so easy:
template<typename T>
void run(T a)
{
        if constexpr(std::is_integral_v<int>)
        {
            std::cout << "FuncA " << a << std::endl;
        }
        else
        {
            std::cout << "FuncB " << a << std::endl;
        }
}
int main()
{
        run(1);
        run(2.3);
        return 0;
}
`
In `main.cpp` there is cpp98 vesrion.
