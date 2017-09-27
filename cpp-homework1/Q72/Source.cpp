#include <iostream>
#include <string>
using namespace std;
inline int f(char c) {
	if (c == 'I') return 1;
	if (c == 'V') return 5;
	if (c == 'X') return 10;
	if (c == 'C') return 100;
	if (c == 'M') return 1000;
	if (c == 'L') return 50;
	if (c == 'D') return 500;
}
int main() {
	string s;
	cin >> s;
	int res = 0;
	for (int i = 0; i < s.length(); i++) {
		if (i + 1 >= s.length() || f(s[i + 1]) <= f(s[i])) res += f(s[i]);
		else res -= f(s[i]);
	}
	cout << res;
}