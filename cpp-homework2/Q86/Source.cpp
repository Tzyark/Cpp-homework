#include <algorithm>
#include <iostream>
#define CHECK {if (0 == x--) {cout << a[i][j]; return 0;}}
using namespace std;

const int N = 1009;

int n, m, x, i, j, a[N][N];

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	cin >> x;
	for (int k = 0; k < min(n, m) / 2; k++) {
		i = k + 1;
		for (j = k + 1; j < m - k; j++) CHECK; 
		for (i = k + 1; i < n - k; i++) CHECK;
		for (j = m - k; j > k + 1; j--) CHECK;
		for (i = n - k; i > k + 1; i--) CHECK;
	}
	if (min(n, m) & 1) {
		if (n <= m) {
			i = min(n, m) / 2 + 1;
			for (j = i; j <= m - i + 1; j++) CHECK;
		}
		else {
			j = min(n, m) / 2 + 1;
			for (i = j; i <= n - i + 1; i++) CHECK;
		}
	}
}