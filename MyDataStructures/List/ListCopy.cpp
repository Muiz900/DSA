#include <iostream>
using namespace std;
class Snode
{
    int val;
    Snode *nextptr;
    friend class Slink;

public:
    Snode(int val) : val(val), nextptr(NULL)
    {
    }
};
class Slink
{
    Snode *headptr;

public:
    Slink() : headptr(NULL)
    {
    }
    void insertAtStart(int val)
    {
        Snode *newNode = new Snode(val);
        if (headptr == NULL)
        {
            headptr = newNode;
            return;
        }
        newNode->nextptr = headptr;
        headptr = newNode;
    }
    void insertAtEnd(int val)
    {
        Snode *newNode = new Snode(val);
        if (headptr == NULL)
        {
            headptr = newNode;
            return;
        }
        Snode *temp = headptr;
        while (temp->nextptr == NULL)
        {
            temp = temp->nextptr;
        }
        temp->nextptr = newNode;
    }
    void insertAtIndex(int val, int index)
    {
        if (index < 0)
        {
            cout << "Invalid Position" << endl;
            return;
        }
        if (index == 0)
        {
            Snode *newNode = new Snode(val);
            newNode->nextptr = headptr;
            headptr = newNode;
            return;
        }
        Snode *temp = headptr;
        Snode *prev = NULL;
        while (temp->nextptr != NULL && --index > 0)
        {
            prev = temp;
            temp = temp->nextptr;
        }
        if (temp == NULL)
        {
            cout << "Position out of Index" << endl;
            return;
        }
        Snode *newNode = new Snode(val);
        prev->nextptr = newNode;
        newNode->nextptr = temp;
    }

    void deleteAtBeginning()
    {
        if (headptr == NULL)
        {
            cout << "Empty list.Nothing to delete" << endl;
            return;
        }
        Snode *temp = headptr;
        headptr = headptr->nextptr;
        delete temp;
    }
    void deleteAtEnd()
    {
        if (headptr == NULL)
        {
            cout << "Empty list.Nothing to delete" << endl;
            return;
        }
        Snode *prev = NULL;
        Snode *temp = headptr;
        while (temp->nextptr != NULL)
        {
            prev = temp;
            temp = temp->nextptr;
        }
        prev->nextptr = NULL;
        delete temp;
    }
    void deleteByData(int data)
    {

        if (headptr == NULL)
        {
            cout << "Empty list.Nothing to delete" << endl;
            return;
        }
        Snode *temp = headptr;
        Snode *prev = NULL;
        while (temp != NULL && temp->val != data)
        {
            prev = temp;
            temp = temp->nextptr;
        }
        if (temp == NULL)
        {
            cout << "Data not found" << endl;
        }

        prev->nextptr = temp->nextptr;
        delete temp;
    }
    void deleteByIndex(int index)
    {

        if (headptr == NULL)
        {
            cout << "Empty list.Nothing to delete" << endl;
            return;
        }
        if (index == 0)
        {
            Snode *temp = headptr;
            headptr = headptr->nextptr;
            delete temp;
            return;
        }
        Snode *temp = headptr;
        Snode *prev = NULL;
        while (temp!= NULL && index-- > 0)
        {
            prev = temp;
            temp = temp->nextptr;
        }
        if (temp == NULL)
        {
            cout << "Invalid Index" << endl;
            return;
        }
        prev->nextptr = temp->nextptr;
        delete temp;
    }
};
