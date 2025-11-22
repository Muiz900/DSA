#include <iostream>
using namespace std;
class queue
{
    int front;
    int rear;
    int arr[5];
    int count;
    int capacity;

public:
    queue()
    {
        capacity = 5;
        front = 0;
        rear = 0;
        count = 0;
    }
    bool isEmpty()
    {
        return count==0;
    }
    bool isFull()
    {
        return count == capacity;
    }
    void enqueue(int val)
    {
        if (isFull())
        {
            cout << "Queue full" << endl;
            exit(1);
        }
        arr[rear] = val;
        rear = (rear + 1) % capacity;
        count++;
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty\n";
            exit(1);
        }
        front = (front + 1) % capacity;
        count--;
    }
    int front() { return arr[front]; }
    int back() { return arr[rear]; }
};
int main() {}