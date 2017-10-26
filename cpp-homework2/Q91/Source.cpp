#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;
typedef pair<LL, double> PLD;

int n;
LL id;
double scr, aveTot, aveTmp;
string name, sub;
set<LL> idSet;
set<string> subSet;
map<LL, double> ave;
map<pair<LL, string>, double> rec;
vector<PLD> res;

bool cmp(const PLD &stu1, const PLD &stu2) {
	return stu1.second > stu2.second || stu1.second == stu2.second && stu1.first > stu2.first;
}

unsigned main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> name >> id >> sub >> scr;
		idSet.insert(id);
		subSet.insert(sub);
		rec[make_pair(id, sub)] = scr;
	}
	for (auto info : rec) {
		aveTot += info.second;
	}
	aveTot /= 1.0 * idSet.size() * subSet.size();
	for (auto id : idSet) {
		aveTmp = 0;
		for (auto info : rec) {
			if (info.first.first == id) 
				aveTmp += info.second;
		}
		ave[id] = aveTmp / (double) subSet.size();
	}
	for (auto stu : ave) {
		if (stu.second <= aveTot) 
			res.emplace_back(stu);
	}
	sort(res.begin(), res.end(), cmp);
	for (auto stu : res) {
		cout << stu.first << endl;
	}
}