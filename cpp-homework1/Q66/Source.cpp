#include <bitset>
#include <iostream>
#include <set>
#include <string>
using namespace std;
int b[101], c[11];
set<int> pow2, bit[11];
int main() {
	string n;
	cin >> n;
	int m = n.length();
	int k = 0;
	for (; m + k + 1 >= pow(2, k); k++) {
		pow2.insert(pow(2, k));
	}
	int p = 0;
	for (int i = 1; i <= m + k; i++) {
		if (pow2.count(i) != 0) continue;
		else b[i] = n[p++] - '0';
		bitset<11> tmp(i);
		for (int j = 0; j < 11; j++) {
			if (tmp[j]) bit[j].insert(i);
		}
	}
	for (int i = 0; i < k; i++) {
		set<int>::iterator iter = bit[i].begin();
		b[(int)pow(2,i)] = b[*iter]; iter++;
		for (; iter != bit[i].end(); iter++) {
			b[(int)pow(2,i)] ^= b[*iter];
		}
	}
	for (int i = 1; i <= m + k; i++) cout << b[i];
	//system("pause");
}