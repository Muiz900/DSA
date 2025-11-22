#include <iostream>
using namespace std;

// ---------------------------------------------
// Node class for Doubly Circular Linked List
// ---------------------------------------------
class Dnode {
    friend class DClist;
    int data;         // Value stored in the node
    Dnode *next;      // Pointer to the next node
    Dnode *prev;      // Pointer to the previous node

public:
    Dnode(int val) : data(val), next(NULL), prev(NULL) {}
};

// ---------------------------------------------
// Doubly Circular Linked List Class
// ---------------------------------------------
class DClist {
    Dnode *head;  // Points to the first node in the list

public:
    DClist() : head(NULL) {}

    // ---------------------------------------------
    // Insert a node at the end (tail)
    // ---------------------------------------------
    void insertAtEnd(int val) {
        Dnode *newNode = new Dnode(val);

        // If list is empty
        if (!head) {
            head = newNode;
            head->next = head;
            head->prev = head;
            return;
        }

        Dnode *tail = head->prev;   // Last node before head
        tail->next = newNode;       // Tail's next = new node
        newNode->prev = tail;       // New node's prev = tail
        newNode->next = head;       // New node's next = head (circular)
        head->prev = newNode;       // Head's prev = new node (new tail)
    }

    // ---------------------------------------------
    // Insert a node at the start (head)
    // ---------------------------------------------
    void insertAtStart(int val) {
        Dnode *newNode = new Dnode(val);

        if (!head) {
            head = newNode;
            head->next = head;
            head->prev = head;
            return;
        }

        Dnode *tail = head->prev;   // Tail node before head
        newNode->next = head;       // New node -> old head
        newNode->prev = tail;       // New node <- tail
        tail->next = newNode;       // Tail next -> new node
        head->prev = newNode;       // Old head prev -> new node
        head = newNode;             // Move head to new node
    }

    // ---------------------------------------------
    // Insert a node at a specific index
    // (index starts from 0)
    // ---------------------------------------------
    void insertAtIndex(int val, int index) {
        // If inserting at beginning
        if (index == 0) {
            insertAtStart(val);
            return;
        }

        // If list is empty and index != 0 -> invalid
        if (!head) {
            cout << "Invalid index: list is empty.\n";
            return;
        }

        Dnode *newNode = new Dnode(val);
        Dnode *temp = head;
        int count = 0;

        // Traverse until position before index
        do {
            if (count == index - 1) {
                Dnode *nextNode = temp->next;

                // Link new node between temp and nextNode
                temp->next = newNode;
                newNode->prev = temp;
                newNode->next = nextNode;
                nextNode->prev = newNode;
                return;
            }

            temp = temp->next;
            count++;
        } while (temp != head);

        // If we finish loop and index not reached
        cout << "Index out of range!\n";
    }

    // ---------------------------------------------
    // Delete a node by value
    // ---------------------------------------------
    void deleteByValue(int val) {
        if (!head)
            return;

        Dnode *temp = head;
        Dnode *toDelete = NULL;

        // Traverse until found or looped back
        do {
            if (temp->data == val) {
                toDelete = temp;
                break;
            }
            temp = temp->next;
        } while (temp != head);

        if (!toDelete)
            return; // Not found

        // If single node
        if (toDelete->next == toDelete) {
            head = NULL;
        } else {
            Dnode *prevNode = toDelete->prev;
            Dnode *nextNode = toDelete->next;
            prevNode->next = nextNode;
            nextNode->prev = prevNode;

            // If head is being deleted
            if (toDelete == head)
                head = nextNode;
        }

        delete toDelete;
    }

    // ---------------------------------------------
    // Delete node from head
    // ---------------------------------------------
    void deleteFromHead() {
        // If list empty
        if (!head) {
            cout << "List is empty.\n";
            return;
        }

        // If only one node
        if (head->next == head) {
            delete head;
            head = NULL;
            return;
        }

        Dnode *tail = head->prev;    // Last node before head
        Dnode *toDelete = head;      // Node to delete = head
        Dnode *newHead = head->next; // Move head to next node

        // Update pointers to remove the old head
        tail->next = newHead;
        newHead->prev = tail;

        head = newHead; // Update head pointer
        delete toDelete;
    }

    // ---------------------------------------------
    // Delete node from tail
    // ---------------------------------------------
    void deleteFromTail() {
        // If list empty
        if (!head) {
            cout << "List is empty.\n";
            return;
        }

        // If only one node
        if (head->next == head) {
            delete head;
            head = NULL;
            return;
        }

        Dnode *tail = head->prev;     // Find tail (before head)
        Dnode *newTail = tail->prev;  // Node before tail

        // Update circular links
        newTail->next = head;
        head->prev = newTail;

        delete tail;  // Remove old tail
    }

    // ---------------------------------------------
    // Display forward
    // ---------------------------------------------
    void displayForward() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }

        Dnode *temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    // ---------------------------------------------
    // Display backward
    // ---------------------------------------------
    void displayBackward() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }

        Dnode *tail = head->prev;
        Dnode *temp = tail;

        do {
            cout << temp->data << " ";
            temp = temp->prev;
        } while (temp != tail);
        cout << endl;
    }
};

// ---------------------------------------------
// MAIN FUNCTION
// ---------------------------------------------
int main() {
    DClist list;

    // Insert at end
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);

    // Insert at start
    list.insertAtStart(5);

    cout << "List (forward): ";
    list.displayForward();

    // Insert at index
    cout << "Insert 15 at index 2:\n";
    list.insertAtIndex(15, 2);
    list.displayForward();

    // Delete from head
    cout << "After deleting from head:\n";
    list.deleteFromHead();
    list.displayForward();

    // Delete from tail
    cout << "After deleting from tail:\n";
    list.deleteFromTail();
    list.displayForward();

    // Delete by value
    cout << "After deleting value 15:\n";
    list.deleteByValue(15);
    list.displayForward();

    cout << "Backward traversal:\n";
    list.displayBackward();

    return 0;
}
