//2. Write a program with a class Time having data members day, hour, minute, and second. 
//Initialise all data members using a parameterised constructor. 
//Write a member function addTime() that takes two Time objects as arguments, adds them with correct carry-over, and stores the result in the calling object. 
//Display all three Time objects in main. [8]
#include<iostream>
using namespace std;
class Box {
private:
    float l, b, h;   

public:

    // i) Default Constructor
    Box() {
        l = b = h = 0.0;
        cout << "[Default Constructor] Box created with l=b=h=0\n";
    }

    // ii) Parameterised Constructor
    Box(float length, float breadth, float height) {
        l = length;
        b = breadth;
        h = height;

        cout << "[Parameterised Constructor] Box created: l="
             << l << ", b=" << b << ", h=" << h << "\n";
    }

    // iii) Constructor with Default Arguments
    Box(float length, float breadth = 1.0,
        float height = 1.0, bool useDefault = true) {

        l = length;
        b = breadth;
        h = height;

        cout << "[Default-Arg Constructor] Box created: l="
             << l << ", b=" << b << ", h=" << h << "\n";
    }

    // iv) Copy Constructor
    Box(const Box& source) {
        l = source.l;
        b = source.b;
        h = source.h;

        cout << "[Copy Constructor] Copied box: l="
             << l << ", b=" << b << ", h=" << h << "\n";
    }

    // v) Destructor
    ~Box() {
        cout << "[Destructor] Box (l=" << l
             << ") is being destroyed.\n";
    }

    // Display function
    void display() {
        cout << "Dimensions -> l = " << l
             << "  b = " << b
             << "  h = " << h << "\n";
    }
};

int main() {

    cout << "\n=== Creating Box Objects ===\n\n";

    // Default constructor
    Box b1;
    b1.display();

    // Parameterised constructor
    Box b2(5.0, 3.0, 2.0);
    b2.display();

    // Constructor with default arguments
    Box b3(4.0, 1.0, 1.0, true);
    b3.display();

    // Copy constructor
    Box b4(b2);
    b4.display();

    cout << "\n=== Exiting main ===\n";

    return 0;
}