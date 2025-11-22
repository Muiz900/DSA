#include <iostream>
#include <vector>
using namespace std;
void mergetwoSortedArray(vector<int> &arr1, int m, vector<int> &arr2, int n)
{
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (i >= 0 && j >= 0)
    {
        if (arr1[i] < arr2[j])
        {
            arr1[k] = arr2[j];
            j--;
            k--;
        }
        else if (arr1[i] > arr2[j])
        {
            arr1[k]=arr1[i];
            i--;
            k--;
        }
        else
        {
            arr1[k] = arr1[i];
            i--;
            k--;
            arr1[k] = arr2[j];
            k--;
            j--;
        }
    }

    while (j >= 0)
    {
        arr1[k] = arr2[j];
        j--;
        k--;
    }
}

void print(vector<int>arr){
    cout<<"[";
    for(int val=0;val<arr.size();val++)
    {
     cout<<arr[val]<<(val<arr.size()-1?",":"");
    }
    cout<<"]"<<endl;

}
int main(){
    vector<int>arr1=
    {
        1,2,3,0,0,0
    };
    vector<int>arr2=
    {
        2,5,6
    };
    cout<<"Before merging:";
    print(arr1);
    cout<<"After merging:";
    mergetwoSortedArray(arr1,3,arr2,3);
    print(arr1);
}