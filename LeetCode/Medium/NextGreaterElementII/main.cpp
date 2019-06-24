#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <deque>
using namespace std;

vector<int> nextGreaterElementsTLE(vector<int> & nums)
{
    if(nums.empty())
    {
        return {};
    }

    int n=int(nums.size());

    vector<int> result(n, -1);

    unordered_map<int, set<int>> indices;

    for(int index=0;index<n;++index)
    {
        indices.insert(make_pair(nums[index], set<int>()));
    }

    for(int i=0;i<n;++i)
    {
        int target=nums[i];

        for(int j=0;j<n;++j)
        {
            if(i!=j)
            {
                if(nums[j] > target)
                {
                    indices[target].insert(j);
                }
            }
        }
    }

    unordered_map<int, int> indexToValue;

    for(int index=0;index<n;++index)
    {
        indexToValue[index]=nums[index];
    }

    for(int index=0;index<n;++index)
    {
        int target=nums[index];

        if(!indices[target].empty())
        {
            auto itr=upper_bound(indices[target].begin(), indices[target].end(), index);

            if(itr!=indices[target].end())
            {
                result[index]=indexToValue[*itr];
            }
            else
            {
                result[index]=indexToValue[*(indices[target].begin())];
            }
        }
    }

    return result;
}

vector<int> nextGreaterElementsTLE2(vector<int> & nums)
{
    if(nums.empty())
    {
        return {};
    }

    int n=int(nums.size());

    vector<int> result(n, -1);

    stack<pair<int, int>> normalOrder;

    stack<pair<int, int>> reverseOrder;

    for(int index=0;index<n;++index)
    {
        reverseOrder.push(make_pair(nums[index], index));
    }

    for(int index=0;index<n;++index)
    {
        int target=nums[index];

        pair<int, int> nextGreaterBefore(-1, -1);

        pair<int, int> nextGreaterAfter(-1, -1);

        while(!reverseOrder.empty())
        {
            auto candidate=reverseOrder.top();

            reverseOrder.pop();

            if(candidate.second <= index)
            {
                if(candidate.first > target)
                {
                    if(nextGreaterBefore.first==-1 && nextGreaterBefore.second==-1)
                    {
                        nextGreaterBefore.first=candidate.first;

                        nextGreaterBefore.second=candidate.second;
                    }
                    else
                    {
                        if(candidate.second < nextGreaterBefore.second)
                        {
                            nextGreaterBefore.first=candidate.first;

                            nextGreaterBefore.second=candidate.second;
                        }
                    }
                }
            }
            else
            {
                if(candidate.first > target)
                {
                    if(nextGreaterAfter.first==-1 && nextGreaterAfter.second==-1)
                    {
                        nextGreaterAfter.first=candidate.first;

                        nextGreaterAfter.second=candidate.second;
                    }
                    else
                    {
                        if(candidate.second < nextGreaterAfter.second)
                        {
                            nextGreaterAfter.first=candidate.first;

                            nextGreaterAfter.second=candidate.second;
                        }
                    }
                }
            }

            normalOrder.push(candidate);
        }

        if((nextGreaterBefore.first!=-1 && nextGreaterBefore.second!=-1) && (nextGreaterAfter.first==-1 && nextGreaterAfter.second==-1))
        {
            result[index]=nextGreaterBefore.first;
        }
        else if((nextGreaterBefore.first==-1 && nextGreaterBefore.second==-1) && (nextGreaterAfter.first!=-1 && nextGreaterAfter.second!=-1))
        {
            result[index]=nextGreaterAfter.first;
        }
        else
        {
            if(index==n-1)
            {
                result[index]=nextGreaterBefore.first;
            }
            else if(index==0)
            {
                result[index]=nextGreaterAfter.first;
            }
            else
            {
                if(nextGreaterBefore.second > index)
                {
                    result[index]=nextGreaterBefore.first;
                }
                else
                {
                    result[index]=nextGreaterAfter.first;
                }
            }
        }

        while(!normalOrder.empty())
        {
            auto element=normalOrder.top();

            reverseOrder.push(element);

            normalOrder.pop();
        }
    }

    return result;
}

vector<int> nextGreaterElements(vector<int>& nums)
{
    unordered_map<int, int> table;

    deque<int> next;

    deque<int> indices;

    int n=int(nums.size());

    for(int i=0;i<n;i++)
    {
        while(!next.empty() && nums[i] > next.back())
        {
            table[indices.back()]=nums[i];

            next.pop_back();

            indices.pop_back();
        }

        next.push_back(nums[i]);

        indices.push_back(i);
    }

    for(int i=0;i<n;i++)
    {
        while(!next.empty() && nums[i] > next.back())
        {
            table[indices.back()]=nums[i];

            next.pop_back();

            indices.pop_back();
        }
    }

    vector<int> result(nums.size(), -1);

    for(int i=0;i<n;i++)
    {
        if(table.find(i)!=table.end())
        {
            result[i]=table[i];
        }
    }

    return result;
}