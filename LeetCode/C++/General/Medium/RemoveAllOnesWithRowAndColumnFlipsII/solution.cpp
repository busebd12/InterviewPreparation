#include <algorithm>
#include <deque>
#include <vector>
using namespace std;

class Solution
{
    public:
        int removeOnes(vector<vector<int>> & grid)
        {
            int result=0;
            
            int rows=grid.size();
            
            int columns=grid[0].size();
            
            deque<vector<vector<int>>> queue;
            
            queue.push_back(grid);
            
            bool done=false;
            
            while(!queue.empty())
            {
                int qSize=queue.size();
                
                for(int count=0;count<qSize;count++)
                {
                    vector<vector<int>> current=queue.front();
                    
                    queue.pop_front();
                    
                    if(allZeros(current)==true)
                    {
                        done=true;
                        
                        break;
                    }
                    
                    for(int row=0;row<rows;row++)
                    {
                        for(int column=0;column<columns;column++)
                        {
                            if(current[row][column]==1)
                            {
                                vector<pair<int, int>> changedPositions=changeCells(current, rows, columns, row, column);
                                
                                queue.push_back(current);
                                
                                for(auto & [r, c] : changedPositions)
                                {
                                    current[r][c]=1;
                                }
                            }
                        }
                    }
                }
                
                if(done==true)
                {
                    break;
                }
                
                result+=1;
            }
            
            return result;
        }

        bool allZeros(vector<vector<int>> & grid)
        {
            for(vector<int> & row : grid)
            {
                if(all_of(begin(row), end(row), [] (int value) {return value==0;})==false)
                {
                    return false;
                }
            }
            
            return true;
        }
    
        vector<pair<int, int>> changeCells(vector<vector<int>> & grid, int rows, int columns, int row, int column)
        {
            vector<pair<int, int>> changedPositions;
            
            for(int column=0;column<columns;column++)
            {
                if(grid[row][column]==1)
                {
                    grid[row][column]=0;
                    
                    changedPositions.emplace_back(row, column);
                }
            }

            for(int row=0;row<rows;row++)
            {
                if(grid[row][column]==1)
                {
                    grid[row][column]=0;
                    
                    changedPositions.emplace_back(row, column);
                }
            }
            
            return changedPositions;
        }
};