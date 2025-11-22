#include <iostream>  // include I/O stream library for cout/cin
using namespace std; // bring std namespace into global scope

class Cnode             // declare node class for circular linked list
{                       // start of Cnode class
    friend class Clink; // allow Clink class to access private members of Cnode
    int data;           // store integer data in the node
    Cnode *nextptr;     // pointer to next node in the list

public:                                          // public access specifier
    Cnode(int val) : data(val), nextptr(NULL) {} // constructor: initialize data and next pointer
}; // end of Cnode class

class Clink         // declare circular linked list class
{                   // start of Clink class
    Cnode *headptr; // pointer to first node
    Cnode *tailptr; // pointer to last node (whose next points to head)

public:                                       // public access specifier
    Clink() : headptr(NULL), tailptr(NULL) {} // constructor: initialize empty list

    // ➤ Insert at Beginning
    void insertAtBeginning(int val)      // method to insert a new node at the beginning
    {                                    // start of insertAtBeginning
        Cnode *newnode = new Cnode(val); // allocate and construct a new node

        if (headptr == NULL)             // if list is empty
        {                                // start if empty
            headptr = tailptr = newnode; // head and tail both point to new node
            tailptr->nextptr = headptr;  // make the link circular by pointing tail->next to head
            return;                      // done
        } // end if empty

        newnode->nextptr = headptr; // new node points to old head
        headptr = newnode;          // update head to new node
        tailptr->nextptr = headptr; // maintain circular link by updating tail->next
    } // end of insertAtBeginning

    // ➤ Insert at End
    void insertAtEnd(int val)            // method to insert a new node at the end
    {                                    // start of insertAtEnd
        Cnode *newnode = new Cnode(val); // allocate and construct a new node

        if (headptr == NULL)             // if list is empty
        {                                // start if empty
            headptr = tailptr = newnode; // head and tail both point to new node
            tailptr->nextptr = headptr;  // circular link: tail->next -> head
            return;                      // done
        } // end if empty

        tailptr->nextptr = newnode; // old tail points to the new node
        tailptr = newnode;          // update tail to the new node
        tailptr->nextptr = headptr; // keep the list circular by pointing new tail->next to head
    } // end of insertAtEnd

    // ➤ Insert at a given index (0-based)
    void insertAtIndex(int val, int index)    // insert a node at specified 0-based index
    {                                         // start of insertAtIndex
        if (index < 0)                        // invalid negative index check
        {                                     // start if invalid
            cout << "Invalid index!" << endl; // print error message
            return;                           // exit
        } // end if invalid

        if (index == 0 || headptr == NULL) // if inserting at head or list is empty
        {                                  // start condition
            insertAtBeginning(val);        // reuse insertAtBeginning logic
            return;                        // done
        } // end condition

        Cnode *newnode = new Cnode(val); // allocate new node
        Cnode *temp = headptr;           // temp pointer to traverse list starting at head
        int count = 0;                   // counter to track position

        while (count < index - 1 && temp->nextptr != headptr) // traverse until position before index or full cycle
        {                                                     // start while
            temp = temp->nextptr;                             // move to next node
            count++;                                          // increment position counter
        } // end while

        newnode->nextptr = temp->nextptr; // link new node to next node at position
        temp->nextptr = newnode;          // insert new node after temp

        // If inserted after tail, update tail
        if (temp == tailptr)   // if insertion point was tail
            tailptr = newnode; // update tail to new node
    } // end of insertAtIndex

    // ➤ Delete from Beginning
    void deleteAtBeginning()                  // delete the node at the beginning
    {                                         // start of deleteAtBeginning
        if (headptr == NULL)                  // if list is empty
        {                                     // start if empty
            cout << "List is empty!" << endl; // notify user
            return;                           // nothing to delete
        } // end if empty

        if (headptr == tailptr)       // if only one node exists
        {                             // start single-node case
            delete headptr;           // free the single node
            headptr = tailptr = NULL; // reset pointers to null
            return;                   // done
        } // end single-node case

        Cnode *temp = headptr;      // store old head to delete
        headptr = headptr->nextptr; // move head to next node
        tailptr->nextptr = headptr; // update tail->next to new head to remain circular
        delete temp;                // free old head node
    } // end of deleteAtBeginning

