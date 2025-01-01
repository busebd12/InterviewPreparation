#include <algorithm>
#include <vector>
using namespace std;

/*
Time complexity: O(rows * (rows * log(columns)))
Space complexity: O(1)
*/

class Solution
{
    public:
        int smallestCommonElement(vector<vector<int>> & mat)
        {
            int rows=mat.size();

            int columns=mat[0].size();

            for(int column=0;column<columns;column++) //O(columns)
            {
                int target=mat[0][column];

                bool foundInAllRows=true;

                for(int row=1;row<rows;row++) //O(rows)
                {
                    auto itr=lower_bound(mat[row].begin(), mat[row].end(), target); //O(log(columns))

                    if(itr==mat[row].end())
                    {
                        foundInAllRows=false;
                    }
                    else
                    {
                        if(*itr!=target)
                        {
                            foundInAllRows=false;
                        }
                    }
                }

                if(foundInAllRows==true)
                {
                    return target;
                }
            }

            return -1;
        }
};