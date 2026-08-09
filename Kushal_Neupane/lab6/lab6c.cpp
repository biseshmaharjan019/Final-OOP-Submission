#include <iostream>
#include <string>

class Teacher {
private:
    int teacherID;
    std::string subject;

public:
    Teacher(int id, std::string sub) : teacherID(id), subject(sub) {}

    void display() const {
        std::cout << "Teacher ID: " << teacherID 
                  << "\nSubject: " << subject << std::endl;
    }
};

class Researcher {
private:
    std::string researchArea;
    int publications;

public:
    Researcher(std::string area, int pubs) 
        : researchArea(area), publications(pubs) {}

    void display() const {
        std::cout << "Research Area: " << researchArea 
                  << "\nPublications: " << publications << std::endl;
    }
};

class Professor : public Teacher, public Researcher {
private:
    std::string university;

public:
    /*
      Constructor Execution Order:
      In C++ multiple inheritance, parent constructors execute strictly in the order
      the classes are listed in the class derivation header (left-to-right):
      1. Teacher(id, sub) executes first because Teacher is declared first in the inheritance list.
      2. Researcher(area, pubs) executes second.
      3. Professor's constructor body executes last.
      The order specified in the member initializer list does not affect execution order.
    */
    Professor(int id, std::string sub, std::string area, int pubs, std::string uni)
        : Teacher(id, sub), Researcher(area, pubs), university(uni) {}

    void display() const {
        Teacher::display();
        Researcher::display();
        std::cout << "University: " << university << std::endl;
    }
};

int main() {
    std::cout << "--- Professor Object ---" << std::endl;
    Professor prof(5001, "Computer Science", "Artificial Intelligence", 24, "MIT");
    prof.display();

    return 0;
}