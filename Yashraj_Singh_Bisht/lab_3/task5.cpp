#include <iostream>

class StudentClass {
private:
    int *studentIDs;
    int size;

public:
    // Dynamic constructor
    StudentClass(int n) {
        size = n;
        studentIDs = new int[size]; // Heap allocation
        std::cout << "Allocated space for " << size << " student IDs on the heap." << std::endl;
        
        // Read student IDs from user
        for (int i = 0; i < size; ++i) {
            std::cout << "Enter ID for student " << (i + 1) << ": ";
            std::cin >> studentIDs[i];
        }
    }

    // Destructor
    ~StudentClass() {
        delete[] studentIDs; // Free allocated memory array
        std::cout << "Memory freed." << std::endl;
    }

    void display() const {
        std::cout << "Stored Student IDs: ";
        for (int i = 0; i < size; ++i) {
            std::cout << studentIDs[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    int count;
    std::cout << "How many students do you want to register? ";
    std::cin >> count;

    if (count <= 0) {
        std::cout << "Invalid count provided." << std::endl;
        return 1;
    }

    // Instantiate class using dynamic memory allocation inside constructor
    StudentClass batch(count);
    
    std::cout << "\n--- Verifying Data ---" << std::endl;
    batch.display();

    std::cout << "\n--- Exiting Main ---" << std::endl;
    return 0;
}