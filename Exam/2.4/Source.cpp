#include <iostream>

using namespace std;

void getMatrix(int **matrix, int **newMatrix, int n, int x, int y) {
	int sdvigX = 0, sdvigY = 0;
	for (int i = 0; i < n-1; i++)
	{
		if (i == y) {
			sdvigY = 1;
		}
		for (int j = 0; j < n-1; j++)
		{
			if (j==x)
			{
				sdvigX=1;
			}
			newMatrix[i][j] = matrix[i + sdvigY][j + sdvigX];
		}
		sdvigX = 0;

	}
}



int det(int **matrix, int n) {
	int **newMatrix;
	int d = 0;
	int k = 1;
	if (n == 1) {
		d = matrix[0][0];
	}
	if (n == 2) {
		d = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
	}
	if (n > 2) {
		newMatrix = new int*[n - 1];
		for (int i = 0; i < n - 1; i++)
		{
			newMatrix[i] = new int[n - 1];
		}
		for (int i = 0; i < n; i++)
		{
			getMatrix(matrix, newMatrix, n, i, 0);
			d += matrix[0][i] * k*det(newMatrix, n - 1);
			k = -k;
		}
	}
	return d;

}

int main() {
	setlocale(LC_ALL, "Russian");
	int n = 4;
	int **matrix = new int*[n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = i + j;
		}
	}
	matrix[2][2] = 14;
	matrix[3][3] = 158;
	cout << det(matrix, n) << endl;


	system("Pause");
	return 0;
}