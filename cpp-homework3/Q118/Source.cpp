#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Hero {
public:
	int id;
	string name;
	int hp;
	int atk;
	int atked;
	Hero() : id(0), name(NULL), hp(0), atk(0), atked(0) {}
	Hero(int _id, string _name, int _hp, int _atk, int _atked) : id(_id), name(_name), hp(_hp), atk(_atk), atked(_atked) {}
	virtual void power() {}
	bool isAlive() {
		return hp > 0;
	}
	void attacked(int del) {
		hp -= del;
		atked = del;
	}
	friend ostream &operator << (ostream &os, Hero &hero) {
		return os << hero.name << " " << hero.atk << " " << hero.hp << endl;
	}
};

class Warrior : public Hero {
public:
	Warrior() : Hero(1, "Warrior", 12, 2, 0) {}
	void power() {
		if (isAlive()) {
			hp++;
		}
	}
};

class Magician : public Hero {
public:
	bool usedPower;
	Magician() : Hero(2, "Magician", 2, 6, 0) {
		usedPower = false;
	}
	void power() {
		if (!usedPower) {
			hp += atked;
			usedPower = true;
		}
	}
};

class Leader : public Hero {
public:
	Leader() : Hero(3, "Leader", 6, 6, 0) {}
	void power() {
		if (isAlive()) {
			atk++;
		}
	}
};

class HeroPool {
public:
	Hero* CreateHero(const int &id) {
		Hero* ret;
		switch(id) {
		case 1:
			ret = new Warrior();
			break;
		case 2:
			ret = new Magician();
			break;
		case 3:
			ret = new Leader();
			break;
		default:
			ret = NULL;
			break;
		}
		return ret;
	}
};

int main(int argc, char* argv[]) {
	int n;
	cin >> n;
	HeroPool heroPool;
	vector<Hero*> h1;
	for (int i = 0; i < n; i++) {
		int id;
		cin >> id;
		h1.emplace_back(heroPool.CreateHero(id));
	}
	vector<Hero*> h2;
	for (int i = 0; i < n; i++) {
		int id;
		cin >> id;
		h2.emplace_back(heroPool.CreateHero(id));
	}
	int i = 0;
	int j = 0;
	while (i < n && j < n) {
		h1[i]->attacked(h2[j]->atk);
		h2[j]->attacked(h1[i]->atk);
		if (h1[i]->id == 2) {
			h1[i]->power();
		}
		if (h2[j]->id == 2) {
			h2[j]->power();
		}
		if (h1[i]->isAlive()) {
			h1[i]->power();
		}
		else {
			i++;
		}
		if (h2[j]->isAlive()) {
			h2[j]->power();
		}
		else {
			j++;
		}
	}
	if (i == n && j == n) {
		cout << "All Dead" << endl;
		return 0;
	}
	else {
		for (int k = i; k < n; k++) {
			cout << *h1[k];
		}
		for (int k = j; k < n; k++) {
			cout << *h2[k];
		}
	}
	return 0;
}