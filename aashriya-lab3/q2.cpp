#include <iostream>
using namespace std;
class Time{
    private:
    int hours;
    int minutes;
    int seconds;
    int days;
    public:
 
    Time(int h, int m, int s,int d){
        hours = h;
        minutes = m;
        seconds = s;
        days = d;
        cout<<"Parameterized constructor called."<<endl;
    } 
    void addtime(Time t1, Time t2){
        seconds = t1.seconds + t2.seconds;
        minutes = t1.minutes + t2.minutes;
        hours = t1.hours + t2.hours;
        days = t1.days + t2.days;
        minutes += seconds / 60;
        seconds = seconds % 60;
        hours += minutes / 60;
        minutes = minutes % 60;
        days += hours / 24;
        hours = hours % 24;
    

    }
    void display(){
        cout<<"Time: "<<days<<" days "<<hours<<" hours "<<minutes<<" minutes "<<seconds<<" seconds"<<endl;
    }
};
int main(){
    Time t1(2, 45, 30, 1);
    Time t2(3, 20, 45, 0);
    Time t3(0, 0, 0, 0);
    t3.addtime(t1, t2);
    cout<<"Total time:"<< endl;
    t3.display();
    return 0;
}
   