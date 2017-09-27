#include <iostream>
#include <string>
using namespace std;
string n;
int len;
inline char f(char c) {
	if (c == '2') return 'a';
	if (c == '3') return 'd';
	if (c == '4') return 'g';
	if (c == '5') return 'j';
	if (c == '6') return 'm';
	if (c == '7') return 'p';
	if (c == '8') return 't';
	if (c == '9') return 'w';
	return 'z' + 1;
}
void print(int i, string cur) {
	if (i == len) cout << cur << endl;
	for (char c = f(n[i]); c < f(n[i] + 1); c++) {
		print(i + 1, cur + c);
	}
}
int main() {
	cin >> n;
	len = n.length();
	print(0, "");
	//system("pause");
}