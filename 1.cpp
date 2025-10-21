// Q1_SimpleList.cpp
#include <iostream>
using namespace std;

class SimpleList {
private:
    int arr[100];    // fixed-size internal storage
    int count;       // current number of elements

public:
    // Constructor: initialize an empty list
    SimpleList() : count(0) {}

    // Add an element at the end (if space available)
    void add(int item) {
        if (count < 100) {
            arr[count++] = item;
            cout << item << " added.\n";
        } else {
            cout << "List full!\n";
        }
    }

    // Remove first occurrence of item (shifts elements left)
    void remove(int item) {
        int i;
        for (i = 0; i < count; ++i) {
            if (arr[i] == item) break;
        }
        if (i == count) {
            cout << item << " not found.\n";
            return;
        }
        for (; i < count - 1; ++i) arr[i] = arr[i + 1];
        --count;
        cout << item << " removed.\n";
    }

    // Display elements
    void display() const {
        cout << "List: [ ";
        for (int i = 0; i < count; ++i) cout << arr[i] << " ";
        cout << "]\n";
    }

    // Return size
    int size() const { return count; }

    // Operator overload: indexing (read-only)
    int operator[](int index) const {
        if (index < 0 || index >= count) {
            cerr << "Index out of range, returning -1\n";
            return -1;
        }
        return arr[index];
    }

    // Friend to allow cout << list
    friend ostream& operator<<(ostream &out, const SimpleList &s) {
        out << "[ ";
        for (int i = 0; i < s.count; ++i) out << s.arr[i] << " ";
        out << "]";
        return out;
    }
};

int main() {
    SimpleList s;
    s.add(10);
    s.add(20);
    s.add(30);
    s.display();
    cout << "Using operator<< : " << s << "\n";
    s.remove(20);
    cout << "Size: " << s.size() << "\n";
    cout << "Element at 1: " << s[1] << "\n";
    return 0;
}
