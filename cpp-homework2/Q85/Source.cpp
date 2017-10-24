#include <iostream>
#include <string>
using namespace std;

const int N = 1009;

int n, m, a, b;
int arr[N];
string cmd, dir;

void replace(int a, int b) {
	for (int i = 0; i < n; i++) {
		if (arr[i] == a) arr[i] = b;
	}
}

void move(string dir, int a) {
	int n1 = 0, n2 = 0;
	int tmp[N];
	for (int i = 0; i < n; i++) {
		if (arr[i] == a) n1++;
		else tmp[n2++] = arr[i];
	}
	if (dir == "head") {
		for (int i = 0; i < n1; i++) arr[i] = a;
		for (int i = n1; i < n; i++) arr[i] = tmp[i - n1];
	}
	if (dir == "tail") {
		for (int i = 0; i < n2; i++) arr[i] = tmp[i];
		for (int i = n2; i < n; i++) arr[i] = a;
	}
}

void translate(string dir, int a) {
	int tmp[N];
	int d = (dir == "head") ? -a : a;
	for (int i = 0; i < n; i++) tmp[(i + d + n) % n] = arr[i];
	for (int i = 0; i < n; i++) arr[i] = tmp[i];
}

void print() {
	for (int i = 0; i < n - 1; i++) cout << arr[i] << " ";
	cout << arr[n - 1] << endl;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> cmd;
		if ("replace" == cmd) {
			cin >> a >> b;
			replace(a, b);
		}
		if ("move" == cmd) {
			cin >> dir >> a;
			move(dir, a);
		}
		if ("translate" == cmd) {
			cin >> dir >> a;
			translate(dir, a);
		}
		if ("print" == cmd) print();
	}
}