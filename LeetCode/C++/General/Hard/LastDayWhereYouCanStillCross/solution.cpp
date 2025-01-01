#include <array>
#include <deque>
#include <vector>
using namespace std;

class Solution
{
    public:
        int latestDayToCross(int row, int col, vector<vector<int>> & cells)
        {
            int result=0;

            int c=cells.size();

            int low=1; //Low needs to be 1 since on day zero all cells are land and flooding doesn't begin until day 1

            int high=c; //High needs to be c, not c-1 since we need to include the cell found at cells[c - 1] in the binary search

            while(low <= high)
            {
                int middle=(low + (high - low)/2);

                if(canCross(cells, row, col, middle)==true)
                {   
                    result=middle;

                    low=middle + 1;
                }
                else
                {   
                    high=middle - 1;
                }
            }

            return result;
        }

        bool canCross(vector<vector<int>> & cells, int row, int col, int day)
        {
            vector<vector<int>> matrix(row, vector<int>(col, 0));

            for(int i=0;i<day;i+=1)
            {   
                int targetRow=cells[i][0] - 1;

                int targetColumn=cells[i][1] - 1;
                
                matrix[targetRow][targetColumn]=1;
            }

            array<pair<int, int>, 4> directions={{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};

            deque<pair<int, int>> stack;

            for(int column=0;column<col;column+=1)
            {
                if(matrix[0][column]==0)
                {
                    stack.emplace_back(0, column);

                    matrix[0][column]=1;
                }
            }

            while(!stack.empty())
            {
                auto [currentRow, currentColumn]=stack.back();

                stack.pop_back();

                if(currentRow==row-1)
                {
                    return true;
                }

                for(auto & [rowOffset, columnOffset] : directions)
                {
                    int nextRow=currentRow + rowOffset;

                    int nextColumn=currentColumn + columnOffset;

                    bool onGrid=((nextRow >= 0 and nextRow < row) and (nextColumn >= 0 and nextColumn < col));

                    if(onGrid==true and matrix[nextRow][nextColumn]!=1)
                    {
                        stack.emplace_back(nextRow, nextColumn);

                        matrix[nextRow][nextColumn]=1;
                    }
                }
            }

            return false;
        }
};

class Solution
{
    public:
        int latestDayToCross(int row, int col, vector<vector<int>> & cells)
        {
            int result=0;

            int c=cells.size();

            int low=1;

            int high=c;

            while(low <= high)
            {
                int middle=(low + (high - low)/2);

                if(canCross(cells, row, col, middle)==true)
                {   
                    result=middle;

                    low=middle + 1;
                }
                else
                {   
                    high=middle - 1;
                }
            }

            return result;
        }

        bool canCross(vector<vector<int>> & cells, int row, int col, int day)
        {
            vector<vector<int>> matrix(row, vector<int>(col, 0));

            for(int i=0;i<day;i+=1)
            {   
                int targetRow=cells[i][0] - 1;

                int targetColumn=cells[i][1] - 1;
                
                matrix[targetRow][targetColumn]=1;
            }

            array<pair<int, int>, 4> directions={{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};

            deque<pair<int, int>> queue;

            for(int column=0;column<col;column+=1)
            {
                if(matrix[0][column]==0)
                {
                    queue.emplace_back(0, column);

                    matrix[0][column]=1;
                }
            }

            while(!queue.empty())
            {
                auto [currentRow, currentColumn]=queue.front();

                queue.pop_front();

                if(currentRow==row-1)
                {
                    return true;
                }

                for(auto & [rowOffset, columnOffset] : directions)
                {
                    int nextRow=currentRow + rowOffset;

                    int nextColumn=currentColumn + columnOffset;

                    bool onGrid=((nextRow >= 0 and nextRow < row) and (nextColumn >= 0 and nextColumn < col));

                    if(onGrid==true and matrix[nextRow][nextColumn]!=1)
                    {
                        queue.emplace_back(nextRow, nextColumn);

                        matrix[nextRow][nextColumn]=1;
                    }
                }
            }

            return false;
        }
};