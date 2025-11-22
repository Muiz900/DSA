#include <iostream>
#include <vector>
using namespace std;
int rotatedArraySearch(vector<int> &num, int target)
{
    int left = 0, right = num.size()-1, mid = 0;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (num[mid] == target)
            return mid;
        if (num[left] <= num[mid])
        {
            if (target >= num[left] && target < num[mid])
            {
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        else
        {

            if (target > num[mid] && target <= num[right])
            {
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int n, target;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements of the array: ";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    cout << "Enter target element: ";
    cin >> target;
    int index = rotatedArraySearch(arr, target);
    if (index != -1)
        cout << "Element found at index: " << index << endl;
    else
        cout << "Element not found." << endl;
    return 0;
}
