#include <iostream>

using namespace std;
#define n 3
#define m 4
int main() {
	setlocale(LC_ALL, "Russian");
	int mas[n][m] = {
		{1,2,2,2},
		{2,2,2,2},
		{2,2,2,2}};
	//int n = 3, m = 4;
	int ***sedl = new int**[2];
	for (int i = 0; i < 2; i++)
	{
		sedl[i] = new int*[n];
		for (int j = 0; j < n; j++)
		{
			sedl[i][j] = new int[m];
		}
	}

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				sedl[i][j][k] = 0;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		int minIndex = 0;
		int maxIndex = 0;
		for (int j = 1; j < m; j++) //Минимальный и максимальный элемент в строке
		{
			if (mas[i][minIndex] > mas[i][j]) minIndex = j;
			if (mas[i][maxIndex] < mas[i][j]) maxIndex = j;
		}
		for (int j = 0; j < m; j++)
		{
			if (mas[i][minIndex] == mas[i][j]) sedl[0][i][j] += 1;
			if (mas[i][maxIndex] == mas[i][j]) sedl[1][i][j] += 1;
		}
	}

	for (int i = 0; i < m; i++)
	{
		int minIndex = 0;
		int maxIndex = 0;
		for (int j = 1; j < n; j++) //Минимальный и максимальный элемент в столбце
		{
			if (mas[minIndex][i] > mas[j][i]) minIndex = j;
			if (mas[maxIndex][i] < mas[j][i]) maxIndex = j;
		}
		for (int j = 0; j < n; j++)
		{
			if (mas[minIndex][i] == mas[j][i]) sedl[1][j][i] += 1;
			if (mas[maxIndex][i] == mas[j][i]) sedl[0][j][i] += 1;
		}
	}

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				//cout << sedl[i][j][k] << " ";
				if (sedl[i][j][k] == 2)
					cout << j << " " << k << endl;
			}
			//cout << endl;
		}
		//cout << endl;
	}
	

	system("Pause");
	return 0;
}