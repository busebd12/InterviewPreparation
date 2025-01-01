#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

/*
Solution 1: recursion + backtracking. Note, this solution receives Time Limit Exceeded when executed.

Time complexity: O(rows * columns)
Space complexity: O(rows) recursive stack space
*/

class Solution
{
    public:
        int maximumInvitations(vector<vector<int>> & grid)
        {
            int result=0;

            int rows=grid.size();

            int columns=grid[0].size();

            unordered_set<int> invited;

            int invitations=0;

            int boy=0;

            helper(grid, invited, rows, columns, result, invitations, boy);

            return result;
        }

        void helper(vector<vector<int>> & grid, unordered_set<int> & invited, int rows, int columns, int & result, int invitations, int boy)
        {
            if(boy==rows)
            {
                result=max(result, static_cast<int>(invited.size()));

                return;
            }

            bool ableToInvite=false;

            for(int girl=0;girl<columns;girl++)
            {
                if(grid[boy][girl]==1 and invited.find(girl)==invited.end())
                {
                    ableToInvite=true;
                    
                    invited.insert(girl);

                    helper(grid, invited, rows, columns, result, invitations, boy + 1);

                    invited.erase(girl);
                }
            }

            if(ableToInvite==false)
            {
                helper(grid, invited, rows, columns, result, invitations, boy + 1);
            }
        }
};

/*
Solution 2: based on this post --> https://leetcode.com/problems/maximum-number-of-accepted-invitations/solutions/1978859/python-hungarian-algorithm-easy-to-understand/

Time complexity: O(rows * columns)
Space complexity: O(rows)
*/

class Solution
{
    public:
        int maximumInvitations(vector<vector<int>> & grid)
        {
            int result=0;

            int rows=grid.size();

            int columns=grid[0].size();

            vector<int> matches(columns, -1);

            for(int boy=0;boy<rows;boy++)
            {
                vector<int> visited(columns, 0);
                
                if(helper(grid, matches, visited, rows, columns, boy)==true)
                {
                    result+=1;
                }
            }

            return result;
        }

        bool helper(vector<vector<int>> & grid, vector<int> & matches, vector<int> & visited, int rows, int columns, int boy)
        {
            for(int girl=0;girl<columns;girl++)
            {
                //Rule 1. Only ask that girl if you haven't asked her before
                if(grid[boy][girl]==1 and visited[girl]==0)
                {
                    visited[girl]=1;

                    //Rule 2. If you wish to ask a girl that's taken, she will only go with you if her current partner finds a new girl.
                    if(matches[girl]==-1 or helper(grid, matches, visited, rows, columns, matches[girl])==true)
                    {
                        matches[girl]=boy;

                        return true;
                    }
                }
            }

            return false;
        }
};