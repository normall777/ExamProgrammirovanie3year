#include <iostream>

using namespace std;


int search(int *mas, int finish, int element, int start=0) {
	int seredina = start + (finish - start) / 2;
	if (element > mas[finish - 1] || element < mas[start]) return -1;
	if (mas[seredina] == element) {
		return seredina;
	}
	if (mas[seredina] > element) {
		finish = seredina;
	}
	if (mas[seredina] < element) {
		start = seredina;
	}
	return search(mas, finish, element, start);
}



int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	n = 501;
	int *mas = new int[n];
	for (int i = 0; i < n; i++)
	{
		mas[i] = 2*i;
	}
	int k;
	cin >> k;
	
	cout << search(mas, n, k) << endl;

	system("Pause");
	return 0;
}