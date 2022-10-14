#include <deque>
#include <vector>
using namespace std;

/*
Time complexity: O(n + (p * n)) [where p is the total number of perfect squares less than or equal to n]
Space complexity: O(p)
*/

class Solution
{
    public:
        int numSquares(int n)
        {
            int result=0;
            
            //List of all perfect squares less than or equal to n
            vector<int> perfectSquares;
            
            int number=1;
            
            //Calculate all perfect squares less than or equal to n
            while(number * number <= n)
            {
                perfectSquares.emplace_back(number * number);
                
                number+=1;
            }
            
            //Keep track of the numbers we've visited during our breadth-first search
            vector<bool> visited(10001, false);
            
            //Queue used for breadth-first search
            deque<int> queue;
            
            //Start our breadth-first search at zero
            queue.emplace_back(0);
            
            //Do the breadth-first search
            while(!queue.empty())
            {
                int qSize=queue.size();
                
                bool done=false;
                
                for(int count=0;count<qSize;count++)
                {
                    int current=queue.front();
                    
                    queue.pop_front();
                    
                    if(current==n)
                    {
                        done=true;
                        
                        break;
                    }
                    
                    //Iterate through the list of perfect squares
                    for(int perfectSquare : perfectSquares)
                    {
                        //Add the perfect square to the current sum
                        int next=current + perfectSquare;
                        
                        //If we haven't seen this number before and it's less than or equal to n
                        if(next <= n and visited[next]==false)
                        {
                            visited[next]=true;
                            
                            queue.push_back(next);
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
};