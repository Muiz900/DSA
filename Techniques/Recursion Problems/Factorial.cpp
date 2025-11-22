
#include<iostream>
#include<vector>
using namespace std;
int factorail(int num){
if(num==0){return 1;}

return num*factorail(num-1);
}
int main(){
    int number=0;
    cout<<"Enter Ther number for factorial:";
    cin>>number;
    cout<<"Factorial:"<<factorail(number);
}