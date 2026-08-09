#include <iostream>
#include <string>
using namespace std;

class Teacher {
private:
    int teacherID;
    string subject;
public:
    Teacher(int id, string sub) {
        teacherID = id;
        subject = sub;
    }
    void display() {
        cout << "Teacher ID: " << teacherID << ", Subject: " << subject << endl;
    }
};

class Researcher {
private:
    string researchArea;
    int publications;
public:
    Researcher(string area, int pub) {
        researchArea = area;
        publications = pub;
    }
    void display() {
        cout << "Research Area: " << researchArea << ", Publications: " << publications << endl;
    }
};

class Professor : public Teacher, public Researcher {
private:
    string university;
public:
    Professor(int id, string sub, string area, int pub, string uni) 
        : Teacher(id, sub), Researcher(area, pub) {
        university = uni;
    }
    void display() {
        Teacher::display();
        Researcher::display();
        cout << "University: " << university << endl;
    }
};

int main() {
    Professor prof(1234, "Computer Science", "Artificial Intelligence", 15, "State University");
    prof.display();
    return 0;
}