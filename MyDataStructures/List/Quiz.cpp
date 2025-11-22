#include <iostream>
using namespace std;
class Snodev1
{
    friend class Slinkv1;
    int data;
    Snodev1 *next;

public:
    Snodev1(int val)
    {
        data = val;
        next = NULL;
    }
};
class Slinkv1
{
    Snodev1 *head;

public:
    Slinkv1()
    {
        head = NULL;
    }
    void insertAtStart(int val)
    {
        Snodev1 *newNode = new Snodev1(val);
        if (!head)
        {
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }
    void insertAtEnd(int val)
    {
        Snodev1 *newNode = new Snodev1(val);
        if (!head)
        {
            head = newNode;
            return;
        }
        Snodev1 *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void insertAtIndex(int val, int index)
    {
        if (index < 0)
        {
            cout << "Invalid index\n";
            return;
        }
        if (index == 0)
        {
            insertAtStart(val);
            return;
        }
        Snodev1 *newNode = new Snodev1(val);
        Snodev1 *temp = head;
        Snodev1 *prev = NULL;
        int count = 0;
        while (temp->next != NULL && count < index)
        {
            prev = temp;
            temp = temp->next;
            count++;
        }
        return;
        if (count >= index)
        {
            cout << "Index out of range\n";
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    void display()
    {
        if (!head)
        {
            cout << "List is empty\n";
            return;
        }
        Snodev1 *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    void deleteAtStart()
    {
        if (!head)
        {
            cout << "List is empty\n";
            return;
        }
        Snodev1 *toDelete = head;
        head = head->next;
        delete toDelete;
    }
    void deleteAtEnd()
    {
        if (!head)
        {
            cout << "List is empty\n";
            return;
        }
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }
        Snodev1 *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    void deleteAtIndex(int index)
    {
        if (index < 0)
        {
            cout << "Invalid index\n";
            return;
        }
        if (index == 0)
        {
            deleteAtStart();
            return;
        }
        Snodev1 *temp = head;
        int count = 0;
        while (temp->next != NULL && count < index - 1)
        {
            temp = temp->next;
            count++;
        }
        if (temp->next == NULL)
        {
            cout << "Index out of range\n";
            return;
        }
        temp->next = temp->next->next;
        delete temp->next;
    }
};
class CSnode
{
    friend class CSlink;
    CSnode *next;
    int data;

public:
    CSnode(int val)
    {
        next = NULL;
        data = val;
    }
};
class CSlink
{

    CSnode *tail;

public:
    CSlink()
    {
        tail = NULL;
    };

    void insertAtEnd(int val)
    {
        CSnode *newNode = new CSnode(val);
        if (!tail)
        {
            tail = newNode;
            newNode->next = newNode;
            return;
        }
        newNode->next = tail->next; // updating head
        tail->next = newNode;       // adding new node after tail
        tail = newNode;             // updating tail to new node
    }
    void insertAtStart(int val)
    {
        CSnode *newNode = new CSnode(val);
        if (!tail)
        {
            tail = newNode;
            newNode->next = newNode;
            return;
        }
        newNode->next = tail->next; // updating head
        tail->next = newNode;       // adding new node after tail
    }
    void insertAtIndex(int val, int index)
    {
        if (index < 0)
        {
            cout << "Invalid index\n";
            return;
        }
        if (index == 0)
        {
            insertAtStart(val);
            return;
        }
        CSnode *newNode = new CSnode(val);
        int count = -1;
        CSnode *temp = tail;
        while (temp->next != tail && count < index)
        {
            temp = temp->next;
            count++;
        }
        if (count > index)
        {
            cout << "Index out of range\n";
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    void display()
    {
        if (!tail)
        {
            cout << "List is empty\n";
            return;
        }
        CSnode *temp = tail->next; // head
        while(temp!= tail)
        {
            cout<<"Tail:"<<temp->data<<" ";
            temp = temp->next;
        }
        }
}

;
int main()
{
    CSlink clist;
    clist.insertAtEnd(10);
    clist.insertAtEnd(20);
    clist.insertAtStart(5);
    clist.insertAtIndex(15, 2);
    clist.display();

    return 0;
}
