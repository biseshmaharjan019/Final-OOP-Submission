#include <iostream>
using namespace std;
class Device { protected: float powerConsumption; public: Device(float p):powerConsumption(p){} virtual void operate()=0; float getPowerConsumption()const{return powerConsumption;} virtual ~Device(){} };
class Printer: virtual public Device { int pagesPerMinute; public: Printer(float p,int ppm):Device(p),pagesPerMinute(ppm){} void operate()override{cout<<"Printer is printing."<<endl;} };
class Scanner: virtual public Device { int resolution; public: Scanner(float p,int r):Device(p),resolution(r){} void operate()override{cout<<"Scanner is scanning."<<endl;} };
class Photocopier: public Printer,public Scanner { public: Photocopier(float p,int ppm,int r):Device(p),Printer(p,ppm),Scanner(p,r){} void operate()override{cout<<"Photocopier operation:"<<endl;Printer::operate();Scanner::operate();} };
int main(){Photocopier p(500,30,1200);Device* d=&p;d->operate();cout<<"Power consumption: "<<d->getPowerConsumption()<<" W"<<endl;/* Printer and Scanner virtually inherit Device, so Photocopier has one shared Device subobject. */system("pause");return 0;}
