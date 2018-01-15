#include <iostream>
#include <functional>

using namespace std;

int sigma(int n, int(*f)(int)) {
	int r = 1;
	for (int i = 2; i <= n; i++)
	{
		r = r + f(i);
	}
	return r;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n = 4;
	cout << sigma(n,[](int n)->int {
		int r=1;
		for (int i = 2; i <= n; i++)
		{
			r = r * i;
		}
		return r;
	}) << endl;
	system("Pause");
	return 0;
}