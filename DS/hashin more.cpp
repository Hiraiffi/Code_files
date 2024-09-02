#include <iostream>
#include <vector>

const int TABLE_SIZE = 10;

enum ProbingMethod {
    LINEAR_PROBING,
    QUADRATIC_PROBING
};

// Function prototypes
void displayMenu();
void insertElement(std::vector<int>& hashTable, ProbingMethod probingMethod);
void deleteElement(std::vector<int>& hashTable, ProbingMethod probingMethod);
void searchElement(const std::vector<int>& hashTable, ProbingMethod probingMethod);
int linearProbe(int index, int attempt);
int quadraticProbe(int index, int attempt);

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

int main() {
    std::vector<int> hashTable(TABLE_SIZE, -1); // Initialize all elements to -1

    int choice;
    ProbingMethod probingMethod;

    do {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Choose probing method:\n";
                std::cout << "1. Linear Probing\n";
                std::cout << "2. Quadratic Probing\n";
                int probingChoice;
                std::cin >> probingChoice;
                probingMethod = (probingChoice == 1) ? LINEAR_PROBING : QUADRATIC_PROBING;
                insertElement(hashTable, probingMethod);
                break;
            case 2:
                std::cout << "Choose probing method:\n";
                std::cout << "1. Linear Probing\n";
                std::cout << "2. Quadratic Probing\n";
                std::cin >> probingChoice;
                probingMethod = (probingChoice == 1) ? LINEAR_PROBING : QUADRATIC_PROBING;
                deleteElement(hashTable, probingMethod);
                break;
            case 3:
                std::cout << "Choose probing method:\n";
                std::cout << "1. Linear Probing\n";
                std::cout << "2. Quadratic Probing\n";
                std::cin >> probingChoice;
                probingMethod = (probingChoice == 1) ? LINEAR_PROBING : QUADRATIC_PROBING;
                searchElement(hashTable, probingMethod);
                break;
            case 4:
                std::cout << "Exiting program. Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }

    } while (choice != 4);

    return 0;
}

void displayMenu() {
    std::cout << "\nMenu:\n";
    std::cout << "1. Insert Element\n";
    std::cout << "2. Delete Element\n";
    std::cout << "3. Search Element\n";
    std::cout << "4. Exit\n";
}

void insertElement(std::vector<int>& hashTable, ProbingMethod probingMethod) {
    std::cout << "Enter the value to insert: ";
    int value;
    std::cin >> value;

    int index = hashFunction(value);
    int attempt = 0;

    while (attempt < TABLE_SIZE) {
        int probeIndex = (probingMethod == LINEAR_PROBING) ? linearProbe(index, attempt) : quadraticProbe(index, attempt);

        if (hashTable[probeIndex] == -1) {
            hashTable[probeIndex] = value;
            std::cout << "Element inserted successfully at index " << probeIndex << ".\n";
            return;
        }

        attempt++;
    }

    std::cout << "Table is full. Unable to insert element.\n";
}

void deleteElement(std::vector<int>& hashTable, ProbingMethod probingMethod) {
    std::cout << "Enter the value to delete: ";
    int value;
    std::cin >> value;

    int index = hashFunction(value);
    int attempt = 0;

    while (attempt < TABLE_SIZE) {
        int probeIndex = (probingMethod == LINEAR_PROBING) ? linearProbe(index, attempt) : quadraticProbe(index, attempt);

        if (hashTable[probeIndex] != -1 && hashTable[probeIndex] == value) {
            hashTable[probeIndex] = -1;
            std::cout << "Element deleted successfully.\n";
            return;
        }

        attempt++;
    }

    std::cout << "Element not found.\n";
}

void searchElement(const std::vector<int>& hashTable, ProbingMethod probingMethod) {
    std::cout << "Enter the value to search: ";
    int value;
    std::cin >> value;

    int index = hashFunction(value);
    int attempt = 0;

    while (attempt < TABLE_SIZE) {
        int probeIndex = (probingMethod == LINEAR_PROBING) ? linearProbe(index, attempt) : quadraticProbe(index, attempt);

        if (hashTable[probeIndex] != -1 && hashTable[probeIndex] == value) {
            std::cout << "Element found at index " << probeIndex << ".\n";
            return;
        }

        attempt++;
    }

    std::cout << "Element not found.\n";
}

int linearProbe(int index, int attempt) {
    return (index + attempt) % TABLE_SIZE;
}

int quadraticProbe(int index, int attempt) {
    return (index + attempt * attempt) % TABLE_SIZE;
}
