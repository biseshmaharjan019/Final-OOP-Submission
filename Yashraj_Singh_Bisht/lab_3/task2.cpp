#include<iostream>
using namespace std;

class time {
private:
	int day, hour, minute, second;

public:
	time(int d,int h, int m, int s) : day(d), hour(h), minute(m), second(s){}
		void addTime(const time &t1, const time &t2){
			this->second = t1.second +t2.second;
			this->minute = t1.minute +t2.minute;
			this->hour = t1.hour +t2.hour;
			this->day = t1.day +t2.day;
			
			this->minute += this->second/60;
			this->second %= 60;

			this->hour += this->minute/60;
			this->minute %= 60;

			this->day += this->hour/24;
			this-> hour %=24;
		}

		void display() const {
			cout << day << "days," << hour << "hours," << minute << "mins," << second << "secs" << endl;
		}
};

int main(){
	time t1(1,14,45,50);
	time t2(0,11,20,25);
	time t3(0,0,0,0);
		cout << "time 1: ";
		t1.display();
		cout << "time 2: ";
		t2.display();
		t3.addTime(t1,t2);
		cout<< "result (time 3): "; t3.display();

		return 0;

}