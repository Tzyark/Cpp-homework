#include <iostream>

using namespace std;

class GPU {
public:
	int price;
	int hashRate;
	virtual double calculate() = 0;
};

class GPU1 : public GPU {
public:
	GPU1() {
	}
	GPU1(int _price, int _hashRate) {
		price = _price;
		hashRate = _hashRate;
	}
	double calculate() {
		return hashRate * 0.02 - 16.2;
	}
	friend istream &operator >> (istream &is, GPU &gpu);
};

class GPU2 : public GPU {
public:
	GPU2() {
	}
	GPU2(int _price, int _hashRate) {
		price = _price;
		hashRate = _hashRate;
	}
	double calculate() {
		return hashRate * 0.02 - 28.8;
	}
	friend istream &operator >> (istream &is, GPU &gpu);
};

class GPU3 : public GPU {
public:
	GPU3() {
	}
	GPU3(int _price, int _hashRate) {
		price = _price;
		hashRate = _hashRate;
	}
	double calculate() {
		return hashRate * 0.02 - 19.44;
	}
	friend istream &operator >> (istream &is, GPU &gpu);
};

istream &operator >> (istream &is, GPU &gpu) {
	return is >> gpu.price >> gpu.hashRate;
}
/*
istream &operator >> (istream &is, GPU2 &gpu) {
	return is >> gpu.price >> gpu.hashRate;
}

istream &operator >> (istream &is, GPU3 &gpu) {
	return is >> gpu.price >> gpu.hashRate;
}
*/
int main(int argc, char *argv[]) {
	GPU1 gpu1;
	GPU2 gpu2;
	GPU3 gpu3;
	cin >> gpu1 >> gpu2 >> gpu3;
	double day = (gpu1.price + gpu2.price + gpu3.price) / (gpu1.calculate() + gpu2.calculate() + gpu3.calculate());
	cout << (day > 0 ? ceil(day) : -1) << endl;
	return 0;
}