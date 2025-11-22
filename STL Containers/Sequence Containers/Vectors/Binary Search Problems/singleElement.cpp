#include <iostream>
#include <vector>
using namespace std;
int singleElement(vector<int> &nums)
{
    int left = 0, right = nums.size() - 1;
    while (left < right)
    { // assuming that a single uniqueelement always exist;
        int mid = (left + right) / 2;
        // mid ^ 1 gives pair index:
        // if mid is even -> mid^1 = mid+1
        // if mid is odd  -> mid^1 = mid-1
        if (nums[mid] == nums[mid ^ 1])
        {
            left = mid + 1; // unique is to the right
        }
        else
        {
            right = mid; // unique is at mid or to the left
        }
    }
    return nums[left];
}

int singleElementOptimized(vector<int> &num)
{
    if(num.size()==1)
    {return num[0];}
    if(num.size()==0)
    {return -1;}
    
    int left = 0, right = num.size() - 1, mid = 0;
    while (left <= right)
    {
        if(mid==0)
        {return num[mid];}
        if(mid==num.size()-1)
        {
            return num[mid];
        }
        mid=left+(right-left)/2;
        if (num[mid] != num[mid - 1] && num[mid] != num[mid + 1])
        {
            return num[mid];
        }
if(mid%2==0)
{
    if(num[mid] == num[mid + 1])
        left = mid + 2;
    else
        right = mid - 1;
}
else{
    if(num[mid] == num[mid - 1])
        left = mid + 1;
    else
        right = mid - 1;
}
}}

int uniqueElement(vector<int> &nums)
{
    int left = 0, right = nums.size() - 1, mid = 0;
    while (left < right)
    {
        mid = left + (right - left) / 2;

        // Check if nums[mid] is the single element
        if ((mid == 0 || nums[mid] != nums[mid - 1]) &&
            (mid == nums.size() - 1 || nums[mid] != nums[mid + 1]))
        {
            return nums[mid];
        }

        // If nums[mid] is equal to next element
        if (mid < nums.size() - 1 && nums[mid] == nums[mid + 1])
        {
            // Pair starts at mid
            if (mid % 2 == 0)
                left = mid + 2;
            else
                right = mid - 1;
        }
        // If nums[mid] is equal to previous element
        else if (mid > 0 && nums[mid] == nums[mid - 1])
        {
            // Pair ends at mid
            if (mid % 2 == 1)
                left = mid + 1;
            else
                right = mid - 2;
        }
    }
    return nums[left];
}
int main()
{
    vector<int> vec = {4,1,2,1,2};
    int result = singleElementOptimized(vec);
    if (result != -1)
        cout << "Single element is: " << result << endl;
    else
        cout << "No single element found." << endl;
    return 0;
}