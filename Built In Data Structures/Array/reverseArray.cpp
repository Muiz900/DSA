#include<iostream>
using namespace std;
void reverseArrayWhileLoop(int arr[], int size) {
    int start = 0;
    int end = size - 1;
    while (start < end) {
        // Swap the elements at start and end
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        
        // Move towards the middle
        start++;
        end--;
    }
}
void reverseArrayForLoop(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        // Swap the elements at i and size - 1 - i
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}
 void reverseArrayusing2array(int arr[],int size,int rev[],int revSize) {
    for (int i = 0; i < size; i++) {
        rev[i] = arr[size - 1 - i]; // Fill the reverse array
    }

}
