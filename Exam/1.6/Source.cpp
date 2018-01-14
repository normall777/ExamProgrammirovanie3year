#include <iostream>

using namespace std;

int fib(int n) {
	int slog1 = 1;
	int slog2 = 1;
	bool flag = false;
	for (int i = 2; i < n; i++)
	{
		if (!flag) {
			slog1 += slog2;
			flag = true;
		}
		else {
			slog2 += slog1;
			flag = false;
		}
	}
	if (!flag) return slog2;
	if (flag) return slog1;
}


int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	cin >> n;
	cout << fib(n) << endl;

	system("Pause");
	return 0;
}