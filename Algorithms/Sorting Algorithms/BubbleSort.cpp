#include<iostream>
#include<array>
#include<vector>
#include<algorithm>
using namespace std;
void bubbleSortAsscending(vector<int>&arr){
    for(int i=0;i<arr.size()-1;i++)
    {
        for(int j=0;j<arr.size()-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            swap(arr[j],arr[j+1]);
        }

    }


}

void bubbleSortDescending(vector<int>&arr){
    for(int i=0;i<arr.size()-1;i++)
    {
        for(int j=0;j<arr.size()-i-1;j++)
        {
            if(arr[j]<arr[j+1]){
            swap(arr[j],arr[j+1]);
            
            }
        }

    }


}
void bubbleSortDescending(array<int,10>&arr ){
    for(int i=0;i<arr.size()-1;i++)
    {
        for(int j=0;j<arr.size()-1;j++)
        {
            if(arr[j]<arr[j+1])
            swap(arr[j],arr[j+1]);
        }

    }


}
void bubbleSortAsscending(array<int,10>&arr){
    for(int i=0;i<arr.size()-1;i++)
    {
        for(int j=0;j<arr.size()-1;j++)
        {
            if(arr[j]>arr[j+1])
            swap(arr[j],arr[j+1]);
        }

    }


}
void bubbleSortDescending(int arr[],int size){
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-1;j++)
        {
            if(arr[j]<arr[j+1])
            swap(arr[j],arr[j+1]);
        }

    }


}

void bubbleSortAsscending(int arr[],int size){
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-1;j++)
        {
            if(arr[j]>arr[j+1])
            swap(arr[j],arr[j+1]);
        }

    }


}
void print(array<int,10>arr){
    cout<<"[";
    array<int,10>::iterator val;
    for(val=arr.begin();val!=arr.end();val++)
    {
        cout<<*val<<(val<arr.end()-1?",":"");

    }
    cout<<"]"<<endl;

}
void print(int arr[],int size){
    cout<<"[";
      for(int i=0; i<size; i++) {
            cout << arr[i] <<(i<size-1?",":"");
        }
    cout<<"]"<<endl;

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
    vector <int>vec={1,2,3,4,5,6,7,8,9,0};
    array<int,10>tarr={1,2,3,4,5,6,7,8,9,0};
    int arr[10]={1,2,3,4,5,6,7,8,9,0};
    cout<<"Using vectors"<<endl;
    bubbleSortDescending(vec);
    print(vec);
    bubbleSortAsscending(vec);
    print(vec);
    cout<<"Using array Templates"<<endl;
    bubbleSortDescending(tarr);
    print(tarr);
    bubbleSortAsscending(tarr);
    print(tarr);
    cout<<"Using Simple Array"<<endl;
    bubbleSortDescending(arr,10);
    print(arr,10);
    bubbleSortAsscending(arr,10);
    print(arr,10);



}


