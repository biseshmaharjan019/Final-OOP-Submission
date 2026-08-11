#include<iostream>
#include<string.h>
using namespace std;

class Vechile{
    private:
    string vechile;
    int year;

    public:
    Vechile(string V, int Y){
        vechile = V;
        year = Y;
    }

    string getVechile(){ return vechile;}
    int getyear(){return year;}

    void display()
    {
        cout<<"Vechile: " << vechile << "Year: " << year << endl;
    }
};

class Car: public Vechile{
    private:
    int numDoors;

    public:
    Car(int N, string V, int Y):Vechile(V, Y){
        numDoors = N;
    }
    int getnumDoors() { return numDoors; }

    void display(){
        cout<< "Number of Doors: " << numDoors<<endl;
    }

};

class ElectricVechile: public Car{
    private:
    float batteryCapacity;
    int range;

    public:
    ElectricVechile(float C, int R, int N, string V, int Y):Car(N, V, Y){
        batteryCapacity = C;
        range = R;
    }
    
    void display(){
        cout<<"Vechile: "<< getVechile()<<endl;
        cout<<"Year: "<< getyear()<< endl;
        cout<<"Number of Doors: "<< getnumDoors() << endl;
        cout<<"Battery Capacity: "<< batteryCapacity<<"Kw"<< endl;
        cout<<"Range:"<<range<<"km"<<endl;
    }
};

int main(){
    cout<<"Vechile Details: "<< endl;
    ElectricVechile e(1000, 1947, 5, "Toyota", 550);
    e.display();

    return 0;
}
