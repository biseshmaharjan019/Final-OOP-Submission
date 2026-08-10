#include <iostream>
using namespace std;
class Time {
public:
    int day, hour, min, sec;
    Time(int d, int h, int m, int s) {
        day = d; hour = h; min = m; sec = s;
    }
       void addTime(Time t1, Time t2) {
        sec = t1.sec + t2.sec;
        min = t1.min + t2.min + sec / 60;
        sec %= 60;
        hour = t1.hour + t2.hour + min / 60;
        min %= 60;
        day = t1.day + t2.day + hour / 24;
        hour %= 24;
    }
 void display() {
        cout << day << "d " << hour << "h " << min << "m " << sec << "s\n";
    }
};
int main() {
    Time t1( 1,10, 50, 40);
    Time t2(0, 15, 30, 30);
    Time t3(0,0,0,0);
    t3.addTime(t1, t2);
    t1.display();
    t2.display();
    t3.display();
}