#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

const int N = 10009;

int n;
string s[N];

int hashing(const char &c) {
	return 2 * (toupper(c) - 'A') + isupper(c);
}

bool smaller(const string &s1, const string &s2) {
	for (int i = 0; i < s1.size(); i++) {
		if (hashing(s1[i]) < hashing(s2[i])) return true;
		if (hashing(s1[i]) > hashing(s2[i])) return false;
	}
	return true;
}

bool cmp(const string &s1, const string &s2) {
	return s1.size() < s2.size() || s1.size() == s2.size() && smaller(s1, s2);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> s[i];
	sort(s, s + n, cmp);
	for (int i = 0; i < n - 1; i++) cout << s[i] << endl;
	cout << s[n - 1];
}