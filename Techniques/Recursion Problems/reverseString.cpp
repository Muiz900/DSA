#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
string reverseString(string str, int start, int end) {
    // Base case or checking if sting can be reversed or not
    if (start >= end) return str;

    // Swap characters
    swap(str[start], str[end]);

    // Recursive call
    return reverseString(str, start + 1, end - 1);
}
string reverseString2(string str)
{
    if(str.length()==1)
    {
        return str;
    }
    return str.substr(str.size()-1,1)+reverseString2(str.substr(0,str.size()-1));
}
int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    string reversed = reverseString2(str);
    cout << "Reversed string: " << reversed << endl;

    return 0;
}