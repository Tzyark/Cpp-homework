#include <iostream>
typedef long long LL;
int main() {
	LL n, f[101];
	f[0] = 0, f[1] = 1;
	std::cin >> n;
	for (LL i = 2; i <= n; i++) {
		f[i] = f[i - 1] + f[i - 2];
	}
	std::cout << f[n];
}