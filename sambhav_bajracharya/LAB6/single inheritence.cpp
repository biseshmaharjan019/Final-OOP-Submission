#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;
    int age;

public:
    Person(string n, int a) {
        name = n;
        age = a;
    }

    string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    void display() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Student : public Person {
private:
    int rollNo;
    float gpa;

public:
    Student(string n, int a, int r, float g) : Person(n, a) {
        rollNo = r;
        gpa = g;
    }

    void display() const {
        Person::display();
        cout << "Roll No: " << rollNo << endl;
        cout << "GPA: " << gpa << endl;
    }
};

int main() {
    Person p("John Doe", 45);
    Student s("Alice Smith", 20, 101, 3.85f);

    cout << "Person Details" << endl;
    p.display();

    cout << "\nStudent Details" << endl;
    s.display();

    return 0;
}
