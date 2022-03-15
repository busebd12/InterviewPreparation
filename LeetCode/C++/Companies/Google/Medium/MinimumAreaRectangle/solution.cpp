#include <cmath>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/*
Solution: inspired from this post --> https://leetcode.com/problems/minimum-area-rectangle/discuss/1306328/C%2B%2B-Solution-using-Hash-Map

Time complexity: O(n^2) [where n is the number of points]
Space complexity: O(n)
*/

class Solution
{
    public:
        int minAreaRect(vector<vector<int>> & points)
        {
            int result=numeric_limits<int>::max();
            
            unordered_map<int, unordered_set<int>> hashtable;
            
            for(auto point : points)
            {
                int xCoordinate=point[0];
                
                int yCoordinate=point[1];
                
                hashtable[xCoordinate].insert(yCoordinate);
            }
            
            int n=points.size();
            
            for(int i=0;i<n;i++)
            {
                for(int j=i+1;j<n;j++)
                {
                    int x1=points[i][0];
                    
                    int y1=points[i][1];
                    
                    int x2=points[j][0];
                    
                    int y2=points[j][1];
                    
                    if((x1!=x2) && (y2!=y1))
                    {
                        if(hashtable[x1].find(y2)!=end(hashtable[x1]) && hashtable[x2].find(y1)!=end(hashtable[x2]))
                        {
                            result=min(result, (abs(x1 - x2) * abs(y1 - y2)));
                        }
                    }
                }
            }
            
            return (result==numeric_limits<int>::max()) ? 0 : result;
        }
};