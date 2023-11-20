#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

float frand(int min, int max, int prc);         // ��������� � ������� (�� , �� , ��������)
int min_elem(float arr[], int n);
double mult_elem(float arr[], int n);

int main()
{
	setlocale(LC_ALL, "RU");
	srand(time(NULL));

	cout << "������� ������ ������� N: ";
	int n;
	cin >> n;

	float *arr = new float[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = frand(-5, 5, 2);
		cout << setw(6) << arr[i];
	}
	cout << endl << endl;

	cout << "����� ������������ ��������� = " << min_elem(arr, n) + 1 << endl;
	
	cout << "������������ = " << round(mult_elem(arr, n) * 10) / 10 << endl;       // ������� � ����������� �� 1 ����� ���� ,


	delete[] arr;
	system("pause");
	return 0;
}

//---------- �������� ���������� ����� � ������
float frand(int min, int max, int prc)
{
	double value = rand() % (int)pow (10, prc);               // �������� ����� (������� ����� ����� �������)
	
	value = min + (value / pow(10, prc)) * (max - min);       // ����� ����� �� 10..100..1000... � ����������� �� ��������

	return value;
}

//---------- ����� ������������ ����� � �������
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

//---------- ������������ ���������, ����������� ����� 1-�� � 2-�� �������������� ����������
double mult_elem(float arr[], int n)
{
	double mult = 0;
	int i_first = -1, i_second = -1;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] < 0)
		{
			i_first = i;
			break;
		}
	}

	for (int i = i_first + 1; i < n; i++)
	{
		if (arr[i] < 0)
		{
			i_second = i;
			break;
		}
	}

	if ((i_first != -1 && i_second != -1) && (i_second - i_first > 1))
	{
		mult = 1;
		for (int i = i_first + 1; i < i_second; i++)
		{
			mult *= arr[i];
		}
		return mult;
	}

	return mult;
}


