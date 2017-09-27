#include <iostream>
#include <string>
using namespace std;
int n, m, a, b, c, arr[101];
void add(int a) {
	for (int i = 1; i <= n; i++) arr[i] += a;
}
void sub(int b) {
	for (int i = 1; i <= n; i++) arr[i] -= b;
}
void mul(int c) {
	for (int i = 1; i <= n; i++) arr[i] *= c;
}
void pow() {
	for (int i = 1; i <= n; i++) arr[i] = pow(arr[i], n);
}
int sqa() {
	int ret = 0;
	for (int i = 1; i <= n; i++) ret += pow(arr[i], 2);
	return ret;
}
void print() {
	for (int i = 1; i < n; i++) cout << arr[i] << " ";
	cout << arr[n];
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> arr[i];
	}
	cin >> m;
	for (int i = 1; i <= m; i++) {
		string cmd;
		cin >> cmd;
		if (cmd == "add") cin >> a, add(a);
		if (cmd == "sub") cin >> b, sub(b);
		if (cmd == "mul") cin >> c, mul(c);
		if (cmd == "pow") pow();
		if (cmd == "sqa") cout << sqa() << endl;
		if (cmd == "print") print();
	}
}