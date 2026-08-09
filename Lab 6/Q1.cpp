#include<iostream>
#include<string>
using namespace std;

class Person{
    private:
    string Name;
    int age;

    public:
    Person(string N, int a){
        Name = N;
        age = a;
    }
        string getName()  {return Name;}
        int getAge()  {return age;}

        void display(){
            cout<<"Name: " << Name <<"Age: " << age << endl;
        }
    
};

class Student : public Person{
    private:
    int rollNo;
    float gpa;

    public:
    Student(int roll, float g, string N, int a) : Person(N, a){
        rollNo = roll;
        gpa = g;
    }

    void display(){
        
        cout<< "Roll number: " << rollNo<<endl << "GPA: " << gpa <<endl;
        cout<< "Name: " << getName()<< endl;
        cout<< "Age: " << getAge()<< endl;

    }

   

};
 int main(){

        

        cout<< "Person Detail:"<<endl;
        Student s(07, 4.0, "Bardan Bhatta", 18);
        s.display();

        return 0;
    }