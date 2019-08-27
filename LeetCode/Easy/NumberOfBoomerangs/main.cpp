#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

/*
 * Approaches:
 *
 * 1) Brute force. Generate all tuples of three points and check if the distance between tuple i and tuple j is
 * the same as tuple j and k.
 *
 * Time complexity: O(n-cubed) [where n is the number of points]
 * Space complexity: O(1)
 *
 * 2) For each point i, group all points j that share the same distance from i, using a hashtable.
 * Then, use the formula nP2 = n!/(n - 2)! = n * (n - 1) to calculate all the ways of choosing 2 points
 * from a group of n points.
 *
 * Time complexity: O(n-squared) [where n is the number of points]
 * Space complexity: O(n-squared)
 */

int numberOfBoomerangs(vector<vector<int>>& points)
{
    int result=0;

    if(points.empty())
    {
        return result;
    }

    int n=int(points.size());

    for(int x=0;x<n;++x)
    {
        for(int y=0;y<n;++y)
        {
            for(int z=0;z<n;++z)
            {
                if(x!=y && y!=z && x!=z)
                {
                    pair<int, int> i(points[x][0], points[x][1]);

                    pair<int, int> j(points[y][0], points[y][1]);

                    pair<int, int> k(points[z][0], points[z][1]);

                    int xDiff=0;

                    int yDiff=0;

                    xDiff=(j.first - i.first);

                    yDiff=(j.second - i.second);

                    double d1=sqrt((xDiff * xDiff) + (yDiff * yDiff));

                    xDiff=(k.first - j.first);

                    yDiff=(k.second - j.second);

                    double d2=sqrt((xDiff * xDiff) + (yDiff * yDiff));

                    if(d1==d2)
                    {
                        result++;
                    }
                }
            }
        }
    }

    return result;
}

int numberOfBoomerangs(vector<vector<int>> & points)
{
    int result=0;

    if(points.empty())
    {
        return result;
    }

    int n=int(points.size());

    for(int i=0;i<n;++i)
    {
        unordered_map<int, int> tuples(n);

        for(int j=0;j<n;++j)
        {
            if(j!=i)
            {
                int dx=points[i][0] - points[j][0];

                int dy=points[i][1] - points[j][1];

                int dist=(dx * dx) + (dy * dy);

                tuples[dist]++;
            }
        }

        for(auto & element : tuples)
        {
            if(element.second > 1)
            {
                result+=(element.second * (element.second-1));
            }
        }
    }

    return result;
}