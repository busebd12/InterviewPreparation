#include <algorithm>
#include <deque>
#include <set>
#include <vector>

/*
Solution: inspired by these posts

1) https://en.wikibooks.org/wiki/Algorithm_Implementation/Geometry/Convex_hull/Monotone_chain

2) https://leetcode.com/problems/erect-the-fence/solutions/1442271/day-3-erect-the-fence-convex-hull-algorithm-c-with-graphical-explanation/

3) https://www.youtube.com/watch?v=nBvCZi34F_o

Time complexity: O(n * log(n)) [where n is the length of trees]
Space complexity: O(n)
*/

class Solution
{
    public:
        vector<vector<int>> outerTrees(vector<vector<int>> & trees)
        {
            vector<vector<int>> result;

            int n=trees.size();

            if(n <= 3)
            {
                return trees;
            }

            sort(trees.begin(), trees.end());

            deque<vector<int>> upperPart={trees[0], trees[1]};

            for(int i=2;i<n;i++)
            {
                int upperPartSize=upperPart.size();
                
                while(upperPart.size() >= 2 and getOrientation(upperPart[upperPartSize - 2], upperPart[upperPartSize - 1], trees[i]) > 0)
                {
                    upperPart.pop_back();

                    upperPartSize-=1;
                }
                
                upperPart.push_back(trees[i]);
            }

            deque<vector<int>> lowerPart={trees[n - 1], trees[n - 2]};

            for(int i=n-3;i>=0;i--)
            {
                int lowerPartSize=lowerPart.size();

                while(lowerPart.size() >= 2 and getOrientation(lowerPart[lowerPartSize - 2], lowerPart[lowerPartSize - 1], trees[i]) > 0)
                {
                    lowerPart.pop_back();

                    lowerPartSize-=1;
                }

                lowerPart.push_back(trees[i]);
            }

            set<vector<int>> uniquePoints;

            while(!upperPart.empty())
            {
                uniquePoints.insert(upperPart.front());

                upperPart.pop_front();
            }

            while(!lowerPart.empty())
            {
                uniquePoints.insert(lowerPart.front());

                lowerPart.pop_front();
            }

            while(!uniquePoints.empty())
            {
                result.push_back(*(uniquePoints.begin()));

                uniquePoints.erase(uniquePoints.begin());
            }

            return result;
        }

        int getOrientation(vector<int> & onHull, vector<int> & secondPoint, vector<int> & thirdPoint)
        {
            int x1=onHull[0];

            int y1=onHull[1];

            int x2=secondPoint[0];

            int y2=secondPoint[1];

            int x3=thirdPoint[0];

            int y3=thirdPoint[1];

            int firstPart=(y3 - y2) * (x2 - x1);

            int secondPart=(y2 - y1) * (x3 - x2);

            int difference=firstPart - secondPart;

            return difference;
        }
};