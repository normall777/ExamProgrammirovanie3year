#include <iostream>
#include <string>

using namespace std;

string pal(string s, int l, int r, string** str) {
	string p = "", pr = "", pl = "";
	if (l == r)
	{
		p = p + s[l];
	}
	else if (s[l] == s[r]) {
		if (r - l == 1) {
			p = p + s[l] + s[r];
		}
		else {
			if (str[l][r] == "") {
				str[l][r] = pal(s, l + 1, r - 1, str);
			}
			p = p + s[l] + str[l][r] + s[r];
		}
	}
	else {
		if (r - l == 1) {
			pl = pl + s[l];
		}
		else {
			if (str[l][r - 1] == "") {
				str[l][r - 1] = pal(s, l, r - 1, str);
			}
			pl = str[l][r - 1];

			if (str[l+1][r] == "") {
				str[l + 1][r] = pal(s, l + 1, r, str);
			}
			pr = str[l + 1][r];
		}
		if (pl.length() >= pr.length())
			p = pl;
		else
			p = pr;
	}
	str[l][r] = p;
	return p;
}

int main() {
	setlocale(LC_ALL, "Russian");
	string s;
	cin >> s;
	string **str = new string*[s.length()];
	int **mas = new int*[s.length()];
	for (int i = 0; i < s.length(); i++)
	{
		mas[i] = new int[s.length()];
		str[i] = new string[s.length()];
		for (int j = 0; j < s.length(); j++)
		{
			mas[i][j] = 0;
			str[i][j] = "";
		}
	}
	cout << pal(s, 0, s.length() - 1, str) << endl;
	system("Pause");
	return 0;
}