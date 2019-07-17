#include <iostream>
#include <vector>
using namespace std;

/*
 * Approach: alternate the generating of the rows of Pascal's triangle (even vs odd).
 * If rowIndex is even, return the last even row. Else, return the last odd row.
 *
 * Time complexity: O(rowIndex) [where rowIndex is the index of the target row of Pascal's triangle]
 * Space complexity: O(rowIndex number of rows)
 */

vector<int> getRow(int rowIndex)
{
    int level=1;

    vector<int> evenRow(rowIndex + 1, 1);

    vector<int> oddRow(rowIndex + 1, 1);

    while(level < rowIndex)
    {
        for(int i=1;i<level+1;++i)
        {
            if(level % 2)
            {
                oddRow[i]=evenRow[i - 1] + evenRow[i];
            }
            else
            {
                evenRow[i]=oddRow[i - 1] + oddRow[i];
            }

        }

        ++level;
    }

    return rowIndex % 2 ? evenRow : oddRow;
}