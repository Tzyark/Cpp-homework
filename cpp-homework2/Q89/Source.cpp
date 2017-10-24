#include <iostream>
#include <map>
#include <string>
using namespace std;

const int N = 10009;

int n;
map<string, int> node;
string node1, node2, tree[N];

bool check(int u, int v) {
	while (v >= u) {
		if (v == u) return 1;
		v >>= 1;
	}
	return 0;
}

int depth(int u) {
	int ret = 0;
	while (u) {
		u >>= 1;
		ret++;
	}
	return ret;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> tree[i];
		node[tree[i]] = i;
	}
	cin >> node1 >> node2;
	if (node[node1] > node[node2]) swap(node1, node2);
	if (!check(node[node1], node[node2])) cout << "-1";
	else cout << depth(node[node2]) - depth(node[node1]);
}