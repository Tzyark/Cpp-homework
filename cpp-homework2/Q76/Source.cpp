#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

const int N = 1000009;

string s;
int n, carry, a[N], b[N], c[N];

void toArray(string s, int x[]) {
	for (int i = s.size() - 6; i >= 0; i -= 2) {
		x[ ++x[0] ] = s[i] - '0';
	}
}

int main() {
	cin >> s; toArray(s, a);
	cin >> s; toArray(s, b);
	n = max(a[0], b[0]);
	for (int i = 1; i <= n; i++) {
		c[i] = a[i] + b[i] + carry;
		carry = c[i] / 10;
		c[i] %= 10;
	}
	if (carry) c[++n] = carry;
	while (0 == c[n]) n--;
	for (int i = n; i; i--) {
		cout << c[i] << ">";
	}
	cout << "null";
}