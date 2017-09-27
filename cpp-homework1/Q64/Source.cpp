#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int to(string th) {
	int abs = 0, sgn = 1, pow = 1;
	if (th[0] == '-') {
		sgn = -1;
		th = th.substr(1);
	}
	reverse(th.begin(), th.end());
	for (auto ch : th) {
		if (isdigit(ch)) abs += (int) (ch - '0') * pow;
		else abs += (int) (10 + ch - 'A') * pow;
		pow *= 13;
	}
	return sgn * abs;
}
string re(int de) {
	string ret;
	bool neg = 0;
	if (de == 0) return "0";
	if (de < 0) {
		neg = 1;
		de = abs(de);
	}
	while (de > 0) {
		int m = de % 13;
		if (m < 10) ret += (char)('0' + m);
		else ret += (char)('A' + m - 10);
		de /= 13;
	}
	reverse(ret.begin(), ret.end());
	return neg ? "-" + ret : ret;
}
int main() {
	string cmd, a, b;
	cin >> cmd >> a >> b;
	if (cmd == "add") cout << re(to(a) + to(b));
	if (cmd == "sub") cout << re(to(a) - to(b));
	if (cmd == "mul") cout << re(to(a) * to(b));
	//system("pause");
}