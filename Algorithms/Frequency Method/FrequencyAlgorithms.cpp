#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 1. Find the element with maximum frequency
int maxFrequencyElement(const vector<int>& nums) {
    unordered_map<int, int> freq;
    for (int num : nums) freq[num]++;
    int maxFreq = 0, element = nums[0];
    for (const auto& [num, count] : freq) {
        if (count > maxFreq) {
            maxFreq = count;
            element = num;
        }
    }
    return element;
}

// 2. Find all elements that appear more than n/k times
vector<int> elementsMoreThanNbyK(const vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for (int num : nums) freq[num]++;
    vector<int> result;
    int threshold = nums.size() / k;
    for (const auto& [num, count] : freq) {
        if (count > threshold) result.push_back(num);
    }
    return result;
}

// 3. Find the first non-repeating element
int firstNonRepeating(const vector<int>& nums) {
    unordered_map<int, int> freq;
    for (int num : nums) freq[num]++;
    for (int num : nums) {
        if (freq[num] == 1) return num;
    }
    return -1; // If all elements repeat
}

// 4. Find duplicates in the vector (using only vectors)
vector<int> findDuplicates(const vector<int>& nums) {
    vector<int> result;
    vector<bool> visited(nums.size(), false);
    for (size_t i = 0; i < nums.size(); ++i) {
        if (visited[i]) continue;
        int count = 1;
        for (size_t j = i + 1; j < nums.size(); ++j) {
            if (nums[j] == nums[i]) {
                count++;
                visited[j] = true;
            }
        }
        if (count > 1) result.push_back(nums[i]);
    }
    return result;
}

// 5. Check if two vectors are anagrams (same frequency of elements, using only vectors)
bool areAnagrams(const vector<int>& a, const vector<int>& b) {
    if (a.size() != b.size()) return false;
    vector<int> a_sorted = a, b_sorted = b;
    sort(a_sorted.begin(), a_sorted.end());
    sort(b_sorted.begin(), b_sorted.end());
    return a_sorted == b_sorted;
}

// 6. Find the element with minimum frequency (using only vectors)
// Problem: Given a vector of integers, find the element that appears the least number of times.
int minFrequencyElementVector(const vector<int>& nums) {
    vector<int> unique;
    vector<int> freq;
    for (int num : nums) {
        auto it = find(unique.begin(), unique.end(), num);
        if (it == unique.end()) {
            unique.push_back(num);
            freq.push_back(1);
        } else {
            freq[it - unique.begin()]++;
        }
    }
    int minFreq = nums.size() + 1, element = nums[0];
    for (size_t i = 0; i < unique.size(); ++i) {
        if (freq[i] < minFreq) {
            minFreq = freq[i];
            element = unique[i];
        }
    }
    return element;
}

// 7. Count distinct elements (using only vectors)
// Problem: Given a vector of integers, count the number of distinct elements.
int countDistinctVector(const vector<int>& nums) {
    vector<int> unique;
    for (int num : nums) {
        if (find(unique.begin(), unique.end(), num) == unique.end())
            unique.push_back(num);
    }
    return unique.size();
}

// 8. Find all elements with exactly k frequency (using only vectors)
// Problem: Given a vector of integers and an integer k, return all elements that appear exactly k times.
vector<int> elementsWithKFrequencyVector(const vector<int>& nums, int k) {
    vector<int> unique;
    vector<int> freq;
    for (int num : nums) {
        auto it = find(unique.begin(), unique.end(), num);
        if (it == unique.end()) {
            unique.push_back(num);
            freq.push_back(1);
        } else {
            freq[it - unique.begin()]++;
        }
    }
    vector<int> result;
    for (size_t i = 0; i < unique.size(); ++i) {
        if (freq[i] == k) result.push_back(unique[i]);
    }
    return result;
}

// 9. Find all elements that appear only once (using only vectors)
// Problem: Given a vector of integers, return all elements that appear exactly once.
vector<int> elementsAppearingOnceVector(const vector<int>& nums) {
    vector<int> unique;
    vector<int> freq;
    for (int num : nums) {
        auto it = find(unique.begin(), unique.end(), num);
        if (it == unique.end()) {
            unique.push_back(num);
            freq.push_back(1);
        } else {
            freq[it - unique.begin()]++;
        }
    }
    vector<int> result;
    for (size_t i = 0; i < unique.size(); ++i) {
        if (freq[i] == 1) result.push_back(unique[i]);
    }
    return result;
}

// 10. Find the frequency of each element (using only vectors)
// Problem: Given a vector of integers, return a vector of pairs {element, frequency}.
vector<pair<int, int>> frequencyVector(const vector<int>& nums) {
    vector<int> unique;
    vector<int> freq;
    for (int num : nums) {
        auto it = find(unique.begin(), unique.end(), num);
        if (it == unique.end()) {
            unique.push_back(num);
            freq.push_back(1);
        } else {
            freq[it - unique.begin()]++;
        }
    }
    vector<pair<int, int>> result;
    for (size_t i = 0; i < unique.size(); ++i) {
        result.push_back({unique[i], freq[i]});
    }
    return result;
}
int main() {
    vector<int> nums = {1, 2, 2, 3, 4, 4, 4, 5};
    cout << "Max frequency element: " << maxFrequencyElement(nums) << "\n";
    cout << "Elements more than n/3 times: ";
    for (int x : elementsMoreThanNbyK(nums, 3)) cout << x << " ";
    cout << "\nFirst non-repeating element: " << firstNonRepeating(nums) << "\n";
    cout << "Duplicates: ";
    for (int x : findDuplicates(nums)) cout << x << " ";
    cout << "\nAre {1,2,2,3} and {2,1,3,2} anagrams? " 
         << (areAnagrams({1,2,2,3}, {2,1,3,2}) ? "Yes" : "No") << "\n";
    return 0;
}