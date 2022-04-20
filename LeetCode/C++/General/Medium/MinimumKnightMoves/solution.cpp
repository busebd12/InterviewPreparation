#include <array>
#include <deque>
#include <set>
#include <utiltity>

class Solution
{
    public:
        int minKnightMoves(int x, int y)
        {
            int result=0;
            
            //It will take the same number of moves to go from (-x, -y) to (0, 0) as it will to go from (0, 0) to (x, y)
            //So, let's only deal with the positive case
            x=abs(x);
            
            y=abs(y);
            
            //All eight directions that a knight can move
            array<pair<int, int>, 8> directions={{{-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {2, 1}, {2, -1}}};
            
            //Make sure we don't visited spots on the board we've already been to
            set<pair<int, int>> visited;
            
            //Queue used for breadth-first search
            deque<pair<int, int>> queue;
            
            visited.emplace(0, 0);
            
            queue.emplace_back(0, 0);
            
            bool done=false;
            
            while(!queue.empty())
            {
                auto qSize=queue.size();
                
                for(int count=0;count<qSize;count++)
                {
                    auto [currentX, currentY]=queue.front();
                    
                    queue.pop_front();
                    
                    //We've reached the destination
                    if(currentX==x && currentY==y)
                    {
                        done=true;
                        
                        break;
                    }
                    
                    //Iterate through all eight knight moves
                    for(auto & [xOffset, yOffset] : directions)
                    {
                        int nextX=currentX + xOffset;
                        
                        int nextY=currentY + yOffset;
                        
                        auto key=make_pair(nextX, nextY);
                        
                        //If we haven't visited this spot on the board yet and the new (x, y) is within our reach
                        //(the knight can only move a maximum distance of 2 in either the x or y direction)
                        if(visited.find(key)==end(visited) && nextX >= -2 && nextY >= -2)
                        {
                            visited.insert(key);
                            
                            queue.emplace_back(nextX, nextY);
                        }
                    }
                }
                
                if(done)
                {
                    break;
                }
                
                result+=1;
            }
            
            return result;
        }
};