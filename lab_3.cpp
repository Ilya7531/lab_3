#include <cstring>
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *lnk;
};

class Stack
{
    int n;
    Node *top;

public:
    Stack()
    {
        top = NULL;
        n = 0;
    }
    ~Stack()
    {
        while (top) pop();
        n = 0;
    }

    void push(int data);
    int pop();
    bool isEmpty()
    {
        return !n;
    }
    int getNum()
    {
        return n;
    }
};

void Stack::push(int data)
{
    Node *p;
    p = new Node;
    p->data = data;
    p->lnk = top;
    top = p;
    p = NULL;
    ++n;
}

int Stack::pop()
{
    Node *p;
    p = top;
    top = top->lnk;
    p->lnk = NULL;
    int data = p->data;
    delete p;
    p = NULL;
    --n;
    return data;
}

int toint(char c)
{
    int a;
    switch(c)
    {
    case '0':
        a = 0;
        break;

    case '1':
        a = 1;
        break;

    case '2':
        a = 2;
        break;

    case '3':
        a = 3;
        break;

    case '4':
        a = 4;
        break;

    case '5':
        a = 5;
        break;

    case '6':
        a = 6;
        break;

    case '7':
        a = 7;
        break;

    case '8':
        a = 8;
        break;

    case '9':
        a = 9;
        break;

    default:
        break;
    }
    return a;
}

int calc(int a, int b, char c)
{
    switch(c)
    {
    case '+':
        a += b;
        break;

    case '-':
        a -= b;
        break;

    case '*':
        a *= b;
        break;

    case '/':
        a /= b;
        break;
    default:
        break;
    }
    return a;
}

int main()
{
    Stack s;
    char str[] = "12 2 3 - + ";
    cout << "RPN: " << str << endl;

    int i, n = strlen(str);
    bool isNorm = true;

    for (i = 0; i < n && isNorm; ++i)
    {
        if (isdigit(str[i]))
        {
            int z = toint(str[i]);

            while (isdigit(str[++i]))
            {
                z = toint(str[i]) + z * 10;
            }
            s.push(z);
        }
        else
        {
            if (str[i] == ' ') continue;
            if ((str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') && s.getNum() > 1)
            {
                int a = s.pop();
                int b = s.pop();

                s.push(calc(b, a, str[i]));
            }
            else
            {

                cout << "Smth wrong!\n";
                isNorm = false;
            }
        }
    }

    if (isNorm)
    {
        cout << "ANS: " << s.pop();

        if (!s.isEmpty())
        {
            cout << "\n extra digits: ";
            while (!s.isEmpty()) cout << s.pop() << ' ';
        }
    }

    return 0;
}
