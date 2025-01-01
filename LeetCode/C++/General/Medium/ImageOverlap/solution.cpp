#include <algorithm>
#include <map>
#include <utility>
#include <vector>
using namespace std;

/*
Solution: inspired by these posts

1) https://leetcode.com/problems/image-overlap/solutions/662082/c-solution-to-compute-the-max-count-of-pairwise-vector-differences/
2) https://leetcode.com/problems/image-overlap/solutions/832485/javascript-linear-transformation-with-comments/
3) https://leetcode.com/problems/image-overlap/solutions/832947/python-linear-algebra-solution-beats-50-optimized-for-code-understandability/

Time complexity: O(n^2 + (n^4 * log(n^4))
Space complexity: O(n^2)
*/

class Solution
{
    public:
        int largestOverlap(vector<vector<int>> & img1, vector<vector<int>> & img2)
        {
            int result=0;

            int n=img1.size();

            vector<pair<int, int>> img1OneCoordinates;

            for(int row=0;row<n;row++)
            {
                for(int column=0;column<n;column++)
                {
                    if(img1[row][column]==1)
                    {
                        img1OneCoordinates.emplace_back(row, column);
                    }
                }
            }

            vector<pair<int, int>> img2OneCoordinates;

            for(int row=0;row<n;row++)
            {
                for(int column=0;column<n;column++)
                {
                    if(img2[row][column]==1)
                    {
                        img2OneCoordinates.emplace_back(row, column);
                    }
                }
            }

            map<pair<int, int>, int> hashmap;

            for(auto & [img1Row, img1Column] : img1OneCoordinates)
            {
                for(auto & [img2Row, img2Column] : img2OneCoordinates)
                {
                    int dx=img1Row - img2Row;

                    int dy=img1Column - img2Column;

                    pair<int, int> transformationVector(dx, dy);

                    if(hashmap.find(transformationVector)==hashmap.end())
                    {
                        hashmap.emplace(transformationVector, 0);
                    }

                    hashmap[transformationVector]+=1;
                }
            }

            for(auto & [key, frequency] : hashmap)
            {
                result=max(result, frequency);
            }

            return result;
        }
};