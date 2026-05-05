/*
#include <iostream>
using namespace std;
template <typename t>
t returnIndex(t a[], t b)
{
    t temp = 0;
    while (a[temp] != b)
    {
        temp++;
    }
    return temp;
}
int main()
{
    int array[] = {1, 2, 3};
    cout << returnIndex(array, 3);

    cout << endl;
    system("pause");
    return 0;
} */

/* #include <iostream>
using namespace std;
int main()
{
    cout << "enter number of lockers to setup ";
    int n;
    cin >> n;
    char *lockers[n] = new char;
    int choice = 0;
    while (choice != 4)
    {
        cout << "enter 1 to set locker pass, enter 2 to display locker pass, enter 3 to clear locker pass and enter 4 to exit ";
        if (choice == 1)
        {
            cout << "what locker you want to set lock for out of " << n << " lockers ";
            int set;
            cin >> set;
            setLocker(lockers, set);
        }
        else if (choice == 2)
        {
            cout << "what locker you want to set lock for out of " << n << " lockers ";
            int display;
            cin >> display;
            displayLocker(lockers, display);
        }
        else if (choice == 3)
        {
            cout << "what locker you want to set lock for out of " << n << " lockers ";
            int clear;
            cin >> clear;
            clearLocker(lockers, clear);
        }
    }
    for (int i = 0; i < n; i++)
    {
        delete lockers[i];
        lockers[i] = nullptr;
    }

    return 0;
} */

/* #include <iostream>
#include <cstring>
using namespace std;
void setLocker(char *lockers[], int lockerNum)
{
    cout << "enter password for locker ";
    char temp[100];
    cin >> temp;
    lockers[lockerNum - 1] = new char[strlen(temp) + 1];
    strcpy(lockers[lockerNum - 1], temp);
    cout << "password set\n";
}

void displayLocker(char *lockers[], int lockerNum)
{
    cout << lockers[lockerNum - 1] << endl;
}

void clearLocker(char *lockers[], int lockerNum)
{
    delete[] lockers[lockerNum - 1];
    lockers[lockerNum - 1] = nullptr;
    cout << "pass cleared\n";
}

int main()
{
    cout << "enter number of lockers to setup ";
    int n;
    cin >> n;

    char **lockers = new char *[n];

    int choice = 0;
    while (choice != 4)
    {
        cout << "\nenter 1 to set locker pass\nenter 2 to display locker pass\nenter 3 to clear locker pass\nenter 4 to exit\n";
        cin >> choice;
        if (choice == 1)
        {
            cout << "what locker you want to set lock for out of " << n << " lockers ";
            int set;
            cin >> set;
            setLocker(lockers, set);
        }
        else if (choice == 2) // if we display locker that has not been given a value, the program runs abnromally so we need to make sure we display an allocated locker
        {
            cout << "what locker you want to display lock for out of " << n << " lockers ";
            int display;
            cin >> display;
            displayLocker(lockers, display);
        }
        else if (choice == 3)
        {
            cout << "what locker you want to clear lock for out of " << n << " lockers ";
            int clear;
            cin >> clear;
            clearLocker(lockers, clear);
        }
        else if (choice == 4)
        {
            cout << "bye bye\n";
        }
    }
    // below we delete and equate memory to nullptr to avoid dangling pointers
    // i could have added more functionality if i would have more time ')
    for (int i = 0; i < n; i++)
    {
        delete[] lockers[i];
        lockers[i] = nullptr;
    }
    delete[] lockers;
    return 0;
} */

/* #include <iostream>
using namespace std;
#define length 10
int top = -1;
void push();
int pop();
void listStack();
int stack[length];
int main()
{
    int ch = -1;
    do
    {
        cout << "enter 1 to push\n2 to pop\n3 to exit ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            push();
            listStack();
            break;
        case 2:
            cout << pop() << " poped\n";
            listStack();
            break;
        case 3:
            cout << "exiting";
            break;
        default:
            break;
        }
    } while (ch != 3);
    return 0;
}
void push()
{
    if (top + 1 == length)
    {
        cout << "stack overflow\n";
    }
    else
    {
        cout << "enter element ";
        top++;
        cin >> stack[top];
    }
}
int pop()
{
    if (top == -1)
    {
        cout << "stack underflow\n";
    }
    else
        top--;
    return stack[top + 1];
}
void listStack()
{
    for (int i = top; i >= 0; i--)
    {
        cout << stack[i] << " ";
    }
    cout << endl
         << endl;
} */

/* #include <iostream>
using namespace std;
struct list
{
    int value;
    list *next;
};
list *head = nullptr;
void insert(int x)
{
    list *temp = new list;
    temp->value = x;
    if (head == nullptr)
    {
        temp->next = nullptr;
        head = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
}
void del()
{
    list *temp = head;
    if (head == nullptr)
    {
        cout << "there is no list to delete from\n";
    }
    else
    {
        head = head->next;
        delete head->next;
        delete head;
    }
}
void display()
{
    list *view = head;
    while (view != nullptr)
    {
        cout << view->value << " ";
        view = view->next;
    }
}
int main()
{
    insert(10);
    insert(20);
    insert(30);
    display();
    cout << head->next->next->value;
    del();
    return 0;
} */

/* #include <iostream>
using namespace std;
struct node
{
    int value;
    node *next;
};
node *head = nullptr;
node *lastNodePtr = nullptr;
node *ptr = new node;
int main()
{
    ptr->value = 1;
    ptr->next = nullptr;
    head = ptr;
    lastNodePtr = ptr;
    for (int i = 2; i <= 9; i++)
    {
        ptr = new node;
        ptr->value = i;
        ptr->next = nullptr;
        lastNodePtr->next = ptr;
        lastNodePtr = ptr;
    }
    return 0;
} */

