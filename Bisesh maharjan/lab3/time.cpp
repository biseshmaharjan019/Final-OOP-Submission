#include<iostream>
using namespace std;

class Time {
    int day, hour, minute, second;

    public:
        Time(int d=0, int h=0, int m=0, int s=0) {
            day    = d;
            hour   = h;
            minute = m;
            second = s;
        }
        Time addTime(Time t1, Time t2) {
            Time t3;
            t3.second = t1.second + t2.second;
            t3.minute = t1.minute + t2.minute;
            t3.hour   = t1.hour   + t2.hour;
            t3.day    = t1.day    + t2.day;
            if(t3.second >= 60) {
                t3.second = t3.second - 60;
                t3.minute = t3.minute + 1;
            }
            if(t3.minute >= 60) {
                t3.minute = t3.minute - 60;
                t3.hour   = t3.hour + 1;
            }
            if(t3.hour >= 24) {
                t3.hour = t3.hour - 24;
                t3.day  = t3.day + 1;
            }
            return t3;
        }
        void display() {
            cout << day << " day  " << hour << " hour  " << minute << " min  " << second << " sec" << endl;
        }
};

int main() {
    Time t1(1, 10, 45, 50);
    Time t2(2, 15, 20, 30);
    Time t3;
    t3 = t3.addTime(t1, t2);
    cout << "Time 1 : ";
    t1.display();
    cout << "Time 2 : ";
    t2.display();
    cout << "Sum    : ";
    t3.display();
    return 0;
}
