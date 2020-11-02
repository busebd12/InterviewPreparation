#include <iostream>
#include <stack>
using namespace std;

/*
 * Approach: use two stacks, one to keep track of all the numbers and another one to keep track of only
 * the minimum values we've seen so far. This way, we maintain the ordering and the number of minimum values.
 */

class MinStack
{
    public:
        stack<int> stk;

        stack<int> previousMinimumValues;

        MinStack()
        {

        }

        void push(int x)
        {
            if(previousMinimumValues.empty() || x <= previousMinimumValues.top())
            {
                previousMinimumValues.push(x);
            }

            stk.push(x);
        }

        void pop()
        {
            int value=stk.top();

            if(value==getMin())
            {
                previousMinimumValues.pop();
            }

            stk.pop();
        }

        int top()
        {
            return stk.top();
        }

        int getMin()
        {
            return previousMinimumValues.top();
        }
};