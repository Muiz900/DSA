// Include input/output stream library
#include <iostream>
// Using standard namespace
using namespace std;

// Definition of node class for circular linked list
class Cnode
{
    friend void swap(Cnode *, Cnode *);
    // Make Clink class a friend to access private members
    friend class Clink;
    // Data member to store value
    int data;
    // Pointer to next node
    Cnode *nextptr;

public:
    // Constructor to initialize node with value and NULL next pointer
    Cnode(int val) : data(val), nextptr(NULL) {}
};

// Definition of circular linked list class
class Clink
{
    // Pointer to the first node of the list
    Cnode *headptr;

public:
    // Constructor to initialize empty list
    Clink() : headptr(NULL) {}

    // Function to insert node at the beginning of list
    void insertAtBeginning(int val)
    {
        // Create new node with given value
        Cnode *newnode = new Cnode(val);

        // If list is empty
        if (headptr == NULL)
        {
            // Make head point to new node
            headptr = newnode;
            // Make new node point to itself
            newnode->nextptr = headptr;
            return;
        }

        // Temporary pointer to traverse list
        Cnode *temp = headptr;
        // Traverse to last node
        while (temp->nextptr != headptr)
            temp = temp->nextptr;

        // Make new node point to current head
        newnode->nextptr = headptr;
        // Make last node point to new node
        temp->nextptr = newnode;
        // Make new node the head
        headptr = newnode;
    }

    // Function to insert node at the end of list
    void insertAtEnd(int val)
    {
        // Create new node with given value
        Cnode *newnode = new Cnode(val);

        // If list is empty
        if (headptr == NULL)
        {
            // Make head point to new node
            headptr = newnode;
            // Make new node point to itself
            newnode->nextptr = headptr;
            return;
        }

        // Temporary pointer to traverse list
        Cnode *temp = headptr;
        // Traverse to last node
        while (temp->nextptr != headptr)
            temp = temp->nextptr;

        // Make last node point to new node
        temp->nextptr = newnode;
        // Make new node point to head
        newnode->nextptr = headptr;
    }

    // Function to insert node at given index
    void insertAtIndex(int val, int index)
    {
        // Check for invalid index
        if (index < 0)
        {
            cout << "Invalid index!" << endl;
            return;
        }

        // If index is 0, insert at beginning
        if (index == 0)
        {
            insertAtBeginning(val);
            return;
        }

        // Create new node with given value
        Cnode *newnode = new Cnode(val);
        // Temporary pointer to traverse list
        Cnode *temp = headptr;
        // Counter for current position
        int count = 0;

        // Traverse until one position before desired index
        while (count < index - 1 && temp->nextptr != headptr)
        {
            temp = temp->nextptr;
            count++;
        }

        // If reached end, insert at last
        if (temp->nextptr == headptr)
        {
            insertAtEnd(val);
            return;
        }

        // Connect new node to next node
        newnode->nextptr = temp->nextptr;
        // Connect current node to new node
        temp->nextptr = newnode;
    }

    // Function to delete node from beginning
    void deleteAtBeginning()
    {
        // If list is empty
        if (headptr == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }

        // If only one node exists
        if (headptr->nextptr == headptr)
        {
            // Delete the node
            delete headptr;
            // Set head to NULL
            headptr = NULL;
            return;
        }

        // Temporary pointer to store head
        Cnode *temp = headptr;
        // Pointer to find last node
        Cnode *last = headptr;

        // Find last node
        while (last->nextptr != headptr)
            last = last->nextptr;

        // Move head to next node
        headptr = headptr->nextptr;
        // Make last node point to new head
        last->nextptr = headptr;
        // Delete old head
        delete temp;
    }

    // Function to delete node from end
    void deleteAtEnd()
    {
        // If list is empty
        if (headptr == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }

        // If only one node exists
        if (headptr->nextptr == headptr)
        {
            // Delete the node
            delete headptr;
            // Set head to NULL
            headptr = NULL;
            return;
        }

        // Temporary pointer to traverse list
        Cnode *temp = headptr;
        // Pointer to keep track of previous node
        Cnode *prev = NULL;

        // Traverse to last node
        while (temp->nextptr != headptr)
        {
            prev = temp;
            temp = temp->nextptr;
        }

        // Make second-last node point to head
        prev->nextptr = headptr;
        // Delete last node
        delete temp;
    }

    // Function to delete node with given value
    void deleteByValue(int val)
    {
        // If list is empty
        if (headptr == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }

        // If value is in head node
        if (headptr->data == val)
        {
            deleteAtBeginning();
            return;
        }

        // Temporary pointer to traverse list
        Cnode *temp = headptr;
        // Pointer to keep track of previous node
        Cnode *prev = NULL;

        // Traverse list to find value
        do
        {
            prev = temp;
            temp = temp->nextptr;

            // If value found
            if (temp->data == val)
            {
                // Remove node from list
                prev->nextptr = temp->nextptr;
                // Delete node
                delete temp;
                return;
            }

        } while (temp != headptr);

        // If value not found
        cout << "Value not found!" << endl;
    }

    // Function to display all nodes in list
    void displayList()
    {
        // If list is empty
        if (headptr == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }

        // Temporary pointer to traverse list
        Cnode *temp = headptr;
        cout << "Circular Linked List: ";
        // Print each node's data
        do
        {
            cout << temp->data << " ";
            temp = temp->nextptr;
        } while (temp != headptr);
        cout << endl;
    }
    void bubbleSort()
    {
        if (headptr == NULL || headptr->nextptr == headptr)
            return; // empty list
        Cnode *temp = headptr;
        while (temp->nextptr != headptr)
        {
            Cnode *next = temp->nextptr;
            while (next != headptr)
            {
                if (temp->data > next->data)
                {
                    swap(temp, next);
                }
                next = next->nextptr;
            }
            temp = temp->nextptr;
        }
    }
    void selectionSort()
    {
        if (headptr == NULL || headptr->nextptr == headptr)
            return; // List is empty or has only one element
        Cnode *temp = headptr;
        while (temp->nextptr != headptr)
        {
            Cnode *min = temp;
            Cnode *next = temp->nextptr;
            while (next != headptr)
            {
                if (next->data < min->data)
                {
                    min = next;
                }
                next = next->nextptr;
            }
            temp = temp->nextptr;
            swap(temp, min);
        }
    }
};
void swap(Cnode *a, Cnode *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}
int main()
{
    Clink list;

    // Test Case: Multiple elements in random order
    list.insertAtEnd(4);
    list.insertAtEnd(2);
    list.insertAtEnd(9);
    list.insertAtEnd(1);
    list.insertAtEnd(5);

    cout << "Original list:" << endl;
    list.displayList();

    // Bubble Sort
    list.bubbleSort();
    cout << "After Bubble Sort:" << endl;
    list.displayList();

    // Reset list to original order
    list.deleteAtBeginning();
    list.deleteAtBeginning();
    list.deleteAtBeginning();
    list.deleteAtBeginning();
    list.deleteAtBeginning();

    list.insertAtEnd(4);
    list.insertAtEnd(2);
    list.insertAtEnd(9);
    list.insertAtEnd(1);
    list.insertAtEnd(5);

    // Selection Sort
    list.selectionSort();
    cout << "After Selection Sort:" << endl;
    list.displayList();

    return 0;
}
