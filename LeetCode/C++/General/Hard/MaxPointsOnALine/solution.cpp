#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

/*
Time complexity: O(p^2) [where p=length of points]
Space complexity: O(u) [where u=number of unique slopes]
*/

class Solution
{
    public:
        int maxPoints(vector<vector<int>> & points)
        {
            int result=0;

            int p=points.size();

            for(int i=0;i<p;i++) //O(p)
            {
                //Map slope of a line to the number of pairs of points that have this slope
                unordered_map<double, int> slopeToPoints;

                //Keep track of points that are the same
                int duplicates=0;

                double slope=0.0;

                int x1=points[i][0];

                int y1=points[i][1];

                for(int j=0;j<p;j++) //O(p)
                {
                    int x2=points[j][0];

                    int y2=points[j][1];

                    int dy=y2 - y1;

                    int dx=x2 - x1;

                    //points[i] and points[j] are the same
                    if(dy==0 and dx==0)
                    {
                        duplicates+=1;

                        continue;
                    }

                    //If the change in x is not zero
                    if(dx!=0)
                    {
                        //Calculate the slope between points[i] and points[j];
                        slope=(dy * 1.0)/dx;
                    }
                    //Else, the change in x is zero and the slope will be infinity
                    //Or, programmatically represented as numeric_limits<double>::max();
                    else
                    {
                        slope=numeric_limits<double>::max();
                    }

                    //Increment the number of pairs of points that have slope "slope"
                    slopeToPoints[slope]+=1;
                }

                //If no points share common slope
                if(slopeToPoints.empty())
                {
                    //Then, the max number of points will be the number of points that are the same
                    result=duplicates;
                }
                else
                {
                    //Iterate through all pairs {slope, numberOfPoints} and maximize our result
                    for(auto & [slope, numberOfPoints] : slopeToPoints)
                    {
                        result=max(result, numberOfPoints + duplicates);
                    }
                }
            }

            return result;
        }
};