#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size = nums1.size() + nums2.size();
        vector<int> sorArr(size);

        for (int i = 0; i < nums1.size(); i++) {
            sorArr[i] = nums1[i];
        }

        for (int i = 0; i < nums2.size(); i++) {
            sorArr[nums1.size() + i] = nums2[i];
        }

        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (sorArr[j] > sorArr[j + 1]) {
                    int temp = sorArr[j];
                    sorArr[j] = sorArr[j + 1];
                    sorArr[j + 1] = temp;
                }
            }
        }

        if (size % 2 == 0) {
            return (sorArr[size/2 - 1] + sorArr[size/2]) / 2.0;
        } else {
            return sorArr[size/2];
        }
    }
};
int main() {
    Solution sol;
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    double median = sol.findMedianSortedArrays(nums1, nums2);
    cout << "Median: " << median << endl; // Output: Median: 2.0
    return 0;
}