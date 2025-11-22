#include <iostream>
using namespace std;

class Cnode
{
    friend class Clink;
    int data;
    Cnode *nextptr;

public:
    Cnode(int val) : data(val), nextptr(NULL) {}
};

class Clink
{
    Cnode *headptr;

public:
    Clink() : headptr(NULL) {}

    void insertAtBeginning(int val)
    {
        Cnode *newnode = new Cnode(val);

        if (headptr == NULL)
        {
            headptr = newnode;
            newnode->nextptr = headptr;
            return;
        }

        Cnode *temp = headptr;
        while (temp->nextptr != headptr)
            temp = temp->nextptr;

        newnode->nextptr = headptr;
        temp->nextptr = newnode;
        headptr = newnode;
    }

    void insertAtEnd(int val)
    {
        Cnode *newnode = new Cnode(val);

        if (headptr == NULL)
        {
            headptr = newnode;
            newnode->nextptr = headptr;
            return;
        }

        Cnode *temp = headptr;
        while (temp->nextptr != headptr)
            temp = temp->nextptr;

        temp->nextptr = newnode;
        newnode->nextptr = headptr;
    }

    void insertAtIndex(int val, int index)
    {
        if (index < 0)
        {
            cout << "Invalid index!" << endl;
            return;
        }

        if (index == 0)
        {
            insertAtBeginning(val);
            return;
        }

        Cnode *newnode = new Cnode(val);
        Cnode *temp = headptr;
        int count = 0;

        while (count < index - 1 && temp->nextptr != headptr)
        {
            temp = temp->nextptr;
            count++;
        }

        if (temp->nextptr == headptr)
        {
            insertAtEnd(val);
            return;
        }

        newnode->nextptr = temp->nextptr;
        temp->nextptr = newnode;
    }

    void deleteAtBeginning()
    {
        if (headptr == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }

        if (headptr->nextptr == headptr)
        {
            delete headptr;
            headptr = NULL;
            return;
        }

        Cnode *temp = headptr;
        Cnode *last = headptr;

        while (last->nextptr != headptr)
            last = last->nextptr;

        headptr = headptr->nextptr;
        last->nextptr = headptr;
        delete temp;
    }

    void deleteAtEnd()
    {
        if (headptr == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }

        if (headptr->nextptr == headptr)
        {
            delete headptr;
            headptr = NULL;
            return;
        }

        Cnode *temp = headptr;
        Cnode *prev = NULL;

        while (temp->nextptr != headptr)
        {
            prev = temp;
            temp = temp->nextptr;
        }

        prev->nextptr = headptr;
        delete temp;
    }

    void deleteByValue(int val)
    {
        if (headptr == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }

        if (headptr->data == val)
        {
            deleteAtBeginning();
            return;
        }

        Cnode *temp = headptr;
        Cnode *prev = NULL;

        do
        {
            prev = temp;
            temp = temp->nextptr;

            if (temp->data == val)
            {
                prev->nextptr = temp->nextptr;
                delete temp;
                return;
            }

        } while (temp != headptr);

        cout << "Value not found!" << endl;
    }

    void displayList()
    {
        if (headptr == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }

        Cnode *temp = headptr;
        cout << "Circular Linked List: ";
        do
        {
            cout << temp->data << " ";
            temp = temp->nextptr;
        } while (temp != headptr);
        cout << endl;
    }
    void traverseListAtIndex(int index)
    {
        Cnode *current = headptr;
        int count = 0;
        while (current->nextptr != headptr && count < index)
        {

            current = current->nextptr;
            count++;
        }
        if (current->nextptr == headptr && count < index)
        {
            cout << "Index out of range!" << endl;
        }
        else
        {
            cout << current->data << endl;
        }
    }
    void bubbleSortCircularLinkedList()
    {
        if (headptr == NULL || headptr->nextptr == headptr)
            return;

        bool swapped = true;
        while (swapped)
        {
            swapped = false;
            Cnode *current = headptr;
            while (current->nextptr != headptr)
            {
                if (current->data > current->nextptr->data)
                {
                    swap(current->data, current->nextptr->data);
                    swapped = true;
                }
                current = current->nextptr;
            }
        }
    }
    void catenateCircularLinkedList(Clink &otherList)
    {
        if (headptr == NULL)
        {
            headptr = otherList.headptr;
            return;
        }
        if (otherList.headptr == NULL)
        {
            return;
        }

        Cnode *temp1 = headptr;
        while (temp1->nextptr != headptr)
        {
            temp1 = temp1->nextptr;
        }

        Cnode *temp2 = otherList.headptr;
        while (temp2->nextptr != otherList.headptr)
        {
            temp2 = temp2->nextptr;
        }

        temp1->nextptr = otherList.headptr;
        temp2->nextptr = headptr;
    }
    void nthNodeFromEnd(int n)
    {
        if (headptr == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }

        Cnode *mainPtr = headptr;
        Cnode *refPointer = headptr;
        int count = 0;

        while (count < n)
        {
            if (refPointer->nextptr == headptr)
            {
                cout << "List has less than " << n << " nodes." << endl;
                return;
            }
            refPointer = refPointer->nextptr;
            count++;
        }

        while (refPointer != headptr)
        {
            mainPtr = mainPtr->nextptr;
            refPointer = refPointer->nextptr;
        }

        cout << "The " << n << "th node from end is: " << mainPtr->data << endl;
    }
    void middleFirstInEvenCaseNode()
    {
        if (headptr == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }

        Cnode *slow = headptr;
        Cnode *fast = headptr;

        while (fast->nextptr != headptr && fast->nextptr->nextptr != headptr)
        {
            slow = slow->nextptr;
            fast = fast->nextptr->nextptr;
        }

        cout << "Middle node is: " << slow->data << endl;
    }
    void middleSecondInEvenCaseNode()
    {
        if (headptr == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }

        Cnode *slow = headptr;
        Cnode *fast = headptr->nextptr;

        while (fast->nextptr != headptr && fast != headptr)
        {
            slow = slow->nextptr;
            fast = fast->nextptr;
        }

        cout << "Middle node is: " << slow->data << endl;
    }
    void removeCircularLoop()
    {
        if (headptr == NULL)
            return;

        bool flag = false;
        Cnode *slow = headptr;
        Cnode *fast = headptr;

        while (fast != headptr&&fast->nextptr != headptr)
        {
            slow = slow->nextptr;
            fast = fast->nextptr->nextptr;

            if (slow == fast)
            {
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            return;
        }
        slow = headptr;
        Cnode *prev = NULL;
        while (slow !=fast)
        {
            prev = fast;
            slow = slow->nextptr;
            fast = fast->nextptr;
        }
        prev->nextptr = NULL;
    }
    void displayLinkedList()
    {
        if (headptr == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }

        Cnode *temp = headptr;
        cout << "Linked List: ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->nextptr;
        }
        cout << endl;
    }
};
int main()
{
    Clink list;
    // initialize list with several values using different insert methods
    list.insertAtEnd(15);
    list.insertAtEnd(25);
    list.insertAtBeginning(5);
    list.insertAtIndex(12, 2); // insert 12 at index 2
    list.displayList();
    cout << "First middle node in even case:" << endl;
    list.middleFirstInEvenCaseNode();
    cout << "Second middle node in even case:" << endl;

    list.middleSecondInEvenCaseNode();
    list.removeCircularLoop();
    list.displayLinkedList();

}
