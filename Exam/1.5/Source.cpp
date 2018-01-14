#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	cin >> n;
	int sum=1;
	int slog=1;
	for (int i = 2; i <= n; i++)
	{
		slog *= i;
		sum += slog;
	}
	cout << sum << endl;

	system("Pause");
	return 0;
}