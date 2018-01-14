#include <iostream>

using namespace std;

int exponenta(int a, int n, int sapas = 1) {
	int result = 1;
	if (n % 2 != 0 && n >= 2) {
		sapas *= a;
		n--;
	}
	if (n % 2 == 0 && n >= 2) {
		n = n / 2;
		a = a*a;
		result = a;
		return exponenta(a, n, sapas);
	}
	result = a;
	result *= sapas;
	return result;
}

int main() {
	setlocale(LC_ALL, "Russian");
	cout << exponenta(3, 11) << endl;
	system("Pause");
	return 0;
}