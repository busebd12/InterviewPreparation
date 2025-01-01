#include <queue>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

class Solution
{
    public:
        int assignBikes(vector<vector<int>> & workers, vector<vector<int>> & bikes)
        {
            int result=0;
            
            int n=workers.size();

            int m=bikes.size();

            //Use a min heap since we want the minimum possible sum
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

            //Keep track of which bit masks we have already seen
            //Each set bit position in the mask tells us that worker[setBitPosition] has been assigned bike[setBitPosition]
            unordered_set<int> seenBitMasks;

            minHeap.emplace(0, 0);

            while(!minHeap.empty())
            {
                auto [distanceSum, availableBikePositions]=minHeap.top();

                minHeap.pop();

                auto [insertionIterator, success]=seenBitMasks.insert(availableBikePositions);

                if(success==false)
                {
                    continue;
                }

                //Count the number of 1's (set bits) in availableBikePositions to know how many workers are already assigned bikes
                //The number of set bits also tells us the index of the next worker to assign a bike to since we both the bikes and workers vectors are zero indexed
                //Put another way: since both the bikes and workers vectors are zero indexed, if there are two set bits in availableBikePositions,
                //that means workers with index 0 and 1 have already been assigned bikes and the worker with index two is next in line for a bike
                int nextWorkerIndex=countSetBits(availableBikePositions);

                if(nextWorkerIndex==n)
                {
                    result=distanceSum;
                    
                    break;
                }

                for(int bikeIndex=0;bikeIndex<m;bikeIndex++)
                {
                    bool bikeIsAvailable=false;

                    //If the bit at position bikeIndex is a 0, then this bike is available and can be assigned to worker at nextWorkerIndex
                    if((availableBikePositions & (1 << bikeIndex))==0)
                    {
                        bikeIsAvailable=true;
                    }

                    //If the current bike at bikeIndex is available
                    if(bikeIsAvailable==true)
                    {
                        //Get the manhattan distance between the worker at nextWorkerIndex and the available bike
                        int manhattanDistance=getManhattanDistance(workers[nextWorkerIndex], bikes[bikeIndex]);
                        
                        //Add the manhattan distance to our distance sum
                        int nextDistanceSum=distanceSum + manhattanDistance;

                        //Generate the next bit mask by changing the bit at bikeIndex from 0 to 1
                        //This marks the bike at bikeIndex as assigned
                        int nextAvailableBikePositions=availableBikePositions | (1 << bikeIndex);

                        //Add the next state to the heap
                        minHeap.emplace(nextDistanceSum, nextAvailableBikePositions);
                    }
                }
            }

            return result;
        }

        int countSetBits(int mask)
        {
            int setBits=0;

            while(mask > 0)
            {
                //If the least significant bit in mask is a one
                if((mask & 1)==1)
                {
                    setBits+=1;
                }

                //Shift mask to the right to removing the least significant bit
                mask=mask >> 1;
            }

            return setBits;
        }

        int getManhattanDistance(vector<int> & worker, vector<int> & bike)
        {
            int x1=worker[0];

            int y1=worker[1];

            int x2=bike[0];

            int y2=bike[1];
            
            int dx=abs(x1 - x2);

            int dy=abs(y1 - y2);
            
            int manhattanDistance=dx + dy;

            return manhattanDistance;
        }
};