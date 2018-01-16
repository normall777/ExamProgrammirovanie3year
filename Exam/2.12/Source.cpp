#include <iostream>
#include <string>
#include <map>

using namespace std;

string pal(string s, int l, int r) {
	static map<string, string> memory;
	string p = "", pl = "", pr = "";
	if (l == r) {
		p = p + s[l];
	}
	else if (s[l] == s[r]) {
		if (r - l == 1) {
			p = p + s[l] + s[r];
		}
		else {
			if (memory[s.substr(l + 1, r - l - 1)] == "") {
				memory[s.substr(l + 1, r - l - 1)] = pal(s, l + 1, r - 1);
			}
			p = p + s[l] + memory[s.substr(l + 1, r - l - 1)] + s[r];
		}
	}
	else {
		if (r - l == 1) {
			pl = s[l];
		}
		else {
			if (memory[s.substr(l, r - l)] == "") {
				memory[s.substr(l, r - l)] = pal(s, l, r - 1);
			}
			pl = memory[s.substr(l, r - l)];
			if (memory[s.substr(l + 1, r - l)] == "") {
				memory[s.substr(l + 1, r - l)] = pal(s, l + 1, r);
			}
			pr = memory[s.substr(l + 1, r - l)];
		}
		if (pl.length() >= pr.length())
			p = pl;
		else
			p = pr;
	}
	memory[s.substr(l, r - l + 1)] = p;
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