/* #include <iostream>
using namespace std;
struct queue
{
    int value;
    queue *next;
};
queue *front = nullptr;
queue *rear = nullptr;
void enqueue(int x)
{
    queue *newNode = new queue;
    newNode->value = x;
    newNode->next = nullptr;
    if (front == nullptr)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}
void dequeue()
{
    if (front == nullptr)
    {
        cout << "list empty\n";
    }
    queue *temp = front;
    if (front == rear)
    {
        front = rear = nullptr;
    }
    else
    {
        front = front->next;
    }
    delete temp;
}
int main()
{
    return 0;
} */
/*
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
void insertAtBeginning(Node *&head, int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}
void insertAtEnd(Node *&head, int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    Node *current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    current->next = newNode;
}
void insertAtPosition(Node *&head, int value, int position)
{
    if (position < 1)
    {
        cout << "must be>=1\n";
        return;
    }
    if (position == 1)
    {
        insertAtBeginning(head, value);
        return;
    }
    Node *newNode = new Node;
    newNode->data = value;
    Node *current = head;
    for (int i = 1; i < position - 1 && current != nullptr; i++)
    {
        current = current->next;
    }
    if (current == nullptr)
    {
        cout << "out of range\n";
        delete newNode;
        return;
    }
    newNode->next = current->next;
    current->next = newNode;
}
void display(Node *head)
{
    if (head == nullptr)
    {
        cout << "empty\n";
        return;
    }
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->data;
        if (current->next != nullptr)
        {
            cout << " -> ";
        }
        current = current->next;
    }
    cout << " -> NULL\n";
}
int main()
{
    Node *head = nullptr;
    int choice, value, position;
    do
    {
        cout << "1 at eginning\n2 at End\n3 at Position\n4 display\n5 exit\nenter choice ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "enter value ";
            cin >> value;
            insertAtBeginning(head, value);
            break;
        case 2:
            cout << "enter value ";
            cin >> value;
            insertAtEnd(head, value);
            break;
        case 3:
            cout << "enter value ";
            cin >> value;
            cout << "position ";
            cin >> position;
            insertAtPosition(head, value, position);
            break;
        case 4:
            display(head);
            break;
        case 5:
            cout << "exiting\n";
            break;
        default:
            cout << "invalid. again\n";
        }
    } while (choice != 5);
    Node *temp;
    while (head != nullptr)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
} */

/* #include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
void insertAtBeginning(Node *&head, int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}
void insertAtEnd(Node *&head, int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    Node *current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    current->next = newNode;
}
void insertAtPosition(Node *&head, int value, int position)
{
    if (position < 1)
    {
        cout << "must be>=1\n";
        return;
    }
    if (position == 1)
    {
        insertAtBeginning(head, value);
        return;
    }
    Node *newNode = new Node;
    newNode->data = value;
    Node *current = head;
    for (int i = 1; i < position - 1 && current != nullptr; i++)
    {
        current = current->next;
    }
    if (current == nullptr)
    {
        cout << "out of range\n";
        delete newNode;
        return;
    }
    newNode->next = current->next;
    current->next = newNode;
}
void deleteFromBeginning(Node *&head)
{
    if (head == nullptr)
    {
        cout << "list empty.can't del.\n";
        return;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
    cout << "deleted";
    display(head);
}
void deleteFromEnd(Node *&head)
{
    if (head == nullptr)
    {
        cout << "list is empty. can't del\n";
        return;
    }
    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        cout << "Deleted ";
        display(head);
        return;
    }
    Node *current = head;
    while (current->next->next != nullptr)
    {
        current = current->next;
    }
    delete current->next;
    current->next = nullptr;
    cout << "deleted ";
    display(head);
}
void deleteFromPosition(Node *&head, int position)
{
    if (head == nullptr)
    {
        cout << "list is empty. can't del\n";
        return;
    }
    if (position < 1)
    {
        cout << "position>=1\n";
        return;
    }
    if (position == 1)
    {
        deleteFromBeginning(head);
        return;
    }
    Node *current = head;
    for (int i = 1; i < position - 1 && current != nullptr; i++)
    {
        current = current->next;
    }
    if (current == nullptr || current->next == nullptr)
    {
        cout << "out of range\n";
        return;
    }
    Node *temp = current->next;
    current->next = temp->next;
    delete temp;
    cout << "deleted ";
    display(head);
}
void search(Node *head, int value)
{
    if (head == nullptr)
    {
        cout << "list empty. can't search\n";
        return;
    }
    Node *current = head;
    int position = 1;
    while (current != nullptr)
    {
        if (current->data == value)
        {
            cout << "value at position " << position << endl;
            return;
        }
        current = current->next;
        position++;
    }
    cout << "Value does not exist\n";
}
void update(Node *head, int position, int newValue)
{
    if (head == nullptr)
    {
        cout << "List is empty. Cannot update.\n";
        return;
    }
    if (position < 1)
    {
        cout << "Position must be 1 or greater.\n";
        return;
    }
    Node *current = head;
    for (int i = 1; i < position && current != nullptr; i++)
    {
        current = current->next;
    }
    if (current == nullptr)
    {
        cout << "Position out of range.\n";
        return;
    }
    current->data = newValue;
    cout << "Value at position " << position << " updated to " << newValue << ".\n";
}
void display(Node *head)
{
    if (head == nullptr)
    {
        cout << "empty\n";
        return;
    }
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->data;
        if (current->next != nullptr)
        {
            cout << " -> ";
        }
        current = current->next;
    }
    cout << " -> NULL\n";
}
int main()
{
    Node *head = nullptr;
    int choice, value, position, newValue;
    do
    {
        cout << "\n--- Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete from Position\n";
        cout << "7. Search for Element\n";
        cout << "8. Update Node Value\n";
        cout << "9. Display List\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            insertAtBeginning(head, value);
            cout << "Inserted at beginning.\n";
            break;
        case 2:
            cout << "Enter value: ";
            cin >> value;
            insertAtEnd(head, value);
            cout << "Inserted at end.\n";
            break;
        case 3:
            cout << "Enter value: ";
            cin >> value;
            cout << "Enter position: ";
            cin >> position;
            insertAtPosition(head, value, position);
            break;
        case 4:
            deleteFromBeginning(head);
            break;
        case 5:
            deleteFromEnd(head);
            break;
        case 6:
            cout << "Enter position to delete: ";
            cin >> position;
            deleteFromPosition(head, position);
            break;
        case 7:
            cout << "Enter value to search: ";
            cin >> value;
            search(head, value);
            break;
        case 8:
            cout << "Enter position to update: ";
            cin >> position;
            cout << "Enter new value: ";
            cin >> newValue;
            update(head, position, newValue);
            break;
        case 9:
            cout << "Current List: ";
            display(head);
            break;
        case 10:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 10);
    Node *temp;
    while (head != nullptr)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
} */

/* #include <iostream>
using namespace std;
class stack
{
    int *stackArray;
    int top;
    int size;

public:
    stack(int);
    void push(int);
    void pop();
    bool isFull();
    bool isEmpty();
};
stack::stack(int a)
{
    stackArray = new int[a];
    top = -1;
    size = a;
}
void stack::push(int a)
{
    if (isFull())
    {
        cout << "stack overFlow\n";
    }
    top++;
    stackArray[top] = a;
}
void stack::pop()
{
    if (isEmpty())
    {
        cout << "stack underFlow\n";
    }
    cout << stackArray[top];
    top--;
}
bool stack::isFull()
{
    if (top + 1 == size)
    {
        return 1;
    }
    else
        return 0;
};
bool stack::isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
        return 0;
}
int main()
{
    cout << "enter no. to convert to binary ";
    int number;
    cin >> number;
    int stackSize = 8;
    stack stack1(stackSize);
    for (int i = 0; i < stackSize; i++)
    {
        if (number % 2)
        {
            stack1.push(1);
        }
        else
            stack1.push(0);
        number /= 2;
    }
    for (int i = 0; i < stackSize; i++)
    {
        stack1.pop();
    }
    return 0;
} */

