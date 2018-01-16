#include <iostream>
#include <vector>

using namespace std;

int fact(int n, int a[100]) {
	if (n == 0)
		return 1;
	if (a[n] == 0) {
		a[n] = fact(n - 1, a)*n;
		return a[n];
	}
	else return a[n];
}

int memoize(int n, int a[], int(*f)(int, int*)) {
	return a[n] = f(n, a);
}

int factmem(int n, int(*f)(int, int*))
{
	static int a[100];
	static bool flag = false;
	if (!flag) {
		for (int i = 0; i < 100; i++) {
			a[i] = 0;
		}
		flag = true;
		a[0] = 1;
		a[1] = 1;
	}
	if (a[n] == 0) return memoize(n, a, f);
	return a[n];
}


int main() {
	setlocale(LC_ALL, "Russian");
	cout << factmem(5,fact) << endl;
	system("Pause");
	return 0;
}