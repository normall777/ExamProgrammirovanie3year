#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	int n = 5;
	int **mas = new int*[n];
	for (int i = 0; i < n; i++)
	{
		mas[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			mas[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++)
	{
		//mas[0][i] = 1;
		//mas[n - 1][i] = 1;
	}
	mas[1][1] = 1;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << mas[i][j] << " ";
		}
		cout << endl;
	}
	int size = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i*j == 0) continue;
			if (mas[i][j] == 0)
				mas[i][j] = max(max(mas[i - 1][j - 1], mas[i - 1][j]), mas[i][j - 1]) - 1;
			if (mas[i][j] < size) size = mas[i][j];
		}
	}
	size = -size + 1;
	cout << size << endl;

	system("Pause");
	return 0;
}