/* #include <iostream>
#include <cstring>
using namespace std;
#define length 100
class evaluation
{
    int stackArr[length];
    int top;

public:
    evaluation() { top = -1; }
    void push(char);
    char pop();
    int processEvaluation();
};
int evaluation::processEvaluation()
{
    char expression[length];
    int x, y;
    cout << "enter postFix expression ";
    cin >> expression;
    for (int i = 0; i < strlen(expression); i++)
    {
        if (expression[i] >= '0' && expression[i] <= '9')
        {
            push((int)expression[i] - '0');
        }
        else
        {
            x = pop();
            y = pop();

            switch (expression[i])
            {
            case '+':
                push(x + y);
                break;
            case '-':
                push(y - x);
                break;
            case '/':
                push(y / x);
                break;
            case '*':
                push(y * x);
                break;
            case '%':
                push(y % x);
                break;

            default:
                break;
            }
        }
    }
    return pop();
}
int main()
{
    evaluation ev1;
    ev1.processEvaluation();
    return 0;
}
// incomplete */

/* #include <iostream>
using namespace std;
int main()
{
    int *x;
    int y[] = {1, 2, 3};
    x = y;
    for (int i = 0; i < 3; i++)
    {
        cout << x[i];
    }
    return 0;
} */

/* #include <iostream>
using namespace std;
struct queue
{
    int front = -1, rear = -1;
    int array[8];
    int count = 0;
};
bool isEmpty(queue *q)
{
    // if (q->front == -1)
    if (q->count == 0)
    {
        return 1;
    }
    return 0;
}
bool isFull(queue *q)
{
    // if (q->rear + 1 % 8 == q->front)
    if (q->count == 8)
    {
        return 1;
    }
    return 0;
}

void enqueue(queue *q, int element)
{
    if (isFull(q))
    {
        cout << "queue is full\n";
        return;
    }
    if (isEmpty(q))
    {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % 8;
    q->array[q->rear] = element;
    cout << "enqueued\n";
    q->count++;
}
void dequeue(queue *q)
{
    if (isEmpty(q))
    {
        cout << "queue is empty\n";
        return;
    }
    q->front = ++q->front % 8;
    cout << "dequeued\n";
    q->count--;
}
queue *q = new queue;
int main()
{
    // dequeue(q);
    enqueue(q, 0);
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    enqueue(q, 6);
    enqueue(q, 7);
    enqueue(q, 8);
} */

/* #include <iostream>
using namespace std;

template <class T>
class Array
{
protected:
    T *array;
    int currentSize;
    int maxSize;

public:
    Array(int a)
    {
        array = new T[a];
        currentSize = 0;
        maxSize = a;
    }

    virtual ~Array()
    {
        delete[] array;
    }

    virtual void addElement(T a) = 0;
    virtual T removeElement() = 0;
    virtual bool isEmpty() = 0;
    virtual bool isFull() = 0;
};

template <class T>
class myArray : public Array<T>
{
public:
    myArray(int a) : Array<T>(a) {}

    void addElement(T a)
    {
        if (isFull())
        {
            cout << "array is full\n";
            return;
        }
        this->array[this->currentSize] = a;
        this->currentSize++;
    }

    T removeElement()
    {
        if (isEmpty())
        {
            cout << "array is empty\n";
            return T();
        }
        this->currentSize--;
        return this->array[this->currentSize];
    }

    bool isEmpty()
    {
        return this->currentSize == 0;
    }

    bool isFull()
    {
        return Array<T>::currentSize == this->maxSize;
    }
};

int main()
{
    myArray<int> arr(5);

    arr.addElement(10);
    arr.addElement(20);
    arr.addElement(30);

    cout << arr.removeElement() << endl; // Prints 30
    cout << arr.removeElement() << endl; // Prints 20
    cout << arr.removeElement() << endl; // Prints 10
    cout << arr.removeElement() << endl; // Prints "array is empty" and returns 0

    return 0;
} */

/* #include <iostream>
#include "stack.h"
#include <iostream>
using namespace std; */

/* #include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

class Queue
{
public:
    Node *front = nullptr, *rear = nullptr;

    void enqueue(int x)
    {
        Node *temp = new Node(x);
        if (!rear)
        {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }

    int dequeue()
    {
        if (!front)
            return -1;
        Node *temp = front;
        int val = temp->data;
        front = front->next;
        if (!front)
        {
            rear = nullptr;
        }
        delete temp;
        return val;
    }

    int size()
    {
        int count = 0;
        Node *curr = front;
        while (curr)
        {
            curr = curr->next;
            count++;
        }
        return count;
    }

    bool empty()
    {
        return front == nullptr;
    }
};

class Stack
{
    Queue q;

public:
    void push(int x)
    {
        int s = q.size();
        q.enqueue(x);

        for (int i = 0; i < s; i++)
        {
            q.enqueue(q.dequeue());
        }
    }

    void pop()
    {
        if (q.empty())
            return;
        q.dequeue();
    }

    int top()
    {
        if (q.empty())
            return -1;
        return q.front->data;
    }
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;

    return 0;
} */

/* #include <iostream>
#include "linkedList.h"

using namespace std;

template <class t>
void reverse(linkedList<t> &a)
{
    if (a.isEmpty())
    {
        return;
    }

    node<t> *previous = nullptr;
    node<t> *current = a.head;
    node<t> *next = nullptr;
    a.tail = a.head;
    while (current != nullptr)
    {
        next = current->nodePtr;
        current->nodePtr = previous;
        previous = current;
        current = next;
    }
    a.head = previous;
}
int main()
{
    linkedList<int> my;
    my.insertAtTail(1);
    my.insertAtTail(2);
    my.insertAtTail(3);
    my.insertAtTail(4);
    my.display();
    reverse(my);
    my.display();
} */

