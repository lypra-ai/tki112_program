#include <iostream>

using namespace std;

enum Numbers {
	NegativeNumbers = 1,
	AbsoluteSum = 2,
};

int numberOfNegativeNumbers(double a, double b, double c);

double absoluteValueOfSum(double a, double b, double c);

int main() {
	setlocale(LC_ALL, "ru");
	cout << "Введите 3 числа:\na =  ";
	double a; cin >> a;
	cout << "b = "; double b; cin >> b;
	cout << "c = "; double c; cin >> c;

	cout << "Выберите действие:\n1 - найти количество отрицательных чисел\n2 - найти абсолютное значение суммы\n";
	int choice; cin >> choice;
	static_cast<Numbers>(choice);

	switch (choice) {
	case 1:
		cout << "Количество отрицательных чисел равно " << numberOfNegativeNumbers(a, b, c) << endl;
		break;
	case 2:
		cout << "Абсолютная сумма равна " << absoluteValueOfSum(a, b, c) << endl;
		break;
	default:
		cout << "Введено неверное значение!";
	}

	return 0;
}

int numberOfNegativeNumbers(double a, double b, double c) {
	int sum = 0;
	if (a < 0)
		sum++;
	if (b < 0)
		sum++;
	if (c < 0)
		sum++;
	return sum;
}

double absoluteValueOfSum(double a, double b, double c) {
	return a + b + c;
}