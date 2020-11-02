#include <iostream>
#include <stack>
using namespace std;

/*
 * Approach: Use two stacks, main and extra.
 * When we are inserting an element, move all elements from main to extra.
 * Then, add the element to main. Finally, move all the elements from extra
 * back to main.
 */

class MyQueue
{
    public:
        stack<int> main;
        stack<int> extra;

        MyQueue()
        {

        }

        void push(int x)
        {
            if(!empty())
            {
                emptyMain();
            }

            main.push(x);

            fillMain();
        }

        int pop()
        {
            int topElement=main.top();

            main.pop();

            return topElement;
        }

        int peek()
        {
            return main.top();
        }

        bool empty()
        {
            return main.empty();
        }

        void emptyMain()
        {
            while(!main.empty())
            {
                int current=main.top();

                main.pop();

                extra.push(current);
            }
        }

        void fillMain()
        {
            while(!extra.empty())
            {
                int current=extra.top();

                extra.pop();

                main.push(current);
            }
        }
};