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