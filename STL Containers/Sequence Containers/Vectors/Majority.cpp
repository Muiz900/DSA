#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int majorityElementBruteForce(vector<int> &nums)
{
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        count = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[i] == nums[j])
            {
                count++;
            }
        }
        if (count > floor(nums.size() / 2))
        {

            return nums[i];
        }
    }
    return -1; // If no majority element found
}
int majorityElementBruteForceForEachLoop(vector<int> &nums)
{
    int frequency = 0;
    for (int val : nums)
    {
        frequency = 0;
        for (int val1 : nums)
        {
            if (val1 == val)
            {
                frequency++;
            }
        }
        if (frequency > nums.size() / 2)
        {
            return val;
        }
    }
    return -1;
}
int majorityElementOptimizeSol(vector<int>&nums)
{
    sort(nums.begin(), nums.end());

    int count=1;
    for(int i=1;i<nums.size();i++)
    {
        if(nums[i]==nums[i-1])
        {
            count++;
            
        }else
        {
            count=1;
        }
        if(count>nums.size()/2)
        {
            return nums[i];
    }
}
return -1;



}
int majorityElement(vector<int> &nums)
{
    // Boyer-Moore Voting Algorithm
    // Time Complexity: O(n)
    int count = 0, candidate;
    for (int num : nums)
    {
        if (count == 0)
        {
            candidate = num;
        }
        cout<<"\nCandidate:"<<candidate<<endl;
        
        cout<<"Number:"<<num<<endl;
        
        cout<<"Before update Count:"<<count<<endl;
        count += (num == candidate) ? 1 : -1;
        cout<<"After update Count:"<<count<<endl;
        
    }
    return candidate;
}
int main()
{
    vector<int> nums = {2,2,1,1,1,2,2,1};
    cout << "Majority Element (Boyer-Moore): " << majorityElement(nums) << endl;
    return 0;
}