/* #include <iostream>
#include "linkedList.h"
#include "circularQueue.h"
using namespace std;
int returnLinkedListLength(linkedList &a)
{
    int length = 0;
    node *traverse = a.head;
    while (traverse != nullptr)
    {
        traverse = traverse->nodePtr;
        length++;
    }
    return length;
}
void findingValueInLl(linkedList &a, int findingValue)
{
    node *traverse = a.head;
    int location = 1;
    while (traverse->value != findingValue)
    {
        if (traverse->nodePtr == nullptr)
        {
            cout << "value not found\n";
            return;
        }
        location++;
        traverse = traverse->nodePtr;
    }
    cout << "value found at node " << location << " with address " << traverse << endl;
}
void returnMiddleNode(linkedList &my)
{
    int middle;
    if (returnLinkedListLength(my) % 2 == 0)
    {
        middle = returnLinkedListLength(my) / 2 - 1;
    }
    else
        middle = returnLinkedListLength(my) / 2;
    node *traverse = my.head;
    for (int i = 0; i < middle; i++)
    {
        traverse = traverse->nodePtr;
    }
    cout << "middle value is " << traverse->value << " at position " << middle << " and has address " << traverse;
}
void returnMiddleNodeMethod2(linkedList &my)
{
    node *slowPtr = my.head, *fastPtr = my.head;
    while (fastPtr != nullptr && fastPtr->nodePtr != nullptr)
    {
        fastPtr = fastPtr->nodePtr->nodePtr;
        slowPtr = slowPtr->nodePtr;
    }
    cout << slowPtr->value;
}
bool checkPalindrome(linkedList &my)
{
    node *orgTraverse = my.head;
    linkedList reversed;
    while (orgTraverse != nullptr)
    {
        reversed.insertAtHead(orgTraverse->value);
        orgTraverse = orgTraverse->nodePtr;
    }
    orgTraverse = my.head;
    node *reverseTraverse = reversed.head;
    while (orgTraverse != nullptr)
    {
        if (orgTraverse->value == reverseTraverse->value)
        {
            orgTraverse = orgTraverse->nodePtr;
            reverseTraverse = reverseTraverse->nodePtr;
            continue;
        }
        else
            return false;
    }
    return true;
}
void removeDuplicates(linkedList &my)
{
    node *traverse = my.head;
    while (traverse->nodePtr != nullptr)
    {
        if (traverse->value == traverse->nodePtr->value)
        {
            node *temp = traverse->nodePtr;
            traverse->nodePtr = traverse->nodePtr->nodePtr;
            delete temp;
        }
        else
            traverse = traverse->nodePtr;
    }
}
bool checkCycle(linkedList &my)
{
    node *traverse = my.head;
    while (traverse->nodePtr != nullptr)
    {
        if (traverse->nodePtr == my.head)
        {
            return 1;
        }
        traverse = traverse->nodePtr;
    }
    return 0;
}
void mergeTwoSortedLinkedLists(linkedList &my, linkedList &my2)
{
    linkedList final;
    node *traverseMy = my.head, *traverseMy2 = my2.head;
    while (traverseMy != nullptr && traverseMy2 != nullptr)
    {
        if (traverseMy->value <= traverseMy2->value)
        {
            final.insertAtTail(traverseMy->value);
            traverseMy = traverseMy->nodePtr;
        }
        else
        {
            final.insertAtTail(traverseMy2->value);
            traverseMy2 = traverseMy2->nodePtr;
        }
    }
    if (traverseMy != nullptr)
    {
        while (traverseMy != nullptr)
        {
            final.insertAtTail(traverseMy->value);
            traverseMy = traverseMy->nodePtr;
        }
    }
    else if (traverseMy2 != nullptr)
    {
        while (traverseMy2 != nullptr)
        {
            final.insertAtTail(traverseMy2->value);
            traverseMy2 = traverseMy2->nodePtr;
        }
    }
    final.display();
}
void removeNFromStart(linkedList &my, int n)
{
    if (returnLinkedListLength(my) < n)
    {
        cout << "invalid n\n";
        return;
    }
    node *traverse = my.head;
    for (int i = 1; i < n - 1; i++)
    {
        traverse = traverse->nodePtr;
    }
    node *temp = traverse->nodePtr;
    traverse->nodePtr = traverse->nodePtr->nodePtr;
    delete temp;
}
void insertAtNFromStart(linkedList &my, int n)
{
    if (n > returnLinkedListLength(my) + 1)
    {
        cout << "invalid n\n";
        return;
    }
    node *toAdd = new node;
    toAdd->value = 3;
    node *traverse = my.head;
    for (int i = 1; i < n - 1; i++)
    {
        traverse = traverse->nodePtr;
    }
    toAdd->nodePtr = traverse->nodePtr;
    traverse->nodePtr = toAdd;
}

void sortLinkedList(linkedList &my)
{
    if (my.head == nullptr)
        return;

    linkedList temp;

    // Extract all nodes to temp in sorted order
    while (my.head != nullptr)
    {
        node *current = my.head;
        my.head = my.head->nodePtr;

        // Insert into temp at correct position
        if (temp.head == nullptr || current->value < temp.head->value)
        {
            current->nodePtr = temp.head;
            temp.head = current;
        }
        else
        {
            node *tempPtr = temp.head;
            while (tempPtr->nodePtr != nullptr &&
                   tempPtr->nodePtr->value < current->value)
            {
                tempPtr = tempPtr->nodePtr;
            }
            current->nodePtr = tempPtr->nodePtr;
            tempPtr->nodePtr = current;
        }
    }

    // Copy back
    my.head = temp.head;

    if (my.head != nullptr)
    {
        node *tail = my.head;
        while (tail->nodePtr != nullptr)
            tail = tail->nodePtr;
        my.tail = tail;
    }
}

int main()
{
    linkedList my;

    my.insertAtTail(1);
    my.insertAtTail(11);
    my.insertAtTail(10);
    my.insertAtTail(19);
    my.insertAtTail(18);
    my.insertAtTail(17);
    my.insertAtTail(20);

    sortLinkedList(my);
    my.display();

    // cout << "length for lL is " << returnLinkedListLength(my);
    // findingValueInLl(my, 3);
    // returnMiddleNode(my);
    // returnMiddleNodeMethod2(my);

    // if (checkPalindrome(my))
    // {
    //     cout << "lL is palindrome\n";
    // }
    // else
    //     cout << "not a palindrome\n";

    // removeDuplicates(my);
    // my.display();

    // my.tail->nodePtr = my.head;
    // if (checkCycle(my))
    // {
    //     cout << "yes cycle\n";
    // }
    // else
    //     cout << "no cycle\n";

    // linkedList my2;
    // my2.insertAtTail(2);
    // my2.insertAtTail(4);
    // mergeTwoSortedLinkedLists(my, my2);

    // removeNFromStart(my, 3);
    // my.display();

    // insertAtNFromStart(my, 3);
    // my.display();

    // circularQueue<int> my(4);
    // my.enqueue(1);
    // my.enqueue(2);
    // my.enqueue(3);
    // my.dequeue();
    // my.enqueue(4);
    // my.enqueue(5);
    // my.display();

    return 0;
} */

