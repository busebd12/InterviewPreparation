#include <algorithm>
#include <vector>
using namespace std;

/*
Time complexity: O(n^2)
Space complexity: O(n^2)
*/

class Solution
{
    public:
        int orderOfLargestPlusSign(int n, vector<vector<int>> & mines)
        {
            int result=0;

            if(n < 2)
            {
                return result;
            }

            vector<vector<int>> grid(n, vector<int>(n, 1));

            for(const vector<int> & mine : mines)
            {
                int row=mine[0];

                int column=mine[1];

                grid[row][column]=0;
            }

            bool onesExist=false;

            for(int row=0;row<n;row++)
            {
                for(int column=0;column<n;column++)
                {
                    if(grid[row][column]==1)
                    {
                        onesExist=true;
                    }
                }
            }

            if(onesExist==false)
            {
                return result;
            }

            vector<vector<int>> up=populateUpDirection(grid, n);

            vector<vector<int>> down=populateDownDirection(grid, n);

            vector<vector<int>> left=populateLeftDirection(grid, n);

            vector<vector<int>> right=populateRightDirection(grid, n);

            for(int row=0;row<n;row++)
            {
                for(int column=0;column<n;column++)
                {
                    int upLength=up[row][column];

                    int downLength=down[row][column];

                    int leftLength=left[row][column];

                    int rightLength=right[row][column];

                    int rank=min(min(upLength, downLength), min(leftLength, rightLength)) + 1;

                    result=max(result, rank);
                }
            }

            return result;
        }

        vector<vector<int>> populateUpDirection(vector<vector<int>> & grid, int n)
        {
            vector<vector<int>> up(n, vector<int>(n, 0));

            for(int column=0;column<n;column++)
            {
                int ones=0;

                if(grid[0][column]==1)
                {
                    ones=1;
                }

                for(int row=1;row<n;row++)
                {
                    if(grid[row][column]==0)
                    {
                        up[row][column]=0;

                        ones=0;
                    }
                    else
                    {
                        up[row][column]=ones;

                        ones+=1;
                    }
                }
            }

            return up;
        }

        vector<vector<int>> populateDownDirection(vector<vector<int>> & grid, int n)
        {
            vector<vector<int>> down(n, vector<int>(n, 0));

            for(int column=0;column<n;column++)
            {
                int ones=0;

                if(grid[n-1][column]==1)
                {
                    ones=1;
                }

                for(int row=n-2;row>=0;row--)
                {
                    if(grid[row][column]==0)
                    {
                        down[row][column]=0;

                        ones=0;
                    }
                    else
                    {
                        down[row][column]=ones;

                        ones+=1;
                    }
                }
            }

            return down;
        }

        vector<vector<int>> populateLeftDirection(vector<vector<int>> & grid, int n)
        {
            vector<vector<int>> left(n, vector<int>(n, 0));

            for(int row=0;row<n;row++)
            {
                int ones=0;

                if(grid[row][0]==1)
                {
                    ones=1;
                }

                for(int column=1;column<n;column++)
                {
                    if(grid[row][column]==0)
                    {
                        left[row][column]=0;

                        ones=0;
                    }
                    else
                    {
                        left[row][column]=ones;

                        ones+=1;
                    }
                }
            }

            return left;
        }

        vector<vector<int>> populateRightDirection(vector<vector<int>> & grid, int n)
        {
            vector<vector<int>> right(n, vector<int>(n, 0));

            for(int row=0;row<n;row++)
            {
                int ones=0;

                if(grid[row][n-1]==1)
                {
                    ones=1;
                }

                for(int column=n-2;column>=0;column--)
                {
                    if(grid[row][column]==0)
                    {
                        right[row][column]=0;

                        ones=0;
                    }
                    else
                    {
                        right[row][column]=ones;

                        ones+=1;
                    }
                }
            }

            return right;
        }
};