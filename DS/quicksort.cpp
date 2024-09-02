#include <iostream>
using namespace std;

class Book {
private:
    string name;
    int key; // 0 for DS, 1 for PF and 2 for OOP
    string category; // DS, OOP, PF
    float price;
    public:
    Book () {}

    Book(string pName, string pCat, float pPrice) : name(pName), category(pCat), price(pPrice) {}

    string getCategory() { 
        return this->category; 
    }

    string getName() {
        return this->name;
    }

    void display() {

        cout << "Name: " << name << endl;
        cout << "Key: " << key << endl;
        cout << "Category: " << category << endl;
        cout << "Price: " << price << endl;
        cout << endl;
    }

};
int partition(int arr[], int left, int right) {
    
    int pivot = arr[left];
    int i = left;
    for (int j = left; j <= right; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[j], arr[i]);
        }
    }

    swap(arr[i], arr[left]);
    return i;
}

void quicksort(int array[], int low, int high) {
    if(low >= high) {
        return;
    }
    int pivot = partition(array, low, high);
    quicksort(array, low, pivot - 1);
    quicksort(array, pivot + 1, high);
}

int convert(Book t) {

    if(t.getCategory() == "DS") {
        return 0;
    } else if(t.getCategory() == "PF") {
        return 1;
    } else {
        return 2;
    }
}

void swap(Book& b, Book& c) {
    Book temp;
    temp = b;
    b = c;
    c = temp;
}

int partition1(Book arr[], int low, int high) {
    int i = low;
    int pivot = convert(arr[low]);

    for (int j = low; j <= high; j++) {
        if(convert(arr[j]) < pivot) {
            i++;
            swap(arr[j], arr[i]);
        }
    }

    swap(arr[i], arr[low]);
    return i;
}

void quickSortQuestion(Book arr[], int low, int high ) {
    if(low >= high) {
        return;
    }
    int pivot = partition1(arr, low, high);
    quickSortQuestion(arr, low, pivot - 1);
    quickSortQuestion(arr, pivot + 1, high);
}

void Sort(Book arr[], int N) {

    quickSortQuestion(arr, 0, N - 1);
}

void Search (Book arr[], int N, string search) {

    int start = 0, end = N - 1;

    while(start <= end) {
        int mid = (start + end) / 2;

        if(arr[mid].getName() == search) {
            cout << "Found";
            return;
        } else if(arr[mid].getName() < search) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    cout << "Not Found";
}

int main() {
    int arr[5] = {1002, 5, 6, 4, 100};
    quicksort(arr, 0, 4);

    Book array[4] = {Book("Book of OOP", "OOP", 20.0), Book("Book of DS", "DS", 20.0),
                     Book("Book of PF", "PF", 20.0), Book("Book of DS", "DS", 23.3)};

    quickSortQuestion(array, 0, 3);

    for (int i = 0; i < 4; i++) {
        array[i].display();
    }

    cout << endl;

  
    Search(array, 4, "Book of PF");
    return 0;
}