#include <iostream>
#include <queue>
#include <deque>
using namespace std;

/*
 * Approaches, from top-to-bottom:
 *
 * 1) Use two queues, main and extra. When we push a new element onto our stack
 * we move all the elements currently in the main queue into our extra queue,
 * insert the new element, and then copy the elements back into the main queue.
 *
 * 2) Use a deque (double ended queue) and only add and remove from the end/back
 * of the deque. This exactly mimics a stack and could be considered "cheating"
 * in terms of the question.
 */

class MyStack
{
    public:
        queue<int> main;
        queue<int> extra;

        MyStack()
        {

        }

        void push(int x)
        {
            if(!empty())
            {
                emptyMain();
            }

            main.push(x);

            if(!extra.empty())
            {
                fillMain();
            }
        }

        int pop()
        {
            int firstElement=top();

            main.pop();

            return firstElement;
        }

        int top()
        {
            return main.front();
        }

        bool empty()
        {
            return main.empty();
        }

        void emptyMain()
        {
            while(!main.empty())
            {
                int current=main.front();

                main.pop();

                extra.push(current);
            }
        }

        void fillMain()
        {
            while(!extra.empty())
            {
                int current=extra.front();

                extra.pop();

                main.push(current);
            }
        }
};


class MyStack
{
    public:

        deque<int> dq;

        MyStack()
        {

        }

        void push(int x)
        {
            dq.push_back(x);
        }

        int pop()
        {
            int firstElement=top();

            dq.pop_back();

            return firstElement;
        }

        int top()
        {
            return dq.back();
        }

        bool empty()
        {
            return dq.empty();
        }
};