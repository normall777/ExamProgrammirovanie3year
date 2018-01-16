#include <iostream>
#include <functional>

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

int recurse(int n, int start, int(*f)(int, int)) {
	if (n == 1)
		return start;
	else
		return f(recurse(n - 1, start, f), n);
}



int main() {
	setlocale(LC_ALL, "Russian");
	cout << fact(5) << endl;
	cout << recurse(5, 1, [](int a, int b)->int {return a*b; }) << endl;
	system("Pause");
	return 0;
}