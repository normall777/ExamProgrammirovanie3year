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

void exitRec(int y, int x) {
	if (x + 1 < m) {
		if (lab[y][x + 1] == 0) {
			lab[y][x + 1] = 2;
			exitRec(y, x + 1);
		}
	}
	if (y + 1 < n) {
		if (lab[y + 1][x] == 0) {
			lab[y + 1][x] = 1;
			exitRec(y + 1, x);
		}
	}
	if (x - 1 >= 0) {
		if (lab[y][x - 1] == 0) {
			lab[y][x - 1] = 4;
			exitRec(y, x - 1);
		}
	}
	if (y - 1 >= 0) {
		if (lab[y - 1][x] == 0) {
			lab[y - 1][x] = 3;
			exitRec(y - 1, x);
		}
	}
}

int main() {
	setlocale(LC_ALL, "Russian");

	for (int i = 0; i < m; i++)
	{
		if (lab[0][i] == 0) {
			lab[0][i] = 1;
			exitRec(0, i);
		}
		if (lab[n-1][i] == 0) {
			lab[n-1][i] = 3;
			exitRec(n-1, i);
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (lab[i][0] == 0) {
			lab[i][0] = 2;
			exitRec(i, 0);
		}
		if (lab[i][m - 1] == 0) {
			lab[i][m - 1] = 4;
			exitRec(i, m - 1);
		}
	}
	show();
	system("Pause");
	return 0;
}