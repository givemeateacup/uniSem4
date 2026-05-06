

#include <iostream>
using namespace std;

template <class t>
class templateStack
{

public:
    t *st;
    int currentSize;
    int maxSize;
    stack(int a)
    {
        st = new t[a];
        currentSize = 0;
        maxSize = a;
    }

    void push(t a)
    {
        if (isFull())
        {
            cout << "stack is full\n";
            return;
        }
        st[currentSize] = a;
        currentSize++;
    };

    t pop()
    {
        if (isEmpty())
        {
            cout << "stack is empty\n";
            return;
        }
        t toReturn = st[currentSize - 1];
        currentSize--;
        return toReturn;
    };

    t top()
    {
        if (isEmpty())
        {
            cout << "stack is empty\n";
            return t();
        }
        return st[currentSize - 1];
    };

    bool isEmpty() { return currentSize == 0; };
    bool isFull() { return currentSize == maxSize; };

    virtual ~stack()
    {
        delete[] st;
        st = nullptr;
    }
};

// template <class t>
// class myStack : public stack<t>
// {
// public:
//     myStack(int a) : stack<t>(a) {}
// };

// int main()
// {
//     myStack<int> st(5);

//     cout << "Top: " << st.top() << endl;
//     st.push(10);
//     st.push(20);
//     st.push(30);
//     cout << "Top: " << st.top() << endl;
//     st.pop();
//     st.pop();
//     st.pop();
//     st.pop();
//     return 0;
// }

#include <iostream>
using namespace std;

class intStack
{
public:
    int *st;
    int currentSize;
    int maxSize;

    intStack(int a)
    {
        st = new int[a];
        currentSize = 0;
        maxSize = a;
    }
    void display()
    {
        int temp = currentSize - 1;
        while (temp >= 0)
        {
            cout << st[temp] << " ";
            temp--;
        }
        cout << endl;
    }
    int displaySpecific(int a)
    {
        return st[a];
    }

    void push(int a)
    {
        if (isFull())
        {
            cout << "stack is full\n";
            return;
        }
        st[currentSize] = a;
        currentSize++;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "stack is empty\n";
            return -1; // Added return for safety
        }
        int toReturn = st[currentSize - 1];
        currentSize--;
        return toReturn;
    }

    int top()
    {
        if (isEmpty())
        {
            cout << "stack is empty\n";
            return -1;
        }
        return st[currentSize - 1];
    }

    int getSize()
    {
        return currentSize;
    }

    bool isEmpty() { return currentSize == 0; }
    bool isFull() { return currentSize == maxSize; }

    virtual ~intStack()
    {
        delete[] st;
        st = nullptr;
    }
};

class charStack
{
public:
    char *st;
    int currentSize;
    int maxSize;

    charStack(int a)
    {
        st = new char[a];
        currentSize = 0;
        maxSize = a;
    }

    void push(char a)
    {
        if (isFull())
        {
            cout << "stack is full\n";
            return;
        }
        st[currentSize] = a;
        currentSize++;
    }

    char pop()
    {
        if (isEmpty())
        {
            cout << "stack is empty\n";
            return '\0'; // Null character for safety
        }
        char toReturn = st[currentSize - 1];
        currentSize--;
        return toReturn;
    }

    char top()
    {
        if (isEmpty())
        {
            cout << "stack is empty\n";
            return '\0';
        }
        return st[currentSize - 1];
    }

    bool isEmpty() { return currentSize == 0; }
    bool isFull() { return currentSize == maxSize; }

    virtual ~charStack()
    {
        delete[] st;
        st = nullptr;
    }
};