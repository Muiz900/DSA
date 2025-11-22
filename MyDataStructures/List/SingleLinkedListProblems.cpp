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
    bool hasCycle()
    {
        Snode *slow = headptr;
        Snode *fast = headptr;

        while (fast != NULL && fast->nextptr != NULL)
        {
            slow = slow->nextptr;
            fast = fast->nextptr->nextptr;

            if (slow == fast)
            {
                return true; // Cycle detected
            }
        }
        return false; // No cycle
    }
    void searchByValue(int data)
    {
        Snode *temp = headptr;
        int index = 0;
        while (temp != NULL)
        {
            if (temp->data == data)
            {
                cout << "Value " << data << " found at index " << index << endl;
                return;
            }
            temp = temp->nextptr;
            index++;
        }
        cout << "Value " << data << " not found in the list!" << endl;
    }
    void NthNodeFromEnd(int n)
    {
        Snode *mainPtr = headptr;
        Snode *refPointer = headptr;
        int count = 0;
        while (count < n)
        {
            if (refPointer == NULL)
            {
                cout << "List has less than " << n << " nodes." << endl;
                return;
            }
            refPointer = refPointer->nextptr;
            count++;
        }
        while (refPointer != NULL)
        {
            mainPtr = mainPtr->nextptr;
            refPointer = refPointer->nextptr;
        }
        cout << "The " << n << "th node from end is: " << mainPtr->data << endl;
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
void MergeList(Slink *&list1, Slink *&list2)
{
    Snode *temp1 = list1->headptr;
    Snode *temp2 = list2->headptr;
    Snode *tail = NULL;
    headptr = NULL;

    while (temp1 != NULL && temp2 != NULL)
    {
        int val;
        if (temp1->data < temp2->data)
        {
            val = temp1->data;
            temp1 = temp1->nextptr;
        }
        else
        {
            val = temp2->data;
            temp2 = temp2->nextptr;
        }

        // Create a new node for this list
        Snode *newNode = new Snode(val);

        if (headptr == NULL)
        {
            headptr = newNode;
            tail = newNode;
        }
        else
        {
            tail->nextptr = newNode;
            tail = tail->nextptr;
        }
    }

    // Add remaining nodes (if any)
    while (temp1 != NULL)
    {
        Snode *newNode = new Snode(temp1->data);
        if (headptr == NULL)
        {
            headptr = newNode;
            tail = newNode;
        }
        else
        {
            tail->nextptr = newNode;
            tail = tail->nextptr;
        }
        temp1 = temp1->nextptr;
    }

    while (temp2 != NULL)
    {
        Snode *newNode = new Snode(temp2->data);
        if (headptr == NULL)
        {
            headptr = newNode;
            tail = newNode;
        }
        else
        {
            tail->nextptr = newNode;
            tail = tail->nextptr;
        }
        temp2 = temp2->nextptr;
    }
}

    void reverseList(){
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
        cout<<"Previous List Pointer"<<prev->data<<endl;
    }
    bool isPalindrome()
    {
        Snode *fast = headptr;
        Snode *slow = headptr;
        Snode *prev = NULL;
        Snode *next = NULL;
        while (fast != NULL && fast->nextptr != NULL)
        {
            fast = fast->nextptr->nextptr;
            slow = slow->nextptr;
        }
        while (slow != NULL)
        {
            next=slow->nextptr;
            slow->nextptr=prev;
            prev=slow;
            slow=next;
        }
        Snode *left = headptr;
        Snode *right = prev;
        while (right != NULL&&left!=NULL)
        {
            if (left->data != right->data)
            {
                return false;
            }
            left = left->nextptr;
            right = right->nextptr;
        }

        return true;
    }
    void SortLinkedListUsingBubbleSort(){
        if( headptr ==NULL||headptr->nextptr==NULL){
            return;}
            bool swapped=true;
            while(swapped){
                swapped=false;
                Snode *temp=headptr;
                while(temp->nextptr!=NULL){
                    if(temp->data>temp->nextptr->data){
                        swap(temp->data,temp->nextptr->data);
                        swapped=true;
                    }
                    temp=temp->nextptr;
                }

            }
    }
    ~Slink(){
        Snode *temp;
        while (headptr != NULL)
        {
            temp = headptr;
            headptr = headptr->nextptr;
            delete temp;
        }
    }
}
;
int main()
{
    Slink list;

    cout << "Insert at beginning: 10, 20, 30, 40" << endl;
    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.insertAtBeginning(30);
    list.insertAtBeginning(40);
    cout << "List after insertAtBeginning: ";
    list.displayList();

    cout << "Insert 5 at end" << endl;
    list.insertAtEnd(5);
    cout << "List after insertAtEnd: ";
    list.displayList();

    cout << "Delete at end" << endl;
    list.deleteAtEnd();
    cout << "List after deleteAtEnd: ";
    list.displayList();

    cout << "Insert 99 at position 2" << endl;
    list.insertAtPosition(99, 2);
    cout << "List after insertAtPosition: ";
    list.displayList();

    cout << "Delete element at position 2" << endl;
    list.deleteAtPosition(2);
    cout << "List after deleteAtPosition: ";
    list.displayList();

    cout << "Delete at beginning" << endl;
    list.deleteAtBeginning();
    cout << "List after deleteAtBeginning: ";
    list.displayList();

    cout << "Delete node by value 10" << endl;
    list.deleteNodeByValue(10);
    cout << "List after deleteNodeByValue: ";
    list.displayList();

    cout << "Add nodes 100 and 110 at end" << endl;
    list.insertAtEnd(100);
    list.insertAtEnd(110);
    cout << "List now: ";
    list.displayList();

    cout << "Search for value 100" << endl;
    list.searchByValue(100);

    cout << "Get 2nd node from end" << endl;
    list.NthNodeFromEnd(2);

    cout << "Reverse the list" << endl;
    list.reverseList();
    cout << "List after reverse: ";
    list.displayList();

    cout << "Check for cycle in the list" << endl;
    cout << "Has cycle? " << (list.hasCycle() ? "Yes" : "No") << endl;

    cout << "Prepare two sorted lists l1 and l2 for merging" << endl;
    Slink l1;
    l1.insertAtEnd(1);
    l1.insertAtEnd(3);
    l1.insertAtEnd(5);

    Slink l2;
    l2.insertAtEnd(2);
    l2.insertAtEnd(4);
    l2.insertAtEnd(6);

    Slink merged;
    Slink *p1 = &l1;
    Slink *p2 = &l2;
    merged.MergeList(p1, p2);
    cout << "Merged list: ";
    merged.displayList();

    // call SortLinkedList (no-op in current implementation)
    merged.SortLinkedListUsingBubbleSort();
    cout << "After sort (no-op): ";
    merged.displayList();
}