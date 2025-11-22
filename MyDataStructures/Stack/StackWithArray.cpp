#include<iostream>
using namespace std;
class Stack{
    int arr[5];
    int front;
    int rear;
    int capacity;
    int count;
    public:
    bool isFull(){return capacity==count;}
    bool isEmpty(){return count==0;}
    void push(int val){
        if(isFull())
        {cout<<"Stack Full\n";
            exit(1);
        }
        arr[rear]=val;
        rear=(rear+1)%capacity;
        count++;
        
    }
    void pop(){
        if(isEmpty())
        {
            cout<<"Stack is Empty"<<endl;
            exit(1);
        }
        front=(front+1)%capacity;
        count--;
    }
    int top(){
        return arr[rear];
    }
    int bottom(){
        return arr[front];
    }
};