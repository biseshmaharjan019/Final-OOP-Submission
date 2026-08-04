/*=====================================================================
   STUDENT-TEACHER ATTENDANCE MANAGEMENT SYSTEM
   C++ Semester End Project

   Concepts used (mapped to comments in code):
     [OOP]        Classes & Objects
     [INHERIT]    Inheritance
     [VIRTUAL]    Virtual Functions / Runtime Polymorphism / Abstract class
     [OPERATOR]   Operator Overloading
     [STREAM]     Stream Computation (fstream, cin/cout, custom << >>)
     [TEMPLATE]   Templates (class template + function template)
     [EXCEPTION]  Exception Handling (custom exception hierarchy)
=====================================================================*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <exception>
#include <iomanip>
#include <limits>
using namespace std;

const string STUDENT_FILE = "students.txt";
const string TEACHER_FILE = "teachers.txt";
const double PASS_PERCENT = 70.0;

/* ------------------------------------------------------------------
   [EXCEPTION] Custom exception hierarchy (inheritance used here too,
   all derive from std::exception)
------------------------------------------------------------------ */
class AppException : public exception {
protected:
    string msg;
public:
    AppException(string m){ msg=m; }
    const char* what() const noexcept override { return msg.c_str(); }
};

class LoginFailedException : public AppException {
public:
    LoginFailedException() : AppException("Invalid ID or Password!") {}
};

class FileOpenException : public AppException {
public:
    FileOpenException(string filename) : AppException("Could not open file: " + filename) {}
};

class InvalidChoiceException : public AppException {
public:
    InvalidChoiceException() : AppException("Invalid menu choice, please try again.") {}
};

class NoRecordException : public AppException {
public:
    NoRecordException() : AppException("No matching record found!") {}
};

/* ------------------------------------------------------------------
   [OOP][INHERIT][VIRTUAL] Abstract base class Person.
   showDashboard() is pure virtual -> Person is an abstract class,
   Student and Teacher MUST provide their own implementation.
   This is classic runtime polymorphism: main() calls dashboard()
   through a Person* without knowing the concrete type.
------------------------------------------------------------------ */
class Person {
protected:
    string id;
    string name;
    string password;
public:
    Person() {}
    Person(string i, string n, string p) : id(i), name(n), password(p) {}

    string getId()   const { return id; }
    string getName() const { return name; }
    string getPassword() const { return password; }

    virtual void displayInfo() const {           // [VIRTUAL]
        cout << "ID: " << id << " | Name: " << name;
    }

    virtual void showDashboard() = 0;             // pure virtual -> abstract class

    // [OPERATOR] compare two people by their ID
    bool operator==(const Person &other) const {
        return this->id == other.id;
    }

    virtual ~Person() {}
};

/* ------------------------------------------------------------------
   [OOP][INHERIT] Student : public Person
------------------------------------------------------------------ */
class Student : public Person {
private:
    string className;
    int totalClasses;
    int presentClasses;
public:
    Student() : totalClasses(0), presentClasses(0) {}
    Student(string i, string n, string p, string cls, int total = 0, int present = 0)
        : Person(i, n, p), className(cls), totalClasses(total), presentClasses(present) {}

    string getClassName() const { return className; }
    int getTotal()   const { return totalClasses; }
    int getPresent() const { return presentClasses; }

    void markAttendance(bool present) {
        totalClasses++;
        if (present) presentClasses++;
    }

    double attendanceRate() const {
        if (totalClasses == 0) return 0.0;
        return (double(presentClasses) / totalClasses) * 100.0;
    }

    void displayInfo() const override {           // [VIRTUAL] override
        Person::displayInfo();
        cout << " | Class: " << className
             << " | Present: " << presentClasses << "/" << totalClasses
             << " | Attendance: " << fixed << setprecision(2) << attendanceRate() << "%";
    }

    void showDashboard() override;                 // defined after main() helpers below

