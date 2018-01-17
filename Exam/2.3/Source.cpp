#include <iostream>
#include <vector>

using namespace std;

int fib(int n) {
	static vector<int> memo(n);
	static int sizeOfMemo = n;
	static bool initial = false;
	if (!initial) {
		memo[0] = 1;
		memo[1] = 1;
		initial = true;
	}
	if (initial) {
		if (sizeOfMemo < n) {
			memo.resize(n);
			for (int i = sizeOfMemo; i < n; i++)
			{
				memo[i] = 0;
			}
			sizeOfMemo = n;
		}
	}
	if (memo[n-1]==0)
	{
		memo[n-1] = fib(n - 1) + fib(n - 2);
	}
	return memo[n-1];
	
}


int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	cin >> n;
	cout << fib(n) << endl;
	cin >> n;
	cout << fib(n) << endl;
	cin >> n;
	cout << fib(n) << endl;
	system("Pause");
	return 0;
}