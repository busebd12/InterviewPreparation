#include <algorithm>
#include <array>
#include <deque>
#include <limits>
#include <utility>
#include <vector>

/*
Time complexity: O(b) [where b=number of black pixels]
Space complexity: O(b)
*/

class Solution
{
    public:
        int minArea(vector<vector<char>> & image, int x, int y)
        {
            int result=0;

            int rows=image.size();

            int columns=image[0].size();

            //{max black pixel x-coordinate, min black pixel x-coordinate}
            pair<int, int> xCoordinatePair(numeric_limits<int>::min(), numeric_limits<int>::max());

            //{max black pixel y-coordinate, min black pixel y-coordinate}
            pair<int, int> yCoordinatePair(numeric_limits<int>::min(), numeric_limits<int>::max());

            //Search for all black pixel coordinates and find the max black pixel x-coordinate, min black pixel x-coordinate,
            //max black pixel y-coordinate, and min black pixel y-coordinate
            findComponent(image, xCoordinatePair, yCoordinatePair, rows, columns, x, y);

            int maxXCoordinate=xCoordinatePair.first;

            int minXCoordinate=xCoordinatePair.second;

            //The width of the rectangle is the difference in the max black pixel x-coordinate and min black pixel x-coordinate
            //(plus 1 in order to convert the length to 1-indexed)
            int width=(maxXCoordinate - minXCoordinate) + 1;

            int maxYCoordinate=yCoordinatePair.first;

            int minYCoordinate=yCoordinatePair.second;

            //The length of the rectangle is the difference in the max black pixel y-coordinate and min black pixel y-coordinate
            //(plus 1 in order to convert the width to 1-indexed)
            int length=(maxYCoordinate - minYCoordinate) + 1;

            result=length * width;

            return result;
        }

        void findComponent(vector<vector<char>> & image, pair<int, int> & xCoordinatePair, pair<int, int> & yCoordinatePair, int rows, int columns, int x, int y)
        {
            deque<pair<int, int>> queue;

            array<pair<int, int>, 4> directions={{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};

            queue.emplace_back(x, y);

            image[x][y]='2';

            while(!queue.empty())
            {
                int qSize=queue.size();

                for(int count=0;count<qSize;count++)
                {
                    auto [currentX, currentY]=queue.front();

                    queue.pop_front();

                    //Update the max x-coordinate
                    xCoordinatePair.first=max(xCoordinatePair.first, currentX);

                    //Update the min x-coordinate
                    xCoordinatePair.second=min(xCoordinatePair.second, currentX);

                    //Update the max y-coordinate
                    yCoordinatePair.first=max(yCoordinatePair.first, currentY);

                    //Update the min y-coordinate
                    yCoordinatePair.second=min(yCoordinatePair.second, currentY);

                    for(auto & [rowOffset, columnOffset] : directions)
                    {
                        int nextX=currentX + rowOffset;

                        int nextY=currentY + columnOffset;

                        bool isValid=((0 <= nextX and nextX < rows) and (0 <= nextY and nextY < columns));

                        if(isValid==true and image[nextX][nextY]=='1')
                        {
                            queue.emplace_back(nextX, nextY);

                            image[nextX][nextY]='2';
                        }
                    }
                }
            }
        }
};