#include <iostream>
using namespace std;

ListNode* removeNthFromEnd(ListNode* head, int n)
{   
    ListNode* current=head;
    
    ListNode * trailing=head;
    
    while(n-- > 0)
    {
        current=current->next;
    }
    
    if(current==nullptr)
    {
        head=head->next;
        
        return head;
    }
    
    while(current->next!=nullptr)
    {
        current=current->next;
        
        trailing=trailing->next;
    }
    
    trailing->next=trailing->next->next;
    
    return head;
}