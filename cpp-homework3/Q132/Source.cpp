#include <iostream>
#include <list>

using namespace std;

class Food {
public:
    const double min_car = 13.3;
    const double min_pro = 13.5;
    const double min_DF = 3.3;
    const double max_fat = 10.3;
    double car;
    double pro;
    double DF;
    double fat;
    Food() : car(0.0), pro(0.0), DF(0.0), fat(0.0) {}
    Food(double _car, double _pro, double _DF, double _fat) : car(_car), pro(_pro), DF(_DF), fat(_fat) {}   
};

class FoodFactory {
public:
    Food *getFood(int id) {
        switch (id) {
            case 1: return new Food(16.2, 3.7, 0.0, 0.0);
            case 2: return new Food(1.8, 17.5, 0.0, 7.2);
            case 3: return new Food(0.2, 0.4, 3.6, 0.0);
            case 4: return new Food(12.3, 5.7, 7.3, 3.0);
            case 5: return new Food(6.9, 9.0, 0.0, 9.3);
            case 6: return new Food(2.1, 0.8, 4.3, 0.0);
            default: break;
        }
		Food *ret;
		ret = NULL;
        return ret;        
    }    
};

class Diet {
public:
    list <Food> foods;
	Diet() {
		foods.clear();
	}
    ~Diet();
    Diet &operator += (Food &food) {
        foods.emplace_back(food);
		return *this;
    }
    bool is_healthy() {
        double car_sum = 0.0;
        double pro_sum = 0.0;
        double DF_sum = 0.0;
        double fat_sum = 0.0;
        for (Food food : foods) {
            car_sum += food.car;
            pro_sum += food.pro;
            DF_sum += food.DF;
            fat_sum += food.fat;
        }
		Food *food = new Food;
        return car_sum >= food->min_car
            && pro_sum >= food->min_pro
            && DF_sum >= food->min_DF
            && fat_sum <= food->max_fat;
    }
};

int main(int argc, char *argv[]) {
    Diet *diet = new Diet;
    FoodFactory foodFactory;
    for (int i = 0; i < 3; i++) {
        int id;
        cin >> id;
        if (id > 6) {
            cout << -1 << endl;
            return 0;
        }
		Food *food = new Food;
		food = foodFactory.getFood(id);
		*diet += *food;
    }
	cout << (diet->is_healthy() ? "healthy" : "unhealthy") << endl;
    return 0;
}