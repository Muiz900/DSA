#include<iostream>
using namespace std;
void swapMaxAndMin(int a[],int size)
{
    if (size < 2) return; // No swap needed for arrays with less than 2 elements

    int maxIndex = 0, minIndex = 0;

    // Find the indices of the maximum and minimum elements
    for (int i = 1; i < size; i++) {
        if (a[i] > a[maxIndex]) {
            maxIndex = i;
        }
        if (a[i] < a[minIndex]) {
            minIndex = i;
        }
    }

    // Swap the maximum and minimum elements
    int temp = a[maxIndex];
    a[maxIndex] = a[minIndex];
    a[minIndex] = temp;
}