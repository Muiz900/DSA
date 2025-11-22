#include<iostream>
#include<vector>
using namespace std;
vector<int>twoSumTarget(vector<int>&arr,int target,int start=0,int index=0){
    if(arr.size()==2)
    {
        return (arr[0]+arr[1]==target) ? vector<int>{0, 1} : vector<int>{-1};
    }
    if(index==arr.size()-1)
    {
        return {-1};
    }
    if(arr[start]+arr[index]==target)
    {
        return {start,index};
    }else
    {
        return twoSumTarget(arr,target,start+1,index);
    }
}

int main() {

    int size=0,n=0,target=0;
    vector<int>arr;
    cout<<"Enter Your Total Elements of arr:";
    cin>>size;
    for(int i=0;i<size;i++)
    {
        cout<<"Enter "<< i <<"th element of your array";
        cin>>n;
        arr.push_back(n);
    }
    cout<<"Enter Your Target:";
    cin>>target;

    vector<int> result = twoSumTarget(arr, target, 0, 1);

    if (result.size() == 2 && result[0] != -1) {
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
    } else {
        cout << "No solution found." << endl;
    }
    return 0;
}
