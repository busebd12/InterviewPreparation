#include <algorithm>
#include <vector>

/*
Solution: inspired by this post --> https://leetcode.com/problems/remove-all-ones-with-row-and-column-flips/discuss/1698026/Java-solution-(with-explanation)

Time complexity: O(m * n) [where m is the number of rows and n is the number of columns in the grid]
Space complexity: O(1)
*/

class Solution
{
    public:
        bool removeOnes(vector<vector<int>> & grid)
        {
            int m=grid.size();
            
            int n=grid[0].size();

            //Iterate through the grid
            for(int column=0;column<n;column++)
            {
                //If any column in the first row is a 1, flip that column
                if(grid[0][column]==1)
                {
                    for(int row=0;row<m;row++)
                    {
                        grid[row][column]=!grid[row][column];
                    }
                }
            }
            
            //Now, after we have flipped all columns in the first row that have 1 in them, the whole first row is all zeros.
            //Since our goal is to make the entire grid all zeros, we can't change the first row at all. By extension, this
            //means that we cannot flip any columns since values in the first row will be affected. So, any further flips
            //we do must be only applied to rows. Since we've already made the first row all zeros, any row flips can only
            //be applied to rows [1, m-1]. However, for any row to become all zeros, it can only have two original states:
            //1) be all zeros [in this case, no flip is necessary] or 2) all ones [in this case, a single flip will make the row all zeros].
            //Therefore, if any of the remaining rows are not all ones or all zeros, then it is not possible to transform the grid into all zeros.
            for(int row=1;row<m;row++)
            {
                //Check if the row is all zeros
                bool allZeros=all_of(begin(grid[row]), end(grid[row]), [] (const auto & number) {return number==0;});

                //Check if the row is all ones
                bool allOnes=all_of(begin(grid[row]), end(grid[row]), [] (const auto & number) {return number==1;});
                
                //If the row is not all zeros or not all ones, then it is not possible to transform the grid into all zeros
                if(!(allZeros || allOnes))
                {
                    return false;
                }
            }
            
            return true;
        }
};