#include<iostream>
#include <vector>
using namespace std;
vector<int> pairSum(vector <int> arr,int target) {
   
    // Brute force approach to find pairs with the given sum
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[i] + arr[j] == target) {
                return {i,j};
            }
        }
    }
    return {};
}

vector<int> pairSumOptimized(vector <int> arr, int target) {

    int i=0;
    int j=arr.size()-1;
    // Optimized approach using two pointers
    while (i < j) {
    
        if (arr[i] + arr[j] == target) {
            return {i, j};
        } else if (arr[i] + arr[j] < target) {
            i++;
        } else {
            j--;
        }
    }
    return {};
    

}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int target = 5;

    // Using brute force approach
    vector<int> result = pairSum(arr, target);
    if (!result.empty()) {
        cout << "Pair found at indices: " << result[0] << " and " << result[1] << endl;
    } else {
        cout << "No pair found." << endl;
    }

    // Using optimized approach
    vector<int> optimizedResult = pairSumOptimized(arr, target);
    if (!optimizedResult.empty()) {
        cout << "Optimized Pair found at indices: " << optimizedResult[0] << " and " << optimizedResult[1] << endl;
    } else {
        cout << "No pair found in optimized search." << endl;
    }

    return 0;



}