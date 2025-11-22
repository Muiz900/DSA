#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
int maxArea(vector<int> &height)
{
    int maxArea = 0;
    int area = 0;
    for (int left = 0; left < height.size(); left++)
    {
        for (int right = left + 1; right < height.size(); right++)
        {
            if (height[left] < height[right])
            {
                area = (right - left) * (height[left]);
            }
            else
            {
                area = (right - left) * height[right];
            }
            if (area > maxArea)
            {
                maxArea = area;
            }
        }
    }
    return maxArea;
}
int maxAreaOptimized(vector<int> &heights)
{if (heights.empty()) return 0;

    int left = 0;
    int right = heights.size()-1;
    int area = 0;
    int maxArea=0;
    while (left<right)
    {
        if (heights[left] < heights[right])
        {
            area = (right - left) * heights[left];
            left++;
        }
        else
        {

            area = (right - left) * heights[right];
            right--;
        }
        maxArea=max(area,maxArea);
    }
    return maxArea;
}
int main()
{
    vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Maximum area: " << maxArea(heights) << endl;

    cout << "Maximum Water:" << maxAreaOptimized(heights) << endl;
}