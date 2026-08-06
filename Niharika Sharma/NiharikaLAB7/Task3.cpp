#include<iostream>
#include<typeinfo>
using namespace std;
class Vehicle{
public:
    virtual ~Vehicle(){
        cout << "Vehicle Destructor" <<endl;
    }
    virtual string getType(){
        return "Vehicle";
    }
};
class Car: public Vehicle{
private:
    int numDoors;
public:
    Car(int d){
        numDoors=d;
    }
    ~Car(){
        cout << "Car Destructor" <<endl;
    }
    string getType(){
        return "Car";
    }
    int getDoors(){
        return numDoors;
    }
};
class Truck: public Vehicle{
private:
    float payloadTons;
public:
    Truck(float p){
        payloadTons=p;
    }
    ~Truck(){
        cout << "Truck Destructor" <<endl;
    }
    string getType(){
        return "Truck";
    }
    float getPayload(){
        return payloadTons;
    }
};
int main()
{
    Vehicle *v[3];
    v[0] = new Vehicle();
    v[1] = new Car(4);
    v[2] = new Truck(12.5);
    for(int i=0;i<3;i++){
        cout << "\nObject " <<i+1 <<endl;
        cout << "Runtime Type: " <<typeid(*v[i]).name() <<endl;
        Car *c=dynamic_cast<Car *>(v[i]);
        if(c!=NULL){
            cout << "Number of Doors: " <<c->getDoors() <<endl;
        }
        Truck *t=dynamic_cast<Truck *>(v[i]);
        if(t!=NULL){
            cout << "Payload: " <<t->getPayload() <<" tons" <<endl;
        }
    }
    cout << "\nDeleting Ojects:\n";
    for(int i=0;i<3;i++){
        delete v[i];
    }
    return 0;
}
