#include <iostream>
using namespace std;

class Time {
    int day, hour, minute, second;

public:
    Time(int d = 0, int h = 0, int m = 0, int s = 0) {
        day = d;
        hour = h;
        minute = m;
        second = s;
    }

    void addTime(Time t1, Time t2) {
        second = t1.second + t2.second;
        minute = t1.minute + t2.minute + (second / 60);
        second %= 60;

        hour = t1.hour + t2.hour + (minute / 60);
        minute %= 60;

        day = t1.day + t2.day + (hour / 24);
        hour %= 24;
    }

    void display() const {
        cout << day << " days, " << hour << " hours, " 
             << minute << " mins, " << second << " secs" << endl;
    }
};

int main() {
    Time T1(1, 15, 45, 50);
    Time T2(0, 10, 20, 30);
    Time T3;

    T3.addTime(T1, T2);

    cout << "Time 1: "; T1.display();
    cout << "Time 2: "; T2.display();
    cout << "Sum (Time 3): "; T3.display();

    return 0;
}
