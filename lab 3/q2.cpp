
//2. Write a program with a class Time having data members day, hour, minute, and second. 
//Initialise all data members using a parameterised constructor.
// Write a member function addTime() that takes two Time objects as arguments, adds them with correct carry-over, and stores the result in the calling object.
// Display all three Time objects in main. [8]


#include<iostream>
using namespace std;

class Time {
private:
    int day, hour, minute, second;

public:
    Time(int d, int h, int m, int s) {
        day    = d;
        hour   = h;
        minute = m;
        second = s;
    }

    void addTime(Time t1, Time t2) {
        second = t1.second + t2.second;
        minute = t1.minute + t2.minute + second / 60;
        second = second % 60;

        hour   = t1.hour + t2.hour + minute / 60;
        minute = minute % 60;

        day    = t1.day + t2.day + hour / 24;
        hour   = hour % 24;
    }

    void display() {
        cout << day << " day(s)  "
             << hour << " hr  "
             << minute << " min  "
             << second << " sec\n";
    }
};

int main() {
    Time t1(1, 22, 45, 50);
    Time t2(0, 3, 20, 25);
    Time t3(0, 0, 0, 0);

    t3.addTime(t1, t2);

    cout << "Time 1 : "; t1.display();
    cout << "Time 2 : "; t2.display();
    cout << "Sum    : "; t3.display();

    return 0;
}