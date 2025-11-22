#include<iostream>
#include<cstring>
using namespace std;
bool plandromeString(string str)
{
    if(str.length()==1||str.length()==0)
    {
        return true;
    }

    return ((str[0]==str[str.length()-1])&&(plandromeString(str.substr(1,str.length()-2))));
}
int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);
    if (plandromeString(s)) {
        cout << "Palindrome" << endl;
    } else {
        cout << "Not a palindrome" << endl;
    }
    return 0;
}