#include <iostream>

using namespace std;

int lab[7][8] = {
	{ 9,9,9,9,9,0,9,9 },
	{ 9,0,0,0,0,0,0,9 },
	{ 9,0,0,9,9,9,0,9 },
	{ 9,0,9,9,0,9,0,9 },
	{ 9,0,0,0,0,9,9,9 },
	{ 9,9,0,9,0,9,0,9 },
	{ 9,9,0,9,9,9,9,9 }
};
int n = 7, m = 8;
void show()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (lab[i][j] == 0) cout << '0';
			else if (lab[i][j] == 9) cout << '#';
			else if (lab[i][j] == 1) cout << '^';
			else if (lab[i][j] == 2) cout << '<';
			else if (lab[i][j] == 3) cout << 'v';
			else if (lab[i][j] == 4) cout << '>';
		}
		cout << endl;
	}
	cout << endl;
}

void exitWidth() {
	int *x = new int[n*m];
	int *y = new int[n*m];
	int k = 0;
	for (int i = 0; i < m; i++)
	{
		if (lab[0][i] == 0) {
			lab[0][i] = 1;
			y[k] = 0;
			x[k] = i;
			k++;
		}
		if (lab[n-1][i] == 0) {
			lab[n-1][i] = 3;
			y[k] = n-1;
			x[k] = i;
			k++;
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (lab[i][0] == 0) {
			lab[i][0] = 2;
			y[k] = i;
			x[k] = 0;
			k++;
		}
		if (lab[i][m-1] == 0) {
			lab[i][m-1] = 4;
			y[k] = i;
			x[k] = m-1;
			k++;
		}
	}

	for (int i = 0; i < k; i++)
	{
		if (x[i] + 1 < m && lab[y[i]][x[i] + 1] == 0)
		{
			lab[y[i]][x[i] + 1] = 2;
			y[k] = y[i];
			x[k] = x[i] + 1;
			k++;
		}
		if (y[i] - 1 >= 0 && lab[y[i] - 1][x[i]] == 0) {
			lab[y[i] - 1][x[i]] = 3;
			y[k] = y[i] - 1;
			x[k] = x[i];
			k++;
		}
		if (x[i]-1 >=0 && lab[y[i]][x[i] - 1] == 0) {
			lab[y[i]][x[i] - 1] = 4;
			y[k] = y[i];
			x[k] = x[i] - 1;
			k++;
		}
		if (y[i] + 1 < n && lab[y[i] + 1][x[i]] == 0) {
			lab[y[i] + 1][x[i]] = 1;
			y[k] = y[i] + 1;
			x[k] = x[i];
			k++;
		}
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	exitWidth();
	show();
	system("Pause");
	return 0;
}