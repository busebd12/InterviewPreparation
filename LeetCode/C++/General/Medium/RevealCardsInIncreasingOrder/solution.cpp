#include <algorithm>
#include <deque>
#include <vector>
using namespace std;

/*
Solution: see this post --> https://leetcode.com/problems/reveal-cards-in-increasing-order/discuss/200526/Java-Queue-Simulation-Step-by-Step-Explanation

Time complexity: O(n) [where n is the length of deck]
Space complexity: O(n)
*/


class Solution
{
    public:
        vector<int> deckRevealedIncreasing(vector<int> & deck)
        {
            vector<int> result;
            
            int n=deck.size();
            
            result.resize(n, 0);
            
            sort(begin(deck), end(deck));
            
            deque<int> queue;
            
            for(int i=0;i<n;i++)
            {
                queue.push_back(i);
            }
            
            for(int i=0;i<n;i++)
            {
                int resultIndex=queue.front();
                
                queue.pop_front();
                
                result[resultIndex]=deck[i];
                
                queue.push_back(queue.front());
                
                queue.pop_front();
            }
            
            return result;
        }
};