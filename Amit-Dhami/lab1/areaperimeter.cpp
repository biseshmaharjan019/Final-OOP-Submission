#include <iostream>
using namespace std;
float area(float length,float width) {
    return length*width;
}
float perimeter(float length,float width) {
    return 2*(length+width);
}
int main() {
    float length, width;
cout << "Enter length and width: ";
    cin >>length>>width;
cout << "Area = "<< area(length,width)<< endl;
    cout << "Perimeter = "<< perimeter(length,width)<< endl;
return 0;
}
