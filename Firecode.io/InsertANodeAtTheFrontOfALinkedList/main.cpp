#include <iostream>
using namespace std;

struct listNode
{
      int value;
      struct listNode* next;
}

listNode* insert_at_head( listNode* head, int data)
{
    listNode* newHead=new listNode();
    
    newHead->value=data;
    
    newHead->next=head;

    return newHead;
}
