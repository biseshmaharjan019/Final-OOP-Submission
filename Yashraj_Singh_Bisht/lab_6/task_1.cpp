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
    string getName() { return name; }
    int getAge() { return age; }
    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
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
    void display() {
        cout << "Name: " << getName() << ", Age: " << getAge() 
             << ", Roll No: " << rollNo << ", GPA: " << gpa << endl;
    }
};

int main() {
    Person p("Alice", 40);
    Student s("Bob", 20, 101, 3.8f);

    cout << "--- Person Display ---" << endl;
    p.display();

    cout << "\n--- Student Display ---" << endl;
    s.display();

    return 0;
}
