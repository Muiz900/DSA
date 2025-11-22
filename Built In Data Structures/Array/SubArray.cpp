#include<iostream>
using namespace std;
void printSubArray(int arr[], int n) {


    
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            cout << "[";
            int sum=0;
            for (int k = i; k <= j; k++) {
                cout << arr[k];
                if (k < j) cout << ", ";
                sum+= arr[k];  
            }
            cout << "]"<<" Sum: " << sum<<endl;
        }
        cout << endl;  // Move to the next line after printing all subarrays starting from index i
    }
}
int main() {
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    printSubArray(arr, n);
    return 0;
}