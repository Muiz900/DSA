#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

void allSubSequence(string str,int start=0,int end=0){
    if(start==str.length())
    {
        return ;
    }
    if(end<str.length())
    {//print current subsequence when all subsequences starting from first character to last character


        cout<<str.substr(start,end-start+1)<<endl;
        allSubSequence(str, start, end + 1);
    } 
    else {
        // move to next starting next character and from the next character it starts the function again
        allSubSequence(str, start + 1, start + 1);
        //which uses code to print the string defined in if {}
    }
}

void allSubSequenceInVec(vector<string>&vec,string str,int start=0,int end=0){
    if(start==str.length())
    {
        return ;
    }
    if(end<str.length())
    {//print current subsequence when all subsequences starting from first character to last character

        
       vec.push_back(str.substr(start,end-start+1));
        allSubSequenceInVec(vec,str, start, end + 1);
    } 
    else {
        // move to next starting next character and from the next character it starts the function again
        allSubSequenceInVec(vec,str, start + 1, start + 1);
        //which uses code to print the string defined in if {}
    }
}

void print(vector<string>arr){
    cout<<"[";
    for(int val=0;val<arr.size();val++)
    {
     cout<<arr[val]<<(val<arr.size()-1?",":"");
    }
    cout<<"]"<<endl;

}

int main() {
    vector<string>substring;
    string str;
    cout << "Enter a string: ";
    cin >> str;
    cout << "All substrings are:\n";
    allSubSequenceInVec(substring,str);
   print(substring);
    return 0;
}