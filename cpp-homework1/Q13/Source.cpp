#include <iostream>
int main() {
	int n, i = 1, s = 0;
	std::cin >> n;
	while (s < n) {
		s += i;
		i++;
	}
	int j = n - s + i - 1;
	(i % 2 == 1) ? std::cout << j << "/" << i - j : std::cout << i - j << "/" << j;
}