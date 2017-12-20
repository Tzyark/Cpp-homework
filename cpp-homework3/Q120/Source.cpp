#include <iostream>

using namespace std;

class Food {
private:
	int price;
public:
	Food() : price(0) {}
	Food(int _price) : price(_price) {}
	virtual int getPrice() {
		return price;
	}
};

class Hamburger : public Food {
private:
	Food *bread;
	Food *vegetable;
public:
	Hamburger() : bread(NULL), vegetable(NULL) {}
	int getPrice() {
		return bread->getPrice() + vegetable->getPrice();
	}
};

class FoodFactory {
public:
	Food *getBread(int id) {
		switch (id) {
		case 1: return new Food(10);
		case 2: return new Food(8);
		case 3: return new Food(7);
		default: break;
		}
	}
	Food *getVegetable(int id) {
		switch (id) {
		case 1: return new Food(4);
		case 2: return new Food(3);
		default: break;
		}
	}
};

int main(int argc, char *argv[]) {
	int sum = 0;
	int id, num;
	cin >> id >> num;
	sum += ((FoodFactory::getBread(id))->getPrice()) * num;
	cin >> id >> num;
	sum += ((FoodFactory::getVegetable(id))->getPrice()) * num;
	cout << sum << endl;
	return 0;
}