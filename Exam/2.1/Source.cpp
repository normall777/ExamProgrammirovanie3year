#include <iostream>

using namespace std;



int exponenta(int n, int p) {
	if (p == 1) return n;
	if (p % 2 == 1) {
		return n*exponenta(n, p - 1);
	}
	else {
		return exponenta(n*n, p / 2);
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	cout << exponenta(3, 11) << endl;
	system("Pause");
	return 0;
}