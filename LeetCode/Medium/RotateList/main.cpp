#include <iostream>
using namespace std;

struct ListNode
{
    int val;

    ListNode* next;

    ListNode(): val(-1), next(nullptr) {};

    ListNode(int x): val(x), next(nullptr) {}
};

void printList(ListNode* list)
{
    ListNode* current=list;

    while(true)
    {
        cout << current->val << " ";

        if(current->next==nullptr)
        {
            return;
        }

        current=current->next;
    }
}

int getLastElement(ListNode* head)
{
    int lastElement{};

    ListNode* current=head;

    while(true)
    {
        lastElement=current->val;

        if(current->next==nullptr)
        {
            break;
        }

        current=current->next;
    }

    return lastElement;
}
void insertAtBeginning(ListNode* & head, int number)
{
    ListNode* newHead=new ListNode(number);

    newHead->next=head;

    head=newHead;
}

void deleteEnd(ListNode* head)
{
    if(head->next==nullptr)
    {
        delete head;

        head=nullptr;
    }
    else
    {
        ListNode* nextToEnd=head;

        ListNode* end=head->next;

        while(end->next!=nullptr)
        {
            nextToEnd=end;

            end=end->next;
        }

        delete end;

        nextToEnd->next=nullptr;
    }
}

void addToEnd(ListNode* head, int number)
{
    ListNode* newNode=new ListNode(number);

    if(!head)
    {
        head=newNode;

        return;
    }
    else
    {
        ListNode* last=head;

        while(last->next!=nullptr)
        {
            last=last->next;
        }

        last->next=newNode;
    }
}

//First solution: loop k times and each time we delete the last element and add it to the beginning of the list
//However, this solution was too slow (surprising, since it's O(k+2n) --> O(k+n) time)
ListNode* rotateRight(ListNode* head, int k)
{
    if(head==nullptr || head->next==nullptr)
    {
        return head;
    }

    int length=1;

    ListNode *current=head;

    while(current->next!=nullptr)
    {
        ++length;

        current=current->next;
    }

    if(length==1)
    {
        return head;
    }

    for(int rotations=0;rotations<k;++rotations)
    {
        int lastElement=getLastElement(head);

        deleteEnd(head);

        insertAtBeginning(head, lastElement);
    }

    return head;
}

//Second solution: make the linked list cyclical, cut the list at the rotation point, and update the end of the list
//Accepted
ListNode* rotateRight(ListNode* head, int k)
{
    if(head==nullptr || head->next==nullptr)
    {
        return head;
    }

    int length=1;

    ListNode* node=head;

    //calculate the length of the list
    while(node->next!=nullptr)
    {
        node=node->next;

        ++length;
    }

    //connect the linked list, make it cyclical
    node->next=head;

    //deals with the case if k is greater than the length of the linked list
    k=k%length;

    //loop till the point where the rotation will happen
    while(--length >= k)
    {
        node=node->next;
    }

    //the new head of the rotated list
    ListNode* rotatedHead=node->next;

    //set the end of the rotated list to NULL
    node->next=nullptr;

    return rotatedHead;
}