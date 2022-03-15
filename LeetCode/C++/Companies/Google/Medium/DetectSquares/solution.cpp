#include <vector>

/*
Solution: inspired from this post --> https://leetcode.com/problems/detect-squares/discuss/1471958/C%2B%2BJavaPython-2-approaches-using-HashMap-with-Picture-Clean-and-Concise

Space complexity: O(1001 * 1001) => O(1)
*/

class DetectSquares
{
    public:
        int hashtable[1001][1001]={};
    
        vector<pair<int, int>> points;
        
        DetectSquares()
        {
            
        }

        //Time complexity: O(1)
        void add(vector<int> point)
        {
            int x=point[0];
            
            int y=point[1];
            
            hashtable[x][y]++;
            
            points.emplace_back(x, y);
        }

        //Time complexity: O(p) [where p is the total number of points]
        int count(vector<int> point)
        {   
            int result=0;
            
            int x1=point[0];
            
            int y1=point[1];
            
            for(auto & [x2, y2] : points)
            {   
                if(abs(x1-x2)==abs(y1-y2) && abs(x1-x2) > 0)
                {   
                    result+=hashtable[x2][y1] * hashtable[x1][y2];
                }
            }
            
            return result;
        }
};
