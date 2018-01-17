#include <iostream>

using namespace std;

int fib(int n) {
	int slog1 = 1;
	int slog2 = 1;
	int res;
	for (int i = 3; i <= n; i++)
	{
		res = slog1 + slog2;
		slog1 = slog2;
		slog2 = res;
	}
	return res;
}


int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	cin >> n;
	cout << fib(n) << endl;

	system("Pause");
	return 0;
}