#include <iostream>

using namespace std;

int lab[7][8] = {
	{9,9,9,9,9,0,9,9},
	{9,0,0,0,0,0,0,9},
	{9,0,0,9,9,9,0,9},
	{9,0,9,9,0,9,0,9},
	{9,0,0,0,0,9,9,9},
	{9,9,0,9,0,9,0,9},
	{9,9,0,9,9,9,9,9}
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

void exitLen(int y, int x) {
	int y1 = y, x1 = x;
	do {
		if (x + 1 < m) {
			if (lab[y][x + 1] == 0) {
				lab[y][x + 1] = 2;
				x = x + 1;
				continue;
			}
		}
		if (x - 1 >= 0) {
			if (lab[y][x - 1] == 0) {
				lab[y][x - 1] = 4;
				x = x - 1;
				continue;
			}
		}
		if (y + 1 < n) {
			if (lab[y + 1][x] == 0) {
				lab[y + 1][x] = 1;
				y = y + 1;
				continue;
			}
		}
		if (y - 1 >= 0)
		{
			if (lab[y - 1][x] == 0) {
				lab[y - 1][x] = 3;
				y = y - 1;
				continue;
			}
		}
		if (lab[y][x] == 1) y = y - 1;
		else if (lab[y][x] == 2) x = x - 1;
		else if (lab[y][x] == 3) y = y + 1;
		else if (lab[y][x] == 4) x = x + 1;

	} while (!(y1 == y && x1 == x));
}

int main() {
	setlocale(LC_ALL, "Russian");
	for (int i = 0; i < m; i++)
	{
		if (lab[0][i] == 0) {
			lab[0][i] = 1;
			exitLen(0, i);
		}
		else if (lab[n - 1][i] == 0) {
			lab[n - 1][i] = 3;
			exitLen(n - 1, i);
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (lab[i][0] == 0) {
			lab[i][0] = 2;
			exitLen(i, 0);
		}
		else if (lab[i][m - 1] == 0) {
			lab[i][m - 1] = 4;
			exitLen(i, m - 1);
		}
	}

	


	show();


	system("Pause");
	return 0;
}