#include<iostream>
#include<vector>
using namespace std;
vector<int>ProductArrayExceptSelfBruteForce(vector<int>&arr){
    vector<int>result(arr.size(),1);
for (int i = 0; i < arr.size(); i++) {
    int product = 1;
    for (int j = 0; j < arr.size(); j++) {
        if (i != j) product *= arr[j];
    }
    result[i] = product;
}
return result;
}
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, 1);

    int prefix = 1;
    for (int i = 0; i < n; i++) {
        result[i] = prefix;
        prefix *= nums[i];
    }

    int suffix = 1;
    for (int i = n - 1; i >= 0; i--) {
        result[i] *= suffix;
        suffix *= nums[i];
    }

    return result;
}

vector<int> productExceptSelfOptimiziedApproach(vector<int>&arr){
    vector<int>result(arr.size(),1);
    int prefix=1;
    for(int i=1;i<arr.size();i++)
    {
        result[i]=prefix;
        prefix*=arr[i];
  
    }
    int suffix=1;
    for(int i=arr.size()-1;i>=0;i--)
    {
        result[i]=suffix*result[i];
suffix=arr[i]*suffix;

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

int main(){
    vector<int>vec={1,2,3};

    cout<<"Array :";
   print(vec);
  vector<int>ps=productExceptSelfOptimiziedApproach(vec);
   cout<<"Product of Array Except Self:";
   print(ps);

}