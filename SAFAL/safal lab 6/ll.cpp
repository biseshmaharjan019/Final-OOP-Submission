#include <iostream>
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
protected:
    int getTeacherID() {
        return teacherID;
    }

    string getSubject() {
        return subject;
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
protected:
    string getResearchArea() {
        return researchArea;
    }
    int getPublications() {
        return publications;
    }
};
class Professor : public Teacher, public Researcher {
private:
    string university;
public:
    Professor(int id, string sub, string area,
              int pub, string uni)
        : Teacher(id, sub), Researcher(area, pub) {
        university = uni;
    }
    void display() {
        cout << "Teacher ID: " << getTeacherID() << endl;
        cout << "Subject: " << getSubject() << endl;
        cout << "Research Area: " << getResearchArea() << endl;
        cout << "Publications: " << getPublications() << endl;
        cout << "University: " << university << endl;
    }
};
int main() {
    Professor p(101, "OOP", "AI", 25, "TU");
    p.display();
    return 0;
}