/* #include <iostream>
using namespace std;

struct node
{
    int roll;
    string name;
    int marks;
    node *nodePtr;
};

class linkedList
{
public:
    node *head;
    node *tail;

    linkedList() { head = tail = nullptr; }

    bool isEmpty()
    {
        return head == nullptr;
    }

    virtual void insertAtHead(int roll,
                              string name,
                              int marks)
    {
        node *temp = new node;
        temp->roll = roll;
        temp->name = name;
        temp->marks = marks;
        if (isEmpty())
        {
            temp->nodePtr = nullptr;
            tail = temp;
        }
        else
        {
            temp->nodePtr = head;
        }
        head = temp;
    }

    void insertAtTail(int roll,
                      string name,
                      int marks)
    {
        node *temp = new node;
        temp->roll = roll;
        temp->name = name;
        temp->marks = marks;
        temp->nodePtr = nullptr;
        if (isEmpty())
        {
            head = temp;
        }
        else
        {
            tail->nodePtr = temp;
        }
        tail = temp;
    }

    void display()
    {
        node *traverse = head;
        while (traverse != nullptr)
        {
            cout << traverse->roll << " " << traverse->name << " " << traverse->marks << endl;
            traverse = traverse->nodePtr;
        }
        cout << endl;
    }

    virtual ~linkedList()
    {
        node *current = head;
        while (current != nullptr)
        {
            node *next = current->nodePtr;
            delete current;
            current = next;
        }
        head = tail = nullptr;
    }
};
void insertAtPosition(linkedList &my, int a, string b, int c, int d)
{
    node *toAdd = new node;
    toAdd->roll = a;
    toAdd->name = b;
    toAdd->marks = c;
    node *traverse = my.head;
    for (int i = 1; i < d - 1; i++)
    {
        traverse = traverse->nodePtr;
    }
    toAdd->nodePtr = traverse->nodePtr;
    traverse->nodePtr = toAdd;
}
int main()
{
    linkedList my;
    my.insertAtTail(123, "ali ahmad", 30);
    my.insertAtTail(1234, "ahmad", 40);
    my.insertAtTail(12345, "shams", 70);
    insertAtPosition(my, 123456, "veha", 70, 3);

    my.display();
    return 0;
} */

/* #include <iostream>
#include <string>
#include "stack.h"
using namespace std;
void toReverse(charStack &my, string &word)
{
    char letter;
    for (int i = 0; word[i] != '\0'; i++)
    {
        my.push(word[i]);
    }
    for (int i = 0; word[i] != '\0'; i++)
    {
        word[i] = my.pop();
    }
}
bool checkPalindrome(charStack &my, string word)
{
    for (int i = 0; i < word.length() / 2; i++)
    {
        my.push(word[i]);
    }
    int i;
    if (word.length() % 2 == 0)
    {
        i = word.length() / 2;
    }
    else
        i = word.length() / 2 + 1;

    while (!my.isEmpty())
    {
        char temp = my.pop();
        if (temp != word[i])
        {
            return 0;
        }
        i++;
    }
    return 1;
}
void doMyThing(intStack &one, intStack &two, int arr[], int size)
{
    int start = 0, end = size - 1;
    while (true)
    {
        one.push(arr[start]);
        start++;
        if (start == end)
        {
            two.push(arr[end]);
            break;
        }
        two.push(arr[end]);
        end--;
        if (start == end)
        {
            one.push(arr[start]);
            break;
        }
    }
}
void sort(intStack &one)
{
    intStack temp(100);
    while (!one.isEmpty())
    {
        int value = one.pop();
        while (temp.currentSize != 0 && temp.top() > value)
        {
            one.push(temp.pop());
        }
        temp.push(value);
    }
    while (!temp.isEmpty())
    {
        one.push(temp.pop());
    }
}
int main()
{
    // charStack my(100);
    // string word = "maam";
    // cout << word.length();
    // toReverse(my, word);
    // cout << word;

    // if (checkPalindrome(my, word))
    // {
    //     cout << "y\n";
    // }
    // else
    // {
    //     cout << "n\n";
    // }

    // intStack one(100);
    // intStack two(100);
    // int arr[] = {1, 2, 3, 4, 5};
    // int size = sizeof(arr) / sizeof(arr[0]);
    // // cout << size << endl;
    // doMyThing(one, two, arr, size);
    // one.display();
    // two.display();

    intStack one(100);
    one.push(3);
    one.push(1);
    one.push(4);
    one.push(2);
    sort(one);
    one.display();
    return 0;
} */

/* #include <iostream>
using namespace std;
template <class t>
class stack
{
public:
    t *arr;
    int top;
    int maxSize;
    stack(int a)
    {
        arr = new t[a];
        top = -1, maxSize = a;
    }
    void push(t a)
    {
        top++;
        arr[top] = a;
    }
    t pop()
    {
        return arr[top--];
    }
    void display()
    {
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    virtual ~stack()
    {
        delete[] arr;
        arr = nullptr;
    }
};
template <class t>
void displayCurrentPosition(stack<t> &fileSystem)
{
    cout << "we are rn in ";
    fileSystem.display();
}
int main()
{
    stack<string> fileSystem(100);
    fileSystem.push("desktop");
    fileSystem.push("win");
    fileSystem.push("vsc");
    displayCurrentPosition(fileSystem);
    fileSystem.pop();
    displayCurrentPosition(fileSystem);

    return 0;
} */

