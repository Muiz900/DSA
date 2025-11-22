#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Node
{
public:
    string data;
    Node *next;
    Node(const string &d) : data(d), next(nullptr) {}
};

class Stack
{
private:
    Node *top;

public:
    Stack() : top(nullptr) {}

    void pushString(const string &str)
    {
        Node *n = new Node(str);
        n->next = top;
        top = n;
    }

    string popString()
    {
        if (!top)
            return "";
        string s = top->data;
        Node *temp = top;
        top = top->next;
        delete temp;
        return s;
    }

    string peekString()
    {
        if (!top)
            return "";
        return top->data;
    }

    bool isEmptyString()
    {
        return top == nullptr;
    }

    void pushChar(char c)
    {
        string s(1, c);
        pushString(s);
    }

    char popChar()
    {
        string s = popString();
        if (s.empty())
            return '\0';
        return s[0];
    }

    char peekChar()
    {
        string s = peekString();
        if (s.empty())
            return '\0';
        return s[0];
    }

    bool isEmptyChar()
    {
        return isEmptyString();
    }

    void pushOp(char op)
    {
        pushChar(op);
    }

    char popOp()
    {
        return popChar();
    }

    char peekOp()
    {
        return peekChar();
    }

    bool isEmptyOp()
    {
        return isEmptyString();
    }

    void pushNum(int value)
    {
        pushString(to_string(value));
    }

    int popNum()
    {
        string s = popString();
        if (s.empty())
            return 0;
        return stoi(s);
    }

    int peekNum()
    {
        string s = peekString();
        if (s.empty())
            return 0;
        return stoi(s);
    }

    bool isEmptyNum()
    {
        return isEmptyString();
    }

    ~Stack()
    {
        while (!isEmptyString())
        {
            popString();
        }
    }

    bool balanced(const string &string, Stack stack)
    {
        bool balanced = true;

        for (char c : string)
        {
            if (c == '(' || c == '{' || c == '[')
                stack.pushChar(c);
            else if (c == ')')
            {
                if (stack.isEmptyChar() || stack.popChar() != '(')
                {
                    balanced = false;
                    break;
                }
            }
            else if (c == '}')
            {
                if (stack.isEmptyChar() || stack.popChar() != '{')
                {
                    balanced = false;
                    break;
                }
            }
            else if (c == ']')
            {
                if (stack.isEmptyChar() || stack.popChar() != '[')
                {
                    balanced = false;
                    break;
                }
            }
        }
        if (!stack.isEmptyChar())
            balanced = false;

        return balanced;
    }

    void emptystack()
    {
        while (!isEmptyString())
            popString();
    }

    int precedence(char op)
    {
        if (op == '+' || op == '-')
            return 1;
        if (op == '*' || op == '/')
            return 2;
        if (op == '^')
            return 3;
        return 0;
    }

    string infixToPostfix(const string &infix, Stack stack)
    {
        string postfix;
        for (char c : infix)
        {
            if (isalnum(c))
                postfix += c;
            else if (c == '(')
                stack.pushChar(c);
            else if (c == ')')
            {
                while (!stack.isEmptyChar() && stack.peekChar() != '(')
                    postfix += stack.popChar();
                if (!stack.isEmptyChar() && stack.peekChar() == '(')
                    stack.popChar();
            }
            else
            {
                while (!stack.isEmptyChar() && precedence(stack.peekChar()) >= precedence(c))
                    postfix += stack.popChar();
                stack.pushChar(c);
            }
        }
        while (!stack.isEmptyChar())
            postfix += stack.popChar();
        return postfix;
    }
};

int evaluatePostfix(const string &postfix, Stack &stack)
{
    for (char c : postfix)
    {
        if (isdigit(c))
            stack.pushNum(c - '0');
        else
        {
            int val2 = stack.popNum();
            int val1 = stack.popNum();
            switch (c)
            {
            case '+': stack.pushNum(val1 + val2); break;
            case '-': stack.pushNum(val1 - val2); break;
            case '*': stack.pushNum(val1 * val2); break;
            case '/': stack.pushNum(val1 / val2); break;
            case '^': stack.pushNum(pow(val1, val2)); break;
            }
        }
    }
    return stack.popNum();
}

string reverseBrackets(string str)
{
    for (char &c : str)
    {
        if (c == '(') c = ')';
        else if (c == ')') c = '(';
        else if (c == '{') c = '}';
        else if (c == '}') c = '{';
        else if (c == '[') c = ']';
        else if (c == ']') c = '[';
    }
    return str;
}

string reverseString(const string str)
{
    string rev;
    for (int i = (int)str.size() - 1; i >= 0; --i)
        rev += str[i];
    return rev;
}

int main()
{//task 1
    string s[] = {"{{{()}}}{}(()){}"};
    Stack stack;

    for (const string &str : s)
    {
        bool balanced = stack.balanced(str, stack);
        if (balanced)
            cout << "Accepted: Sequence is right\n";
        else
        {
            cout << "Rejected: Sequence is wrong\n";
            stack.emptystack();
        }
    }
     //task2
    Stack stack2;
    string infix[] = {"(A+B)*C"};
    for (const string &infixExp : infix)
    {
        cout << "Infix Expression: " << infixExp << endl;
        string postfix = stack2.infixToPostfix(infixExp, stack2);
        cout << "Postfix Expression: " << postfix << endl;
    }

    //TAsk 3
    string infix2[] = {"(A+B)*(C+D)"};
    Stack stack3;
    for (const string &infixExp : infix2)
    {
        cout << "Infix Expression: " << infixExp << endl;
        string postfix = stack3.infixToPostfix(reverseBrackets(reverseString(infixExp)), stack3);
        cout << "Prefix Expression: " << reverseString(postfix) << endl;
    }

    // Task 4 
    Stack stack4;
    string postfix = "23+5*";
    int result = evaluatePostfix(postfix, stack4);
    cout << "Result = " << result << endl;

    // task 5
    Stack stack5;
    string expr = "((A+B)*C-(D-E))^(F+G)";
    string postfixExpr = stack5.infixToPostfix(expr, stack5);
    cout<<"Infix Expression: "<<expr<<endl;
    cout << "Postfix Expression: " << postfixExpr << endl;

    return 0;
}
