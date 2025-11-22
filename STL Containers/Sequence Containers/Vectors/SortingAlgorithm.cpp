#include<iostream>
#include<vector>
using namespace std;
//I am useless
vector<int> BubbleSortAlgorithm(vector<int> arr) {
    // Implementing Bubble Sort
    //Time Complexity: O(n^2)
    //Space Complexity: O(1)
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    return arr;
}
vector<int> SelectionAlgorithm(vector<int> arr) {
    // Implementing Selection Sort
    //Time Complexity: O(n^2)
    //Space Complexity: O(1)
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
    return arr;
}
int main(){

vector<int>arr={321,33421,231,1,123434,234};
vector<int>BubbleSortedArr=BubbleSortAlgorithm(arr);
cout<<"Bubble Sorted Array: [";
for(int val:BubbleSortedArr){
    cout<<val<<" ";
}
cout<<"]"<<endl;

vector<int>SelectionSortedArr=SelectionAlgorithm(arr);
cout<<"Selection Sorted Array: [";
for(int val:SelectionSortedArr){
    cout<<val<<" ";}

    cout<<"]"<<endl;

}