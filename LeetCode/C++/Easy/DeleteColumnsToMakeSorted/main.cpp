#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
 * Approach: we just need to count the number of columns that are not sorted in ascending order.
 * So, do a column-order traversal of all the strings and increment are count variable if the
 * column is not sorted in ascending order. Return the count variable after we are done.
 *
 * Time complexity: O(m * n) [where n is the number columns and n is the number of rows formed by our vector<string> A]
 * Space complexity: O(1)
 */

int minDeletionSize(vector<string> & A)
{
    int rows=int(A.size());

    int columns=int(A[0].size());

    int count=0;

    for(int i=0;i<columns;++i)
    {
        for(int j=0;j<rows;++j)
        {
            if(j+1 < rows)
            {
                if(A[j][i] > A[j+1][i])
                {
                    count++;

                    break;
                }
            }
        }
    }

    return count;
}