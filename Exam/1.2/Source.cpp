#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	int k;
	cin >> n;
	int *mas = new int[n];
	int sdvig = 0;
	cin >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> mas[i];
	}
	for (int i = 0; i < n-sdvig; i++)
	{
		while (mas[i + sdvig] == k) { sdvig++; }
		mas[i] = mas[i + sdvig];
	}
	for (int i = n-sdvig; i < n; i++)
	{
		mas[i] = 0;
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << mas[i] << " ";
	}





	system("Pause");
	return 0;
}