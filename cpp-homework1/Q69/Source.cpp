#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int palindromicLen(string s) {
	string t = s;
	reverse(t.begin(), t.end());
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != t[i]) return 0;
	}
	return s.length();
}
int main() {
	string s;
	int n, res = 0;
	cin >> n >> s;
	for (int i = 0; i < s.length(); i++) {
		for (int j = i; j < s.length(); j++) {
			res = max(res, palindromicLen(s.substr(i, j - i + 1)));
		}
	}
	cout << res;
	//system("pause");
}