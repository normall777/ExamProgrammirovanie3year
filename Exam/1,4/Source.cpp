#include <iostream>

#define PR 4 // Промежуток

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	cin >> n;
	int a;
	int mux=-9999;
	int k = PR+1;
	int *mas = new int[k];
	int counter = 0;
	int maxChislo;
	for (int i = 0; i < k; i++, counter++) // Стартовый массив
	{
		cin >> mas[i];
	}
	maxChislo = mas[0];
	for (int i = 0; i < k; i++, counter++) // Поиск максимального произведения
	{
		if (counter >= n) break; // Делать пока вся последовательность не кончится
		cin >> a;
		if (mux < a*mas[i]) mux = a*mas[i];
		if (mux < a*maxChislo) mux = a*maxChislo;
		if (maxChislo < mas[i]) maxChislo = mas[i];
		
		mas[i] = a;

		if (i == k - 1) i = -1;
	}
	cout << mux << endl;

	system("Pause");
	return 0;
}