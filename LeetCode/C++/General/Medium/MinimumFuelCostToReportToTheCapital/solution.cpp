#include <deque>
#include <vector>
using namespace std;

/*
Solution: topological sort + breadth-first search. See comments for more details.

Time complexity: O(n)
Space complexity: O(n)
*/

class Solution
{
    public:
        long long minimumFuelCost(vector<vector<int>> & roads, int seats)
        {
            long long result=0;

            int r=roads.size();

            int n=r + 1;

            //Undirected graph
            vector<vector<int>> graph(n, vector<int>());

            //Track the outdegree of each city
            vector<int> outdegree(n, 0);

            //Iterate through the roads
            for(vector<int> & road : roads)
            {
                int a=road[0];

                int b=road[1];

                //Build the undirected graph
                graph[a].push_back(b);

                graph[b].push_back(a);

                //Updated the outdegrees for each city
                outdegree[a]+=1;

                outdegree[b]+=1;
            }

            //Queue used for topological sort
            deque<int> queue;

            //Iterate through each city
            for(int city=1;city<n;city++)
            {
                //If the outdegree of the city is one, then this city is a leaf city
                if(outdegree[city]==1)
                {
                    //Add it to the queue for processing during topological sort
                    queue.push_back(city);
                }
            }

            const int CAPITAL=0;

            //Keep track of the number of people in each city as the topological sort progresses
            vector<int> peopleInCity(n, 1);

            //Do topological sort
            while(!queue.empty())
            {
                int qSize=queue.size();

                for(int count=0;count<qSize;count++)
                {
                    int city=queue.front();

                    queue.pop_front();

                    //If the current city is the capital, then we are done processing the subtree coming
                    //into the capital city node and we need to stop traversing this level
                    if(city==CAPITAL)
                    {
                        break;
                    }

                    //Calculate the number of cars needed to transport the representatives in this current city
                    int carsNeeded=peopleInCity[city] / seats;

                    if((peopleInCity[city] % seats)!=0)
                    {
                        carsNeeded+=1;
                    }

                    //Update our result
                    result+=carsNeeded;

                    //Set the outdegree of the current city to zero since we are done processing it
                    outdegree[city]=0;

                    //Loop through the cities that are neighbours of the current city
                    for(int neighbouringCity : graph[city])
                    {
                        //Move the representatives from the current city into the neighbouring city
                        //Therefore, we need to increase the number of representatives in the neighbouring city
                        peopleInCity[neighbouringCity]+=peopleInCity[city];

                        //Decrease the outdegree of the neighbouring city since we finished processing the current city
                        outdegree[neighbouringCity]-=1;

                        //If the outdegree of the neighbouring city is one, that means the only city it is connected to is its parent
                        //Thus, this neighbouring city is now a leaf city
                        if(outdegree[neighbouringCity]==1)
                        {
                            //Add the new leaf city to the queue
                            queue.push_back(neighbouringCity);
                        }
                    }
                }
            }

            return result;
        }
};