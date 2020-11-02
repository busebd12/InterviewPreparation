#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
 * Approaches:
 *
 * 1. while vector<int> stones is not empty and we have at least two stones, "smash" together
 * the two stones with the most weight. If the weights are equal, remove both stones. Else,
 * only the stone with the smaller weight gets removed and the other stone's weight is changed
 * to the weight difference between the two stones.
 *
 * Time complexity: O(n-squared) [where n is the length of the stones vector]
 * Space complexity: O(1)
 *
 * 2. Priority queue. Since we only ever care about the two heaviest stones, we can use a priority queue to store
 * the stones. This way, we always have access to the heaviest stone in constant time. Then, we simply remove the top
 * two stones from the priority queue and follow the same "smash" logic as in the first solution. The only difference
 * being that we add the new weight back into the priority queue if the stones weight is not the same, instead of
 * modifying an element inside the priority queue.
 *
 * Time complexity: O(n log n) [where n is the length of the stones vector]
 * Space complexity: O(n)
 */

int lastStoneWeight(vector<int> & stones)
{
    if(stones.empty())
    {
        return 0;
    }

    while(!stones.empty() && stones.size() > 1)
    {
        auto largestItr=max_element(stones.begin(), stones.end());

        auto largestIndex=largestItr - stones.begin();

        int secondLargest=(largestIndex==0) ? stones[1] : stones[0];

        int secondLargestIndex=-1;

        for(auto i=0;i<stones.size();++i)
        {
            if(i!=largestIndex)
            {
                if(stones[i] <= stones[largestIndex])
                {
                    if(stones[i] >= secondLargest)
                    {
                        secondLargest=stones[i];

                        secondLargestIndex=i;
                    }
                }
            }
        }


        if(stones[largestIndex]==stones[secondLargestIndex])
        {
            if(largestIndex < stones.size())
            {
                stones.erase(stones.begin() + largestIndex);
            }

            secondLargestIndex--;

            stones.erase(stones.begin() + secondLargestIndex);

        }
        else
        {
            stones[largestIndex]=stones[largestIndex] - stones[secondLargestIndex];

            if(secondLargestIndex < stones.size())
            {
                stones.erase(stones.begin() + secondLargestIndex);
            }
        }
    }

    return stones.empty() ? 0 : stones[0];
}

int lastStoneWeight(vector<int> & stones)
{
    priority_queue<int> pq;

    for(const auto & stone : stones)
    {
        pq.push(stone);
    }

    while(pq.size() > 1)
    {
        int largest=pq.top();

        pq.pop();

        int secondLargest=pq.top();

        pq.pop();

        if(secondLargest!=largest)
        {
            pq.push(largest - secondLargest);
        }
    }

    return pq.empty() ? 0 : pq.top();
}