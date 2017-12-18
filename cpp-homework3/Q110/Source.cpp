#include <iostream>

using namespace std;

class Point {
private:
	int x;
	int y;
	int z;
public:
	Point() : x(0), y(0), z(0) {}
	Point(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}
	Point &operator +(const Point &rhs) {
		return Point(x + rhs.x, y + rhs.y, z + rhs.z);
	}
	friend Point &operator ++(Point &point) {
		point.x++;
		point.y++;
		point.z++;
		return point;
	}
	friend istream &operator >> (istream &is, Point &point) {
		return is >> point.x >> point.y >> point.z;
	}
	friend ostream &operator << (ostream &is, Point &point) {
		return is << "x:" << point.x << ",y:" << point.y << ",z:" << point.z << endl;
	}
};

int main(int argc, char *argv[]) {
	Point point1, point2;
	cin >> point1 >> point2;
	point1++;
	cout << point1;
	point1 = point1 + point2;
	cout << point1;
	return 0;
}