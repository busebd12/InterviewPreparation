#include <iostream>
using namespace std;

struct listNode
{
      int value;
      struct listNode* next;
};

bool is_list_even(listNode* head)
{
    if(head==nullptr)
    {
        return true;
    }
    
    listNode* current=head;
    
    int count=0;
    
    while(true)
    {
        count++;
        
        if(current->next==nullptr)
        {
            break;
        }
        
        current=current->next;
    }
    
    return count%2==0;
}
