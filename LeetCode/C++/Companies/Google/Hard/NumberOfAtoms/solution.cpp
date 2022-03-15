#include <cctype>
#include <map>
#include <stack>
#include <string>
using namespace std;

/*
Solution inspired by this post --> https://leetcode.com/problems/number-of-atoms/discuss/999090/C%2B%2B-Linear-Scan-with-Stack.-Runtime%3A-0ms

See comments for more details.

Time complexity: O(n + a log a) [where n is the length of the input formula and a is the total number of atoms]
Space complexity: O(a)
*/

class Solution
{
    public:
        string countOfAtoms(string formula)
        {
            string result{};

            int n=formula.size();

            //Hashtable (map) for mapping each atom to its total frequency
            //Map keeps keys sorted at a cost of log(n) for operations
            map<string, int> hashtable;

            //Stack of pairs where each pair is an atom and its frequency
            stack<pair<string, int>> stk;

            //Frequency of each atom
            int times=0;

            string atom{};

            //Iterate over the input string
            for(int i=0;i<n;)
            {
                char c=formula[i];

                //If the character is uppercase
                if(isupper(c))
                {
                    //Add the uppercase letter to the atom
                    atom+=c;

                    i++;

                    //Add the lowercase letters to the atom if there are any 
                    while(i < n && islower(formula[i]))
                    {
                        atom+=formula[i];

                        i++;
                    }

                    //Get the frequency for the atom - the number following the atom in the formula
                    while(i < n && isdigit(formula[i]))
                    {
                        times=times * 10 + (formula[i] - '0');

                        i++;
                    }

                    //If there is no number following the atom, then the frequency is 1
                    if(times==0)
                    {
                        times=1;
                    }

                    //Add the atom and frequency to the stack as a pair
                    stk.emplace(atom, times);

                    times=0;

                    atom.clear();
                }
                //Else if the character is a '(', then we have found a nested part of the formula
                else if(c=='(')
                {
                    string s(1, c);

                    //Add it to the stack to mark the beginning of the nested section
                    stk.emplace(s, 0);

                    i++;
                }
                //Else if the character is a ')', then we have found the end of a nested section
                else if(c==')')
                {
                    i++;

                    //After the ')', there may be a numeric value telling us how many times the nested section should repeat
                    while(i < n && isdigit(formula[i]))
                    {
                        times=times * 10 + (formula[i] - '0');

                        i++;
                    }

                    //If there is no numeric value, then the frequency is just 1
                    if(times==0)
                    {
                        times=1;
                    }

                    //Temporary stack used to hold the section inside the () that we need to apply the frequency multiplier to
                    stack<pair<string, int>> temp;

                    //While we haven't found the corresponding '(' character
                    while(!stk.empty() && stk.top().first!="(")
                    {
                        //Remove the part that is inside the ()
                        auto current=stk.top();

                        stk.pop();

                        //Apply the frequency multipler to the atom and add it to the temporary stack
                        temp.emplace(current.first, (current.second * times));
                    }

                    //If the stack is not empty, then we are at the '(' character and we remove it
                    if(!stk.empty())
                    {
                        stk.pop();
                    }

                    //Add the parts of the nested formula section back onto the original stack with the frequency multiplier applied
                    while(!temp.empty())
                    {
                        stk.emplace(temp.top());

                        temp.pop();
                    }

                    //Reset times
                    times=0;
                }
            }

            //At this point, the stack holds all the atoms and there corresponding frequencies and we add them to the hashtable
            while(!stk.empty())
            {
                if(!hashtable.count(stk.top().first))
                {
                    hashtable.emplace(stk.top().first, stk.top().second);
                }
                else
                {
                    hashtable[stk.top().first]+=stk.top().second;
                }

                stk.pop();
            }
            
            //Iterate over the hashtable and form the output string
            for(auto element : hashtable)
            {
                result+=element.first;

                if(element.second > 1)
                {
                    result+=to_string(element.second);
                }
            }

            return result;
        }
};