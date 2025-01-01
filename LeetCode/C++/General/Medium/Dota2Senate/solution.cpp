#include <algorithm>
#include <deque>
#include <string>
using namespace std;

class Solution
{
    public:
        string predictPartyVictory(string senate)
        {
            string result="";

            int n=senate.length();

            deque<int> dQueue;

            deque<int> rQueue;

            for(int i=0;i<n;i++)
            {
                char letter=senate[i];

                if(letter=='D')
                {
                    dQueue.push_back(i);
                }
                else
                {
                    rQueue.push_back(i);
                }
            }

            while(!dQueue.empty() and !rQueue.empty())
            {
                int largerIndex=max(dQueue.back(), rQueue.back());
                
                int dIndex=dQueue.front();

                dQueue.pop_front();

                int rIndex=rQueue.front();

                rQueue.pop_front();

                if(dIndex < rIndex)
                {
                    int updatedDIndex=largerIndex + 1;

                    dQueue.push_back(updatedDIndex);
                }
                else
                {
                    int updatedRIndex=largerIndex + 1;

                    rQueue.push_back(updatedRIndex);
                }
            }

            result=dQueue.empty() ? "Radiant" : "Dire";

            return result;
        }
};