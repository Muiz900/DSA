#include <iostream>
#include <string>
using namespace std;
//permutation in string leetcode problem

bool isSameFreq(int f1[], int f2[])
{
    for (int i = 0; i < 26; i++)
    {
        if (f1[i] != f2[i])
            return false;
    }
    return true;
}
bool checkInclusion(string s1, string s2)
{
    int freq[26] = {0};
    for (int i = 0; i < s1.length(); i++)
    {
        freq[s1[i] - 'a']++;
    }
    int winSlice[26] = {0};

    for (int i = 0; i < s2.length(); i++)
    {
        int index = 1, winIndex = 0;
        int winFreq[26] = {0};
        while (s1.length() < s2.length() && winIndex < s1.length())
        {
            winFreq[s2[winIndex] - 'a']++;
            index++;
            winIndex++;
        }
         if(isSameFreq(freq,winFreq)){
            return true;
            }
    }


    return false;
    }
