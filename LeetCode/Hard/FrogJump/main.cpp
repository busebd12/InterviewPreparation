#include <iostream>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>

/*
 * Solutions:
 *
 * 1. Recursion + Depth-first search.
 *
 * Time complexity: O(3^n) [where n is the number of stones]
 * Space complexity: O(n) recursive stack space used
 *
 * 2. Top-down memoization.
 *
 * Time complexity: O(n^2)
 * Space complexity: O(n^2)
 *
 * 3. Bread-first search. If we view moving from one stone to the next as moving from one node to another
 * node in a graph, then this problem is asking whether a path exists from the start node (stone) to the ending
 * node (stone) in the graph. We can use breadth-first search to solve this.
 *
 * Time complexity: O(n^2)
 * Space complexity: O(n^2)
 *
 *
 */

bool dfs(std::vector<int> & stones, std::unordered_map<int, int> & hashtable, int n, int k, int previousStone, int start)
{
    if(start==n-1)
    {
        return true;
    }

    if(start > n-1)
    {
        return false;
    }

    bool subproblem=false;

    for(int count=0;count<3;count++)
    {
        int nextJump=0;

        int nextStone=0;

        if(count==0)
        {
            nextJump=k-1;
        }
        else if(count==1)
        {
            nextJump=k;
        }
        else
        {
            nextJump=k + 1;
        }

        nextStone=previousStone + nextJump;

        if(nextJump > 0)
        {
            if(hashtable.count(nextStone))
            {
                if(dfs(stones, hashtable, n, nextJump, nextStone, hashtable[nextStone]))
                {
                    subproblem=true;

                    return subproblem;
                }
            }
        }
    }

    return subproblem;
}

bool canCross(std::vector<int> & stones)
{
    int n=int(stones.size());

    std::unordered_map<int, int> hashtable;

    for(int i=0;i<n;i++)
    {
        int stone=stones[i];

        hashtable[stone]=i;
    }

    int k=0;

    int start=0;

    int previousStone=0;

    bool result=dfs(stones, hashtable, n, k, previousStone, start);

    return result;
}

bool memoization(std::vector<int> & stones, std::unordered_map<int, int> & hashtable, std::vector<std::vector<int>> & dp, int n, int k, int previousStone, int start)
{
    if(start==n-1)
    {
        return true;
    }

    if(start > n-1)
    {
        return false;
    }

    if(dp[start][k]!=-1)
    {
        return dp[start][k];
    }

    bool subproblem=0;

    for(int count=0;count<3;count++)
    {
        int nextJump=0;

        int nextStone=0;

        if(count==0)
        {
            nextJump=k-1;
        }
        else if(count==1)
        {
            nextJump=k;
        }
        else
        {
            nextJump=k + 1;
        }

        nextStone=previousStone + nextJump;

        if(nextJump > 0)
        {
            if(hashtable.count(nextStone))
            {
                if(memoization(stones, hashtable, dp, n, nextJump, nextStone, hashtable[nextStone]))
                {
                    subproblem=1;

                    return subproblem;
                }
            }
        }
    }

    dp[start][k]=subproblem;

    return subproblem;
}

bool canCross(std::vector<int> & stones)
{
    int n=int(stones.size());

    std::vector<std::vector<int>> dp(n, std::vector<int>(n, -1));

    std::unordered_map<int, int> hashtable;

    for(int i=0;i<n;i++)
    {
        int stone=stones[i];

        hashtable[stone]=i;
    }

    int k=0;

    int start=0;

    int previousStone=0;

    bool result=memoization(stones, hashtable, dp, n, k, previousStone, start);

    return result;
}

bool bfs(std::vector<int> & stones)
{
    int n=int(stones.size());

    std::unordered_map<int, int> hashtable;

    for(int i=0;i<n;i++)
    {
        int stone=stones[i];

        hashtable[stone]=i;
    }

    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

    std::queue<std::tuple<int, int, int>> Q;

    int k=0;

    int start=0;

    int previousStone=0;

    Q.emplace(std::make_tuple(k, previousStone, start));

    while(!Q.empty())
    {
        int qSize=int(Q.size());

        for(int count=0;count<qSize;count++)
        {
            auto current=Q.front();

            Q.pop();

            int index=std::get<2>(current);

            k=std::get<0>(current);

            previousStone=std::get<1>(current);

            if(index==n-1)
            {
                return true;
            }

            if(dp[index][k]==1 || index > n-1)
            {
                continue;
            }

            dp[index][k]=1;

            for(int i=0;i<3;i++)
            {
                int nextJump=0;

                int nextStone=0;

                if(i==0)
                {
                    nextJump=k-1;
                }
                else if(i==1)
                {
                    nextJump=k;
                }
                else
                {
                    nextJump=k + 1;
                }

                nextStone=previousStone + nextJump;

                if(nextJump > 0)
                {
                    if(hashtable.count(nextStone))
                    {
                        Q.emplace(std::make_tuple(nextJump, nextStone, hashtable[nextStone]));
                    }
                }
            }
        }
    }

    return false;
}

bool canCross(std::vector<int> & stones)
{
    bool result=bfs(stones);

    return result;
}