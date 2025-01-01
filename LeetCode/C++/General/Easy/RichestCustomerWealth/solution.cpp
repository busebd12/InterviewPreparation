#include <algorithm>
#include <vector>
using namespace std;

/*
Solution

Submission status: accepted.

Time complexity: O(rows * columns)

Space complexity: O(rows)
*/

class Solution
{
    public:
        int maximumWealth(vector<vector<int>> & accounts)
        {
            int result=0;

            int rows=accounts.size();

            int columns=accounts[0].size();

            vector<int> customers(rows, 0);

            for(int row=0;row<rows;row++)
            {
                for(int column=0;column<columns;column++)
                {
                    int amount=accounts[row][column];

                    customers[row]+=amount;
                }
            }

            for(int wealth : customers)
            {
                result=max(result, wealth);
            }

            return result;
        }
};