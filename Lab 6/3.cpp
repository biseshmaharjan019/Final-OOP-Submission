#include <iostream>
#include <string>
using namespace std;

class Teacher {
private:
    int teacherID;
    string subject;

public:
    Teacher(int id, string sub) : teacherID(id), subject(sub) {}

    void display() const {
        cout << "Teacher ID: " << teacherID << ", Subject: " << subject << endl;
    }
};

class Researcher {
private:
    string researchArea;
    int publications;

public:
    Researcher(string area, int pub) : researchArea(area), publications(pub) {}

    void display() const {
        cout << "Research Area: " << researchArea << ", Publications: " << publications << endl;
    }
};

// Constructor execution order in multiple inheritance depends on the order 
// of base classes listed in the class declaration header (Teacher first, then Researcher), 
// regardless of their order in the constructor initializer list.
class Professor : public Teacher, public Researcher {
private:
    string university;

public:
    Professor(int id, string sub, string area, int pub, string uni)
        : Teacher(id, sub), Researcher(area, pub), university(uni) {}

    void display() const {
        Teacher::display();
        Researcher::display();
        cout << "University: " << university << endl;
    }
};

int main() {
    Professor prof(501, "Object Oriented Programming", "Artificial Intelligence", 12, "Tribhuvan University");

    cout << "--- Professor Details ---" << endl;
    prof.display();

    return 0;
}