    // ➤ Delete from End
    void deleteAtEnd()                        // delete the node at the end
    {                                         // start of deleteAtEnd
        if (headptr == NULL)                  // if list is empty
        {                                     // start if empty
            cout << "List is empty!" << endl; // notify user
            return;                           // nothing to delete
        } // end if empty

        if (headptr == tailptr)       // if only one node exists
        {                             // start single-node case
            delete headptr;           // free the single node
            headptr = tailptr = NULL; // reset pointers
            return;                   // done
        } // end single-node case

        Cnode *temp = headptr;           // temp to find node before tail
        while (temp->nextptr != tailptr) // traverse until the node before tail
            temp = temp->nextptr;        // move to next node

        delete tailptr;             // delete current tail
        tailptr = temp;             // update tail to previous node
        tailptr->nextptr = headptr; // maintain circular link: new tail->next -> head
    } // end of deleteAtEnd

    // ➤ Delete by Value
    void deleteByValue(int val)               // delete first occurrence of node with given value
    {                                         // start of deleteByValue
        if (headptr == NULL)                  // if list is empty
        {                                     // start if empty
            cout << "List is empty!" << endl; // notify user
            return;                           // nothing to delete
        } // end if empty

        // if only one node
        if (headptr == tailptr && headptr->data == val) // check single node matches value
        {                                               // start single-node-match
            delete headptr;                             // delete node
            headptr = tailptr = NULL;                   // reset pointers
            return;                                     // done
        } // end single-node-match

        // if deleting head
        if (headptr->data == val) // if head contains the value
        {                         // start head-delete
            deleteAtBeginning();  // reuse deleteAtBeginning
            return;               // done
        } // end head-delete

        Cnode *prev = headptr;          // previous pointer starts at head
        Cnode *curr = headptr->nextptr; // current pointer starts at second node

        while (curr != headptr)                // traverse until back to head (full cycle)
        {                                      // start while
            if (curr->data == val)             // if current node matches value
            {                                  // start match
                prev->nextptr = curr->nextptr; // unlink current node

                if (curr == tailptr) // if current is tail
                    tailptr = prev;  // update tail to previous node

                delete curr; // free the matched node
                return;      // done
            } // end match
            prev = curr;          // move prev forward
            curr = curr->nextptr; // move curr forward
        } // end while

        cout << "Value not found!" << endl; // value was not present in list
    } // end of deleteByValue

    // ➤ Display the list
    void displayList()                        // print the elements of the list
    {                                         // start of displayList
        if (headptr == NULL)                  // if list is empty
        {                                     // start if empty
            cout << "List is empty!" << endl; // notify user
            return;                           // nothing to display
        } // end if empty

        Cnode *temp = headptr;            // temp pointer to iterate from head
        cout << "Circular Linked List: "; // header output

        do                             // iterate at least once
        {                              // start do-while
            cout << temp->data << " "; // print current node's data
            temp = temp->nextptr;      // move to next node
        } while (temp != headptr); // continue until back to head

        cout << endl; // newline after printing list
    } // end of displayList

    // ➤ Count the number of nodes
    int countNodes()         // return the number of nodes in the list
    {                        // start of countNodes
        if (headptr == NULL) // if list is empty
            return 0;        // count is zero

        int count = 0;            // initialize counter
        Cnode *temp = headptr;    // temp pointer to traverse list
        do                        // iterate through list once circularly
        {                         // start do-while
            count++;              // increment for each node
            temp = temp->nextptr; // move to next node
        } while (temp != headptr); // stop when back at head

        return count; // return total count
    } // end of countNodes

    // ➤ Search for a value
    bool search(int val)     // search for value in list, return true if found
    {                        // start of search
        if (headptr == NULL) // if list is empty
            return false;    // nothing to find

        Cnode *temp = headptr;     // temp pointer to traverse list
        do                         // iterate circularly
        {                          // start do-while
            if (temp->data == val) // if current node matches value
                return true;       // found, return true

            temp = temp->nextptr; // move to next node
        } while (temp != headptr); // continue until back to head

        return false; // not found after full traversal
    } // end of search
}; // end of Clink class
