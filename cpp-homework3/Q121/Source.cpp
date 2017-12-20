#include <iostream>
#include <string>

using namespace std;

class Course {
public:
    int weight;
    double score;
    Course() : weight(0), score(0) {}
    Course(int _weight, double _score) : weight(_weight), score(_score) {}
};

class Student {
public:
    string id;
    string name;
    int age;
    double weight;
    Course *math;
    Course *english;
    Course *cpp;
    Student() : id(""), name(""), age(0), weight(0), math(NULL), english(NULL), cpp(NULL) {}
    Student(string _id, string _name, int _age, double _weight, Course *_math, Course *_english, Course *_cpp) : id(_id), name(_name), age(_age), weight(_weight), math(_math), english(_english), cpp(_cpp) {}
    double getGPA() {
        double ret = 0.0;
        ret += math->score * math->weight + english->score * english->weight + cpp->score * cpp->weight;
        ret /= (math->weight + english->weight + cpp->weight) * 20.0;
        return ret;
    }
    bool operator > (Student &rhs) {
        return getGPA() > rhs.getGPA();
    }
    bool operator < (Student &rhs) {
        return getGPA() < rhs.getGPA();
    }
    bool operator == (Student &rhs) {
        return getGPA() == rhs.getGPA();
    }
};

template<class T>
int compare(T &a, T &b) {
    if (a > b) return 1;
    if (a == b) return 0;
    if (a < b) return -1;
}

int main(int argc, char *argv[]) {
    string id, name;
    int age;
    double weight, math, english, cpp;
    cin >> id >> name >> age >> weight >> math >> english >> cpp;
    Student *student1 = new Student(id, name, age, weight, new Course(4, math), new Course(4, english), new Course(3, cpp));
    cin >> id >> name >> age >> weight >> math >> english >> cpp;
    Student *student2 = new Student(id, name, age, weight, new Course(4, math), new Course(4, english), new Course(3, cpp));
    cout << compare(student1->name, student2->name) << " ";
    cout << compare(student1->age, student2->age) << " ";
    cout << compare(student1->weight, student2->weight) << " ";
    cout << compare(*student1, *student2) << endl;
    return 0;
}