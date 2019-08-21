#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
 * Approaches:
 *
 * 1) Recursive depth-first search
 *
 * Time complexity: O(number of nested levels)
 * Space complexity: O(number of nested levels)
 *
 * 2) Iterative depth-first search
 *
 * Time complexity: O(number of nested levels)
 * Space complexity: O(number of nested levels)
 */

void dfs(vector<NestedInteger> & nestedList, int & sum, int & weight)
{
    for(int i=0;i<nestedList.size();++i)
    {
        if(nestedList[i].isInteger())
        {
            sum+=(nestedList[i].getInteger() * weight);
        }
        else
        {
            dfs(nestedList[i].getList(), sum, weight+=1);
        }
    }

    weight-=1;
}

int depthSum(vector<NestedInteger>& nestedList)
{
    int sum=0;

    int weight=1;

    dfs(nestedList, sum, weight);

    return sum;
}

int depthSum(vector<NestedInteger> & nestedList)
{
    int sum=0;

    stack<pair<vector<NestedInteger>, int>> stk;

    pair<vector<NestedInteger>, int> p(nestedList, 1);

    stk.push(p);

    while(!stk.empty())
    {
        pair<vector<NestedInteger>, int> current=stk.top();

        stk.pop();

        for(int index=0;index<current.first.size();++index)
        {
            if(current.first[index].isInteger())
            {
                sum+=(current.first[index].getInteger() * current.second);
            }
            else
            {
                stk.push(make_pair(current.first[index].getList(), current.second+1));
            }
        }
    }

    return sum;
}