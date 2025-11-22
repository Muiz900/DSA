#include<iostream>
#include<vector>
using namespace std;
int peak(vector<int>&vec)
{
    int low=1,high=vec.size()-2,mid=0;
    while(low<=high)
    {mid=low+(high-low)/2;
        if(vec[mid-1]<vec[mid]&&vec[mid]>vec[mid+1])
        {
            return mid;
        }else
        if(vec[mid-1]>vec[mid])
        {
            high=mid-1;
        }
        else low=mid+1;
    }
    return -1;
}
int main(){
    vector<int> vec = {1, 3, 5, 7, 6, 4, 2};
    int idx = peak(vec);
    if (idx != -1) {
        cout << "Peak element at index: " << idx << ", value: " << vec[idx] << endl;
    } else {
        cout << "No peak found." << endl;
    }
}