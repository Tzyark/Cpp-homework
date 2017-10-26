#include <iostream>
#include <stack>
#include <string>

#include <fstream>
#include <time.h>
using namespace std;

const string T = "True";
const string F = "False";

string str;
stack<string> st;

bool checkTag(const string &tag) {
	if (tag.size() > 9) return false;
	for (auto c : tag) {
		if (!isupper(c)) return false;
	}
	return true;
}

string check(string s) {
	int i = 0, len = s.size();
	while (i < len) {
		if ('<' == s[i]) {
			string tag = "";
			if ('!' == s[i + 1] && '-' == s[i + 2] && '-' == s[i + 3]) {
				i += 4;
				while ('-' != s[i] || '-' != s[i + 1] || '>' != s[i + 2]) i++;
				i += 3;
				continue;
			}
			if ('/' == s[i + 1]) {
				i++;
				while (s[i + 1] != '>') tag += s[++i];
				i++;
				if (tag == st.top()) st.pop(); else return F;
				continue;
			}
			while (s[i + 1] != '>') tag += s[++i];
			i++;
			if (checkTag(tag)) st.push(tag); else return F;
		}
		else
			i++;
	}
	if (!st.empty()) return F;
	else return T;
}

int main() {
	getline(cin, str);
	cout << check(str);
}