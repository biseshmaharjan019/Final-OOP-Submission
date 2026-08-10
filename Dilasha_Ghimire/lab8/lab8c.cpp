#include <iostream>
#include <fstream>
#include <cstring>

class Student {
public:
    int rollNo;
    char name[30];
    float gpa;

    void input() {
        std::cout << "Enter Roll Number: ";
        std::cin >> rollNo;
        std::cout << "Enter Name: ";
        std::cin.ignore();
        std::cin.getline(name, 30);
        std::cout << "Enter GPA: ";
        std::cin >> gpa;
    }

    void display() const {
        std::cout << "Roll No: " << rollNo << " | Name: " << name << " | GPA: " << gpa << std::endl;
    }
};

int main() {
    std::fstream file("students.dat", std::ios::binary | std::ios::out | std::ios::in | std::ios::trunc);
    if (!file) {
        std::cout << "Error opening file!" << std::endl;
        return 1;
    }

    std::cout << "--- Enter Information for 10 Students ---" << std::endl;
    for (int i = 0; i < 10; ++i) {
        std::cout << "\nStudent " << (i + 1) << ":" << std::endl;
        Student s;
        s.input();
        file.write(reinterpret_cast<char*>(&s), sizeof(Student));
    }

    file.seekg(0, std::ios::beg);
    std::cout << "\n--- Student Records ---" << std::endl;
    Student s;
    while (file.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
        s.display();
    }

    int searchRoll;
    std::cout << "\nEnter Roll Number to modify: ";
    std::cin >> searchRoll;

    file.clear();
    file.seekg(0, std::ios::beg);

    bool found = false;
    while (file.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
        if (s.rollNo == searchRoll) {
            found = true;
            std::cout << "Record found! Enter new details:" << std::endl;
            Student newDetails;
            newDetails.input();

            streampos pos = file.tellg() - static_cast<streamoff>(sizeof(Student));
            file.seekp(pos);
            file.write(reinterpret_cast<char*>(&newDetails), sizeof(Student));
            std::cout << "Record updated successfully." << std::endl;
            break;
        }
    }

    if (!found) {
        std::cout << "Student with Roll Number " << searchRoll << " not found." << std::endl;
    }

    file.close();
    return 0;
}