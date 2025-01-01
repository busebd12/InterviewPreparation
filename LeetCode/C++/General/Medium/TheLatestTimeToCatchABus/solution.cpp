#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

/*
Solution 1: see comments.

Time complexity: O((b * log(b)) + (p * log(p)) + b * p) [where b=length of buses and p=length of passengers]
Space complexity: O(p)
*/

class Solution
{
    public:
        int latestTimeCatchTheBus(vector<int> & buses, vector<int> & passengers, int capacity)
        {
            int result=0;

            int b=buses.size();

            int p=passengers.size();

            //Sort the bus departure time in increasing order
            sort(buses.begin(), buses.end());

            //Sort the passenger arrival times in increasing order
            sort(passengers.begin(), passengers.end());

            //Hashset used to keep track of passengers who have already arrived
            unordered_set<int> uniqueArrivalTimes;

            int j=0;

            //Iterate through the buses
            for(int i=0;i<b;i++)
            {
                int busDepartureTime=buses[i];

                //Keep track of how many people are on the current bus
                int riders=0;

                //While there are still passengers to board the bus, can there is capacity left on the bus, and the passenger's arrival time is <= the buses' departure time
                while(j < p and riders < capacity and passengers[j] <= busDepartureTime)
                {
                    //Since passengers with the earliest arrival time board first, for each arriving passenger at time T, we want to check if we can board the bus if we arrive before that passenger whose boarding at time T if we arrive at time T-1
                    int beforeCurrentArrivalTime=passengers[j] - 1;

                    //If time T-1 is an arrival time that is available
                    if(uniqueArrivalTimes.find(beforeCurrentArrivalTime)==uniqueArrivalTimes.end())
                    {
                        //Update our result
                        result=beforeCurrentArrivalTime;
                    }

                    //Add the current passenger's arrival time to the hashset
                    uniqueArrivalTimes.insert(passengers[j]);

                    //Increment the number of people on the bus
                    riders+=1;
                    
                    //Move to the next passenger
                    j+=1;
                }

                //After the bus reaches capacity, if no passenger arrived at the latest possible time to board the bus, the departure time of the bus, then that will be our answer
                if(riders < capacity and uniqueArrivalTimes.find(busDepartureTime)==uniqueArrivalTimes.end())
                {
                    result=busDepartureTime;
                }
            }

            return result;
        }
};

/*
Same logic as the first solution except that we can use a variable, previousArrivalTime,
instead of a hashmap to keep track of previous passenger's arrival times since they are sorted in increasing order.

Time complexity: O((b * log(b)) + (p * log(p)) + b * p) [where b=length of buses and p=length of passengers]
Space complexity: O(log(b) + log(p)) [space needed for the Standard Template Library sort algorithm to sort buses and passengers]
*/

class Solution
{
    public:
        int latestTimeCatchTheBus(vector<int> & buses, vector<int> & passengers, int capacity)
        {
            int result=0;

            int b=buses.size();

            int p=passengers.size();

            sort(buses.begin(), buses.end());

            sort(passengers.begin(), passengers.end());

            int j=0;

            int previousArrivalTime=-1;

            for(int i=0;i<b;i++)
            {
                int busDepartureTime=buses[i];

                int riders=0;

                while(j < p and riders < capacity and passengers[j] <= busDepartureTime)
                {
                    int beforeCurrentArrivalTime=passengers[j] - 1;

                    if(beforeCurrentArrivalTime!=previousArrivalTime)
                    {
                        result=beforeCurrentArrivalTime;
                    }

                    previousArrivalTime=passengers[j];

                    riders+=1;
                    
                    j+=1;
                }

                if(riders < capacity and previousArrivalTime!=busDepartureTime)
                {
                    result=busDepartureTime;
                }
            }

            return result;
        }
};