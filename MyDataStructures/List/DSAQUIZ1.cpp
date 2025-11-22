#include <iostream>
using namespace std;
class Node
{
    int data;
    Node *nextptr;

public:
    Node(int val) : data(val), nextptr(nullptr) {}
    friend class List;
};
class List
{
    Node *headptr;

public:
    List() : headptr(nullptr)
    {
    }

    void insertAtBegining(int val)
    {
        Node *newNode = new Node(val);
        if (!headptr)
        {
            headptr = newNode;
            cout << "Operation Performed SuccessFully" << endl;
            return;
        }

        newNode->nextptr = headptr;
        headptr = newNode;

        cout << "Operation Performed SuccessFully" << endl;
    }

    void insertAtEnd(int val)
    {
        Node *newNode = new Node(val);
        if (!headptr)
        {
            headptr = newNode;
            cout << "Operation Performed SuccessFully" << endl;
            return;
        }
        Node *temp = headptr;
        while (temp->nextptr != nullptr)
        {
            temp = temp->nextptr;
        }
        temp->nextptr = newNode;
        cout << "Operation Performed SuccessFully" << endl;
    }

    void insertAtIndex(int val, int index)
    {
        if (index < 0)
        {
            cout << "Invalid Index" << endl;
            return;
        }
        if (index == 0 || !headptr)
        {
            Node *newNode = new Node(val);
            newNode->nextptr = headptr;
            headptr = newNode;
            return;
        }
        Node *temp = headptr;
        int i = 0;
        while (temp->nextptr != nullptr && i < index - 1)
        {
            temp = temp->nextptr;
            ++i;
        }
        if (i != index - 1)
        {
            cout << "Invalid Index" << endl;
            return;
        }
        Node *newNode = new Node(val);
        newNode->nextptr = temp->nextptr;
        temp->nextptr = newNode;
    }

