#include<iostream>
using namespace std;
class Fahrenheit;
class Celsius{
private:
	float temp;
public:
	Celsius(float t=0){
		temp=t;
	}
	void display(){
		cout << temp << " C";
	}
	operator Fahrenheit();
};
class Fahrenheit{
private:
	float temp;
public:
	Fahrenheit(float t=0){
		temp=t;
	}
	void display(){
		cout << temp << " F";
	}
	operator Celsius();
};
Celsius::operator Fahrenheit(){
	return Fahrenheit((temp*9.0/5.0)+32);
}
Fahrenheit::operator Celsius(){
	return Celsius((temp-32)*5.0/9.0);
}
int main()
{
	Celsius c(25);
	Fahrenheit f;
	f=c;
	cout << "Celsius Temperature: ";
	c.display();
	cout << "\nEquivalent Fahrenheit Temperature: ";
	f.display();
	Fahrenheit f2(98.6);
	Celsius c2;
	c2=f2;
	cout << "\n\nFahrenheit Temperature: ";
	f2.display();
	cout << "\nEquivalent Celsius Temperature: ";
	c2.display();
	return 0;
}
