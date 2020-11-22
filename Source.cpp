// Lab_7_3.cpp
// < Kolmykova Kateryna >
// Лабораторна робота № 7.3.
// Опрацювання динамічних багатовимірних масивів. Рекурсивний спосіб.
// Варіант 12
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void PrintRow(int** a, const int i, const int n, int j)
{
	cout << setw(4) << a[i][j];
	if (j < n - 1)
		PrintRow(a, i, n, j + 1);
	else
		cout << endl;
}
void PrintRows(int** a, const int k, const int n, int i)
{
	PrintRow(a, i, n, 0);
	if (i < k - 1)
		PrintRows(a, k, n, i + 1);
	else
		cout << endl;
}
void InputRow(int** a, const int i, const int n, int j)
{
	cout << "a[" << i << "][" << j << "] = ";
	cin >> a[i][j];
	if (j < n - 1)
		InputRow(a, i, n, j + 1);
	else
		cout << endl;
}
void InputRows(int** a, const int k, const int n, int i)
{
	InputRow(a, i, n, 0);
	if (i < k - 1)
		InputRows(a, k, n, i + 1);
	else
		cout << endl;
}
void NullS(int** a, const int k, const int n)
{
	for (int i = 0; i < k; i++)
	{
		int f = 0;
		for (int j = 0; j < n; j++)
			if (a[i][j] == 0)
				delete a[j];
		f++;
	}
}
int Num(int** a, const int n)
{
	int j = 0;
	int index = j;
	int i = 0;
	for (int j = 0; j < n; j++)
	{
		if (a[i][j] > 0)
			index = j;
		i++;
	}
	return index;
}
int main()
{
	srand((unsigned)time(NULL));
	int Low = -20;
	int High = 20;
	int k, n;
	cout << "k = "; cin >> k;
	cout << "n = "; cin >> n;
	int** a = new int* [k];
	for (int i = 0; i < k; i++)
		a[i] = new int[n];
	InputRows(a, k, n, 0);
	PrintRows(a, k, n, 0);
	NullS(a, k, n);
	PrintRows(a, k, n,0);
	cout << "Num=" << Num(a, n);
	for (int i = 0; i < k; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}