#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
inline LL high3(LL x) {
	LL y = x, bit = 0;
	while (x > 0) {
		bit++;
		x >>= 1;
	}
	return (y >> max(bit - 3LL, 0LL));
}
int main() {
	LL n, a, res = 0;
	cin >> n;
	for (LL i = 1; i <= n; i++) {
		cin >> a;
		res += high3(a);
	}
	cout << res;
	//system("pause");
}