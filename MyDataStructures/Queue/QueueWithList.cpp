#include <iostream>
using namespace std;

class Snode
{
    friend class Slink;

protected:
    int data;
    Snode *nextptr;

public:
    Snode(int val)
    {
        data = val;
        nextptr = NULL;
    }
    void display() const
    {
        cout << data << " ";
    }
    int getData() const
    {
        return data;
    }
    void setData(int val)
    {
        data = val;
    }
    Snode *getNext() const
    {
        return nextptr;
    }
    void setNext(Snode *ptr)
    {
        nextptr = ptr;
    }
};
class Slink
{
    Snode *headptr;

public:
    Slink()
    {
        headptr = NULL;
    }
    void displayList()
    {

        Snode *temp = headptr;
        while (temp->nextptr != NULL)
        {
            cout << temp->data << " ";
            temp = temp->nextptr;
        }
        cout << temp->data << " ";
        cout << endl;
    }
    // TASK # 1
    void insertAtBeginning(int val)
    {
        Snode *newnode = new Snode(val);
        if (headptr == NULL)
        {
            headptr = newnode;
            return;
        }
        newnode->nextptr = headptr;
        headptr = newnode;
    }
    void deleteAtPosition(int pos)
    {
        if (headptr == NULL)
        {
            cout << "List is empty! Nothing to delete." << endl;
            return;
        }

        if (pos < 0)
        {
            cout << "Invalid position!" << endl;
            return;
        }

        // Case 1: Delete the first node
        if (pos == 0)
        {
            Snode *temp = headptr;
            cout << "Deleted element: " << temp->data << endl;
            headptr = headptr->nextptr;
            delete temp;
            return;
        }

        // Case 2: Delete node at given position
        Snode *temp = headptr;
        Snode *prev = NULL;

        // Traverse to the desired node
        while (temp != NULL && pos > 0)
        {
            prev = temp;
            temp = temp->nextptr;
            pos--;
        }

        // If position is out of range
        if (temp == NULL)
        {
            cout << "Position out of range!" << endl;
            return;
        }

        // Unlink and delete node
        prev->nextptr = temp->nextptr;
        cout << "Deleted element: " << temp->data << endl;
        delete temp;
    }

    void deleteAtEnd()
    {
        if (headptr == NULL)
        {
            return;
        }
        Snode *temp = headptr;
        ;
        Snode *prev = NULL;
        while (temp->nextptr != NULL)
        {
            prev = temp;
            temp = temp->nextptr;
        }
        cout << "Element to be deleted:";
        temp->display();
        cout << endl;
        prev->nextptr = NULL;
        delete temp;
    }
    // TASK # 2
    void insertAtEnd(int val)
    {
        Snode *newnode = new Snode(val);
        if (headptr == NULL)
        {
            headptr = newnode;
            return;
        }
        Snode *temp = headptr;
        while (temp->nextptr != NULL)
        {
            temp = temp->nextptr;
        }
        temp->nextptr = newnode;
    }
    // TASK # 3
    void insertAtPosition(int val, int pos)
    {
        // Case 2: Insert at beginning
        if (pos == 0)
        {
            insertAtBeginning(val);
            return;
        }

        if (pos < 0)
        {
            cout << "Invalid position!" << endl;
            return;
        }
        Snode *temp = headptr;
        while (temp->nextptr != NULL && --pos > 0)
        {
            temp = temp->nextptr;
        }
        if (temp->nextptr == NULL)
        {
            cout << "Position out of range!" << endl;
            return;
        }

        Snode *newNode = new Snode(val);
        newNode->nextptr = temp->nextptr;
        temp->nextptr = newNode;
    }
    void deleteAtBeginning()
    {
        if (headptr == NULL)
        {
            return;
        }
        Snode *temp = headptr;
        headptr = headptr->nextptr;
        delete temp;
    }
    void deleteNodeByValue(int data)
{
    if (headptr == NULL)
    {
        cout << "List is empty! Nothing to delete." << endl;
        return;
    }

    Snode *temp = headptr;
    Snode *prev = NULL;

    // Case 1: Value is at head
    if (temp != NULL && temp->data == data)
    {
        cout << "Deleted element: " << temp->data << endl;
        headptr = temp->nextptr;
        delete temp;
        return;
    }

    // Case 2: Search for the node to delete
    while (temp != NULL && temp->data != data)
    {
        prev = temp;
        temp = temp->nextptr;
    }

    // Case 3: Value not found
    if (temp == NULL)
    {
        cout << "Value not found in the list!" << endl;
        return;
    }

    // Case 4: Delete the found node
    cout << "Deleted element: " << temp->data << endl;
    prev->nextptr = temp->nextptr;
    delete temp;
}

    void reverseList()
    {
        Snode *current = headptr;
        Snode *prev = NULL, *next = NULL;
        while (current != NULL)
        {
            next = current->nextptr;
            current->nextptr = prev;
            prev = current;
            current = next;
        }
        headptr = prev;
    }
    int front(){
        return headptr->data;
    }
    int end(){
        Snode *temp=headptr;
        while(temp->nextptr!=NULL)
        {temp=temp->nextptr;
        }
        return temp->data;

    }
    ~Slink()
    {
        Snode *temp;
        while (headptr != NULL)
        {
            temp = headptr;
            headptr = headptr->nextptr;
            delete temp;
        }
    }
};
class queue{
    Slink list;
    public:
    void enqueue(int val){
        list.insertAtEnd(val);
    }
    void dequeue(){
        list.deleteAtBeginning();
    }
int  front(){
        return list.front();

    }
    int back(){
        return list.end();
    }
};