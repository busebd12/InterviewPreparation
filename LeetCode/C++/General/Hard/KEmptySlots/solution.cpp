#include <set>
#include <vector>
using namespaces std;

/*
Solution: see comments.

Time complexity: O(n * log(n)) [where n is the length of bulbs]
Space complexity: O(n)
*/

class Solution
{
    public:
        int kEmptySlots(vector<int> & bulbs, int k)
        {
            int result=-1;

            int n=bulbs.size();

            set<int> onBulbs;

            for(int i=0;i<n;i++)
            {
                int bulb=bulbs[i];
                
                //Insert the bulb that was just turned on into the ordered set
                onBulbs.insert(bulb);

                //Get an iterator pointing to the bulb that we just inserted
                auto itr=onBulbs.find(bulb);

                //If the iterator does not point to the beginning of the set, then there is at least
                //one bulb that is also turned on to the left of the bulb that we just turned on
                if(itr!=onBulbs.begin())
                {
                    //Iterator pointing to that left neighbour
                    auto leftNeighbour=itr;

                    //Decrement the iterator to point to the actual left neighbour
                    leftNeighbour--;

                    //Calculate the number of bulbs that are turned-off between the current on bulb and its left neighbour
                    //IMPORTANT: we need to subtract one since the bulbs are one indexed but the days are zero indexed
                    int offBulbsBetweenThem=(*itr - *leftNeighbour) - 1;

                    //If the number of bulbs between these two is k, we have found a valid day
                    if(offBulbsBetweenThem==k)
                    {
                        result=i + 1;

                        return result;
                    }
                }

                //Iterator pointing to that right neighbour
                auto rightNeighbour=itr;

                //Increment the iterator to point to the actual right neighbour
                rightNeighbour++;

                //If the iterator is not pointing to the end of the set, then there is at least one bulb turned-on to the right of the current on bulb
                if(rightNeighbour!=onBulbs.end())
                {
                    //Calculate the number of bulbs that are turned-off between the current on bulb and its left neighbour
                    //IMPORTANT: we need to subtract one since the bulbs are one indexed but the days are zero indexed
                    int offBulbsBetweenThem=(*rightNeighbour - *itr) - 1;

                    //If the number of bulbs between these two is k, we have found a valid day
                    if(offBulbsBetweenThem==k)
                    {
                        result=i + 1;

                        return result;
                    }
                }
            }

            return result;
        }
};