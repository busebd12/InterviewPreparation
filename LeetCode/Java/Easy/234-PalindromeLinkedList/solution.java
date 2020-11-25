import java.lang.String;
import java.util.Arrays;
import java.util.Stack;

class ListNode
{
	int val;
	ListNode next;
	ListNode() {}
	ListNode(int val) { this.val = val; }
	ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

/*
	Solution:

	1. We put all the elements of the linked-list in a stack (thereby reversing the elements).
	Then, we iterate through the linked-list and the stack, comparing elements as we go.
	If any two elements are not the same, then the linked-list is not a palindrome.
	If we iterate through both the stack and linked-list without finding any mismatched elements,
	then we know that the linked-list is a palindrome.

	Time complexity: O(n) [where n is the length of the input linked-list]
	Space complexity: O(n)

	2. First, we find the halfway point in the linked-list. Second, we reverse the second half of the linked-list.
	Third, we iterate through both halves, comapring elements. If any two elements are not the same, then the linked-list
	is not a palidrome. Once we exhaust one of the halves, then we know the linked-list is a palindrome.

	Time complexity: O(n) [where n is the length of the linked-list]
	Space complexity: O(1)
*/

class Solution
{
	public boolean isPalindrome(ListNode head)
    {   
        Stack<ListNode> stack=new Stack<>();
        
        ListNode current=head;
        
        while(current!=null)
        {
            stack.push(current);
            
            current=current.next;
        }
        
        current=head;
        
        while(current!=null && !stack.empty())
        {
            ListNode node=stack.pop();
            
            if(current.val!=node.val)
            {
                return false;
            }
            
            current=current.next;
        }
        
        return true;
    }
}

class Solution
{
	public ListNode reverse(ListNode head)
	{
		ListNode current=head;

		ListNode newHead=null;

		ListNode after=null;

		while(current!=null)
		{
			after=current.next;

			current.next=newHead;

			newHead=current;

			current=after;
		}
		
		return newHead;
	}
    
    public boolean isPalindrome(ListNode head)
    {   
        if(head==null || head.next==null)
        {
        	return true;
        }

        if(head.next.next==null && head.val==head.next.val)
        {
        	return true;
        }

        ListNode fast=head;

		ListNode slow=head;

		while(fast.next!=null && fast.next.next!=null)
		{
			fast=fast.next.next;

			slow=slow.next;
		}

		ListNode reversed=reverse(slow.next);

		slow=head;

		while(slow!=null && reversed!=null)
		{
			if(slow.val!=reversed.val)
			{
				return false;
			}

			slow=slow.next;

			reversed=reversed.next;
		}

		return true;
    }
}