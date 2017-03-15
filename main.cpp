#include <iostream>
using namespace std;

void ktke(int x, int y, int **a, long e)
{
	int z = 0;
	for (int i = 0; i < e; i++)
	{
		if (a[i][0] == x && a[i][1] == y)
		{
			z += 1;
		}
	}
	if (z > 0)
		cout << "\nTRUE";
	else
		cout << "\nFALSE";
}
void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void sx(int *a, int n) {
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[i]) {
				swap(a[i], a[j]);
			}
		}
	}
}
void ktlancan(int x, int **a, long e)
{
	int *b = new int[(int)e];

	int j = 0;
	for (int i = 0; i < e; i++)
	{
		if (a[i][0] == x)
		{
			b[j] = a[i][1];
			j++;
		}
	}
	if (j < 1)
	{
		cout << "\nNONE";
		return;
	}
	//QuickSort(b, 0, j);
	sx(b, j);
	cout << "\n";
	for (int i = 0; i < j; i++)
	{
		cout << b[i] << " ";
	}

	delete b;
}

int main()
{
	long v, e, n;
	v = e = n = 0;
	cin >> v >> e >> n;

	int **Array = new int*[(n + e*2)];
	for (int i = 0; i < (e*2 + n); i++)
	{
		Array[i] = new int[3];
	}

	//nhap mang du lieu
	for (int i = 0; i < e*2; i+=2)
	{
		for (int j = 0; j < 2; j++)
		{
			cin >> Array[i][j];
		}
		int temp = 1;
		for (int j = 0; j < 2; j++,temp--)
		{
			Array[i + 1][j] = Array[i][temp];
		}
	}
	// Nhap mang yeu cau kiem tra
	for (int i = e*2; i < e*2 + n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> Array[i][j];
			if (Array[i][0] == 2 && j == 1)
				break;
		}
	}
	//thuc thi yeu cau
	for (int i = e*2; i < e*2 + n; i++)
	{
		if (Array[i][0] == 1)
		{
			ktke(Array[i][1], Array[i][2], Array, e*2);
		}
		else
		{
			ktlancan(Array[i][1], Array, e*2);
		}
	}


	delete[] Array;
}