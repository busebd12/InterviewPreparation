#include <iostream>
#include <vector>
using namespace std;

//Time complexity: O(m*n)
//Space complexity: O(1)
int uniquePathsWithObstacles(vector<vector<int>> & obstacleGrid)
{
    int m=int(obstacleGrid.size());

    if(m==0)
    {
        return 0;
    }

    int n=int(obstacleGrid[0].size());

    if(n==0)
    {
        return 0;
    }

    //First spot is an obstacle, we can't go anywhere
    if(obstacleGrid[0][0]==1)
    {
        return 0;
    }

    obstacleGrid[0][0]=1;

    //Traverse first column. As soon as we hit an obstacle, we can make that spot and every spot after it a zero
    for(int i=1;i<m;++i)
    {
        if(obstacleGrid[i][0]==1)
        {
            obstacleGrid[i][0]=0;
        }
        else
        {
            obstacleGrid[i][0]=obstacleGrid[i-1][0];
        }
    }

    //Traverse first row. As soon as we hit an obstacle, we can make that spot and every spot after it a zero
    for(int j=1;j<n;++j)
    {
        if(obstacleGrid[0][j]==1)
        {
            obstacleGrid[0][j]=0;
        }
        else
        {
            obstacleGrid[0][j]=obstacleGrid[0][j-1];
        }
    }

    //Now, just use dynamic programming
    for(int i=1;i<m;++i)
    {
        for(int j=1;j<n;++j)
        {
            //Found an obstacle, no paths from here
            if(obstacleGrid[i][j]==1)
            {
                obstacleGrid[i][j]=0;
            }
            //No obstacle; count the paths
            else
            {
                obstacleGrid[i][j]=obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
            }
        }
    }

    return obstacleGrid[m-1][n-1];
}