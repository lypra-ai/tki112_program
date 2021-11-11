#include <iostream>
#include <math.h>

using namespace std;

double GetA(const double x, const double y, const double z);
double GetB(const double x, const double y, const double z);
int main()
{
    const auto x=0.3;
    const auto y=2.9;
    const auto z=0.5;
        
    const auto a = GetA(x,y,z);
    const auto b = GetB(x,y,z);
        
    std::cout <<"x = " << x << ", y = " << y << ", z = " << z <<'\n';
    std::cout <<"a = " << a << ", b = " << b << endl;
        
        
    return 0;
}

double GetA(const double x, const double y, const double z)
{
    return ((pow(z, 2)*x + exp(-x)*cos(y*x))/(y*x-exp(-x)*sin(y*x)+1));
}

double GetB(const double x, const double y, const double z)
{
    return (exp(2*x)* log(z+x)-pow(y,3*x)*log(y-x));
}