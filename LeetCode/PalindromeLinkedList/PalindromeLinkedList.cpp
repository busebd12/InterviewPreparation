ListNode* reverseList(ListNode* head)
{   
    ListNode* current=head;

    ListNode* previous=nullptr;

    ListNode* next;

    while(current!=nullptr)
    {
        next=current->next;

        current->next=previous;

        previous=current;

        current=next;
    }

    head=previous;

    return head;
}

bool isPalindrome(ListNode* head) 
{   
    if(head==nullptr)
    {
        return true;
    }
    
    ListNode* left=head;
    
    size_t length=0;
    
    while(left!=nullptr)
    {
        ++length;
        
        left=left->next;
    }
    
    left=head;
    
    if(length==1)
    {
        return true;
    }
    
    ListNode* right=head;
    
    int half=(length+1)/2;
    
    for(int count=0;count<half;count++)
    {
        right=right->next;
    }
    
    ListNode* rightReversed=reverseList(right);
    
    while(left!=nullptr && rightReversed!=nullptr)
    {   
        if(left->val==rightReversed->val)
        {
            left=left->next;
            
            rightReversed=rightReversed->next;
        }
        else
        {
            return false;
        }
    }
    
    return true;
}