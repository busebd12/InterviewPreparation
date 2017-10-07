#include <iostream>
#include <stack>

class MinStack
{
    private:
        stack<int> s;
        stack<int> previousMins;
    public:
        void push(int x)
        {
            s.push(x);
            
            if(previousMins.empty() || x <= getMin())
            {
                previousMins.push(x);
            }    
        }
        void pop()
        {
            if(s.top()==getMin())
            {
                previousMins.pop();
            }
            
            s.pop();
        }
    
        int top()
        {
            return s.top();
        }
    
        int getMin()
        {
            return previousMins.top();
        }
};