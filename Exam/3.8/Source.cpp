#include <iostream>
#include <vector>

using namespace std;

int fact(int n) {
	static vector<int> memory(n+1, 0);
	static int sumMemory = n + 1;
	if (sumMemory < n + 1) {
		sumMemory = n + 1;
		memory.resize(sumMemory);
		for (int i = 0; i < sumMemory; i++)
		{
			cout << memory[i] << " ";
		} 
		cout << endl;
	}

	if (memory[n] != 0) return memory[n];
	else {
		memory[1] = 1;
		memory[n] = n*fact(n - 1);
		return memory[n];
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	
	cout << fact(5) << endl;
	cout << fact(7) << endl;
	cout << fact(9) << endl;
	cout << fact(5) << endl;
	system("Pause");
	return 0;
}