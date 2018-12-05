#include <iostream>
#include <stack>
using namespace std;

class NestedIterator
{
    private:
        stack<int> stk;

    public:
        NestedIterator(vector<NestedInteger> & nestedList)
        {
            dfs(nestedList);
        }

        int next()
        {
            auto result=stk.top();

            stk.pop();

            return result;
        }

        bool hasNext()
        {
            return !stk.empty();
        }

        void dfs(vector<NestedInteger> & nestedList)
        {
            for(int i=nestedList.size()-1;i>=0;--i)
            {
                if(nestedList[i].isInteger())
                {
                    stk.push(nestedList[i].getInteger());
                }
                else
                {
                    dfs(nestedList[i].getList());
                }
            }
        }
};