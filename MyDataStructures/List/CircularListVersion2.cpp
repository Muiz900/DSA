#include <iostream>     // Include input/output stream library
using namespace std;    // Use standard namespace

class Cnode           // Define a class for circular linked list node
{
    friend class Clink;    // Allow Clink class to access private members
    int data;             // Store the node's data
    Cnode *nextptr;       // Pointer to the next node

public:
    Cnode(int val) : data(val), nextptr(NULL) {}    // Constructor initializing data and nextptr
};

class Clink           // Define the circular linked list class
{
    Cnode *tailptr;       // Pointer to the last node of the list

public:
    Clink() : tailptr(NULL) {}    // Constructor initializing empty list

    // Insert at Beginning function
    void insertAtBeginning(int val)
    {
        Cnode *newnode = new Cnode(val);    // Create a new node with given value

        if (tailptr == NULL)    // If list is empty
        {
            tailptr = newnode;    // Set tail to new node
            newnode->nextptr = newnode;    // Make it point to itself (circular)
            return;
        }

        newnode->nextptr = tailptr->nextptr;    // New node points to old head
        tailptr->nextptr = newnode;             // Tail points to new head
    }

    // Insert at End function
    void insertAtEnd(int val)
    {
        Cnode *newnode = new Cnode(val);    // Create a new node

        if (tailptr == NULL)    // If list is empty
        {
            tailptr = newnode;    // Set tail to new node
            newnode->nextptr = newnode;    // Make it circular
            return;
        }

        newnode->nextptr = tailptr->nextptr;    // New node points to head
        tailptr->nextptr = newnode;             // Old tail points to new node
        tailptr = newnode;                      // Update tail to new node
    }

    // Insert at specific index function
    void insertAtIndex(int val, int index)
    {
        if (index < 0)    // Check for invalid index
        {
            cout << "Invalid index!" << endl;
            return;
        }

        if (tailptr == NULL || index == 0)    // Handle empty list or insertion at beginning
        {
            insertAtBeginning(val);
            return;
        }

        Cnode *newnode = new Cnode(val);    // Create new node
        Cnode *temp = tailptr->nextptr;     // Start from head
        int count = 0;                      // Counter for position

        while (count < index - 1 && temp != tailptr)    // Find insertion position
        {
            temp = temp->nextptr;
            count++;
        }

        newnode->nextptr = temp->nextptr;    // Connect new node
        temp->nextptr = newnode;             // Update links

        if (temp == tailptr)    // If inserting at end
            tailptr = newnode;  // Update tail pointer
    }

    // Delete from Beginning function
    void deleteAtBeginning()
    {
        if (tailptr == NULL)    // Check if list is empty
        {
            cout << "List is empty!" << endl;
            return;
        }

        Cnode *head = tailptr->nextptr;    // Get head node

        if (head == tailptr)    // If only one node exists
        {
            delete tailptr;     // Delete the node
            tailptr = NULL;     // Reset tail pointer
            return;
        }

        tailptr->nextptr = head->nextptr;    // Update tail's next to skip head
        delete head;                         // Delete head node
    }

    // Delete from End function
    void deleteAtEnd()
    {
        if (tailptr == NULL)    // Check if list is empty
        {
            cout << "List is empty!" << endl;
            return;
        }

        Cnode *head = tailptr->nextptr;    // Get head node

        if (head == tailptr)    // If only one node exists
        {
            delete tailptr;     // Delete the node
            tailptr = NULL;     // Reset tail pointer
            return;
        }

        Cnode *temp = head;    // Start from head
        while (temp->nextptr != tailptr)    // Find node before tail
            temp = temp->nextptr;

        temp->nextptr = tailptr->nextptr;    // Connect to head
        delete tailptr;                      // Delete tail node
        tailptr = temp;                      // Update tail pointer
    }

    // Delete node with specific value
    void deleteByValue(int val)
    {
        if (tailptr == NULL)    // Check if list is empty
        {
            cout << "List is empty!" << endl;
            return;
        }

        Cnode *head = tailptr->nextptr;    // Get head node

        if (head == tailptr && head->data == val)    // If single node with matching value
        {
            delete tailptr;    // Delete the node
            tailptr = NULL;    // Reset tail pointer
            return;
        }

        Cnode *prev = tailptr;    // Track previous node
        Cnode *curr = head;       // Track current node

        do
        {
            if (curr->data == val)    // If value found
            {
                prev->nextptr = curr->nextptr;    // Update links

                if (curr == tailptr)    // If deleting tail
                    tailptr = prev;

                if (curr == head)       // If deleting head
                    tailptr->nextptr = curr->nextptr;

                delete curr;    // Delete the node
                return;
            }

            prev = curr;              // Move previous pointer
            curr = curr->nextptr;     // Move current pointer

        } while (curr != tailptr->nextptr);    // Continue until back to start

        cout << "Value not found!" << endl;    // Value wasn't found in list
    }

    // Display all elements in the list
    void displayList()
    {
        if (tailptr == NULL)    // Check if list is empty
        {
            cout << "List is empty!" << endl;
            return;
        }

        Cnode *temp = tailptr->nextptr;    // Start from head
        cout << "Circular Linked List: ";   // Output header

        do
        {
            cout << temp->data << " ";     // Print current node's data
            temp = temp->nextptr;          // Move to next node
        } while (temp != tailptr->nextptr);    // Continue until back to start

        cout << endl;    // New line after printing list
    }
};
