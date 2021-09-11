#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/*
 * Approaches:
 *
 * 1) Using a hashtable (unordered_map<int, int>), map each candy to the number of times it appears
 * in the input vector. We have another hashtable to keep track of how many different kinds of candies
 * the sister can get. Then, we loop for n/2 times and while we haven't assigned half the candies to the
 * sister, keep giving her candies (if the current candy has more than zero pieces left).
 *
 * Time complexity: O(n)
 * Space complexity: O(n)
 *
 * 2) Use a unordered_set<int> to remove all duplicates from the input vector.
 * Since we have to distribute the even amount of candies evenly, the sister
 * can get no more candies than half the original amount.
 *
 * Time complexity: O(n)
 * Space complexity: O(n)
 */

int distributeCandies(vector<int>& candies)
{
    int result=0;

    if(candies.empty())
    {
        return result;
    }

    unordered_map<int, int> candyHashtable;

    for(const int & candy : candies)
    {
        candyHashtable[candy]++;
    }

    unordered_map<int, int> sistersCandyChoices;

    int half=int(candies.size()/2);

    while(half > 0)
    {
        for(auto element : candyHashtable)
        {
            if(element.second > 0)
            {
                int candy=element.first;

                if(half > 0)
                {
                    element.second--;

                    half--;

                    sistersCandyChoices[candy]++;
                }
            }
        }
    }

    result=int(sistersCandyChoices.size());

    return result;
}

int distributeCandies(vector<int>& candies)
{
    unordered_set<int> kinds;

    for(const auto & candy : candies)
    {
        kinds.insert(candy);
    }

    int half=int(candies.size()/2);

    return min(int(kinds.size()), half);
}