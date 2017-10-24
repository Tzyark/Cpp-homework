#include <iostream>
#include <string>
using namespace std;

const int N = 109;

int n;
string tree[N];

void inOrder(int r) {
	if (r * 2 <= n) inOrder(r * 2);
	if (tree[r] != "null") cout << tree[r] << " ";
	if (r * 2 + 1 <= n) inOrder(r * 2 + 1);
}

int main() {
	while (cin >> tree[++n]);
	inOrder(1);
}
                                                                                                                                                                                                                                                                                                                                                                                              