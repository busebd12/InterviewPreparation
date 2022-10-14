#include <algorithm>
#include <set>
#include <vector>
using namespace std;

class Solution
{
    public:
        bool validSquare(vector<int> & p1, vector<int> & p2, vector<int> & p3, vector<int> & p4)
        {
            vector<vector<int>> coordinates;
            
            coordinates.emplace_back(p1);
            
            coordinates.emplace_back(p2);
            
            coordinates.emplace_back(p3);
            
            coordinates.emplace_back(p4);
            
            //Custom comparator for sorting
            auto compareLikeThis=[] (vector<int> & lhs, vector<int> & rhs)
            {
                if(lhs[0]==rhs[0])
                {
                    return lhs[1] < rhs[1];
                }
                else
                {
                    return lhs[0] < rhs[0];
                }
            };
            
            //Sort the coordinates in order of increasing x value
            sort(begin(coordinates), end(coordinates), compareLikeThis); //O(n log n)
            
            //Set to hold distances between all the points and the diagonals
            set<double> distances;
            
            for(int i=0;i<4;i++)
            {
                for(int j=i+1;j<4;j++)
                {
                    double dist=getDistance(coordinates[i], coordinates[j]);
                    
                    if(dist!=0)
                    {
                        distances.insert(dist); //O(6 * log(n))
                    }
                    //If a distance between two points is zero, then the points do not form a valid square
                    else
                    {
                        return false;
                    }
                }
            }
            
            //For a perfect square, since all four sides will have equal distance, we just need to keep track of one distance
            //Also, since both diagonals have to have the same distance, we just need to keep track of one distance as well.
            //So, a perfect square will only have two unique distances.
            return distances.size()==2;
        }
    
        double getDistance(vector<int> & point1, vector<int> & point2)
        {
            int firstTerm=point2[0] - point1[0];
            
            int secondTerm=point2[1] - point1[1];
            
            double dist=sqrt((firstTerm * firstTerm) + (secondTerm * secondTerm));
            
            return dist;
        }
};