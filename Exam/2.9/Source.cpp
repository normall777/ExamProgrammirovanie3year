#include <iostream>

using namespace std;

int lab[7][8] = {
	{ 9,9,9,9,9,0,9,9 },
	{ 9,0,0,0,0,0,0,9 },
	{ 9,0,0,9,9,9,0,9 },
	{ 9,0,9,9,0,9,0,9 },
	{ 9,0,9,0,0,9,9,9 },
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
			else cout << char('a' - 10 + lab[i][j]);
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
	if (x - 1 >= 0) {
		if (lab[y][x - 1] == 0) {
			lab[y][x - 1] = 4;
			exitRec(y, x - 1);
		}
	}
	if (y + 1 < n) {
		if (lab[y + 1][x] == 0) {
			lab[y + 1][x] = 3;
			exitRec(y + 1, x);
		}
	}
	if (y - 1 >= 0) {
		if (lab[y - 1][x] == 0) {
			lab[y - 1][x] = 1;
			exitRec(y - 1, x);
		}
	}
}

void Sector() {
	int c = 10;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (lab[i][j]==0)
			{
				lab[i][j] = 1;
				exitRec(i, j);
				for (int i1 = 0; i1 < n; i1++)
				{
					for (int j1 = 0; j1 < m; j1++)
					{
						if (lab[i1][j1] > 0 && lab[i1][j1] < 5) {
							lab[i1][j1] = c;
						}
					}
				}
				c++;
			}
		}
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	Sector();
	show();
	system("Pause");
	return 0;
}