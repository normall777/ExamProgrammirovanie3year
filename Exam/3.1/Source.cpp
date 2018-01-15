#include <iostream>

using namespace std;

int akkerman(int m, int n) {
	if (m == 0) {
		return n + 1;
	}
	else if (m > 0 && n == 0) {
		return akkerman(m - 1, 1);
	}
	else if (m > 0 && n > 0) {
		return akkerman(m - 1, akkerman(m, n - 1));
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	int m, n;
	cin >> m;
	cin >> n;
	cout << akkerman(m, n) << endl;
	system("Pause");
	return 0;
}