#include<iostream>
#include<vector>
#include<array>
using namespace std;
void selectionSortAscending(vector<int>&arr){
    for(int i=0;i<arr.size();i++)
    {int minIndex=i;
        for(int j=0;j<arr.size();j++)
        {
            if(arr[i]>arr[j]){
minIndex=j;
                
            }
        }
        swap(arr[i],arr[minIndex]);

    }
}
void selectionSortDescending(vector<int>&arr){
    for(int i=0;i<arr.size();i++)
    {
        int maxIndex=i;
        for(int j=0;j<arr.size();j++)
        {
                if(arr[i]<arr[j]){
maxIndex=j;

            }

        }
        swap(arr[i],arr[maxIndex]);
    }
}
void selectionSortAscending(int arr[],int size)
{
    for(int i=0;i<size;i++)
    { int minIndex=i;

        for(int j=i+1;j<size;j++)
        {
if(arr[i]>arr[j])
minIndex=j;

        }
        swap(arr[i],arr[minIndex]);
}
}
int main(){
    
}