/* #include <iostream>
#include <string>
using namespace std;

class student
{
public:
    int id;
    string name;

    // Default constructor
    student() : id(0), name("") {}

    // Parameterized constructor
    student(int i, string n) : id(i), name(n) {}

    // Display student info
    void display() const
    {
        cout << "ID: " << id << ", Name: " << name;
    }
};

class circularQueue
{
public:
    int front;
    int rear;
    student **cQ; // Array of pointers to student objects
    int count;
    int maxSize;

    circularQueue(int a)
    {
        cQ = new student *[a]; // Allocate array of pointers
        for (int i = 0; i < a; i++)
        {
            cQ[i] = nullptr; // Initialize all pointers to nullptr
        }
        front = -1;
        rear = -1;
        count = 0;
        maxSize = a;
    }

    void enqueue(student *a)
    {
        if (isFull())
        {
            cout << "Queue is full\n";
            return;
        }

        // Create a new student object dynamically
        // student *newStudent = new student(a.id, a.name);

        if (isEmpty())
        {
            front = 0;
        }
        rear = (rear + 1) % maxSize;
        cQ[rear] = a;
        count++;
        cout << "Enqueued: ";
        cQ[rear]->display();
        cout << endl;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Dequeued: ";
        cQ[front]->display();
        cout << endl;

        // Delete the student object to prevent memory leak
        delete cQ[front];
        cQ[front] = nullptr;

        if (count == 1) // Last element
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % maxSize;
        }
        count--;
    }

    bool isEmpty()
    {
        return count == 0;
    }

    bool isFull()
    {
        return count == maxSize;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Queue contents (front to rear):\n";
        int i = front;
        int displayed = 0;
        while (displayed < count)
        {
            cout << "[";
            cQ[i]->display();
            cout << "] ";
            i = (i + 1) % maxSize;
            displayed++;
        }
        cout << endl;
        cout << "Front index: " << front << ", Rear index: " << rear << ", Count: " << count << endl;
    }

    student frontValue() // Peek at front
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return student(); // Return default student
        }
        return *cQ[front]; // Return by value (copy)
    }

    // Get front student pointer (to avoid copying)
    student *frontPointer()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return nullptr;
        }
        return cQ[front];
    }

    virtual ~circularQueue()
    {
        // Delete all remaining student objects
        for (int i = 0; i < maxSize; i++)
        {
            if (cQ[i] != nullptr)
            {
                delete cQ[i];
                cQ[i] = nullptr;
            }
        }
        delete[] cQ;
        cQ = nullptr;
    }
};

int main()
{
    // Test the circular queue with student objects
    circularQueue cq(5);

    cout << "=== Testing Circular Queue with Student Records ===\n\n";

    cq.enqueue(new student(101, "Alice"));
    cq.enqueue(new student(102, "Bob"));
    cq.enqueue(new student(103, "Charlie"));
    cq.enqueue(new student(104, "David"));
    cq.enqueue(new student(105, "Eve"));
    cq.enqueue(new student(106, "Frank")); // Queue is full

    cout << "\n";
    cq.display();

    cout << "\n=== Dequeue operations ===\n";
    cq.dequeue();
    cq.dequeue();

    cout << "\nAfter dequeue:\n";
    cq.display();

    cout << "\n=== Enqueue more students ===\n";
    cq.enqueue(new student(107, "Grace"));
    cq.enqueue(new student(108, "Henry"));

    cq.display();

    cout << "\n=== Peek at front ===\n";
    student front = cq.frontValue();
    cout << "Front student: ";
    front.display();
    cout << endl;

    cout << "\n=== Dequeue all remaining ===\n";
    while (!cq.isEmpty())
    {
        cq.dequeue();
    }

    cout << "\nFinal queue state:\n";
    cq.display();

    return 0;
} */

/* #include <iostream>
using namespace std;
class student
{
public:
    int id;
    string name;
    student()
    {
        id = 0;
        name = "";
    }
    student(int a, string b) : id(a), name(b) {}
    void display()
    {
        cout << "id: " << id << ", name " << name;
    }
};
class circularQueue
{
public:
    int front;
    int rear;
    student **arr;
    int count;
    int maxSize;
    circularQueue(int a)
    {
        arr = new student *[a];
        for (int i = 0; i < a; i++)
        {
            arr[i] = nullptr;
        }

        count = 0;
        maxSize = a;
        front = -1;
        rear = -1;
    }
    bool isFull()
    {
        if (count == maxSize)
        {
            return 1;
        }
        else
            return 0;
    }
    bool isEmpty()
    {
        if (count == 0)
        {
            return 1;
        }
        else
            return 0;
    }
    void enqueue(student *a)
    {
        if (isFull())
        {
            cout << "is full\n";
            return;
        }
        else if (isEmpty())
        {
            front = 0;
        }
        rear = (rear + 1) % maxSize;
        arr[rear] = a;
        count++;
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "is empty\n";
            return;
        }
        arr[front]->display();
        cout << " dequeued\n";
        if (count == 1)
        {
            front = -1;
            rear = -1;
            count--;
            return;
        }
        front = (front + 1) % maxSize;
        count--;
    }
    void display()
    {
        int i = front;
        int displayed = 0;
        while (displayed < count)
        {
            cout << i << " ";
            arr[i]->display();
            cout << endl;
            i = (i + 1) % maxSize;
            displayed++;
        }
        cout << endl;
    }
    ~circularQueue()
    {
        for (int i = 0; i < count; i++)
        {
            delete arr[i];
            arr[i] = nullptr;
        }
        delete[] arr;
        arr = nullptr;
    }
};
int main()
{
    circularQueue my(3);
    my.enqueue(new student(1, "hary"));
    my.enqueue(new student(2, "jam"));
    my.enqueue(new student(3, "micky"));
    my.enqueue(new student(4, "jon"));
    my.dequeue();
    my.enqueue(new student(4, "jon"));
    my.display();

    return 0;
} */

