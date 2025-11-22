#include<iostream>
#include<vector>
using namespace std;


void print(vector<int>arr){
    cout<<"[";
    for(int val=0;val<arr.size();val++)
    {
     cout<<arr[val]<<(val<arr.size()-1?",":"");
    }
    cout<<"]"<<endl;

}
void bubbleSortDescending(vector<int>&arr){
    for(int i=0;i<arr.size()-1;i++)
    {
        for(int j=0;j<arr.size()-i-1;j++)
        {
            cout<<"Value of i: "<<i<<" j:"<<j<<endl; 
            cout<<"Before Swapping:";
            print(arr);
            if(arr[j]<arr[j+1]){
            swap(arr[j],arr[j+1]);
            
            }
            cout<<"After Swapping:";
            print(arr);
        }

    }
}
void bubbleSortAsscending(vector<int>&arr){
    for(int i=0;i<arr.size()-1;i++)
    {
        for(int j=0;j<arr.size()-i-1;j++)
        {  cout<<"Value of i: "<<i<<" j:"<<j<<endl; 
            cout<<"Before Swapping:";
            print(arr);
          
            if(arr[j]>arr[j+1])
            swap(arr[j],arr[j+1]);
        }

    }


}

void selectionSortAscending(vector<int>&arr){
    for(int i=0;i<arr.size();i++)
    {int minIndex=i;
        for(int j=i+1;j<arr.size();j++)
        {

            if(arr[minIndex]>arr[j]){
           minIndex=j;
                
            }
        }if(i!=minIndex)
        swap(arr[i],arr[minIndex]);

    }
}
void selectionSortDescending(vector<int>&arr){
    for(int i=0;i<arr.size();i++)
    {
        int maxIndex=i;
        for(int j=i+1;j<arr.size();j++)
        {
            cout<<"Before Swapping:";
              cout<<"Value of i: "<<i<<" j:"<<j<<"maxIndex:"<<maxIndex<<endl; 
            print(arr);
          
                if(arr[maxIndex]<arr[j]){
                      maxIndex=j;

            }

        }
        swap(arr[i],arr[maxIndex]);
          cout<<"Value of i: "<<i<<"maxIndex:"<<maxIndex<<endl; 
            print(arr);
          
    }
}

void insertionSort(vector<int >&arr){
    for(int i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

}


int main(){

    vector<int>vec={0,1,2,3,4,8,6,7,8,9};
    selectionSortDescending(vec);
    cout<<"After Descending Selection Sort:";
    print(vec);
    selectionSortAscending(vec);
    print(vec);
}
    