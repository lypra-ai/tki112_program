#include <iostream>

using namespace std;

enum Numbers {
	NegativeNumbers,
	AbsoluteSum
};
/*
* \brief поиск количества отрицательных элементов
* \param a переменная a
* \param b переменная b 
* \param c переменная c
* \return количество отрицательных элементов
*/
int numberOfNegativeNumbers(const double a, const double b, const double c);

/*
* \brief поиск суммы всех элементов
* \param a переменная a
* \param b переменная b
* \param c переменная c
* \return сумма элементов
*/
int absoluteValueOfSum(const double a, const double b, const double c);

/**
* \brief Точка входа в программу.
* \return Код ошибки (0 - успех).
*/
int main() 
{
	setlocale(LC_ALL, "ru");
	cout << "Введите 3 числа:\na = ";
	double a; cin >> a;
	cout << "b = "; double b; cin >> b;
	cout << "c = "; double c; cin >> c;

	cout << "Выберите действие:\nВведите "<< static_cast<int>(Numbers::NegativeNumbers) << " - найти количество отрицательных чисел\nВведите "
		<< static_cast<int>(Numbers::AbsoluteSum) << " - найти абсолютное значение суммы\n";
	int choice; cin >> choice;
	static_cast<Numbers>(choice);

	switch (choice) {
	case Numbers::NegativeNumbers:
		cout << "Количество отрицательных чисел равно " << numberOfNegativeNumbers(a, b, c) << endl;
		break;
	case Numbers::AbsoluteSum:
		cout << "Абсолютная сумма равна " << absoluteValueOfSum(a, b, c) << endl;
		break;
	default:
		cout << "Введено неверное значение!";
	}

	return 0;
}

int numberOfNegativeNumbers(const double a,const double b,const double c) {
	int sum = 0;
	if (a < 0)
		sum++;
	if (b < 0)
		sum++;
	if (c < 0)
		sum++;
	return sum;
}

int absoluteValueOfSum(const double a, const double b, const double c) {
	return a + b + c;
}