import java.util.Stack;

/*
	Solution: we use two stacks, one to store all the elements and one to only store minimum values.
	When we push elements onto the stack, if the stack that holds all minimum values is empty or
	the element we want to push is less than or equal to the top of the minimum values stack,
	we have to add this element to the minimum values stack. Then, we also add the value to
	the stack that holds all the values. When we are popping from our stack, if the top
	value from the stack that holds all values is equal to the top of the minimum values
	stack, then we have to remove the top of the minimum values stack as well. This way,
	we keep the top of the minimum values stack correct at all times. The top() and getMin()
	functions are self-explanatory.

	Time complexity: O(n) [where n is the number of input values]
	Space complexity: O(n)
*/

class MinStack
{
    Stack<Integer> all;
    
    Stack<Integer> minValues;
    
    public MinStack()
    {
        all=new Stack<>();
        
        minValues=new Stack<>();
    }
    
    public void push(int x)
    {
        if(minValues.empty() || x <= minValues.peek())
        {
            minValues.push(x);
        }
        
        all.push(x);
    }
    
    public void pop()
    {
        int value=all.peek();
        
        if(value==getMin())
        {
            minValues.pop();
        }
        
        all.pop();
    }
    
    public int top()
    {
        return all.peek();
    }
    
    public int getMin()
    {
        return minValues.peek();
    }
}