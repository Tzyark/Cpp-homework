#include <algorithm>
#include <iostream>
using namespace std;

const int N = 109;
const int INF = 0x3f3f3f3f;

int n, res, a[N][N];

inline int f(int i, int j) {
	if (0 == i) return 0;
	if (j < 1 || j > i) return INF;
	return a[i][j];
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> a[i][j];
			a[i][j] += min(f(i - 1, j - 1), f(i - 1, j));
		}
	}
	res = a[n][1];
	for (int i = 2; i <= n; i++) {
		res = min(res, a[n][i]);
	}
	cout << res;
}