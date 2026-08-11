#include <iostream>
using namespace std;

class Time {
    public:
    int day, hour, minute, second;


Time(){

}
    Time(int d, int h, int m, int s) {
        day = d; hour = h; minute = m; second = s;
    }

    void addTime(Time t1, Time t2) {
        second = t1.second + t2.second;
        minute = t1.minute + t2.minute + second / 60;
        second %= 60;

        hour = t1.hour + t2.hour + minute / 60;
        minute %= 60;

        day = t1.day + t2.day + hour / 24;
        hour %= 24;
    }

    void display() {
        cout << day << "d "
             << hour << "h "
             << minute << "m "
             << second << "s\n";
    }
};

int main() {
    Time t1;
    Time t2;
    cout<<"Enter the day, hour, minute and second for the first time to add: ";
    cin>>t1.day>>t1.hour>>t1.minute>>t1.second;
    cout<<"Enter the day, hour, minute and second for the second time to add: ";
    cin>>t2.day>>t2.hour>>t2.minute>>t2.second;
    Time t3(0,0,0,0);

    t3.addTime(t1, t2);

    cout << "Time 1: "; t1.display();
    cout << "Time 2: "; t2.display();
    cout << "Sum: "; t3.display();

    return 0;
}