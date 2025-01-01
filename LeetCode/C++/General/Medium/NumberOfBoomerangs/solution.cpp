#include <unordered_map>
#include <vector>
using namespace std;

/*
Solution: inspired by this discussion: https://leetcode.com/problems/number-of-boomerangs/solutions/92868/short-python-o-n-2-hashmap-solution/comments/113268

Time complexity: O(p^2) [where p is the total number of points]
Space complexity: O(u) [where u is the number of unique distances between points]
*/

class Solution
{
    public:
        int numberOfBoomerangs(vector<vector<int>> & points)
        {
            int result=0;
            
            int n=points.size();
            
            for(int i=0;i<n;++i)
            {
                unordered_map<int, int> hashmap;
                
                for(int j=0;j<n;++j)
                {
                    if(j!=i)
                    {
                        int distance=getDistance(points[i], points[j]);

                        if(hashmap.find(distance)==hashmap.end())
                        {
                            hashmap.emplace(distance, 0);
                        }

                        hashmap[distance]+=1;
                    }
                }
                
                for(auto & [distance, numberOfPoints] : hashmap)
                {
                    if(numberOfPoints > 1)
                    {
                        int bommerangs=(numberOfPoints) * (numberOfPoints - 1);
                        
                        result+=bommerangs;
                    }
                }
            }
            
            return result;
        }

        int getDistance(vector<int> & point1, vector<int> & point2)
        {
            int distance=0;
            
            int x1=point1[0];

            int y1=point1[1];

            int x2=point2[0];

            int y2=point2[1];

            int xPart=(x2 - x1) * (x2 - x1);

            int yPart=(y2 - y1) * (y2 - y1);

            distance=xPart + yPart;

            return distance;
        }
};