    // [OPERATOR] Student += true  -> marks a present entry (overloaded compound assignment)
    Student& operator+=(bool present) {
        markAttendance(present);
        return *this;
    }

    // [OPERATOR][STREAM] friend overloaded stream operators for file I/O
    friend ostream& operator<<(ostream &out, const Student &s);
    friend istream& operator>>(istream &in, Student &s);
};

// [STREAM] writing a Student to any ostream (screen OR file - same code!)
ostream& operator<<(ostream &out, const Student &s) {
    out << s.id << ";" << s.name << ";" << s.password << ";" << s.className
        << ";" << s.totalClasses << ";" << s.presentClasses;
    return out;
}

// [STREAM] reading a Student from any istream (keyboard OR file)
istream& operator>>(istream &in, Student &s) {
    string line;
    if (!getline(in, line) || line.empty()) { in.setstate(ios::failbit); return in; }
    stringstream ss(line);
    string tok;
    getline(ss, s.id, ';');
    getline(ss, s.name, ';');
    getline(ss, s.password, ';');
    getline(ss, s.className, ';');
    getline(ss, tok, ';'); s.totalClasses   = tok.empty() ? 0 : stoi(tok);
    getline(ss, tok, ';'); s.presentClasses = tok.empty() ? 0 : stoi(tok);
    return in;
}

/* ------------------------------------------------------------------
   [OOP][INHERIT] Teacher : public Person
------------------------------------------------------------------ */
class Teacher : public Person {
private:
    vector<string> classesTaught;
public:
    Teacher() {}
    Teacher(string i, string n, string p, vector<string> classes)
        : Person(i, n, p), classesTaught(classes) {}

    vector<string> getClasses() const { return classesTaught; }

    void displayInfo() const override {
        Person::displayInfo();
        cout << " | Teaches: ";
        for (auto &c : classesTaught) cout << c << " ";
    }

    void showDashboard() override;

    friend ostream& operator<<(ostream &out, const Teacher &t);
    friend istream& operator>>(istream &in, Teacher &t);
};

ostream& operator<<(ostream &out, const Teacher &t) {
    out << t.id << ";" << t.name << ";" << t.password << ";";
    for (size_t i = 0; i < t.classesTaught.size(); i++) {
        out << t.classesTaught[i];
        if (i != t.classesTaught.size() - 1) out << ",";
    }
    return out;
}

istream& operator>>(istream &in, Teacher &t) {
    string line;
    if (!getline(in, line) || line.empty()) { in.setstate(ios::failbit); return in; }
    stringstream ss(line);
    string tok;
    getline(ss, t.id, ';');
    getline(ss, t.name, ';');
    getline(ss, t.password, ';');
    string clsField;
    getline(ss, clsField, ';');
    t.classesTaught.clear();
    stringstream cs(clsField);
    string cls;
    while (getline(cs, cls, ',')) t.classesTaught.push_back(cls);
    return in;
}

/* ------------------------------------------------------------------
   [TEMPLATE] Class template Repository<T>
   Generic file-backed storage that works for Student OR Teacher
   (or any type that implements operator<< / operator>> and getId()).
   This single template class removes the need to duplicate
   load/save/find/update logic for every entity type.
------------------------------------------------------------------ */
template <class T>
class Repository {
private:
    string filename;
public:
    Repository(string fname) : filename(fname) {}

    vector<T> loadAll() {
        vector<T> records;
        ifstream fin(filename);
        if (!fin) throw FileOpenException(filename);   // [EXCEPTION]
        T temp;
        while (fin >> temp) records.push_back(temp);    // [STREAM] uses overloaded >>
        fin.close();
        return records;
    }

    void saveAll(const vector<T> &records) {
        ofstream fout(filename);
        if (!fout) throw FileOpenException(filename);   // [EXCEPTION]
        for (auto &r : records) fout << r << "\n";       // [STREAM] uses overloaded <<
        fout.close();
    }

    T findById(const string &id) {
        vector<T> records = loadAll();
        for (auto &r : records)
            if (r.getId() == id) return r;
        throw NoRecordException();                       // [EXCEPTION]
    }

