#include<iostream>
#include<vector>
using namespace std;
//Book allocation/ PainterProblem/ Minimum in SubArray
bool isValid(vector<int>&arr,int totalStudents,int totalBooks,int maxPages){
    int students=1,pages=0;
    for(int i=0;i<totalBooks;i++)
    {
        if(arr[i]>maxPages)
        {return false;}
        if(pages+arr[i]<=maxPages)
        {
            pages+=arr[i];
        }else
        {
            pages=arr[i];
            students++;
        }
    }
    if(students<=totalStudents)
    {
        return true;
    }
    return false;
}
int allocateBooks(vector<int>&arr,int totalStudents,int totalBooks)
{
    if(totalStudents>totalBooks){return -1;}
int start=arr[0],end=0,mid=0;
int ans=-1;
      for(int i=0;i<totalBooks;i++)
      {if(start<arr[i])
        {
            start=arr[i];
        }
        end+=arr[i];
      }
      while(start<=end)
      {
        mid=start+(end-start)/2;
             if(isValid(arr,totalStudents,totalBooks,mid))
             {ans=mid;
                end=mid-1;
             }else{
                start=mid+1;
             }
      }
      return ans;
}