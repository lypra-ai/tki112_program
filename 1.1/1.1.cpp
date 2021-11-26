#define _USE_MATH_DEFINES // for C++

#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

/**
 * \brief Функция расчета значения переменной по некоторой формуле.
 * \param x входной параметр.
 * \param y входной параметр.
 * \param z входной параметр.
 * \return Значение функции для константных значений x y z.
 */
double GetA(const double x, const double y, const double z);
/**
 * \brief Функция расчета значения переменной по некоторой формуле.
 * \param x входной параметр.
 * \param y входной параметр.
 * \param z входной параметр.
 * \return Значение функции для константного значения z.
 */
double GetB(const double x, const double y, const double z);
/**
 * \brief Точка входа в программу.
 * \return Код ошибки (0 - успех).
 */
int main()
{
    const auto x = 0.3;
    const auto y = 2.9;
    const auto z = 0.5;

    const auto a = GetA(x, y, z);
    const auto b = GetB(x, y, z);

    std::cout << "x = " << x << ", y = " << y << ", z = " << z << '\n';
    std::cout << "a = " << a << ", b = " << b << endl;


    return 0;
}

double GetA(const double x, const double y, const double z)
{
    return ((pow(z, 2) * x + exp(-x) * cos(y * x)) / (y * x - exp(-x) * sin(y * x) + 1));
}

double GetB(const double x, const double y, const double z)
{
    return (exp(2 * x) * log(z + x) - pow(y, 3 * x) * log(y - x));
}