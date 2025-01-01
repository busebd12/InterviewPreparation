#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
    public:
        bool canWin(string currentState)
        {
            int n=currentState.size();

            if(n < 2)
            {
                return false;
            }

            unordered_map<string, bool> hashmap;

            return helper(hashmap, currentState, n);
        }

        bool helper(unordered_map<string, bool> & hashmap, string & currentState, int n)
        {
            //If the current state is already in the hashmap, then return the solution to this subproblem we've already solved
            if(hashmap.find(currentState)!=hashmap.end())
            {
                return hashmap[currentState];
            }

            for(int i=0;i<n;i++)
            {
                if(i + 1 < n and currentState[i]=='+' and currentState[i + 1]=='+')
                {
                    //Generate the next state by replacing two adjacent + signs with - signs
                    string nextState=currentState.substr(0, i) + "--" + currentState.substr(i + 2, string::npos);

                    //If the next state leads to a position where no moves can be made then this is a winning state
                    if(helper(hashmap, nextState, n)==false)
                    {
                        //Make sure to cache the winning state
                        hashmap.emplace(nextState, true);
                        
                        //Return true since next state leads to a win for the starting player
                        return true;
                    }
                }
            }

            //None of the possible next states leads to a winning state, so cache this state leads to a loosing state
            hashmap.emplace(currentState, false);

            return false;
        }
};