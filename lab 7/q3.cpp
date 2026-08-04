#include<iostream>
#include<typeinfo>
using namespace std;

class Vehicle{
public:
    virtual ~Vehicle()
    {
        cout<<"Vehicle Destructor"<<endl;
    }

    virtual string getType()
    {
        return "Vehicle";
    }
};

class Car:public Vehicle{
    int doors;
public:
    Car(){ doors=4; }

    int getDoors()
    {
        return doors;
    }

    ~Car()
    {
        cout<<"Car Destructor"<<endl;
    }
};

class Truck:public Vehicle{
    float payload;
public:
    Truck(){ payload=10; }

    float getPayload()
    {
        return payload;
    }

    ~Truck()
    {
        cout<<"Truck Destructor"<<endl;
    }
};

int main()
{
    Vehicle *v[3];

    v[0]=new Vehicle;
    v[1]=new Car;
    v[2]=new Truck;

    for(int i=0;i<3;i++)
    {
        cout<<typeid(*v[i]).name()<<endl;

        Car *c=dynamic_cast<Car*>(v[i]);
        if(c)
            cout<<"Doors = "<<c->getDoors()<<endl;

        Truck *t=dynamic_cast<Truck*>(v[i]);
        if(t)
            cout<<"Payload = "<<t->getPayload()<<endl;

        delete v[i];
    }

    return 0;
}

/*
dynamic_cast returns NULL if conversion fails.
Virtual destructor ensures derived destructor is called.
*/