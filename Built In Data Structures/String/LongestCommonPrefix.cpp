#include<iostream>
#include<vector>
#include<string>
using namespace std;
string longestCommonPrefix(vector<string>&strs) {
  if(strs.size()==0) return "";
  string prefix="";
  for(int i=0; i<strs[0].size(); i++) {// Iterate through each character of the first string
    char currentChar = strs[0][i];// Get the current character from the first string
                    for(int j=1; j<strs.size(); j++) {//start from the second string

                      if(i >= strs[j].size() || strs[j][i] != currentChar) {
                        return prefix;
                      }
                    }
    prefix += currentChar;
  }
}

int main() {
  vector<string> strs = {"flower", "flow", "flight"};
  cout << "Longest Common Prefix: " << longestCommonPrefix(strs) << endl; 
  return 0;
}