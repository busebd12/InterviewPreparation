#include <array>
#include <deque>
#include <priority_queue>
#include <tuple>
#include <vector>
using namespace std;

class Solution
{
    private:
        //Directions to use in breadth-first search
        array<pair<int, int>, 4> directions={{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};
    
        //Queue to use for breadth-first search
        deque<tuple<int, int, int, int>> queue;
    
        //Keep track of which spots in the grid we have already visited
        vector<vector<bool>> visited;
    
    public:
        vector<vector<int>> highestRankedKItems(vector<vector<int>> & grid, vector<int> & pricing, vector<int> & start, int k)
        {
            vector<vector<int>> result;
            
            //Custom comparator for the minimum heap
            auto compareLikeThis=[] (tuple<int, int, int, int> & lhs, tuple<int, int, int, int> & rhs)
            {
                //Compare the distance
                if(get<3>(lhs)!=get<3>(rhs))
                {
                    return get<3>(lhs) > get<3>(rhs);
                }
                //Compare the price
                else if(get<2>(lhs)!=get<2>(rhs))
                {
                    return get<2>(lhs) > get<2>(rhs);
                }
                //Compare the row number
                else if(get<0>(lhs)!=get<0>(rhs))
                {
                    return get<0>(lhs) > get<0>(rhs);
                }
                //Compare the column number
                else
                {
                    return get<1>(lhs) > get<1>(rhs);
                }
            };
            
            //Min heap used to sort the potential candidates using our custom comparator
            priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, decltype(compareLikeThis)> minHeap(compareLikeThis);
            
            int rows=grid.size();
            
            int columns=grid[0].size();
            
            visited.resize(rows, vector<bool>(columns, false));
            
            queue.emplace_back(start[0], start[1], grid[start[0]][start[1]], 0);
            
            visited[start[0]][start[1]]=true;
            
            //Do breadth-first search
            while(!queue.empty())
            {
                int qSize=queue.size();
                
                for(int count=0;count<qSize;count++)
                {
                    auto [row, column, price, distance]=queue.front();
                    
                    queue.pop_front();
                    
                    //If the price for the current spot in the grid is within the acceptable range
                    if(pricing[0] <= price and price <= pricing[1])
                    {
                        //Add it to the minimum heap
                        minHeap.emplace(row, column, price, distance);
                    }
                    
                    //Iterate through all the directions
                    for(auto & [rowOffset, columnOffset] : directions)
                    {
                        int nextRow=row + rowOffset;
                        
                        int nextColumn=column + columnOffset;
                        
                        //Make sure next spot in the grid is valid
                        bool isValid=((nextRow >= 0 and nextRow < rows) and (nextColumn >= 0 and nextColumn < columns));
                        
                        //If the next spot is valid and it's not a zero and we haven't visited it before
                        if(isValid==true and grid[nextRow][nextColumn]!=0 and visited[nextRow][nextColumn]==false)
                        {
                            //Mark it as visited
                            visited[nextRow][nextColumn]=true;
                            
                            //Add it to the queue
                            queue.emplace_back(nextRow, nextColumn, grid[nextRow][nextColumn], distance + 1);
                        }
                    }
                }
            }
            
            //Get the K highest spots in the grid and add them to the result
            while(k > 0 and !minHeap.empty())
            {
                auto [row, column, price, distance]=minHeap.top();
                
                minHeap.pop();
                
                result.emplace_back(vector<int>{row, column});
                
                k-=1;
            }
            
            return result;
    }
};