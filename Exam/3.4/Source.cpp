#include <iostream>
#include <functional>

using namespace std;

function<int(int)> power(int pow) {
	return [pow](int n)->int {
		int r = 1;
		for (int i = 0; i < pow; i++)
		{
			r *= n;
		}
		return r;
	};
}

int main() {
	setlocale(LC_ALL, "Russian");
	function<int(int)> fsqr = power(2);
	function<int(int)> fquad = power(3);
	cout << fsqr(5) << endl;
	cout << fquad(50) << endl;

	system("Pause");
	return 0;
}