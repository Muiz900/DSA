#include<iostream>
#include<string>
using namespace std;
void removeOccurences(string &str,string &remOcc){
    while(str.find(remOcc)<str.length()){
        str.erase(str.find(remOcc),remOcc.length());
    }

}
int main() {
    string text, pattern;
    
    cout << "Enter the main string: ";
    getline(cin, text);

    cout << "Enter the substring to remove: ";
    getline(cin, pattern);

    removeOccurences(text, pattern);

    cout << "String after removing occurrences: " << text << endl;
     
    char n;
    cout<<"Press Enter to end";
    cin>>n;

    return 0;
}