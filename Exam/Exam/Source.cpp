#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	bool flagFirst = false;
	bool flagNeighbor = false;
	bool flagAllEq = true;
	int n, a, b;
	cin >> n; //количество элементов
	for (int i = 0; i < n; i++)
	{
		if (!flagFirst) {
			cin >> a;
			flagFirst = true;
			continue;
		}
		cin >> b;
		if (a == b) {
			flagNeighbor = true;
		}
		else {
			flagAllEq = false;
		}
		a = b;
	}

	if (flagAllEq) {
		cout << "Все числа равны";
	}
	else if (flagNeighbor)
	{
		cout << "Есть соседние равные";
	}
	else
	{
		cout << "Нет соседних равных";
	}

	cout << endl;
	system("Pause");
	return 0;
}