#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main() {
	string str;
	getline(cin, str);
	int pos = str.rfind(" ");
	cout << str.substr(pos + 1).length();
	//system("pause");
}