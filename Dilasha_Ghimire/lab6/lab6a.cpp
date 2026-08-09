#include <iostream>
#include <string>

class Person {
private:
    std::string name;
    int age;

public:
    Person(std::string n, int a) : name(n), age(a) {}

    std::string getName() const { return name; }
    int getAge() const { return age; }

    void display() const {
        std::cout << "Name: " << name << "\nAge: " << age << std::endl;
    }
};

class Student : public Person {
private:
    int rollNo;
    float gpa;

public:
    Student(std::string n, int a, int r, float g) 
        : Person(n, a), rollNo(r), gpa(g) {}

    void display() const {
        std::cout << "Name: " << getName() 
                  << "\nAge: " << getAge() 
                  << "\nRoll No: " << rollNo 
                  << "\nGPA: " << gpa << std::endl;
    }
};

int main() {
    std::cout << "--- Person Object ---" << std::endl;
    Person p("Alice Vance", 45);
    p.display();

    std::cout << "\n--- Student Object ---" << std::endl;
    Student s("Bob Smith", 20, 101, 3.85f);
    s.display();

    return 0;
}