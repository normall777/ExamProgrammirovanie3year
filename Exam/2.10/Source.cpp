#include <iostream>
#include <string>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	string s;
	cin >> s;
	int n =s.length();
	int **L, **R; 
	L = new int*[n];
	R = new int*[n];
	for (int i = 0; i < n; i++)
	{
		L[i] = new int[n];
		R[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			L[i][j] = 0;
			R[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++)
	{
		L[i][i] = 1;
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (s[j - i] == s[j]) {
				L[j][j - i] = 2 + L[j - 1][j - i + 1];
				R[j][j - i] = 1;
			}
			else {
				if (L[j][j - i + 1] >= L[j - 1][j - i]) {
					L[j][j - i] = L[j][j - i + 1];
					R[j][j - i] = 2;
				}
				else {
					L[j][j - i] = L[j - 1][j - i];
					R[j][j - i] = 3;
				}
			}
		}
	}
	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < n; j++)
	//	{
	//		cout << R[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	cout << L[n - 1][0] << endl;
	int j = n - 1;
	int i = 0;

	for (int k = 0; k < n; k++)
	{
		if (R[j][i]==1)
		{
			i++;
			j--;
		}
		else if (R[j][i] == 2) {
			s[i] = ' ';
			i++;
		}
		else if (R[j][i] == 3) {
			s[j] = ' ';
			j--;
		}
		else break;
	}
	cout << s << endl;
	
	system("Pause");
	return 0;
}