#include<iostream>
#include<vector>
using namespace std;
#include<algorithm>

//Brute Force
void sortArray(vector<int>&arr)
{
    int count0=0,count1=0,count2=0;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]==0)
            count0++;
        else if(arr[i]==1)
            count1++;
        else if(arr[i]==2)
            count2++;
    }

    int index = 0;
    
    for(int i = 0; i < count0; i++)
        arr[index++] = 0;
    
    for(int i = 0; i < count1; i++)
        arr[index++] = 1;
    
    for(int i = 0; i < count2; i++)
        arr[index++] = 2;
}
void sortArrayDutchNationalFlag(vector<int>&arr)
{
    /*Basic three pointer approach can br increased futher but in this case only three are needed
      depending upon the types the pointers are used to divide array into one more part like if we have 
      3types of things then array will be divided into 4 parts, each part will be filled with specific
      type of the data while there will be the extra part which will be unsorted whose size will decrease 
      during each iteration and that data will be added to their specific data part*/ 
      
      int low=0,high=arr.size()-1,mid=0;
      while(mid>=high)
      {
        if(arr[mid]==0)
        {
            swap(arr[mid],arr[low]);
            mid++;
            low++;
        }
        else if(arr[mid]==1)
        {
            mid++;
        }else 
        {
            swap(arr[high],arr[mid]);
            high--;
        }

      }
}
