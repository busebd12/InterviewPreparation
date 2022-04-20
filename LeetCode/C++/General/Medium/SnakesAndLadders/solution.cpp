#include <algorithm>
#include <deque>
#include <utility>
#include <vector>
using namespace std;

/*
Solution: see comments.

Time complexity: O(rows * columns) [where rows is the number of rows in board and columns is the number of columns in board]
Space complexity: O(rows * columns)

*/

class Solution
{
    public:
        int snakesAndLadders(vector<vector<int>> & board)
        {
            int result=0;
            
            int n=board.size();
            
            int N=n * n;
            
            int hashtableSize=N + 1;
            
            //Mark spaces on board with values [1, n^2] that we have already visited
            vector<bool> visited(N + 1, false);
            
            //Map values [1, n^2] to the corresponding coordinates (row, column)
            vector<pair<int, int>> hashtable(hashtableSize, pair<int, int>());
            
            //Keep track of which value we are on
            int number=1;
            
            //Determine from which direction we fill rows of the Boustrophedon style board
            bool leftToRight=true;
            
            //Generate Boustrophedon style board
            for(int row=n-1;row>=0;row--)
            {
                if(leftToRight==true)
                {
                    //Fill the row of the board from left-to-right
                    for(int column=0;column<n;column++)
                    {
                        //Map the number to its (row, column)
                        hashtable[number]=make_pair(row, column);
                        
                        number+=1;
                    }
                    
                    //Set to false so that we fill the next row correctly
                    leftToRight=false;
                }
                else
                {
                    //Fill the row of the board from right-to-left
                    for(int column=n-1;column>=0;column--)
                    {
                        //Map the number to its (row, column)
                        hashtable[number]=make_pair(row, column);
                        
                        number+=1;
                    }
                    
                    //Set to true so that we will fill the next row correctly
                    leftToRight=true;
                }
            }
            
            //Queue for breadth-first search
            deque<int> queue;
            
            //Mark the starting spot on the board as visited
            visited[1]=true;
            
            queue.emplace_back(1);
            
            while(!queue.empty())
            {
                int qSize=queue.size();
                
                for(int count=0;count<qSize;count++)
                {
                    auto current=queue.front();
                    
                    queue.pop_front();
                    
                    //If we've reached the n^2 spot, we are done
                    if(current==N)
                    {
                        return result;
                    }
                    
                    //Create [start, end] range for next values
                    int start=current + 1;
                    
                    int end=min(current + 6, N);
                    
                    //for each next value
                    for(int next=start;next<=end;next++)
                    {
                        int nextRow=hashtable[next].first;
                        
                        int nextColumn=hashtable[next].second;
                        
                        //Not a snake or ladder
                        if(board[nextRow][nextColumn]==-1)
                        {
                            //If we've not visited this next value
                            if(visited[next]==false)
                            {
                                visited[next]=true;
                                
                                queue.emplace_back(next);
                            }
                        }
                        //Else, current spot is a snake or ladder
                        else
                        {
                            //If we've not visited this next value
                            if(visited[board[nextRow][nextColumn]]==false)
                            {   
                                visited[board[nextRow][nextColumn]]=true;
                                
                                queue.emplace_back(board[nextRow][nextColumn]);
                            }
                        }
                    }
                }
                
                result+=1;
            }
            
            return -1;
        }
};