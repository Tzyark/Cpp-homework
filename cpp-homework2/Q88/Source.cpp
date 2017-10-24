#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
using namespace std;

const int N = 10009;

int n;
string str[N];

inline int hashing(const char &c) {
	return 2 * (tolower(c) - 'a') + isupper(c);
}

bool cmp(const string &s1, const string &s2) {
	if (s1.size() < s2.size())
		return true;
	else 
		if (s1.size() == s2.size()) {
			for (int i = 0; i < s1.size(); i++) {
				if (hashing(s1[i]) < hashing(s2[i]))
					return true;
				else
					return false;
			}
		}
		else
			return false;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> str[i];
	/*
	srand((unsigned) time(0));
	ofstream fout;
	string filename = "e:\\data"; filename += rand() % 10 + 48; filename += ".txt";
	fout.open(filename);
	//for (int i = 0; i < n; i++) fout << str[i] << endl;
	fout.close();
	*/
	sort(str, str + n, cmp);
	for (int i = 0; i < n; i++) cout << str[i] << endl;
}