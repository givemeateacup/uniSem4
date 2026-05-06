/* #include <iostream>
using namespace std;
template <class t>
struct node
{
    t value;
    node *nodePtr;
};
template <class t>
class linkedList
{
public:
    node<t> *head;
    node<t> *tail;
    linkedList() { head = tail = nullptr; }
    bool isEmpty()
    {
        return head == nullptr;
    }
    virtual void insertAtHead(t a) // use virtual else always the function in parent class would execute even if overridden, without virtual we have to use base pointer to access parent function
    {
        node<t> *temp = new node<t>;
        temp->value = a;
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
    void insertAtTail(t a)
    {
        node<t> *temp = new node<t>;
        temp->value = a;
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
        node<t> *traverse = head;
        while (traverse != nullptr)
        {
            cout << traverse->value << " ";
            traverse = traverse->nodePtr;
        }
        cout << endl;
    }
    virtual ~linkedList()
    {
        delete head;
        head = nullptr;
        delete tail;
        tail = nullptr;
    }
}; */

// template <class t>
// class myLinkedList : public linkedList<t>
// {
// };
// int main()
// {
//     myLinkedList<int> myLinkedList1;
//     myLinkedList1.insertAtHead(4);
//     myLinkedList1.insertAtHead(3);
//     myLinkedList1.insertAtHead(2);
//     myLinkedList1.insertAtTail(5);
//     myLinkedList1.display();
//     return 0;
// }

#include <iostream>
using namespace std;

// Replaced template <class t> with a fixed type (int)
struct node
{
    int value;
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

    virtual void insertAtHead(int a)
    {
        node *temp = new node;
        temp->value = a;
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

    void insertAtTail(int a)
    {
        node *temp = new node;
        temp->value = a;
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
            cout << traverse->value << " ";
            traverse = traverse->nodePtr;
        }
        cout << endl;
    }

    // Fixed Destructor: You must loop through to delete all nodes
    ~linkedList()
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