#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
using namespace std;

/*
Solution: inspired by these posts

1) https://leetcode.com/problems/detonate-the-maximum-bombs/discuss/1623528/C%2B%2B-Graph-or-Thought-Process
2) https://leetcode.com/problems/detonate-the-maximum-bombs/discuss/2285193/Detonate-Maximum-Bombs-C%2B%2B-Explained-Solution

Time complexity: O(n^2) [where n is the length of bombs]
Space complexity: O(n)
*/

class Solution
{
    public:
        int maximumDetonation(vector<vector<int>> & bombs)
        {
            int result=0;
            
            int n=bombs.size();
            
            vector<vector<bool>> graph(n, vector<bool>(n, false));
            
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    //bombs[j] will be detonated if bomb[i] is detonated
                    if(inRange(bombs[i], bombs[j])==true)
                    {
                        //Created directed edge between bombs[i] and bombs[j]
                        graph[i][j]=true;
                    }
                }
            }
            
            //Detonate each bomb and record the longest chain of detonated bombs
            //This is another way of saying find the connected component of this graph that contains the most bombs
            for(int i=0;i<n;i++)
            {
                int bombsDetonated=detonate(bombs, graph, bombs[i], i, n);
                
                result=max(result, bombsDetonated);
            }
            
            return result;
        }
    
        bool inRange(vector<int> & bomb1, vector<int> & bomb2)
        {
            long long int bomb1XCoordinate=bomb1[0];
            
            long long int bomb1YCoordinate=bomb1[1];
            
            long long int bomb1Radius=bomb1[2];
            
            
            long long int bomb2XCoordinate=bomb2[0];
            
            long long int bomb2YCoordinate=bomb2[1];
            
            long long int bomb2Radius=bomb2[2];
            
            
            long long int xPartOfDistance=(bomb2XCoordinate - bomb1XCoordinate) * (bomb2XCoordinate - bomb1XCoordinate);
            
            long long int yPartOfDistance=(bomb2YCoordinate - bomb1YCoordinate) * (bomb2YCoordinate - bomb1YCoordinate);
            
            long long int bomb1Diameter=bomb1Radius * bomb1Radius;
            
            long long int dist=xPartOfDistance + yPartOfDistance;
            
            //bomb2 is in range of bomb1 if (bomb2XCoordinate, bomb2YCoordinate) is contained within or is touched by the diameter of the circle surrounding (bomb1XCoordinate, bomb1YCoordinate)
            return dist <= bomb1Diameter;
        }
    
        int detonate(vector<vector<int>> & bombs, vector<vector<bool>> & graph, vector<int> & bomb, int index, int n)
        {
            int bombsDetonated=1;
            
            vector<bool> visited(n, false);
            
            visited[index]=true;
            
            deque<int> queue;
            
            queue.push_back(index);
            
            while(!queue.empty())
            {
                int qSize=queue.size();
                
                for(int count=0;count<qSize;count++)
                {
                    auto currentIndex=queue.front();
                    
                    queue.pop_front();
                    
                    for(int i=0;i<n;i++)
                    {
                        if(visited[i]==false)
                        {
                            if(graph[currentIndex][i]==true)
                            {
                                visited[i]=true;
                                
                                queue.push_back(i);
                                
                                bombsDetonated+=1;
                            }
                        }
                    }
                }
            }
            
            return bombsDetonated;
        }
};