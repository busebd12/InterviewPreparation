#include <map>
#include <numeric>
#include <utility>
using namespace std;

/*
Space complexity: O(u) [where u is the total number of unique points]
*/

class DetectSquares
{
    private:
    //Map each pair of x and y coordinates to how many times the point appears    
    map<pair<int, int>, int> points;
    
    public:
        DetectSquares()
        {
            
        }

        //Time complexity: O(u log(p)) [where p is a point and u is the total number of unique points]
        void add(vector<int> point)
        {
            pair<int, int> p(point[0], point[1]);
            
            points[p]+=1;
        }

        //Time complexity: O(u) [where u is the total number of unique points]
        int count(vector<int> point)
        {
            int result=0;
            
            //Assume each point in the map can be diagonal from the given starting point in the potential square
            for(auto & [diagonal, frequency] : points)
            {
                //The x and y coordinates in the diagonal point and the given point must be different from each other
                if(diagonal.first==point[0] || diagonal.second==point[1])
                {
                    continue;
                }
                
                //The distance between the diagonal point and the starting point must be greater than zero for the square to have non-zero area
                if(abs(diagonal.first - point[0]) != abs(diagonal.second - point[1]))
                {
                    continue;
                }
                
                //Third point in the square
                pair<int, int> p3(diagonal.first, point[1]);
                
                //Fourth point in the square
                pair<int, int> p4(point[0], diagonal.second);
                
                //If the map doesn't have the third or fourth point, we can't form a square
                if(points.find(p3)==end(points) || points.find(p4)==end(points))
                {
                    continue;
                }
                
                //Add the product of the frequencies for the diagonal, third, and fourth points to the result
                result+=(frequency * points[p3] * points[p4]);
            }
            
            return result;
        }
};