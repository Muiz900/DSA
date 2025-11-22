#include<iostream>
using namespace std;
void printEveryElementsUsing2loopOnce(int arr[], int size) {
    if (size == 0) return; // No elements to process

    cout << "Unique elements: ";
    for (int i = 0; i < size; i++) {
        bool isUnique = true;
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isUnique = false;
                break;
            }
        }
        if (isUnique) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}
void printUniqueElementsUsing2loop(int arr[], int size) {
    if (size == 0) return; // No elements to process

    cout << "Unique elements: ";
    for (int i = 0; i < size; i++) {
        bool isUnique = true;
        for (int j = 0; j < size; j++) {
            if (i != j && arr[i] == arr[j]) {
                isUnique = false;
                break;
            }
        }
        if (isUnique) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}
int main(){
    int arr[] = {1, 2, 2, 3, 4, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    printUniqueElementsUsing2loop(arr, size);
    // Uncomment the next line to test the single loop version
    // printUniqueElements1loop(arr, size);

    return 0;
}