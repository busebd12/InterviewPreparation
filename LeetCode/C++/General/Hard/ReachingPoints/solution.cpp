using namespace std;

/*
Solution: based on this resource --> https://www.youtube.com/watch?v=tPr5Uae6Drc

Time complexity: O(log(max(tx, ty)))
Space complexity: O(1)
*/

class Solution
{
    public:
        bool reachingPoints(int sx, int sy, int tx, int ty)
        {
            while(tx >= sx and ty >= sy)
            {
                if(tx==sx and ty==sy)
                {
                    return true;
                }
                else if(tx > ty)
                {
                    tx=(tx % ty);
                }
                else
                {
                    ty=(ty % tx);
                }

                if(tx==sx)
                {
                    int remaining=ty - sy;
                    
                    if((remaining % tx)==0)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }

                if(ty==sy)
                {
                    int remaining=tx - sx;

                    if((remaining % ty)==0)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }

            return false;
        }
};