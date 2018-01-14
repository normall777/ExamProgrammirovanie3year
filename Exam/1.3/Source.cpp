#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	int k;
	int n;
	int a;
	cin >> n;
	cin >> k;
	int *max = new int[k];
	bool flag = false;
	for (int i = 0; i < k; i++)
	{
		cin >> max[i];
	}
	for (int i = 0; i < k-1; i++) // Сортировка от меньшего к большему
	{
		for (int j = i; j < k; j++)
		{
			if (max[i] > max[j]) {
				int temp = max[j];
				max[j] = max[i];
				max[i] = temp;
			}
		}
	}
	for (int i = 0; i < n-k; i++)
	{
		cin >> a;
		for (int j = 0; j < k; j++)
		{
			if (a < max[0]) break;
			if (k - 1 == j || (a > max[j] && j+1 < k && a < max[j + 1])) { // Поиск места для вставки и сдвиг
				for (int k = 0; k < j; k++)
				{
					max[k] = max[k + 1];
				}
				max[j] = a;
				break;
			}
		}
	}
	for (int i = 0; i < k; i++)
	{
		cout << max[i] << " ";
	}
	cout << endl;
	system("Pause");
	return 0;
}