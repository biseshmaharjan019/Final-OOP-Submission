#include <iostream>
#include <string>

class Department {
private:
    int deptID;
    std::string deptName;

public:
    Department(int id, std::string name) : deptID(id), deptName(name) {
        std::cout << "Constructor: [" << deptName << "] created" << std::endl;
    }

    ~Department() {
        std::cout << "Destructor: [" << deptName << "] going out of scope" << std::endl;
    }
};

int main() {
    std::cout << "--- Global Main Block Starts ---" << std::endl;
    Department d1(1, "Computer Science");

    {
        std::cout << "\n  --> Entering Sub-Block A" << std::endl;
        Department d2(2, "Electrical Engineering");
        std::cout << "  --> Leaving Sub-Block A" << std::endl;
    } // d2 goes out of scope here

    {
        std::cout << "\n  --> Entering Sub-Block B" << std::endl;
        Department d3(3, "Mechanical Engineering");
        std::cout << "  --> Leaving Sub-Block B" << std::endl;
    } // d3 goes out of scope here

    std::cout << "\n--- Global Main Block Ends ---" << std::endl;
    return 0;
} // d1 goes out of scope here