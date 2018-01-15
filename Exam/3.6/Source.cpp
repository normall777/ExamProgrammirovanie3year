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

function<function<int(int)>(int)> curring(function<int(int, int)> f) {
	return [f](int n)->function<int(int)> {
		return [f, n](int a)->int {
			return f(a, n);
		};
	};
}

int main() {
	setlocale(LC_ALL, "Russian");
	function<function<int(int)>(int)> curry = curring(power);
	function<int(int)> fsqr = curry(2);
	function<int(int)> fquar = curry(3);
	cout << fsqr(5) << endl;
	cout << fquar(50) << endl;
	system("Pause");
	return 0;
}