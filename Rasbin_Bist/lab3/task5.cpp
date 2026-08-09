#include <iostream>
using namespace std;
 
class StudentClass {
private:
    int* studentIDs;   
    int size;          
 
public:
    
    StudentClass(int n) {
        size = n;
        studentIDs = new int[size];  
        cout << "Enter " << size << " student IDs:\n";
        for (int i = 0; i < size; i++) {
            cout << "  Student " << (i + 1) << " ID: ";
            cin >> studentIDs[i];
        }
        cout << "Memory allocated for " << size << " student IDs.\n";
    }
 
   
    void display() {
        cout << "\nStored Student IDs\n";
        for (int i = 0; i < size; i++) {
            cout << "  Student " << (i + 1) << " : " << studentIDs[i] << "\n";
        }
        
    }
 

    ~StudentClass() {
        delete[] studentIDs;         
        studentIDs = nullptr;
        cout << "Memory freed\n";
    }
};
 
int main() {
    int n;
    cout << "How many students? ";
    cin >> n;
 
    StudentClass sc(n);   
    sc.display();
 
    cout << "\nEnd of main.\n";
    return 0;  
}