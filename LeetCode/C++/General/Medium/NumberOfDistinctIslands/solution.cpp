#include <array>
#include <deque>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class Solution
{
    public:
        string getIslandHash(vector<vector<int>> & grid, int rows, int columns, int row, int column)
        {
            string hash{};
            
            array<pair<int, int>, 4> directions={{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};
            
            deque<pair<int, int>> queue;
            
            grid[row][column]=2;
            
            queue.emplace_back(row, column);
            
            while(!queue.empty())
            {
                int qSize=queue.size();
                
                for(int count=0;count<qSize;count++)
                {
                    auto [currentRow, currentColumn]=queue.front();
                    
                    queue.pop_front();
                    
                    for(auto & [rowOffset, columnOffset] : directions)
                    {
                        int nextRow=currentRow + rowOffset;
                        
                        int nextColumn=currentColumn + columnOffset;
                        
                        bool isValid=((nextRow >= 0 && nextRow < rows) && (nextColumn >= 0 && nextColumn < columns));
                        
                        if(isValid==true && grid[nextRow][nextColumn]==1)
                        {
                            if(rowOffset==-1 && columnOffset==0)
                            {
                                hash.push_back('U');
                            }
                            else if(rowOffset==1 && columnOffset==0)
                            {
                                hash.push_back('D');
                            }
                            else if(rowOffset==0 && columnOffset==-1)
                            {
                                hash.push_back('L');
                            }
                            else if(rowOffset==0 && columnOffset==1)
                            {
                                hash.push_back('R');
                            }
                            
                            grid[nextRow][nextColumn]=2;
                            
                            queue.emplace_back(nextRow, nextColumn);
                        }
                        else
                        {
                            hash.push_back('X');
                        }
                    }
                }
            }
            
            return hash;
        }
    
        int numDistinctIslands(vector<vector<int>> & grid) 
        {
            unordered_set<string> hashes;

            int rows=grid.size();

            int columns=grid[0].size();

            for(int row=0;row<rows;row++)
            {
                for(int column=0;column<columns;column++)
                {
                    if(grid[row][column]==1)
                    {
                        string hash=getIslandHash(grid, rows, columns, row, column);

                        if(hashes.find(hash)==end(hashes))
                        {
                            hashes.insert(hash);
                        }
                    }
                }
            }

            return hashes.size();
        }
};