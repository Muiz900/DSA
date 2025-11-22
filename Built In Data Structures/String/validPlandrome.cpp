#include<iostream>
#include<string>
using namespace std;
bool isAlphaNumeric(char &c)
{
   return ((c >= '0' && c <= '9') || 
            (c >= 'A' && c <= 'Z') || 
            (c >= 'a' && c <= 'z'));
        }
bool validPlandrome(string &str)
{
    int st=0,end=str.size()-1;
    while(st<end){
    if(!isAlphaNumeric(str[st]))
    {
st++;
continue;
    }
    if(!isAlphaNumeric(str[end]))
    {
end--;
continue;
    }
    if(tolower(str[st])!=tolower(str[end]))
    {
        return false;
    }
    st++;
    end--;
    
}

return true;
}
int main(){
    char c='a';
    bool flag=true;
    while(flag){
    cout<<"Enter a character:";
 cin>>c;
    cout<<"isAlphaNumeric:"<<(isAlphaNumeric(c)?"True":"False")<<endl;
    flag=(c=='e')?false:true;
}
}