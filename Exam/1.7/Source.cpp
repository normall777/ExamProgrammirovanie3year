#include <iostream>
#include <string>

using namespace std;


int main() {
	setlocale(LC_ALL, "Russian");
	string slovo;
	cin >> slovo;
	char *sostav = new char[slovo.length() / 2 + 1];
	int counter = -1;
	bool flag = true;
	bool flagOfAdd = true;
	int *kolvo = new int[slovo.length() / 2 + 1];
	for (int i = 0; i < slovo.length(); i++)
	{
		for (int j = 0; j <= counter; j++)
		{
			if (sostav[j] == slovo[i]) {
				kolvo[j]++;
				flagOfAdd = false;
				break;
			}
		}
		if (!flagOfAdd) {
			flagOfAdd = true;
			continue;
		}
		counter++;
		if (counter > slovo.length() / 2 + 1) {
			flag = false;
			break;
		}
		sostav[counter] = slovo[i];
		kolvo[counter] = 1;
	}
	if (flag) {
		int countOfNechet = 0;
		for (int i = 0; i < counter + 1; i++)
		{
			if (kolvo[i] % 2 == 1) countOfNechet++;
			if (countOfNechet >= 2)
			{
				flag = false;
				break;
			}
		}
	}

	if (flag) cout << "�� ���� ����� ����� ����� ��������� ���������" << endl;
	else cout << "�� ���� ����� ����� ������ ��������� ���������" << endl;
	system("Pause");
	return 0;
}