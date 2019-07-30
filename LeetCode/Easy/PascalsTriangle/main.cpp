#include <iostream>
#include <vector>
using namespace std;

/*
 * Approach: Bottom-up dynamic programming. We start with our base case, a row of just a single number, 1.
 * Then, we loop from [2, numsRows] (2 to numRows, inclusive), create the new row based off of the previous row,
 * and add the new row to our vector<vector<int>> dp.
 *
 * Time complexity: O(numRows) [where numRows is the number of rows we want to generate]
 * Space complexity: O(numRows) [where numRows is the number of rows we want to generate]
 */

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> dp;

    if(numRows==0)
    {
        return dp;
    }

    vector<int> first={1};

    dp.push_back(first);

    for(int i=2;i<=numRows;++i)
    {
        int lastRow=int(dp.size()-1);

        int lastRowSize=int(dp[dp.size()-1].size());

        vector<int> row(lastRowSize+1);

        for(int j=0,k=int(row.size());j<k;++j)
        {
            if(j==0 || j==k-1)
            {
                row[j]=1;
            }
            else
            {
                row[j]=dp[lastRow][j-1] + dp[lastRow][j];
            }
        }

        dp.push_back(row);
    }

    return dp;
}