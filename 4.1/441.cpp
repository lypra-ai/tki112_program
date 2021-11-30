#include <iostream>
#include <iomanip>
#include <random>
using namespace std;


/**
 * \brief Заполнение массива случайными числами.
 * \param size размер массива.
 * \param minValue минимальное значение элементов массива.
 * \param maxValue максимальное значение элементов массива.
 * \return заполненный массив.
 */
int* FillRandomArray(const size_t  size, const int minValue, const int maxValue);


/**
 * \brief Заполнение массива пользователем.
 * \param size размер массива.
 * \return заполненный массив.
 *
 */
int* FillUserArray(size_t size);

/**
* \brief Вывод массива
* \param array Массив
* \param size Размер массива
**/
void Print(int* array, const int size);

/**
 * \brief Нахождение суммы элементов массива, которые состоят из одной цифры.
 * \param array массив.
 * \param size размер массива.
 * \return сумма элементов массива, которые состоят из одной цифры.
 */
int GetSumOfOnedigitElements(int* array, const size_t size);

/**
* \brief Поиск индекса минимального элемента.
* \param array Массив.
* \param size Размер массива.
* \return Индекс минимального элемента массива.
**/
int GetMinIndex(int* array, const size_t size);

/**
* \brief Поиск индекса максимального элемента.
* \param array Массив.
* \param size Размер массива.
* \return Индекс максимального элемента массива.
**/
int GetMaxIndex(int* array, const size_t size);

/**
* \brief Замена элементов между минимальным и максимальным элементами теми же в обратном порядке
* \param array Массив.
* \param size Размер массива.
* \param min_index Индекс минимального элемента.
* \param max_index Индекс максимального элемента.
**/
void SwappingArrayElementsBetweenMinAndMax(int* array, const size_t size, const int min_index, const int max_index);

/**
* \brief Метод, возвращающий последнюю пару соседних элементов с одинаковыми знаками, произведение которых меньше заданного числа
* \param array Массив.
* \param size Размер массива.
* \param num Заданное число.
**/
void GetPairCounter(int* array, const size_t size, const int num);

/**
* \brief Выбор заполнения массива
**/
enum class ArrayInputWay
{
	RANDOM = 1,
	USER = 2
};


/**
* \brief Точка входа в программу
* \return Код ошибки (0-успех)
**/
int main() {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	const int minValue = -40, maxValue = 40; // пределы заполнения чисел для рандомайзера

	cout << "Введите количество элементов массива: ";
	size_t size;
	cin >> size;

	cout << "Введите " << static_cast<int>(ArrayInputWay::RANDOM) << " - чтобы сгенерировать массив\nВведите " << static_cast<int>(ArrayInputWay::USER) << " - чтобы заполнить массив вручную\n";
	int choice;
	cin >> choice;

	int* myArray = nullptr;

	const auto filling = static_cast<ArrayInputWay>(choice);
	switch (filling)
	{
	case ArrayInputWay::RANDOM:
		myArray = FillRandomArray(size, minValue, maxValue);
		break;

	case ArrayInputWay::USER:
		myArray = FillUserArray(size);
		break;

	default:
		cout << "Ошибка! Не выбран ни один из вариантов";
	}

	Print(myArray, size);

	const auto sum = GetSumOfOnedigitElements(myArray, size);
	cout << "Сумма элементов, значения которых состоят из одной цифры = " << sum << endl;

	const auto min_index = GetMinIndex(myArray, size);
	cout << "\nИндекс минимального элемента = " << min_index << endl;

	const auto max_index = GetMaxIndex(myArray, size);
	cout << "\nИндекс максимального элемента = " << max_index << endl;

	cout << "\nМассив с заменой элементов между минимальным и максимальным элементами теми же в обратном порядке:\n";
	SwappingArrayElementsBetweenMinAndMax(myArray, size, min_index, max_index);
	Print(myArray, size);
	cout << endl;

	cout << "Введите число, меньше которого будут искаться последняя пара элементов массива с одинаковыми знаками = ";
	int num;
	cin >> num;

	GetPairCounter(myArray, size, num);

	delete[] myArray;

	return 0;
}

int* FillRandomArray(const size_t  size, const int minValue, const int maxValue)//заполнение массива случайными числами
{
	std::random_device rd;

	std::mt19937 gen(rd());

	const std::uniform_int_distribution<> uniformIntDistribution(minValue, maxValue);

	auto* array = new int[size];
	for (size_t index = 0; index < size; index++)
	{
		array[index] = uniformIntDistribution(gen);
	}

	return array;
}

int* FillUserArray(const size_t size)//заполнение массива пользователем
{
	auto* array = new int[size];

	for (size_t i = 0; i < size; i++)
	{
		cout << "arr[" << i << "] = ";
		cin >> array[i];
	}

	return array;
}

void Print(int* array, const int size)//вывод массива
{
	cout << "array[" << size << "]" << "= {";

	for (size_t i = 0; i < size - 1; i++)
	{
		cout << array[i] << ";" << setw(3);
	}

	cout << array[size - 1] << "}\n\n";
}

int GetSumOfOnedigitElements(int* array, const size_t size)//сумма элементов массива из 1 цифры
{
	int sum = 0;

	for (int i = 0; i < size; i++)
	{
		if (abs(array[i] / 10 == 0))
		{
			sum += array[i];
		}
	}

	return sum;
}

int GetMinIndex(int* array, const size_t size)//индекс минимального значения массива
{
	int min = array[0];
	int min_index = 0;
	for (size_t i = 1; i < size; i++)
	{
		if ((array[i]) < min)
		{
			min = array[i];
			min_index = i;
		}
	}
	return min_index;
}

int GetMaxIndex(int* array, const size_t size)//индекс максимального значения массива
{
	int max = array[0];
	int max_index = 0;
	for (size_t i = 1; i < size; i++)
	{
		if ((array[i]) > max)
		{
			max = array[i];
			max_index = i;
		}
	}
	return max_index;
}

void SwappingArrayElementsBetweenMinAndMax(int* array, const size_t size, const int min_index, const int max_index)//замена элементов между минимальными и максимальными,и в обратном порядке с ним же
{
	size_t i = min_index;
	size_t j = max_index;
	int buff;
	if (i < j)
		for (i; i < j; i++, j--)
		{
			buff = array[i];
			array[i] = array[j];
			array[j] = buff;
		}
	else
		for (j; j < i; j++, i--)
		{
			buff = array[i];
			array[i] = array[j];
			array[j] = buff;
		}
}

void GetPairCounter(int* array, const size_t size, const int num)//метод возвращающий последнюю пару соседних элементов с одинаковыми знаками произведение которых меньше заданного числа
{
	int out = 0;
	size_t i = size - 1;
	cout << "Найдены пары: ";
	while (i > 0)
	{
		if ((array[i - 1] * array[i]) < num && (array[i - 1] * array[i]) >= 0)
		{
			cout << "[" << array[i - 1] << ";" << array[i] << "]" << endl;
			out += 1;
		}
		if (out == 1)
			break;
		i--;
	}
	if (out == 0)
		cout << "Пары не найдены.";
}

