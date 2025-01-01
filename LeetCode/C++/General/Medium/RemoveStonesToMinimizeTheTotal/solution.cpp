#include <queue>
#include <vector>
using namespace std;

/*
Time complexity: O(n + (k * log(n)) + l)
Space complexity: O(n)
*/

class Solution
{
    public:
        int minStoneSum(vector<int> & piles, int k)
        {
            int result=0;

            priority_queue<int, vector<int>, less<int>> maxHeap;

            //Insert all piles into the max heap
            for(int pile : piles) //O(n) [where n is the number of piles]
            {
                maxHeap.push(pile);
            }

            //Do the k operations
            while(k > 0) //O(k)
            {
                //Remove the largest pile from the max heap
                //Since we are removing the largest pile each time, we are
                //removing the maximum number of stonespossible from the overall total amount of stones each time
                int pile=maxHeap.top();

                maxHeap.pop(); //O(log(n))

                //Calculate the number of stones to remove from the pile
                int stonesRemoved=floor(pile / 2);

                //Remove the stones
                pile-=stonesRemoved;

                //If there are stones left over, insert the pile back into the max heap
                if(pile > 0)
                {
                    maxHeap.push(pile);
                }

                k-=1;
            }

            //Add up the stones left in all the piles to form our answer
            while(!maxHeap.empty()) //O(l) [where l is the number of left over stones]
            {
                result+=maxHeap.top();

                maxHeap.pop();
            }

            return result;
        }
};