#include<iostream>
using namespace std;
class Time{
private: 
	int day,hour,minute,second;
public:
	Time(int d,int hr,int min,int sec){
		day=d;
		hour=hr;
		minute=min;
		second=sec;
	}
	void addTime(Time t1,Time t2){
		second = t1.second+t2.second;
		minute = t1.minute+t2.minute;
		hour = t1.hour+t2.hour;
		day = t1.day+t2.day;
		if(second>=60){
			minute += second/60;
			second %= 60;
		}
		if(minute>=60){
			hour += minute/60;
			minute %= 60;
		}
		if(hour>=24){
			day += hour/24;
			hour %= 60;
		}
	}
	void display(){
		cout <<day <<"d " <<hour <<"hr " <<minute <<"min " <<second <<"sec " <<endl;
	}
};
int main()
{
	Time t1(1,15,20,50);
	Time t2(2,10,45,30);
	Time result(0,0,0,0);
	result.addTime(t1,t2);
	cout << "Time 1: ";
	t1.display();
	cout << "Time 2: ";
	t2.display();
	cout << "Sum: ";
	result.display();
	return 0;
}
