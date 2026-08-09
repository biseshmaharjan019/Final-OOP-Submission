// Q2. Write a program with a class Time having data members day, hour,
// minute, and second. Initialize all data members using a parameterized
// constructor. Write a member function addTime() that adds two Time objects
// with correct carry-over and stores the result. Display all three Time objects.

#include <iostream>
using namespace std;

class Time {
private:
    int day, hour, minute, second;

public:
    Time(int d, int h, int m, int s) {
        day = d;
        hour = h;
        minute = m;
        second = s;
    }

    void addTime(Time t1, Time t2) {
        second = t1.second + t2.second;
        minute = t1.minute + t2.minute + second / 60;
        second = second % 60;

        hour = t1.hour + t2.hour + minute / 60;
        minute = minute % 60;

        day = t1.day + t2.day + hour / 24;
        hour = hour % 24;
    }

    void display() {
        cout << day << " days, " << hour << " hours, "
             << minute << " minutes, " << second << " seconds" << endl;
    }
};

int main() {
    Time t1(1, 20, 50, 45);
    Time t2(2, 5, 25, 30);
    Time t3(0, 0, 0, 0);

    t3.addTime(t1, t2);

    cout << "Time 1: ";
    t1.display();

    cout << "Time 2: ";
    t2.display();

    cout << "Added Time: ";
    t3.display();

    return 0;
}