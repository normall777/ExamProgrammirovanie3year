#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	int quadr[3][3] = { 
	{6, 1, 8},
	{7, 5, 3},
	{2, 9, 4} };
	int m = 3;

	bool magik = true;
	int etalon = 0;
	int proverka = 0;
	int proverka2 = 0;
	for (int i = 0; i < m; i++)
	{
		etalon += quadr[i][i];//Диагональ
	}
	for (int i = m-1, j = 0; i >= 0, j < m; i--, j++) {
		proverka += quadr[j][i];
	}
	if (proverka != etalon) magik = false;

	if (magik) {
		for (int i = 0; i < m; i++)
		{
			proverka = 0;
			proverka2 = 0;
			for (int j = 0; j < m; j++)
			{
				proverka += quadr[i][j];
				proverka2 += quadr[j][i];
			}
			if (proverka != etalon || proverka2 != etalon) {
				magik = false;
				break;
			}
		}
	}

	if (magik) cout << "Квадрат магический";
	else cout << "Квадрат не магический";
	cout << endl;
	system("Pause");
	return 0;
}