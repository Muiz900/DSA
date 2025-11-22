#include<iostream>
using namespace std;
void intersectionOf2Arrays(int arr1[], int size1, int arr2[], int size2) {
    cout << "Intersection of the two arrays: ";
    const int size=size1 + size2;
    int arr[10000];
    for(int i=0;i<size1;i++){
        arr[i]=arr1[i];
    }
    for(int i=size1;i<size2;i++){
        arr[size1+i]=arr2[i];
    }
    for(int i=0;i<size1+size2;i++){
            if(!(arr[i]==arr[i+1])){
                cout << arr[i] << " ";
            }
    }
    cout << endl;
}
int main() {
    int arr1[] = {1, 4, 4, 4, 5};
    int arr2[] = {3, 4, 4, 6, 7};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    intersectionOf2Arrays(arr1, size1, arr2, size2);

    return 0;
}