#include<iostream>
using namespace std;
void inputArray(int arr[], int size) {
    cout << "Enter " << size << " elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}
void printArray(int arr[], int size) {
    cout << "The elements of the array are: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}