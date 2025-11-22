#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* last;
    
public:
    CircularLinkedList() {
        last = nullptr;
    }
    
    void insert(Node* newNode) {
        if (last == nullptr) {
            last = newNode;
            last->next = last;
        } else {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }
    }
    
    void display(Node* start) {
        if (last == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        
        Node* temp = start;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != start);
        cout << endl;
    }
    
    void deleteNode(Node* nodeToDelete) {
        if (last == nullptr) return;
        
        Node* current = last->next;
        Node* prev = last;
        
        while (current != nodeToDelete) {
            if (current->next == last->next) {
                cout << "Node not found" << endl;
                return;
            }
            prev = current;
            current = current->next;
        }
        
        if (current == last->next && current->next == last->next) {
            last = nullptr;
            delete current;
            return;
        }
        
        if (current == last->next) {
            prev->next = current->next;
            last->next = current->next;
        } else if (current == last) {
            prev->next = last->next;
            last = prev;
        } else {
            prev->next = current->next;
        }
        
        delete current;
    }
    
    Node* getLast() {
        return last;
    }
    
    ~CircularLinkedList() {
        if (last == nullptr) return;
        
        Node* current = last->next;
        Node* next;
        
        do {
            next = current->next;
            delete current;
            current = next;
        } while (current != last->next);
    }
};

int main() {
    CircularLinkedList list;
    
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    
    list.insert(node1);
    list.insert(node2);
    list.insert(node3);
    list.insert(node4);
    
    cout << "List: ";
    list.display(list.getLast()->next);
    
    list.deleteNode(node2);
    cout << "After deleting node with value 2: ";
    list.display(list.getLast()->next);
    
    return 0;
}