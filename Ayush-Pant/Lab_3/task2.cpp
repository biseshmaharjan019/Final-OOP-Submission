#include<iostream>
using namespace std;

class Time{
    int day, hour, minute, second;
public:
    Time(int d, int h, int m, int s){
        day = d; hour = h; minute = m; second = s;
    }
    void addTime(Time t1, Time t2){
        second = t1.second + t2.second;
        minute = t1.minute + t2.minute + second/60;
        second %= 60;
        hour = t1.hour + t2.hour + minute/60;
        minute %= 60;
        day = t1.day + t2.day + hour/24;
        hour %= 24;
    }
    void display(){
        cout<<"Day:"<<day<<" Hour:"<<hour<<" Min:"<<minute<<" Sec:"<<second<<endl;
    }
};

int main(){
    Time t1(1, 10, 45, 50);
    Time t2(0, 5, 20, 30);
    Time t3(0, 0, 0, 0);
    t3.addTime(t1, t2);
    t1.display();
    t2.display();
    t3.display();
    return 0;
}
