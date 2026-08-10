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

    void display() const {
        cout << "Teacher ID: " << teacherID << endl;
        cout << "Subject: " << subject << endl;
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

    void display() const {
        cout << "Research Area: " << researchArea << endl;
        cout << "Publications: " << publications << endl;
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

    void display() const {
        Teacher::display();
        Researcher::display();
        cout << "University: " << university << endl;
    }
};

int main() {
    /*
     * CONSTRUCTOR CALL ORDER EXPLANATION:
     * When a Professor object is created, constructors run in the following sequence:
     * 1. Teacher constructor runs first because Teacher is listed first in the inheritance declaration list (public Teacher, public Researcher).
     * 2. Researcher constructor runs second.
     * 3. Professor constructor runs last after all base class parts are initialized.
     */

    Professor prof(5001, "Computer Science", "Artificial Intelligence", 24, "Stanford");
    
    cout << "Professor Details" << endl;
    prof.display();

    return 0;
}