    void updateOne(const T &updated) {
        vector<T> records = loadAll();
        bool found = false;
        for (auto &r : records) {
            if (r.getId() == updated.getId()) { r = updated; found = true; break; }
        }
        if (!found) throw NoRecordException();
        saveAll(records);
    }
};

/* ------------------------------------------------------------------
   [TEMPLATE] Function template: works for any numeric attendance
   list to find the class topper in attendance percentage.
------------------------------------------------------------------ */
template <typename T>
T findMaximum(const vector<T> &values) {
    if (values.empty()) throw AppException("Empty list, cannot find maximum.");
    T best = values[0];
    for (const T &v : values)
        if (v > best) best = v;
    return best;
}

/* ------------------------------------------------------------------
   Small input helper - keeps cin robust against bad input
   (used together with exception handling in menus)
------------------------------------------------------------------ */
int readMenuChoice() {
    int choice;
    if (!(cin >> choice)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw InvalidChoiceException();               // [EXCEPTION]
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return choice;
}

/* ------------------------------------------------------------------
   TEACHER DASHBOARD  [VIRTUAL override]
------------------------------------------------------------------ */
void Teacher::showDashboard() {
    cout << "\n===== Welcome, Teacher " << name << " =====\n";
    while (true) {
        cout << "\nClasses you teach:\n";
        for (size_t i = 0; i < classesTaught.size(); i++)
            cout << "  " << (i + 1) << ". " << classesTaught[i] << "\n";
        cout << "  0. Logout\n";
        cout << "Select a class to update attendance: ";

        int choice;
        try {
            choice = readMenuChoice();
            if (choice == 0) { cout << "Logging out...\n"; return; }
            if (choice < 1 || choice > (int)classesTaught.size())
                throw InvalidChoiceException();
        } catch (AppException &e) {
            cout << "[Error] " << e.what() << "\n";
            continue;
        }

        string selectedClass = classesTaught[choice - 1];

        try {
            Repository<Student> repo(STUDENT_FILE);
            vector<Student> allStudents = repo.loadAll();

            cout << "\n--- Marking attendance for class: " << selectedClass << " ---\n";
            bool anyStudent = false;
            for (auto &s : allStudents) {
                if (s.getClassName() != selectedClass) continue;
                anyStudent = true;
                char ans;
                cout << "Is " << s.getName() << " (" << s.getId() << ") present today? (y/n): ";
                cin >> ans;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                bool present = (ans == 'y' || ans == 'Y');
                s += present;                       // [OPERATOR] operator+= usage
            }

            if (!anyStudent) {
                cout << "No students found for class " << selectedClass << ".\n";
            } else {
                repo.saveAll(allStudents);           // [STREAM] writes through file
                cout << "Attendance updated and saved successfully!\n";

                // [TEMPLATE] show topper of this class using findMaximum()
                vector<double> rates;
                string topperName;
                double best = -1;
                for (auto &s : allStudents) {
                    if (s.getClassName() != selectedClass) continue;
                    rates.push_back(s.attendanceRate());
                    if (s.attendanceRate() > best) { best = s.attendanceRate(); topperName = s.getName(); }
                }
                double topRate = findMaximum(rates);
                cout << "Highest attendance in " << selectedClass << ": "
                     << topperName << " (" << fixed << setprecision(2) << topRate << "%)\n";
            }
        } catch (AppException &e) {
            cout << "[Error] " << e.what() << "\n";
        }
    }
}

/* ------------------------------------------------------------------
   STUDENT DASHBOARD  [VIRTUAL override]
------------------------------------------------------------------ */
void Student::showDashboard() {
    cout << "\n===== Welcome, " << name << " =====\n";
    cout << "----------------------------------------\n";
    displayInfo();
    cout << "\n----------------------------------------\n";

    if (attendanceRate() < PASS_PERCENT) {
        cout << "\n*** WARNING: Your attendance is below " << PASS_PERCENT
             << "%. You may not be eligible to sit in the exam! ***\n";
    } else {
        cout << "\nYour attendance is satisfactory. Keep it up!\n";
    }
    cout << "\nPress Enter to logout...";
    cin.get();
}

/* ------------------------------------------------------------------
   LOGIN FUNCTIONS  [EXCEPTION] + [TEMPLATE Repository]
------------------------------------------------------------------ */
Student loginStudent() {
    string id, pass;
    cout << "Enter Student ID: "; cin >> id;
    cout << "Enter Password: ";   cin >> pass;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Repository<Student> repo(STUDENT_FILE);
    Student s;
    try {
        s = repo.findById(id);
    } catch (NoRecordException&) {
        throw LoginFailedException();
    }
    if (s.getPassword() != pass) throw LoginFailedException();
    return s;
}

Teacher loginTeacher() {
    string id, pass;
    cout << "Enter Teacher ID: "; cin >> id;
    cout << "Enter Password: ";   cin >> pass;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Repository<Teacher> repo(TEACHER_FILE);
    Teacher t;
    try {
        t = repo.findById(id);
    } catch (NoRecordException&) {
        throw LoginFailedException();
    }
    if (t.getPassword() != pass) throw LoginFailedException();
    return t;
}

/* ------------------------------------------------------------------
   Seed sample data files if they don't exist yet, so the program
   is runnable immediately (demonstrates [STREAM] file writing).
------------------------------------------------------------------ */
void seedDataIfMissing() {
    ifstream testS(STUDENT_FILE);
    if (!testS) {
        ofstream out(STUDENT_FILE);
        out << Student("S101", "Anshu Shiwakoti",  "pass", "BEI", 20, 19) << "\n";
        out << Student("S102", "Dilasha Ghimire",   "pass", "BEI", 20, 18) << "\n";
        out << Student("S103", "Niharika Sharma",   "pass", "BCT", 20, 9)  << "\n";
        out << Student("S104", "Pari Pokhrel",   "pass", "BCT", 20, 20) << "\n";
        out.close();
    }
    testS.close();

    ifstream testT(TEACHER_FILE);
    if (!testT) {
        ofstream out(TEACHER_FILE);
        out << Teacher("T201", "Mr. Sushant Pandey", "teach", {"BEI", "BCT"}) << "\n";
        out << Teacher("T202", "Ms. Haseena Sakhya",      "teach", {"BEI"})          << "\n";
        out.close();
    }
    testT.close();
}

/* ------------------------------------------------------------------
   MAIN  -  role selection, login, then polymorphic dashboard call
------------------------------------------------------------------ */
int main() {
    seedDataIfMissing();

    cout << "==================================================\n";
    cout << "   STUDENT - TEACHER ATTENDANCE MANAGEMENT SYSTEM\n";
    cout << "==================================================\n";

    while (true) {
        cout << "\n1. Login as Teacher\n2. Login as Student\n0. Exit\nChoice: ";
        int roleChoice;
        try {
            roleChoice = readMenuChoice();
        } catch (AppException &e) {
            cout << "[Error] " << e.what() << "\n";
            continue;
        }

        if (roleChoice == 0) {
            cout << "Goodbye!\n";
            break;
        }

        try {
            if (roleChoice == 1) {
                Teacher t = loginTeacher();
                Person *p = &t;          // [VIRTUAL] polymorphism: base pointer, derived behaviour
                p->showDashboard();
            } else if (roleChoice == 2) {
                Student s = loginStudent();
                Person *p = &s;          // [VIRTUAL] polymorphism
                p->showDashboard();
            } else {
                throw InvalidChoiceException();
            }
        } catch (LoginFailedException &e) {
            cout << "[Login Failed] " << e.what() << "\n";
        } catch (AppException &e) {
            cout << "[Error] " << e.what() << "\n";
        } catch (exception &e) {
            cout << "[Unexpected Error] " << e.what() << "\n";
        }
    }
    return 0;
}