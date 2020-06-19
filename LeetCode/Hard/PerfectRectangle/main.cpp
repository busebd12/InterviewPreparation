#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

/*
 * Solution: inspired from this post --> https://leetcode.com/problems/perfect-rectangle/discuss/87200/Python-solution-with-detailed-explanations
 *
 * Time complexity: O(n) [where n is the number of input rectangles]
 * Space complexity: O(u) [where u is the number of unique coordinate pairs representing corners of rectangles]
 */

std::string coordinateToString(std::pair<int, int> & coordinate)
{
    return "(" + std::to_string(coordinate.first) + "," + std::to_string(coordinate.second) + ")";
}

bool isRectangleCover(std::vector<std::vector<int>> & rectangles)
{
    if(rectangles.empty())
    {
        return false;
    }

    int n=int(rectangles.size());

    if(n==1)
    {
        return true;
    }

    std::unordered_map<std::string, int> hashtable;

    int areaOfAllRectangles=0;

    for(const auto & rectangle : rectangles)
    {
        auto bottomLeft=std::make_pair(rectangle[0], rectangle[1]);

        auto topRight=std::make_pair(rectangle[2], rectangle[3]);

        auto topLeft=std::make_pair(bottomLeft.first, topRight.second);

        auto bottomRight=std::make_pair(topRight.first, bottomLeft.second);

        std::string topLeftAsString=coordinateToString(topLeft);

        if(!hashtable.count(topLeftAsString))
        {
            hashtable[topLeftAsString]++;
        }
        else
        {
            hashtable.erase(topLeftAsString);
        }

        std::string bottomLeftAsString=coordinateToString(bottomLeft);

        if(!hashtable.count(bottomLeftAsString))
        {
            hashtable[bottomLeftAsString]++;
        }
        else
        {
            hashtable.erase(bottomLeftAsString);
        }

        std::string topRightAsString=coordinateToString(topRight);

        if(!hashtable.count(topRightAsString))
        {
            hashtable[topRightAsString]++;
        }
        else
        {
            hashtable.erase(topRightAsString);
        }

        std::string bottomRightAsString=coordinateToString(bottomRight);

        if(!hashtable.count(bottomRightAsString))
        {
            hashtable[bottomRightAsString]++;
        }
        else
        {
            hashtable.erase(bottomRightAsString);
        }

        int currentRectangleArea=(rectangle[2] - rectangle[0]) * (rectangle[3] - rectangle[1]);

        areaOfAllRectangles+=currentRectangleArea;
    }

    std::pair<int, int> bottomLeftOfContainingRectangle=std::make_pair(rectangles[0][0], rectangles[0][1]);

    std::pair<int, int> topRightOfContainingRectangle=std::make_pair(rectangles[0][2], rectangles[0][3]);

    for(int i=1;i<n;i++)
    {
        bottomLeftOfContainingRectangle.first=std::min(rectangles[i][0], bottomLeftOfContainingRectangle.first);

        bottomLeftOfContainingRectangle.second=std::min(rectangles[i][1], bottomLeftOfContainingRectangle.second);

        topRightOfContainingRectangle.first=std::max(rectangles[i][2], topRightOfContainingRectangle.first);

        topRightOfContainingRectangle.second=std::max(rectangles[i][3], topRightOfContainingRectangle.second);
    }

    std::pair<int, int> topLeftOfContainingRectangle=std::make_pair(bottomLeftOfContainingRectangle.first, topRightOfContainingRectangle.second);

    std::pair<int, int> bottomRightOfContainingRectangle=std::make_pair(topRightOfContainingRectangle.first, bottomLeftOfContainingRectangle.second);

    std::vector<std::string> cornersOfContainingRectangle;

    cornersOfContainingRectangle.emplace_back(coordinateToString(bottomLeftOfContainingRectangle));

    cornersOfContainingRectangle.emplace_back(coordinateToString(topRightOfContainingRectangle));

    cornersOfContainingRectangle.emplace_back(coordinateToString(topLeftOfContainingRectangle));

    cornersOfContainingRectangle.emplace_back(coordinateToString(bottomRightOfContainingRectangle));

    for(const auto & corner : cornersOfContainingRectangle)
    {
        if(!hashtable.count(corner))
        {
            return false;
        }
    }

    int areaOfContainingRectangle=(topRightOfContainingRectangle.first - bottomLeftOfContainingRectangle.first) * (topRightOfContainingRectangle.second - bottomLeftOfContainingRectangle.second);

    return areaOfContainingRectangle==areaOfAllRectangles && hashtable.size()==4;
}