/* #include <iostream>
#include "linkedList.h"
#include "circularQueue.h"
#include "stack.h"
using namespace std;
void swapTwoNodesByValue(linkedList &, int, int);
void selectionSort(linkedList &my)
{
    if (my.head == nullptr)
        return;
    node *current;
    current = my.head;
    int iterations = 0;
    while (current->nodePtr != nullptr)
    {
        int min = current->value;
        node *roll = current->nodePtr;
        while (roll != nullptr)
        {
            if (roll->value < min)
            {
                min = roll->value;
            }
            roll = roll->nodePtr;
        }
        swapTwoNodesByValue(my, current->value, min);
        iterations++; // below steps are done because after swapTwoNodesByValue execution, nodes addresses are changed
        current = my.head;
        for (int i = 0; i < iterations; i++)
        {
            current = current->nodePtr;
        }
    }
}
void swapTwoNodesByValue(linkedList &my, int a, int b)
{
    if (a == b)
    {
        return;
    }
    node *prevA = nullptr;
    node *currA = my.head;
    node *prevB = nullptr;
    node *currB = my.head;
    while (currA != nullptr && currA->value != a)
    {
        prevA = currA;
        currA = currA->nodePtr;
    }
    while (currB != nullptr && currB->value != b)
    {
        prevB = currB;
        currB = currB->nodePtr;
    }
    if (currA == nullptr || currB == nullptr)
    {
        return;
    }
    if (prevA == nullptr)
    {
        my.head = currB;
    }
    else
    {
        prevA->nodePtr = currB;
    }
    if (prevB == nullptr)
    {
        my.head = currA;
    }
    else
    {
        prevB->nodePtr = currA;
    }
    node *temp = currA->nodePtr;
    currA->nodePtr = currB->nodePtr;
    currB->nodePtr = temp;
}

template <class t>
void removeDuplicates(circularQueue<t> &mine)
{
    circularQueue<t> temp(7);
    if (mine.isEmpty())
        return;
    while (!mine.isEmpty())
    {

        t store = mine.dequeue();
        bool found = 0;

        for (int i = 0; i < temp.count; i++)
        {
            if (store == temp.frontValue())
            {
                found = 1;
            }
            temp.enqueue(temp.dequeue());
        }
        if (!found)
        {
            temp.enqueue(store);
        }
    }
    while (!temp.isEmpty())
    {
        mine.enqueue(temp.dequeue());
    }
}

template <class t>
void reverse(circularQueue<t> &mine)
{
    if (mine.isEmpty())
    {
        return;
    }
    circularQueue<t> temp1(mine.maxSize);
    circularQueue<t> temp2(mine.maxSize);

    for (int i = 0; i < mine.maxSize - 1; i++)
    {
        while (mine.count != 1)
        {
            temp1.enqueue(mine.dequeue());
        }
        temp2.enqueue(mine.dequeue());
        while (!temp1.isEmpty())
        {
            mine.enqueue(temp1.dequeue());
        }
    }
    temp2.enqueue(mine.dequeue());
    while (!temp2.isEmpty())
    {
        mine.enqueue(temp2.dequeue());
    }
}
void evaluatePrefix(circularQueue<int> &prefixOp, intStack &ans)
{
    while (!prefixOp.isEmpty())
    {
        int temp = prefixOp.dequeue();
        if (temp == -1 || temp == -2 || temp == -3)
        {
            ans.push(temp);
        }
        else
        {
            if (ans.top() != -1 && ans.top() != -2 && ans.top() != -3)
            {
                int temp2 = ans.pop();
                int operation = ans.pop();
                if (operation == -1)
                {
                    ans.push(temp2 + temp);
                }
                else if (operation == -2)
                {
                    ans.push(temp2 * temp);
                }
                else
                // (operation = -3)
                {
                    ans.push(temp2 / temp);
                }
            }
            else
                ans.push(temp);
        }
    }
}

void reverseLinkedList(linkedList &ticket)
{
    if (ticket.head == nullptr)
    {
        return;
    }
    node *prev = nullptr;
    node *next = ticket.head;
    node *oldHead = ticket.head;
    while (next != nullptr)
    {
        node *temp = next->nodePtr;
        next->nodePtr = prev;
        prev = next;
        next = temp;
    }
    ticket.tail = oldHead;
    ticket.head = prev;
}

linkedList copyLinkedList(linkedList &ticket)
{
    linkedList copied;
    node *copy = ticket.head;
    while (copy != nullptr)
    {
        copied.insertAtTail(copy->value);
        copy = copy->nodePtr;
    }
    return copied;
}

bool isPalindrome(linkedList &ticket)
{
    linkedList originalCopied = copyLinkedList(ticket);
    reverseLinkedList(originalCopied);
    node *traverseMain = ticket.head;
    node *traverseCopy = originalCopied.head;
    while (traverseMain != nullptr)
    {
        if (traverseCopy->value != traverseMain->value)
        {
            return 0;
        }
        traverseCopy = traverseCopy->nodePtr;
        traverseMain = traverseMain->nodePtr;
    }
    return 1;
}

bool fourDigits(linkedList &ticket)
{
    node *toCount = ticket.head;
    int count = 0;
    while (toCount != nullptr)
    {
        count++;
        toCount = toCount->nodePtr;
    }
    if (count == 4)
    {
        return 1;
    }
    return 0;
}

bool sumAbove20(linkedList &ticket)
{
    node *traverse = ticket.head;
    int sum = 0;
    while (traverse != nullptr)
    {
        sum += traverse->value;
        traverse = traverse->nodePtr;
    }
    if (sum >= 20)
    {
        return 1;
    }
    return 0;
}

int checkIfWon(linkedList &ticket)
{
    if (isPalindrome(ticket) && fourDigits(ticket) && sumAbove20(ticket))
    {
        return 3000;
    }
    if (fourDigits(ticket) && sumAbove20(ticket))
    {
        return 1000;
    }
    if (isPalindrome(ticket))
    {
        return 2000;
    }
    else
        return 0;
}

int findingMidUsingSlowFastPointer(linkedList &a)
{
    int nodeNumber = 0;
    node *slowTraverse = a.head;
    node *fastTraverse = a.head;

    while (fastTraverse->nodePtr != nullptr && fastTraverse->nodePtr->nodePtr != nullptr)
    {
        nodeNumber++;
        slowTraverse = slowTraverse->nodePtr;
        fastTraverse = fastTraverse->nodePtr->nodePtr;
    }
    cout << "mid is " << slowTraverse->value << " at node number " << nodeNumber << endl;
    return nodeNumber;
}

void valueAtNode(linkedList &a, int b)
{
    node *traverse = a.head;
    for (int i = 0; i < b; i++)
    {
        traverse = traverse->nodePtr;
    }
    cout << traverse->value << endl;
}

int main()
{
    // intStack a(3);
    // cout << sizeof(a);

    // linkedList my;
    // my.insertAtTail(5);
    // my.insertAtTail(1);
    // my.insertAtTail(4);
    // my.insertAtTail(2);
    // my.insertAtTail(3);

    // swapTwoNodesByValue(my, 5, 1);
    // my.display();

    // selectionSort(my);
    // my.display();

    // circularQueue<int> mine(7);
    // mine.enqueue(3);
    // mine.enqueue(1);
    // mine.enqueue(4);
    // mine.enqueue(3);
    // mine.enqueue(4);
    // mine.enqueue(2);
    // mine.enqueue(1);
    // mine.display();
    // removeDuplicates(mine);
    // mine.display();

    // circularQueue<int> mine(6);
    // mine.enqueue(1);
    // mine.enqueue(2);
    // mine.enqueue(3);
    // mine.enqueue(4);
    // mine.enqueue(5);
    // mine.enqueue(6);
    // mine.display();
    // reverse(mine);
    // mine.display();

    // circularQueue<int> prefixOp(5);
    // prefixOp.enqueue(-3);
    // prefixOp.enqueue(-2);
    // prefixOp.enqueue(7);
    // prefixOp.enqueue(3);
    // prefixOp.enqueue(2);

    // intStack ans(5);

    // evaluatePrefix(prefixOp, ans);
    // cout << "final ans is " << ans.pop();

    linkedList ticket1;
    ticket1.insertAtTail(4);
    ticket1.insertAtTail(3);
    ticket1.insertAtTail(1);
    ticket1.insertAtTail(2);
    ticket1.insertAtTail(4);

    // linkedList ticket2;
    // ticket2.insertAtTail(5);
    // ticket2.insertAtTail(6);
    // ticket2.insertAtTail(5);
    // ticket2.insertAtTail(7);

    // linkedList ticket3;
    // ticket3.insertAtTail(9);
    // ticket3.insertAtTail(1);
    // ticket3.insertAtTail(1);
    // ticket3.insertAtTail(9);

    // linkedList ticket4;
    // ticket4.insertAtTail(2);
    // ticket4.insertAtTail(1);
    // ticket4.insertAtTail(1);
    // ticket4.insertAtTail(7);
    // ticket4.insertAtTail(1);
    // ticket4.insertAtTail(8);

    // cout << "ticket1 won " << checkIfWon(ticket1) << endl;
    // cout << "ticket2 won " << checkIfWon(ticket2) << endl;
    // cout << "ticket3 won " << checkIfWon(ticket3) << endl;
    // cout << "ticket4 won " << checkIfWon(ticket4) << endl;

    // ticket2.display();
    // reverseLinkedList(ticket2);
    // ticket2.display();

    int mid = findingMidUsingSlowFastPointer(ticket1);


    valueAtNode(ticket1, mid);

    return 0;
} */

