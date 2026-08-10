#include <iostream>
#include <string>
using namespace std;

template <typename T>
class S {
private:
    T a[5];
    int t;
public:
    S() : t(-1) {}
    
    void push(T v) {
        if (t >= 4) throw "Overflow";
        a[++t] = v;
    }
    
    void pop() {
        if (t == -1) throw "Underflow";
        t--;
    }
    
    void show() {
        if (t == -1) { cout << "Empty\n"; return; }
        for (int i = t; i >= 0; i--) cout << a[i] << " ";
        cout << endl;
    }
};

int main() {
    try {
        S<int> is;
        is.push(10); is.push(20); is.push(30);
        cout << "Int: "; is.show();
        
        S<string> ss;
        ss.push("Apple"); ss.push("Banana"); ss.push("Cherry");
        cout << "String: "; ss.show();
    }
    catch (const char* m) {
        cout << "Error: " << m << endl;
    }
    return 0;
}
