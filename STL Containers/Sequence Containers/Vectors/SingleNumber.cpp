#include<iostream>
#include<vector>
using namespace std;
int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int num : nums) {
        result ^= num; 
    }
    return result;
}
int main() {
    vector<int> nums = {4, 1, 2, 1, 2};
    int single = singleNumber(nums);
    cout << "Single number: " << single << endl; // Output: Single number: 4
    return 0;
}
