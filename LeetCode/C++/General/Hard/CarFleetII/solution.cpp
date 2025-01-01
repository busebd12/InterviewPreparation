#include <deque>
#include <vector>
using namespace std;

/*
Solution: based on this resource --> https://www.youtube.com/watch?v=SVW1bD_PN6A

Time complexity: O(c) [where c is the length of cars]
Space complexity: O(c)
*/

class Solution
{
    public:
        vector<double> getCollisionTimes(vector<vector<int>> & cars)
        {
            vector<double> result;

            int c=cars.size();

            result.resize(c, -1);

            deque<int> stack;

            for(int index=c-1;index>=0;index--)
            {
                //Remove all cars to the right of the current car that have speed greater than or equal to since the current car will never catch these cars
                while(!stack.empty() and cars[stack.back()][1] >= cars[index][1])
                {
                    stack.pop_back();
                }

                double collisionTime=-1;

                //At this point, if the stack is not empty, then the only cars remaining are cars to the right of the current one with speed strictly less than it.
                //Thus, there will be at least one collision.
                while(!stack.empty())
                {
                    //Recall the formula distance=rate(speed) * time
                    //Solving for time, we have time=distance/speed
                    //Then, the collision time between two cards is (difference in distance)/(difference in speed)
                    //In our case, it will be (difference in position)/(difference in speed)
                    double positionDifference=(double)(cars[stack.back()][0]) - (double)(cars[index][0]);

                    double speedDifference=(double)(cars[index][1]) - (double)(cars[stack.back()][1]);

                    collisionTime=positionDifference / speedDifference;

                    //If we collide with a car to the right which hasn't collided with another car before
                    //or the car at the top of the stack will collide with another car before the current car collides with it,
                    //then we are done looking for cars to collide with
                    if(result[stack.back()]==-1 or collisionTime <= result[stack.back()])
                    {
                        break;
                    }

                    stack.pop_back();
                }

                result[index]=collisionTime;

                stack.push_back(index);
            }

            return result;
        }
};