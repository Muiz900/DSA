#include <iostream>
#include <vector>
#include<fstream>
using namespace std;
void nextPermutation(vector<int> &arr)
{
    int pivot = -1;
    for (int i = arr.size() - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            pivot = i;
            break;
        }
    }
    if (pivot == -1)
    {
        int st = 0, end = arr.size() - 1;
        while (st <= end)
        {
            swap(arr[end], arr[st]);
            st++;
            end--;
        }
        return;
    }
    for(int i=arr.size()-1;i>pivot;i--){
        if(arr[pivot]<arr[i]){
             swap(arr[pivot], arr[i]);
        
        break;    }
    }
   int st=pivot+1,end=arr.size()-1;
    while(st<=end)
    {     swap(arr[end], arr[st]);
            st++;
            end--;
       

    }

}
int factorial(int n){
    int result=1;
    while(n>0){
result*=n;
n--;

    }
return result;
}

void print(vector<int>arr){
    cout<<"[";
    for(int val=0;val<arr.size();val++)
    {
     cout<<arr[val]<<(val<arr.size()-1?",":"");
    }
    cout<<"]"<<endl;

}
void addtofile(fstream &file,vector<int>&arr,int i){
    file.open("Permutation.txt",ios::app);

    if(!file)
    {
        return;
    }
    file<<i+1<<(i+1%10==1?"st":(i+1%10==2?"nd":i+1%10==3?"rd":"th"))<<" Permutation:";
        file<<"[";
    for(int val=0;val<arr.size();val++)
    {
     file<<arr[val]<<(val<arr.size()-1?",":"");
    }
    file<<"]"<<endl;

file.close();


}
int main(){
    fstream permutation;
    permutation.open("Permutation.txt",ios::in|ios::out);
    permutation.close();
    vector<int>arr={1,2,3,4,5,6,7,8,9};
    int fa=factorial(arr.size());
    cout<<"Original Array:";
    print(arr);
    for(int i=0;i<fa;i++)
    {
        nextPermutation(arr);
        addtofile(permutation,arr,i);
    }
    cout<<"Done"<<endl;
}