#include <iostream>
using namespace std;

class Time
{
private:
    int day;
    int hour;
    int minute;
    int second;

public:
    Time(int d, int h, int m, int s)
    {
        day = d;
        hour = h;
        minute = m;
        second = s;
    }

    void addTime(Time t1, Time t2)
    {
        second = t1.second + t2.second;
        minute = t1.minute + t2.minute + (second / 60);
        second = second % 60;

        hour = t1.hour + t2.hour + (minute / 60);
        minute = minute % 60;

        day = t1.day + t2.day + (hour / 24);
        hour = hour % 24;
    }

    void display()
    {
        cout << "Days: " << day << ", Hours: " << hour
             << ", Minutes: " << minute << ", Seconds: " << second << endl;
    }
};

int main()
{
    Time T1(1, 14, 45, 50);
    Time T2(2, 11, 20, 30);
    Time T3(0, 0, 0, 0);

    T3.addTime(T1, T2);

    cout << "Time 1: ";
    T1.display();
    cout << "Time 2: ";
    T2.display();
    cout << "Result (Time 3): ";
    T3.display();

    return 0;
}