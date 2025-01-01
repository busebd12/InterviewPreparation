class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        if head==None:
            return True

        if head.next==None:
            return True

        #Calculate the length of the list
        length: int=self.get_length(head)

        #Determine the mid point of the list
        middle: int=length // 2

        #Stack to hold the nodes in the first half of the list
        stack: List[ListNode]=list()

        current: ListNode=head

        #Iterate through the first half of the list
        for count in range(0, middle):
            
            #Add the node to the stack
            stack.append(current.val)

            #Move the pointer
            current=current.next

        #If the length of the list is odd, then after we iterate through the first half of the list, current will be pointing to the middle element.
        #So, we need to increment the pointer one position further in the list so it points to the first node in the second half of the list
        if length % 2 == 1:
            current=current.next

        #While current is not None (null) and there are still nodes in the stack
        while current!=None and len(stack) > 0:
            
            #Compare the node in the second half of the list with the current end node of the first half of the list
            #If the node values don't match, then the list is not a palindrome
            if current.val!=stack[-1]:
                return False
            
            #Move the pointer
            current=current.next

            #Remove the node from the stack
            stack.pop()

        return True

    def get_length(self, head: Optional[ListNode]) -> int:
        length: int=0

        current: ListNode=head

        while current!=None:
            length+=1

            current=current.next

        return length