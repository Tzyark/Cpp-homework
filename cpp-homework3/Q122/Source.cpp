#include <iostream>

using namespace std;

class Date {
public:
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
	Date() : year(0), month(0), day(0), hour(0), minute(0), second(0) {}
	Date(int _year, int _month, int _day, int _hour, int _minute, int _second) : year(_year), month(_month), day(_day), hour(_hour), minute(_minute), second(_second) {}
	friend istream &operator >> (istream &is, Date &date) {
		return is >> date.year >> date.month >> date.day >> date.hour >> date.minute >> date.second;
	}
	friend ostream &operator << (ostream &os, Date &date) {
		return os << date.year << " " << date.month << " " << date.day << " " << date.hour << " " << date.minute << " " << date.second << endl;
	}
	bool isLeapYear() {
		return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
	}
	int dayOfMonth() {
		int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		return month == 2 ? (isLeapYear() ? 29 : 28) : days[month];
	}
	Date& operator ++() {
		second++;
		if (second == 60) {
			second = 0;
			minute++;
			if (minute == 60) {
				minute = 0;
				hour++;
				if (hour == 24) {
					hour = 0;
					day++;
					if (day > dayOfMonth()) {
						day = 1;
						month++;
						if (month == 13) {
							month = 1;
							year++;
						}
					}
				}
			}
		}
		return *this;
	}
};

int main(int argc, char *argv[]) {
	Date date;
	cin >> date;
	date++;
	cout << date;
	return 0;
}