#include <iostream>
#include <vector>
using namespace std;
int subArraySum(vector<int> &nums)//BRute Force
{
    int size = (nums.size() * (nums.size() + 1)) / 2;
    vector<int> subArraySums;
    for (int st = 0; st < nums.size(); st++)
    {
        for (int end = st; end < nums.size(); end++)
        {
            int sum = 0;
            cout << "[";
            for (int i = st; i <= end; i++)
            {
                sum += nums[i];
                cout << nums[i];
                if (i < end)
                    cout << ", ";
            }
            cout << "] Sum: " << sum << endl;
            subArraySums.push_back(sum);
        }
    }
    for (int i = 0; i < subArraySums.size()-1; i++)
    {
        for (int j = 0; j < subArraySums.size()-1; j++)
        {
            if (subArraySums[j] < subArraySums[j + 1])
            {
                int temp = subArraySums[j];
                subArraySums[j] = subArraySums[j + 1];
                subArraySums[j + 1] = temp;
            }
        }
    }
    return subArraySums[0];
}
int sumOfSubArray(vector<int>arr)
{
    vector <int> subArraySums;
    for(int st=0; st<arr.size(); st++)
    {
        int sum = 0;
        cout << "[";
        for(int end=st; end<arr.size(); end++)
        {
            sum += arr[end];
            cout << arr[end];
            if(end < arr.size() - 1)
                cout << ", ";

                subArraySums.push_back(sum);
        }
        cout << "] Sum: " << sum << endl;
    }
    for(auto val:subArraySums)
    {
        cout<< val<<endl;
    }
for(int ol=0; ol<subArraySums.size()-1; ol++)
    {
        for(int swap=0; swap<subArraySums.size()-1; swap++)
        {
            if(subArraySums[swap] < subArraySums[swap+1])
            {
                int temp = subArraySums[swap];
                subArraySums[swap] = subArraySums[swap+1];
                subArraySums[swap+1] = temp;
            }
        }
    }
    return subArraySums[0];
}
//most optimal solution
//Kadane's Algorithm
//Time Complexity: O(n)
int sumOfSubArrayOneLoop(vector<int> &arr){
    int maxSum = arr[0];
    int currentSum = arr[0];
    
    for (int i = 1; i < arr.size(); i++) {
        currentSum = max(arr[i], currentSum + arr[i]);
        maxSum = max(maxSum, currentSum);
    }
    
    return maxSum;
}


    int main()
    {
        vector<int> nums = {-1, -2, -3, -4,-5,-6,-7,-6,-8,-9,-10};
        int maxsum = subArraySum(nums);
        cout << "Maximum subarray sum: " << maxsum << endl; // Output: Maximum subarray sum: 10
        int sum = sumOfSubArray(nums);
        cout<<"Maxium Subarray sum is: "<<sum<<endl;
        int sumOneLoop = sumOfSubArrayOneLoop(nums);
        cout << "Maximum subarray sum using one loop: " << sumOneLoop << endl;
        return 0;
    }