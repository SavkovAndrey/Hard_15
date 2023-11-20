#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

float frand(int min, int max, int prc);         // случайное с точнокй (от , до , точность)
int min_elem(float arr[], int n);

int main()
{
	setlocale(LC_ALL, "RU");
	srand(time(NULL));

	cout << "Введите размер массива N: ";
	int n;
	cin >> n;

	float *arr = new float[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = frand(-5, 5, 2);
		cout << setw(6) << arr[i];
	}
	cout << endl << endl;

	cout << "Номер минимального эелемента = " << min_elem(arr, n) + 1 << endl;

	system("pause");
	return 0;
}

//---------- СОЗДАНИЕ СЛУЧАЙНОГО ЧИСЛА С ТОЧКОЙ
float frand(int min, int max, int prc)
{
	double value = rand() % (int)pow (10, prc);               // получаем число (которое будет после запятой)
	
	value = min + (value / pow(10, prc)) * (max - min);       // делим число на 10..100..1000... в зависимости от точности

	return value;
}

//---------- ПОИСК МИНИМАЛЬНОГО ЧИСЛА В МАССИВЕ
int min_elem(float arr[], int n)
{
	int min = 100, i_min = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			i_min = i;
		}
	}
	return i_min;
}

