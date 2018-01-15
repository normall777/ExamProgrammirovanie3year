#include <iostream>
#include <functional>

using namespace std;

int power(int a, int n) {
	int r = 1;
	for (int i = 0; i < n; i++)
	{
		r *= a;
	}
	return r;
}

function<int(int)>partapply(function<int(int, int)> f, int n) {
	return [f, n](int a)->int {
		return f(a, n);
	};
}

int main() {
	setlocale(LC_ALL, "Russian");
	function<int(int)> fsqr = partapply(power, 2);
	function<int(int)> fquad = partapply(power, 3);
	cout << fsqr(5) << endl;
	cout << fquad(50) << endl;
	system("Pause");
	return 0;
}