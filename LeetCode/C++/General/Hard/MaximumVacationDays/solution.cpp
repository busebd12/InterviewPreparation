#include <algorithm>
#include <vector>
using namespace std;

/*
Solution 1: recursive depth-first search.

Time complexity: O(n^k)
Space complexity: O(k) [recursive stack space]
*/

class Solution
{
    public:
        int maxVacationDays(vector<vector<int>> & flights, vector<vector<int>> & days)
        {
            int result=0;

            int n=flights.size();

            int k=days[0].size();

            int week=0;

            int city=0;

            result=helper(flights, days, n, k, city, week);

            return result;
        }

        int helper(vector<vector<int>> & flights, vector<vector<int>> & days, int n, int k, int city, int week)
        {
            if(week==k)
            {
                return 0;
            }

            int subproblemSolution=0;

            for(int destination=0;destination<flights[city].size();destination++)
            {
                int flight=flights[city][destination];
                
                if(flight==1 or destination==city)
                {
                    int pickThisDestination=days[destination][week] + helper(flights, days, n, k, destination, week + 1);

                    subproblemSolution=max(subproblemSolution, pickThisDestination);
                }
            }

            return subproblemSolution;
        }
};

/*
Solution 2: recursive depth-first search + memoization

Time complexity: O(n * k)
Space complexity: O(n * k)
*/

class Solution
{
    public:
        int maxVacationDays(vector<vector<int>> & flights, vector<vector<int>> & days)
        {
            int result=0;

            int n=flights.size();

            int k=days[0].size();

            vector<vector<int>> memo(n + 1, vector<int>(k + 1, -1));

            int week=0;

            int city=0;

            result=helper(flights, days, memo, n, k, city, week);

            return result;
        }

        int helper(vector<vector<int>> & flights, vector<vector<int>> & days, vector<vector<int>> & memo, int n, int k, int city, int week)
        {
            if(week==k)
            {
                return 0;
            }

            if(memo[city][week]!=-1)
            {
                return memo[city][week];
            }

            int subproblemSolution=0;

            for(int destination=0;destination<flights[city].size();destination++)
            {
                int flight=flights[city][destination];
                
                if(flight==1 or destination==city)
                {
                    int pickThisDestination=days[destination][week] + helper(flights, days, memo, n, k, destination, week + 1);

                    subproblemSolution=max(subproblemSolution, pickThisDestination);
                }
            }

            memo[city][week]=subproblemSolution;

            return subproblemSolution;
        }
};