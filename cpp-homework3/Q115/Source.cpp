#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Data {
protected:
	int n;
	vector<T> arr;
public:
	void setN(const int &_n) {
		n = _n;
	}
	void setArr(const vector<T> &_arr) {
		arr = _arr;
	}
	vector<T> getArr() {
		return arr;
	}
	void Sort() {
		sort(arr.begin(), arr.end());
	}
	int BinarySearch(const T &t) {
		int l = 0;
		int r = n - 1;
		int ret = 0;
		while (l <= r) {
			ret++;
			int m = ((l + r) >> 1);
			if (arr[m] == t) {
				break;
			}
			else 
			if (arr[m] < t) {
				l = m + 1;
			}
			else {
				r = m - 1;
			}
		}
		return ret;
	}
};

int main(int argc, char *argv[]) {
	Data<int> data1;
	int n1;
	cin >> n1;
	vector<int> arr1(n1);
	for (int i = 0; i < n1; i++) {
		cin >> arr1[i];
	}
	data1.setN(n1);
	data1.setArr(arr1);
	data1.Sort();
	int t1;
	cin >> t1;
	cout << data1.BinarySearch(t1) << endl;

	Data<double> data2;
	int n2;
	cin >> n2;
	vector<double> arr2(n2);
	for (int i = 0; i < n2; i++) {
		cin >> arr2[i];
	}
	data2.setN(n2);
	data2.setArr(arr2);
	data2.Sort();
	double t2;
	cin >> t2;
	cout << data2.BinarySearch(t2) << endl;

	Data<char> data3;
	int n3;
	cin >> n3;
	vector<char> arr3(n3);
	for (int i = 0; i < n3; i++) {
		cin >> arr3[i];
	}
	data3.setN(n3);
	data3.setArr(arr3);
	data3.Sort();
	char t3;
	cin >> t3;
	cout << data3.BinarySearch(t3) << endl;
	return 0;
}