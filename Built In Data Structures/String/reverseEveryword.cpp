#include <iostream>
#include <string>
using namespace std;

string reverseString2(string str) {
    if (str.length() == 1) {
        return str;
    }
    return str.substr(str.size() - 1, 1) + reverseString2(str.substr(0, str.size() - 1));
}

string reverseEveryWord(string str) {
    string result =reverseString2(str);
    string word="";

  while(result.length()>0)
  { 

    
    
    return result;
}

int main() {
    string input = "hello world cpp";
    getline(cin,input);
    cout << reverseEveryWord(input) << endl;
   char n;
    cout<<"Press Enter to end";
    cin>>n;

}