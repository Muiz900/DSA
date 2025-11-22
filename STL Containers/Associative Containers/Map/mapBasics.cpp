#include<iostream>
#include<string>
#include<map>

using namespace std;
int main(){
    //Creating a map
    map<int,string> m;
    string str="";
    //Assigning Values using indexes
    for(int i=0;i<10;i++)
    {
        cout<<"Enter String you want to store in pair with key:"<<i;
        getline(cin,str);
        m[i]=str;
    }
    cout<<"Displaying All map Pair"<<endl;
    //Displaying values
    //using at()
for(int i=0;i<10;i++)
    {
        cout<<"Element: "<<m.at(i)<<" Key :"<<i<< endl;
    }
    //deleting values using erase
    for(int i=0;i<10;i++)
    {
    m.erase(i);
}
 //Inserting values using insert();
    for(int i=0;i<10;i++)
    {
        cout<<"Enter String you want to store in pair with key:"<<i;
        getline(cin,str);
        m[i]=str;
    }
 
    //using first and second where first is key and second is value
    for(pair<int,string>a:m )
    {
        cout<<"Element: "<<a.first<<" Key :"<<a.second<< endl;
       
    }
    cout<<"Using iterators to display values"<<endl;
    map<int,string>::iterator o;

    for(o=m.begin();o!=m.end();o++)
    {
        cout<<"Key"<<o->first<<"Element "<<o->second<<endl;
    }
    //Storing vectors in map 
    //we can store objects of any class in maps
    
    char n;
    cout<<"Press Enter to end";
    cin>>n;

}
    