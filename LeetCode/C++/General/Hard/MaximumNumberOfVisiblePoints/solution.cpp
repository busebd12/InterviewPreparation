#include <cmath>
#include <vector>
using namespace std;

class Solution
{
    public:
        int visiblePoints(vector<vector<int>> & points, int angle, vector<int> & location)
        {
            int result=0;

            int n=points.size();

            int locationX=location[0];

            int locationY=location[1];

            int pointsOnMe=0;

            vector<double> polarAngles;

            polarAngles.reserve(2 * n);

            for(vector<int> & point : points)
            {
                int x=point[0];

                int y=point[1];

                if(x==locationX and y==locationY)
                {
                    pointsOnMe+=1;
                }
                else
                {
                    double polarAngle=getPolarAngle(x, y, locationX, locationY);

                    polarAngles.push_back(polarAngle);
                }
            }

            sort(polarAngles.begin(), polarAngles.end());

            int p=polarAngles.size();

            for(int count=0;count<p;count++)
            {
                polarAngles.emplace_back(polarAngles[count] + 360.0);
            }

            int left=0;

            for(int right=0;right<polarAngles.size();right++)
            {
                while(polarAngles[right] - polarAngles[left] > angle)
                {
                    left+=1;
                }

                int points=(right - left) + 1;

                result=max(result, points);
            }

            result+=pointsOnMe;

            return result;
        }

        double getPolarAngle(int x1, int y1, int x2, int y2)
        {
            double xDifference=double(x1 - x2);

            double yDifference=double(y1 - y2);

            double polarAngle=(180.0 * atan2(xDifference, yDifference)) / M_PI;

            return polarAngle;
        }
};