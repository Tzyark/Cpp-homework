#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;
typedef pair<string, string> pss;
map<pss, double> rec;
set<string> sName, sCour;
int main() {
	int n;
	for (cin >> n; n; n--) {
		string name, num, cour;
		double scr;
		cin >> name >> num >> cour >> scr;
		sName.insert(name);
		sCour.insert(cour);
		rec[make_pair(name, cour)] = scr;
	}
	cout << setiosflags(ios::fixed) << setprecision(2);
	int m;
	for (cin >> m; m; m--) {
		string cmd;
		cin >> cmd;
		if (cmd == "student") {
			string name;
			cin >> name;
			double sum = 0.0;
			double cnt = 0.0;
			for (auto cour : sCour) {
				pss tmp = make_pair(name, cour);
				if (rec.find(tmp) != rec.end()) {
					sum += rec[tmp];
					cnt++;
				}
			}
			cout << name << " " << (sum / cnt) << endl;
		}
		else {
			string cour;
			cin >> cour;
			double sum = 0.0;
			double cnt = 0.0;
			for (auto name : sName) {
				pss tmp = make_pair(name, cour);
				if (rec.find(tmp) != rec.end()) {
					sum += rec[tmp];
					cnt++;
				}
			}
			cout << cour << " " << (sum / cnt) << endl;
		}
	}
	//system("pause");
}