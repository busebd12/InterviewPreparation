#include <iostream>
#include <stack>
#include <vector>

/*
 * Solutions:
 *
 * 1. When we initialize the NestedIterator object, we recursively flatten the input nested list into a single-level
 * std::vector of integers. Then, we just iterate through the flattened list of integers and return each one.
 *
 * Time complexity: O(n) [where n is the length of the input nested list]
 * Space complexity: O(d) [where d is the total number of numbers contained within the nested list]
 *
 * 2. We use a stack to hold all the NestedIntegers from our list. Then, when we want to get the next integer, we
 * call the next function which return the single integer value from the top of the stack. Within the hasNext function,
 * we flatten the input nested list so that the top of the stack is always a single integer, not a list.
 *
 * Time complexity: O(n) [where n is the length of the input nested list]
 * Space complexity: O(d) [where d is the total number of numbers contained within the nested list]
 */

class NestedInteger
{
    public:
        bool isInteger() const;

        int getInteger() const;

        const std::vector<NestedInteger> &getList() const;
};

class NestedIterator
{
    public:

        std::vector<NestedInteger> nested;

        std::vector<int> flattened;

        std::size_t index;

        NestedIterator(std::vector<NestedInteger> & nestedList)
        {
            nested=nestedList;

            index=0;

            flatten(nested);
        }

        int next()
        {
            return flattened[index++];
        }

        bool hasNext()
        {
            return index < flattened.size();
        }

        void flatten(const std::vector<NestedInteger> & nested)
        {
            for(const NestedInteger & ni : nested)
            {
                if(ni.isInteger())
                {
                    flattened.emplace_back(ni.getInteger());
                }
                else
                {
                    flatten(ni.getList());
                }
            }
        }
};

class NestedIterator
{
    public:
        std::stack<NestedInteger> stk;

        NestedIterator(std::vector<NestedInteger> & nestedList)
        {
            auto size=int(nestedList.size());

            for(auto index=size-1;index>=0;--index)
            {
                stk.push(nestedList[index]);
            }
        }

        int next()
        {
            auto result=stk.top().getInteger();

            stk.pop();

            return result;
        }

        bool hasNext()
        {
            while(!stk.empty())
            {
                auto current=stk.top();

                if(current.isInteger())
                {
                    return true;
                }

                stk.pop();

                auto list=current.getList();

                int size=int(list.size());

                for(auto index=size-1;index>=0;--index)
                {
                    stk.push(list[index]);
                }
            }

            return false;
        }
};