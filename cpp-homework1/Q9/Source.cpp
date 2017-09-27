#include <iostream>
bool isPrime(int x) {
	if (x == 1) return 0;
	for (int d = 2; d * d <= x; d++) {
		if (x % d == 0) return 0;
	}
	return 1;
}
int main() {
	int n, m, res = 0;
	std::cin >> n >> m;
	for (int i = n; i <= m; i++) {
		if (isPrime(i)) res += i;
	}
	std::cout << res;
}