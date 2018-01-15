#include <iostream>

using namespace std;

int fact(int n) {
	int r = 1;
	for (int i = 2; i <= n; i++)
	{
		r = r*i;
	}
	return r;
}

/*int sigma(int n, int(*f)(int)) {
	int r = 1;
	for (int i = 2; i <= n; i++)
	{
		r = r + f(i);
	}
	return r;
}*/


int sigma(int n, int(*f)(int) , int(*zf)(int, int)) {
	int r = 1;
	for (int i = 2; i <= n; i++)
	{
		r = zf(r,f(i));
	}
	return r;
}

int sum(int a, int b) {
	return a + b;
}

int mux(int a, int b) {
	return a*b;
}

int main() {
	setlocale(LC_ALL, "Russian");
	cout << sigma(5, fact, sum) << endl;
	cout << sigma(4, fact, mux) << endl;
	system("Pause");
	return 0;
}