    void display()
    {
        if (!headptr)
        {
            cout << "List: (empty)" << endl;
            return;
        }

        Node *temp = headptr;
        cout << "List: ";
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->nextptr;
        }
        cout << endl;
    }

    void deleteAtBegining()
    {
        if (!headptr)
        {
            cout << "List Empty" << endl;
            return;
        }
        Node *temp = headptr;
        headptr = headptr->nextptr;
        delete temp;
    }

    void deleteAtEnd()
    {
        if (!headptr)
        {
            cout << "List Empty" << endl;
            return;
        }
        if (!headptr->nextptr)
        {
            // only one node
            delete headptr;
            headptr = nullptr;
            return;
        }
        Node *temp = headptr;
        while (temp->nextptr->nextptr != nullptr)
        {
            temp = temp->nextptr;
        }
        cout << "Node Before the one to be deleted: " << temp->data << endl;
        delete temp->nextptr;
        temp->nextptr = nullptr;
    }

    void deleteAtIndex(int index)
    {
        if (!headptr || index < 0)
        {
            cout << "Invalid Index" << endl;
            return;
        }
        if (index == 0)
        {
            Node *temp = headptr;
            headptr = headptr->nextptr;
            delete temp;
            return;
        }
        Node *curr = headptr;
        Node *prev = nullptr;
        int i = 0;
        while (curr != nullptr && i < index)
        {
            prev = curr;
            curr = curr->nextptr;
            ++i;
        }
        if (!curr)
        {
            cout << "Invalid Index" << endl;
            return;
        }
        cout << "Data Node to be deleted: " << curr->data << endl;
        prev->nextptr = curr->nextptr;
        delete curr;
    }

    void reverse()
    {
        Node *prev = nullptr;
        Node *curr = headptr;
        Node *next = nullptr;

        while (curr != nullptr)
        {
            next = curr->nextptr;
            curr->nextptr = prev;
            prev = curr;
            curr = next;
        }
        headptr = prev;
    }

    void middleIndex()
    {
        if (!headptr)
        {
            cout << "List Empty" << endl;
            return;
        }
        Node *fast = headptr;
        Node *slow = headptr;
        while (fast && fast->nextptr)
        {
            fast = fast->nextptr->nextptr;
            slow = slow->nextptr;
        }
        cout << "Middle Index: " << slow->data << endl;
    }

    void plandromeCheck()
    {
        Node *fast = headptr;
        Node *slow = headptr;
        while (fast && fast->nextptr)
        {
            fast = fast->nextptr->nextptr;
            slow = slow->nextptr;
        }
        // reverse the second half
        Node *prev = nullptr;
        Node *curr = slow;
        Node *next = nullptr;
        while (curr)
        {
            next = curr->nextptr;
            curr->nextptr = prev;
            prev = curr;
            curr = next;
        }
        Node *left = headptr;
        Node *right = prev;
        while (right)
        {
            if (left->data != right->data)
            {
                cout << "Not a Plandrome" << endl;
                return;
            }
            left = left->nextptr;
            right = right->nextptr;
        }
        cout << "Plandrome" << endl;
    }
    void mergeTwoSortedArray(List l1, List l2)
    {
        Node *temp1 = l1.headptr;
        Node *temp2 = l2.headptr;
        Node *dummy = new Node(0);
        Node *tail = dummy;
        while (temp2 && temp1)
        {
            if (temp1->data < temp2->data)
            {
                tail->nextptr = temp1;
                temp1 = temp1->nextptr;
                tail = tail->nextptr;
            }
            else
            {
                tail->nextptr = temp2;
                temp2 = temp2->nextptr;
                tail = tail->nextptr;
            }
        }
        if (temp1)
            tail->nextptr = temp1;
        else
            tail->nextptr = temp2;

        headptr = dummy->nextptr;
        delete dummy;
    }
    bool cycleDetection()
    {
        Node *fast = headptr;
        Node *slow = headptr;
        while (fast && fast->nextptr)
        {
            fast = fast->nextptr->nextptr;
            slow = slow->nextptr;
            if (fast == slow)
                return true;
        }
        return false;
    }
    void skipNnodes(int N){
        while(headptr&&N--){
            headptr=headptr->nextptr;
        }
        cout<<"After skipping Nodes"<<headptr->data<<endl;
    }
    void removeDuplicates(){
        if(!headptr){
            cout<<"List Empty"<<endl;
            return;
        }
        Node* curr=headptr;
        while(curr&&curr->nextptr){
            if(curr->data==curr->nextptr->data){
                Node* temp=curr->nextptr;
                curr->nextptr=curr->nextptr->nextptr;
                delete temp;
            }else{
                curr=curr->nextptr;
            }
        }
    }
};
int main()
{
    List l1;
    l1.deleteAtBegining();
    l1.insertAtBegining(10);
    l1.display();
    l1.insertAtBegining(20);
    l1.display();

    l1.insertAtBegining(30);
    l1.insertAtBegining(40);
    l1.insertAtBegining(50);
    l1.insertAtBegining(60);
    l1.insertAtBegining(70);
    l1.display();
    l1.insertAtEnd(5);
    l1.display();
    l1.deleteAtEnd();
    l1.display();
    l1.deleteAtIndex(6);
    l1.display();
    l1.middleIndex();
    l1.reverse();
    l1.display();
    List l2;
    l2.insertAtBegining(75);

    l2.insertAtBegining(65);
    l2.insertAtBegining(55);
    l2.insertAtBegining(45);
    l2.insertAtBegining(35);
    l2.insertAtBegining(25);
    l2.insertAtBegining(15);
    l2.insertAtBegining(5);
    l2.display();
    List l3;
    l3.mergeTwoSortedArray(l1, l2);
   cout<<"l3"; l3.display();
    List l4;
    l4.insertAtEnd(1);
    l4.insertAtEnd(2);
    l4.insertAtEnd(3);  
    l4.insertAtEnd(2);
    l4.insertAtEnd(1);
    l4.plandromeCheck();
    List l5;
    l5.insertAtEnd(1);
    l5.insertAtEnd(2);
    l5.insertAtEnd(3);
    l5.insertAtEnd(4);
    l5.insertAtEnd(5);
    cout << "Cycle Detection: " << (l5.cycleDetection() ? "Cycle Present" : "No Cycle") << endl;
l3.skipNnodes(5);
l3.insertAtBegining(5);
l3.insertAtBegining(5);
l3.insertAtBegining(10);
l3.display();
l3.removeDuplicates();
l3.display();
    return 0;
}