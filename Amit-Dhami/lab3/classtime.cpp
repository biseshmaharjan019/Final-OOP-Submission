#include <iostream>
using namespace std;
class Time
{
int day, hour, minute, second;
public:
    Time(int d, int h, int m, int s)
    {
        day = d;
        hour = h;
        minute = m;
        second = s;
    }
Time()
    {
        day = hour = minute = second = 0;
    }
void addTime(Time t1, Time t2)
    {
        second = t1.second + t2.second;
        minute = t1.minute + t2.minute + second / 60;
        second %= 60;
hour = t1.hour + t2.hour + minute / 60;
        minute %= 60;
day = t1.day + t2.day + hour / 24;
        hour %= 24;
    }
void display()
    {
        cout << day << " Day "
             << hour << " Hour "
             << minute << " Minute "
             << second << " Second\n";
    }
};
int main()
{
    Time t1(2, 10, 45, 50);
    Time t2(1, 15, 30, 20);
    Time t3;
t3.addTime(t1, t2);
t1.display();
    t2.display();
    t3.display();

    return 0;
}
