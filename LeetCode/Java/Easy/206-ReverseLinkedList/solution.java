class ListNode
{
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

/*
	Solution: Using three pointers, reverse the linked-ist as we are looping through it.
	
	Time complexity: O(n)
	Space complexity: O(1)
*/

class Solution
{
	ListNode reverseList(ListNode head)
	{
		ListNode current=head;

		ListNode newHead=null;

		ListNode ahead=null;

		while(current!=null)
		{
			ahead=current.next;

			current.next=newHead;

			newHead=current;

			current=ahead;
		}

		return newHead;
	}
}