#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int N = 1009;

int n, a;
string cmd;
vector<int> res;

int count(int a) {
	int ret = 0;
	for (auto num : res) {
		if (num == a) ret++;
	}
	return ret;
}

void removeRepeat(int a) {
	int cnt = count(a);
	if (0 == cnt) return;
	vector<int> tmp;
	tmp.clear();
	for (auto num : res) {
		if (num != a || cnt == 1) tmp.emplace_back(num);
		else 
			if (num == a) cnt--;
	}
	res = tmp;
}

void del(int a) {
	int cnt = count(a);
	if (0 == cnt) return;
	vector<int> tmp;
	tmp.clear();
	for (auto num : res) {
		if (num != a) tmp.emplace_back(num);
	}
	res = tmp;
}

void print() {
	if (0 == res.size()) 
		cout << "NULL" << endl;
	else {
		for (int i = 0; i < res.size() - 1; i++) cout << res[i] << " ";
		cout << res[res.size() - 1] << endl;
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cmd;
		if (cmd == "ADD") {
			cin >> a;
			res.emplace_back(a);
		}
		if (cmd == "REVERSE") reverse(res.begin(), res.end());
		if (cmd == "REMOVEREPEAT") {
			cin >> a;
			removeRepeat(a);
		}
		if (cmd == "DEL") {
			cin >> a;
			del(a);
		}
		if (cmd == "PRINT") print();
		if (cmd == "SIZE") cout << res.size() << endl;
	}
}