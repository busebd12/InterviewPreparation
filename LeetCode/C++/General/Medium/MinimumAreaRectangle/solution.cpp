#include <set>
#include <utility>
#include <vector>
using namespace std;

/*
Solution: see comments.

Time complexity: O(n log n) + O(n^2 * log(n)) [where n is the number of points]
Space complexity: O(n)
*/

class Solution
{
    public:
        int minAreaRect(vector<vector<int>> & points)
        {
            int result=numeric_limits<int>::max();
            
            int n=points.size();
            
            set<pair<int, int>> ordered;
            
            for(auto & point : points) //O(n)
            {
                int x=point[0];
                
                int y=point[1];
                
                ordered.emplace(x, y); //log(n)
            }
            
            for(int i=0;i<n;i++) //O(n)
            {
                int x1=points[i][0];
                    
                int y1=points[i][1];
                
                for(int j=i+1;j<n;j++) //O(n)
                {
                    int x2=points[j][0];
                    
                    int y2=points[j][1];
                    
                    //Ensure that (x1, y1) and (x2, y2) are diagonal from each other
                    if(x1 != x2 && y1 != y2)
                    {
                        //If the set contains the other two diagonally located points
                        if(ordered.find({x1, y2})!=end(ordered) && ordered.find({x2, y1})!=end(ordered)) //O(log(n))
                        {
                            int width=abs(y2 - y1);
                        
                            int length=abs(x2 - x1);

                            int area=length * width;

                            result=min(result, area);
                        }
                    }
                }
            }
            
            return (result==numeric_limits<int>::max()) ? 0 : result;
        }
};