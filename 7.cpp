// Q7_Sorter.cpp
#include <iostream>
#include <vector>
using namespace std;

class Sorter {
private:
    vector<int> arr;

public:
    void input(const vector<int> &data) { arr = data; }

    void display() const {
        for (int x : arr) cout << x << " ";
        cout << '\n';
    }

    // Bubble Sort
    void bubbleSort() {
        int n = arr.size();
        for (int i = 0; i < n - 1; ++i)
            for (int j = 0; j < n - i - 1; ++j)
                if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
    }

    // Insertion Sort
    void insertionSort() {
        int n = arr.size();
        for (int i = 1; i < n; ++i) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                --j;
            }
            arr[j + 1] = key;
        }
    }

    // Selection Sort
    void selectionSort() {
        int n = arr.size();
        for (int i = 0; i < n - 1; ++i) {
            int minIdx = i;
            for (int j = i + 1; j < n; ++j)
                if (arr[j] < arr[minIdx]) minIdx = j;
            swap(arr[i], arr[minIdx]);
        }
    }
};

int main() {
    Sorter s;
    vector<int> data = {64, 25, 12, 22, 11};
    s.input(data);

    cout << "Original: "; s.display();
    s.bubbleSort();
    cout << "After Bubble: "; s.display();

    s.input(data);
    s.insertionSort();
    cout << "After Insertion: "; s.display();

    s.input(data);
    s.selectionSort();
    cout << "After Selection: "; s.display();

    return 0;
}
