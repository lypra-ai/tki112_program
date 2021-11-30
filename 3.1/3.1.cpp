#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/**
* \brief Расчёт функции
* \param x - аргумент функции
* \return значение функции
**/
double calcFunction(const double x);
/**
* \brief Возможность подсчёта функции в точке x
* \param x - точка x
* \return true, если функция определена в точке x
*/
bool isCalculated(const double x);

/**
* \brief Точка входа в программу
* \return Код ошибки (0-успех)
**/
int main()
{
	setlocale(LC_ALL, "Russian");
	const double LOW_BOUND = 0, UP_BOUND = 1, STEP = 0.1;
	int WIDTH = 3;

	cout << setw(WIDTH) << "X" << " | " << setw(WIDTH) << "Y\n";

	for (double x = LOW_BOUND; x < UP_BOUND; x += STEP)
	{
		if (isCalculated(x))
			cout << setw(WIDTH) << x << " | " << setw(WIDTH) << calcFunction(x) << "\n";
		else
			cout << setw(WIDTH) << x << " | " << setw(WIDTH) << "невозможно вычислить значение функции в дданной точке\n";
	}

	return 0;
}

double calcFunction(const double x)
{
	return sqrt(1 - x) - tan(x);
}


bool isCalculated(const double x)
{
	return x <= 1;
}