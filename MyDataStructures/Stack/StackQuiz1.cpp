#include<iostream>
#include<stack>
#include<vector>
using namespace std;


int main(){
    vector<int>v={1,2,3,4,5};
    stack<int>s;
    for(int i=v.size();i--;){
        while(s.size()>0&&s.top()<=v[i])
        {
            s.pop();
        }
        if(s.size()==0)
        {
            cout<<-1<<" ";
        }
        else
        {
            cout<<s.top()<<" ";
        }
        s.push(v[i]);


    }
}

