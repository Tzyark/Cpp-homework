#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main() {
	string s = "";
	int m;
	for (cin >> m; m; m--) {
		string cmd;
		cin >> cmd;
		if (cmd == "append") {
			string abc;
			cin >> abc;
			s.append(abc);
		}
		if (cmd == "replace") {
			string a, b;
			cin >> a >> b;
			int pos = 0;
			while (pos != string::npos) {
				pos = s.find(a);
				if (pos != string::npos) s.replace(pos, a.length(), b);
			}
		}
		if (cmd == "reverse") {
			reverse(s.begin(), s.end());
		}
		if (cmd == "changecase") {
			string up;
			cin >> up;
			if (up == "up") transform(s.begin(), s.end(), s.begin(), toupper);
			else transform(s.begin(), s.end(), s.begin(), tolower);
		}
		if (cmd == "length") {
			cout << s.length() << endl;
		}
		if (cmd == "print") {
			cout << s << endl;
		}
	}
	//system("pause");
}