#include <iostream>
#include <string>
using namespace std;

class DZ {
public:
    string msg() { return "Division by zero"; }
};

class ND {
public:
    string msg() { return "Negative denominator"; }
};

int main() {
    int n, d;
    cout << "Num: "; cin >> n;
    cout << "Den: "; cin >> d;
    
    try {
        if (d == 0) throw DZ();
        if (d < 0) throw ND();
        if (n == 999) throw 404;
        
        cout << "Result: " << (double)n / d << endl;
    }
    catch (DZ e) { cout << e.msg() << endl; }
    catch (ND e) { cout << e.msg() << endl; }
    catch (...) { cout << "Unexpected error" << endl; }
    
    return 0;
}