/* #include <iostream>
#include "stack.h"
#include "circularQueue.h"
using namespace std;

void pushUsingQueue(circularQueue<int> &main, int a)
{
    main.enqueue(a);
    for (int i = 0; i < main.count - 1; i++)
    {
        main.enqueue(main.dequeue());
    }
}
void popUsingQueue(circularQueue<int> &main)
{
    main.dequeue();
}

void enqueueUsingStack(intStack &mainStack, int a)
{
    mainStack.push(a);
}
void dequeueUsingStack(intStack &mainStack, intStack &secondaryStack)
{
    if (secondaryStack.isEmpty())
    {
        while (!mainStack.isEmpty())
        {
            secondaryStack.push(mainStack.pop());
        }
    }
    secondaryStack.pop();
    while (!secondaryStack.isEmpty())
    {
        mainStack.push(secondaryStack.pop());
    }
}

int main()
{
    // circularQueue<int> main(10);
    // pushUsingQueue(main, 1);
    // pushUsingQueue(main, 2);
    // pushUsingQueue(main, 3);
    // pushUsingQueue(main, 4);
    // pushUsingQueue(main, 5);

    // popUsingQueue(main);
    // main.display();
    // popUsingQueue(main);
    // main.display();
    // popUsingQueue(main);
    // main.display();

    intStack mainStack(10);
    intStack secondaryStack(10);
    enqueueUsingStack(mainStack, 1);
    enqueueUsingStack(mainStack, 2);
    enqueueUsingStack(mainStack, 3);
    enqueueUsingStack(mainStack, 4);
    enqueueUsingStack(mainStack, 5);
    mainStack.display();

    dequeueUsingStack(mainStack, secondaryStack);
    mainStack.display();
    dequeueUsingStack(mainStack, secondaryStack);
    mainStack.display();
    dequeueUsingStack(mainStack, secondaryStack);
    mainStack.display();
    enqueueUsingStack(mainStack, 6);
    dequeueUsingStack(mainStack, secondaryStack);
    mainStack.display();

    return 0;
} */

/* #include <iostream>
using namespace std;
int main()
{
    const int size = 17;
    int arr[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
    int low = 0;
    int high = size - 1;
    int mid = 0;
    int value = 17;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == value)
        {
            cout << mid;
            break;
        }
        else if (value < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return 0;
} */

/* #include <iostream>
#include "stack.h"
#include "circularQueue.h"
#include "linkedList.h"
using namespace std;
void deleteMiddle(intStack &my)
{

    int loopToRun = my.getSize() / 2;
    intStack temp(loopToRun);
    for (int i = 0; i < loopToRun; i++)
    {
        temp.push(my.pop());
    }
    my.pop();
    while (!temp.isEmpty())
    {
        my.push(temp.pop());
    }
}

bool palindrome(intStack &my)
{
    intStack reverse(my.getSize());
    for (int i = my.getSize() - 1; i >= 0; i--)
    {
        reverse.push(my.displaySpecific(i));
    }
    for (int i = my.getSize() - 1; i >= 0; i--)
    {
        if (reverse.displaySpecific(i) != my.displaySpecific(i))
        {
            return false;
        }
    }
    return true;
}

void printSlidingWindowsSum(linkedList &mine, int a)
{
    bool finish = 0;
    int iterations = 0;
    while (!finish)
    {
        node *traverse = mine.head;
        for (int i = 0; i < iterations; i++)
        {
            traverse = traverse->nodePtr;
        }

        int sum = 0;
        bool complete = 1;
        for (int i = 0; i < a; i++)
        {
            if (traverse == nullptr)
            {
                complete = 0;
                finish = 1;
                break;
            }
            sum += traverse->value;
            traverse = traverse->nodePtr;
        }
        if (complete)
        {
            cout << sum << " ";
        }
        iterations++;
    }

    cout << endl;
}

void reverseFirstKElements(circularQueue<int> &mine, int k)
{
    intStack temp(k);
    for (int i = 0; i < k; i++)
    {
        temp.push(mine.dequeue());
    }
    while (!temp.isEmpty())
    {
        mine.enqueue(temp.pop());
    }
    for (int i = 0; i < mine.count - k; i++)
    {
        mine.enqueue(mine.dequeue());
    }
}

int main()
{
    // intStack my(5);
    // my.push(1);
    // my.push(2);
    // my.push(7);
    // my.push(2);
    // my.push(1);

    // my.push(5);

    // my.display();
    // deleteMiddle(my);
    // my.display();

    // if (palindrome(my))
    // {
    //     cout << "stack palindrome\n";
    // }

    // linkedList mine;
    // mine.insertAtTail(15);
    // mine.insertAtTail(0);
    // mine.insertAtTail(-3);
    // mine.insertAtTail(99);
    // // mine.insertAtTail(5);
    // // mine.insertAtTail(6);
    // printSlidingWindowsSum(mine, 4);

    circularQueue<int> mine(10);
    mine.enqueue(15);
    mine.enqueue(0);
    mine.enqueue(-3);
    mine.enqueue(99);
    // mine.enqueue(50);
    mine.display();
    reverseFirstKElements(mine, 4);
    mine.display();

    return 0;
} */

#include <iostream>
using namespace std;
int main()
{
    cout << "hey\n";
    return 0;
}