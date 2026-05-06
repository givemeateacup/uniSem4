#include "../linkedList.h"
#include <iostream>
using namespace std;
node *returnIndexAddress(linkedList &a, int b)
{
    node *temp = a.head;
    for (int i = 0; i < b; i++)
    {
        temp = temp->nodePtr;
    }
    return temp;
}
void customDelete(node *b)
{
    b->value = b->nodePtr->value;
    node *temp = b->nodePtr;
    b->nodePtr = b->nodePtr->nodePtr;
    delete temp;
    temp = nullptr;
}
int main()
{
    linkedList mine;
    mine.insertAtHead(0);
    mine.insertAtHead(1);
    mine.insertAtHead(2);
    mine.insertAtHead(3);
    mine.insertAtHead(4);
    mine.display();
    customDelete(returnIndexAddress(mine, 2));
    mine.display();
    return 0;
}