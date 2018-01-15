#include <iostream>

using namespace std;

int exponenta(int n, int p) {
	int r;
	if (p == 1)
		return n;
	else if (p % 2 == 1)
		return n * exponenta(n, p - 1);
	else
	{
		r = exponenta(n, p / 2);
		return r * r;
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	cout << exponenta(3, 11) << endl;
	system("Pause");
	return 0;
}