#include <iostream>
#include <stack>
#include <map>
#include <unordered_map>
using namespace std;

/*
 * Approaches:
 *
 * 1) Use a stack<int> to keep track of all the elements and an unordered_map<int, int> to keep track of the current and next maximum values.
 *
 * push() time complexity: O(1)
 * push() space complexity: O(1)
 *
 * pop() time complexity: O(1)
 * pop() space complexity: O(1)
 *
 * top() time complexity: O(1)
 * top() space complexity: O(1)
 *
 * peekMax() time complexity: O(number of maximum values that map to zero before we find a maximum value that maps to >= 1)
 * peekMax() space complexity: O(1)
 *
 * popMax() time complexity: O(m) [where m is the number of elements in our stack]
 * popMax() space complexity: O(m)
 *
 *
 * 2) Use a stack<int> to keep track of all the elements and a map<int, int> to keep all the different maximum values ordered.
 *
 * push() time complexity: O(log m) [where m is the size of our hashtable]
 * push() space complexity: O(1)
 *
 * pop() time complexity: O(log m)
 * pop() space complexity: O(1)
 *
 * top() time complexity: O(1)
 * top() space complexity: O(1)
 *
 * peekMax() time complexity: O(1)
 * peekMax() space complexity: O(1)
 *
 * popMax() time complexity: O(log m) + O(s) [where s the size of our stack]
 * popMax() space complexity: O(s)
 */

class MaxStack
{
    public:
        stack<int> stk;

        stack<int> extra;

        unordered_map<int, int> hashtable;

        MaxStack()
        {

        }

        void push(int x)
        {
            stk.push(x);

            hashtable[x]++;
        }

        int pop()
        {
            int topElement=stk.top();

            stk.pop();

            hashtable[topElement]--;

            return topElement;
        }

        int top()
        {
            return stk.top();
        }

        int peekMax()
        {
            unordered_map<int, int>::iterator itr;

            while(true)
            {
                itr=max_element(hashtable.begin(), hashtable.end(), [] (const auto & x1, const auto & x2) {return x1.first < x2.first && x1.second > 0;});

                if(itr->second > 0)
                {
                    break;
                }
                else
                {
                    hashtable.erase(itr->first);
                }
            }

            return itr->first;
        }

        int popMax()
        {
            int currentMax=peekMax();

            if(hashtable[currentMax] > 0)
            {
                hashtable[currentMax]--;
            }

            if(!stk.empty())
            {
                while(stk.top()!=currentMax)
                {
                    int number=stk.top();

                    stk.pop();

                    extra.push(number);
                }

                if(!stk.empty() && stk.top()==currentMax)
                {
                    stk.pop();
                }

                while(!extra.empty())
                {
                    int current=extra.top();

                    extra.pop();

                    stk.push(current);
                }
            }

            return currentMax;
        }
};


class MaxStack
{
    public:
        stack<int> stk;

        stack<int> extra;

        map<int, int> hashtable;

        MaxStack()
        {

        }

        void push(int x)
        {
            stk.push(x);

            ++hashtable[x];
        }

        int pop()
        {
            int topElement=stk.top();

            stk.pop();

            --hashtable[topElement];

            if(hashtable[topElement]==0)
            {
                hashtable.erase(topElement);
            }

            return topElement;
        }

        int top()
        {
            return stk.top();
        }

        int peekMax()
        {
            return hashtable.rbegin()->first;
        }

        int popMax()
        {
            int currentMax=peekMax();

            if(!stk.empty())
            {
                while(stk.top()!=currentMax && !stk.empty())
                {
                    int number=stk.top();

                    stk.pop();

                    extra.push(number);
                }

                if(!stk.empty())
                {
                    stk.pop();
                }

                while(!extra.empty())
                {
                    int current=extra.top();

                    extra.pop();

                    stk.push(current);
                }
            }

            --hashtable[currentMax];

            if(hashtable[currentMax]==0)
            {
                hashtable.erase(currentMax);
            }

            return currentMax;
        }
};