#include<iostream>
using namespace std;

    int stack[5],
    n=5,top=-1;
void push(int x)
{
    if(top==n-1)
    {
        cout<<"Stack is Full"<<endl;
    }else
    {
        top++;
        stack[top]=x;
    }


}
void display(){
    if(top>=0){
        for(int i=top;i>=0;i--)
        {
            cout<<stack[i]<<endl;
        }

    }else{
        cout<<"Stack is empty"<<endl;
    }
}
void pop(){
    if(top==-1)
    {
        cout<<"Satck is empty"<<endl;

    }else
    {
        cout<<"Poped elemeent is "<<stack[top]<<endl;
        top--;
         
    }

}
int peek(){
    return stack[top];

}
int main(){



}