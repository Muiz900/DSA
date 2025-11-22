// SortingAlgorithms.cpp
// Selection Sort, Bubble Sort (optimized), Insertion Sort
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Generic selection sort
template<typename T>
void selectionSort(vector<T>& a) {
    size_t n = a.size();
    for (size_t i = 0; i + 1 < n; ++i) {
        size_t min_idx = i;
        for (size_t j = i + 1; j < n; ++j) {
            if (a[j] < a[min_idx]) min_idx = j;
        }
        if (min_idx != i) swap(a[i], a[min_idx]);
    }
}

// Optimized bubble sort (stops early if already sorted)
template<typename T>
void bubbleSort(vector<T>& a) {
    size_t n = a.size();
    if (n < 2) return;
    for (size_t i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (size_t j = 0; j + 1 < n - i; ++j) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

// Insertion sort
template<typename T>
void insertionSort(vector<T>& a) {
    size_t n = a.size();
    for (size_t i = 1; i < n; ++i) {
        T key = a[i];
        size_t j = i;
        while (j > 0 && a[j - 1] > key) {
            a[j] = a[j - 1];
            --j;
        }
        a[j] = key;
    }
}

template<typename T>
void printArray(const vector<T>& a) {
    for (size_t i = 0; i < a.size(); ++i) {
        if (i) cout << ' ';
        cout << a[i];
    }
    cout << '\n';
}

int main() {
    vector<int> original = {64, 25, 12, 22, 11};

    vector<int> v1 = original;
    cout << "Original: ";
    printArray(v1);
    selectionSort(v1);
    cout << "Selection Sort: ";
    printArray(v1);

    vector<int> v2 = original;
    bubbleSort(v2);
    cout << "Bubble Sort:    ";
    printArray(v2);

    vector<int> v3 = original;
    insertionSort(v3);
    cout << "Insertion Sort: ";
    printArray(v3);

    return 0;
}