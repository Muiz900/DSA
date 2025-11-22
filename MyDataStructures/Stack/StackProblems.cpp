#include <iostream>
#include <cmath>
using namespace std;

class Snode
{
    friend class Slink;

protected:
    char data;
    Snode *nextptr;

public:
    Snode(char val)
    {
        data = val;
        nextptr = NULL;
    }
    void display() const
    {
        cout << data << " ";
    }
    char getData() const
    {
        return data;
    }
    void setData(char val)
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
    void insertAtBeginning(char val)
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
            return; // empty list

        Snode *temp = headptr;
        Snode *prev = NULL;

        while (temp->nextptr != NULL)
        {
            prev = temp;
            temp = temp->nextptr;
        }
        temp->display();
        cout << endl;

        if (prev == NULL)
        { // only one node
            headptr = NULL;
        }
        else
        {
            prev->nextptr = NULL;
        }

        delete temp;
    }

    // TASK # 2
    void insertAtEnd(char val)
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
    void insertAtPosition(char val, int pos)
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
    void deleteNodeByValue(char data)
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

    void reverseList()
    {
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
    }
    char top()
    {
        return headptr->data;
    }
    char end()
    {
        Snode *temp = headptr;
        while (temp->nextptr != NULL)
        {
            temp = temp->nextptr;
        }
        return temp->data;
    }
    bool empty()
    {
        return headptr == NULL;
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
};
class Stack
{
    Slink list;

public:
    void push(char val)
    {
        list.insertAtEnd(val);
    }
    void pop()
    {
        list.deleteAtEnd();
    }
    char top()
    {
        return list.end();
    }
    char back()
    {
        return list.top();
    }
    bool isEmpty()
    {
        return list.empty();
    }
};
void sortStack(Stack s1)
{
    Stack s;
    while (!s1.isEmpty())
    {
        int temp = s1.top();
        s1.pop();
        while (!s.isEmpty() && s.top() > temp)
        {
            s1.push(s.top());
            s.pop();
        }
        s1.push(temp);
    }
    while (!s.isEmpty())
    {
        s1.push(s.top());
        s.pop();
    }
}
string reverseString(string str)
{
    Stack s;
    for (char c : str)
    {
        s.push(c);
    }
    str = "";
    while (!s.isEmpty())
    {
        str += s.top();
        s.pop();
    }
    return str;
}

int precedence(char op)
{
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string infixToPostfix(string infix)
{
    Stack st;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];

        // Case 1: Operand → add to output
        if (isalnum(ch))
        {
            postfix += ch;
        }
        // Case 2: Opening bracket → push
        else if (ch == '(')
        {
            st.push(ch);
        }
        // Case 3: Closing bracket → pop until '('
        else if (ch == ')')
        {
            while (!st.isEmpty() && st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }
            st.pop(); // Remove '('
        }
        // Case 4: Operator
        else if (isOperator(ch))
        {
            while (!st.isEmpty() && precedence(st.top()) >= precedence(ch))
            {
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    // Pop remaining operators
    while (!st.isEmpty())
    {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}
bool isdigit(char c)
{
    return (c >= '0' && c <= '9');
}
int evaluatePostfix(string post)
{
    Stack s;
    for (char c : post)
    {
        if (isdigit(c))
        {
            int val = c - '0';
            s.push(val);
        }
        else if (c == ' ')
            continue;
        else if (isOperator(c))
        {
            int val1 = s.top();
            s.pop();
            int val2 = s.top();
            s.pop();
            switch (c)
            {
            case '+':
                s.push(val2 + val1);
                break;

            case '-':
                s.push(val2 - val1);
                break;

            case '*':
                s.push(val2 * val1);
                break;

            case '/':
                s.push(val2 / val1);
                break;

            case '^':
                s.push(pow(val2, val1));
                break;
            }
        }
    }
    return s.top();

}
int prefix(string pre)
{
    Stack s;
    for (int i = pre.length() - 1; i >= 0; i--)
    {
        char c = pre[i];
        if (isdigit(c))
        {
            int val = c - '0';
            s.push(val);
        }
        else if (c == ' ')
            continue;
        else if (isOperator(c))
        {
            int right = s.top();
            s.pop();
            int left = s.top();
            s.pop();
            switch (c)
            {
            case '+':
                s.push(left + right);
                break;
            case '-':
                s.push(left - right);
                break;
            case '/':
                s.push(left / right);
                break;
            case '*':
                s.push(left * right);
                break;
            case '^':
                s.push(pow(left,right));
                break;
            }
        }
    }
    return s.top();
}
int main() {
    // Prefix test cases
    cout << "Prefix evaluation:\n";
    cout << prefix("+23") << " ";          // 5
    cout << prefix("-52") << " ";          // 3
    cout << prefix("+*23*45") << " ";      // 26
    cout << prefix("-+9*26/82") << " ";    // 17
    cout << prefix("^23") << " ";          // 8
    cout << prefix("+^235") << " ";        // 13
    cout << prefix("+7*45") << " ";        // 27
    cout << prefix("*+34+25") << " ";      // 49
    cout << prefix("+9*34") << " ";        // 21
    cout << prefix("-*+2345") << endl;     // 15

    // Postfix test cases
    cout << "\nPostfix evaluation:\n";
    cout << evaluatePostfix("23+") << " ";       // 5
    cout << evaluatePostfix("52-") << " ";       // 3
    cout << evaluatePostfix("23*5+") << " ";     // 11
    cout << evaluatePostfix("82/") << " ";       // 4
    cout << evaluatePostfix("562++") << " ";     // 13
    cout << evaluatePostfix("93-42*+") << " ";   // 14
    cout << evaluatePostfix("345+*") << " ";     // 27
    cout << evaluatePostfix("84/2*3+") << " ";   // 7
    cout << evaluatePostfix("23^") << " ";}
