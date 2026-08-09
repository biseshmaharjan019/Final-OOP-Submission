#include <iostream>
#include <typeinfo>
using namespace std;
class Vehicle
{
public:
    virtual string getType()
    {
        return "Vehicle";
    }
    virtual ~Vehicle()
    {
        cout<<"Vehicle Destructor"<<endl;
    }
};
class Car : public Vehicle
{
    int numDoors;
public:
    Car(int d=4):numDoors(d){}

    int getDoors()
    {
        return numDoors;
    }
    string getType() override
    {
        return "Car";
    }
    ~Car()
    {
        cout<<"Car Destructor"<<endl;
    }
};
class Truck : public Vehicle
{
    float payloadTons;
public:
    Truck(float p=5.5f):payloadTons(p){}
    float getPayload()
    {
        return payloadTons;
    }
    string getType() override
    {
        return "Truck";
    }
    ~Truck()
    {
        cout<<"Truck Destructor"<<endl;
    }
};
int main()
{
    Vehicle* vehicles[3];
    vehicles[0]=new Vehicle();
    vehicles[1]=new Car(4);
    vehicles[2]=new Truck(10.5f);
    for(int i=0;i<3;i++)
    {
        cout<<typeid(*vehicles[i]).name()<<endl;
        Car* carPtr=dynamic_cast<Car*>(vehicles[i]);
        if(carPtr)
            cout<<"Doors: "<<carPtr->getDoors()<<endl;
        Truck* truckPtr=dynamic_cast<Truck*>(vehicles[i]);
        if(truckPtr)
            cout<<"Payload: "<<truckPtr->getPayload()<<endl;
        delete vehicles[i];
    }

    return 0;
}
