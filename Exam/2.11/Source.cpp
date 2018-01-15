#include <iostream>
#include <string>

using namespace std;

string pal(string s, int l, int r) {
	string p = "", pl = "", pr = "";
	if (l == r) {
		p = p + s[l];
	}
	else if (s[l] == s[r]) {
		if (r - l == 1)
			p = p + s[l] + s[r];
		else
			p = p + s[l] + pal(s, l + 1, r - 1) + s[r];
	}
	else {
		if (r - l == 1)
			pl = pl + s[l];
		else {
			pl = pal(s, l, r - 1);
			pr = pal(s, l + 1, r);
		}
		if (pl.length() >= pr.length())
			p = pl;
		else
			p = pr;
	}
	return p;
}

int main() {
	setlocale(LC_ALL, "Russian");
	string s;
	cin >> s;
	cout << pal(s, 0, s.length()-1) << endl;
	system("Pause");
	return 0;
}