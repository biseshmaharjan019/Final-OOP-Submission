
#include <iostream>
using namespace std;

class Time {
private:
    int hour, minutes, second;

public:
   
    Time(int h = 0, int m = 0, int s = 0) {
        hour = h;
        minutes = m;
        second = s;
    }

    
    friend Time addTime(Time t1, Time t2);

    void display() {
        cout << hour << " hour(s), "
             << minutes << " minute(s), "
             << second << " second(s)" << endl;
    }
};


Time addTime(Time t1, Time t2) {
    Time result;

    result.second = t1.second + t2.second;

    
    result.minutes = result.second / 60;
    result.second   = result.second % 60;

    
    result.minutes += t1.minutes + t2.minutes;

    
    result.hour   = result.minutes / 60;
    result.minutes = result.minutes % 60;

   
    result.hour += t1.hour + t2.hour;


    int days      = result.hour / 24;
    result.hour   = result.hour % 24;

    cout << "Total days carried over: " << days << endl;

    return result;
}

int main() {
    
    Time t1(10, 45, 50);   
    Time t2(14, 20, 30);   

    cout << "Time 1: ";  t1.display();
    cout << "Time 2: ";  t2.display();

    
    Time result = addTime(t1, t2);

    cout << "Aggregate Result: ";
    result.display();

    return 0;
}