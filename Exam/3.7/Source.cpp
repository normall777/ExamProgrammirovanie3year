#include <iostream>

using namespace std;

int factDown(int n) {
	int r = 1;
	if (n > 1)
		r *= factDown(n - 1);
	return r;

}

void factUp(int n, int s, int*r) {
	if (n == s) {
		(*r) = n*(*r);
	}
	else if (n > s) {
		(*r) = (*r)*s;
		factUp(n, s + 1, r);
	}
}

int fact(int n) {
	int r = 1;
	factUp(n, 2, &r);
	return r;
}

int main() {
	setlocale(LC_ALL, "Russian");
	cout << fact(5) << endl;
	system("Pause");
	return 0;
}