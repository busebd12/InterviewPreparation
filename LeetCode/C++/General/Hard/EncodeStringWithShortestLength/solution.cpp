#include <string>
#include <unordered_map>
using namespace std;

/*
Solution 1: recursive depth-first search. Note, this solution receives Time Limit Exceeded when run.
*/

class Solution
{
    public:
        string encode(string s)
        {
            string result="";

            result=helper(s);

            return result;
        }

        string helper(string & s)
        {
            if(s.size() < 5)
            {
                return s;
            }

            string subproblemSolution=s;

            //Iterate through all possible lengths of substrings
            for(int substringLength=0;substringLength<s.size();substringLength++)
            {
                //Generate substring
                string needle=s.substr(0, substringLength + 1);

                //Count the number of times needle appears in s
                //This number will be equal to the k possible encoding values
                int repetitions=countRepetitions(s, needle);

                for(int k=1;k<=repetitions;k++)
                {
                    //Don't encoded the string
                    if(k==1)
                    {
                        string remaining=s.substr(substringLength + 1, string::npos);
                        
                        string notEncoded=needle + helper(remaining);

                        if(notEncoded.size() < subproblemSolution.size())
                        {
                            subproblemSolution=notEncoded;
                        }
                    }
                    //Encode the string
                    else
                    {
                        string remaining=s.substr(needle.size() * k, string::npos);

                        string encoded=to_string(k) + "[" + helper(needle) + "]" + helper(remaining);

                        if(encoded.size() < subproblemSolution.size())
                        {
                            subproblemSolution=encoded;
                        }
                    }
                }
            }

            return subproblemSolution;
        }

        int countRepetitions(string & haystack, string & needle)
        {
            int repetitions=0;

            int i=0;

            while(i < haystack.size())
            {
                if(haystack.substr(i, needle.size())!=needle)
                {
                    break;
                }

                repetitions+=1;

                i=i + needle.size();
            }

            return repetitions;
        }
};

/*
Solution 2: recursive depth-first search + memoization
*/

class Solution
{
    public:
        string encode(string s)
        {
            string result="";

            unordered_map<string, string> memo;

            result=helper(s, memo);

            return result;
        }

        string helper(string & s, unordered_map<string, string> & memo)
        {
            if(s.size() < 5)
            {
                return s;
            }

            if(memo.find(s)!=memo.end())
            {
                return memo[s];
            }

            string subproblemSolution=s;

            for(int substringLength=0;substringLength<s.size();substringLength++)
            {
                string needle=s.substr(0, substringLength + 1);

                int repetitions=countRepetitions(s, needle);

                for(int k=1;k<=repetitions;k++)
                {
                    if(k==1)
                    {
                        string remaining=s.substr(substringLength + 1, string::npos);
                        
                        string notEncoded=needle + helper(remaining, memo);

                        if(notEncoded.size() < subproblemSolution.size())
                        {
                            subproblemSolution=notEncoded;
                        }
                    }
                    else
                    {
                        string remaining=s.substr(needle.size() * k, string::npos);

                        string encoded=to_string(k) + "[" + helper(needle, memo) + "]" + helper(remaining, memo);

                        if(encoded.size() < subproblemSolution.size())
                        {
                            subproblemSolution=encoded;
                        }
                    }
                }
            }

            memo[s]=subproblemSolution;

            return subproblemSolution;
        }

        int countRepetitions(string & haystack, string & needle)
        {
            int repetitions=0;

            int i=0;

            while(i < haystack.size())
            {
                if(haystack.substr(i, needle.size())!=needle)
                {
                    break;
                }

                repetitions+=1;

                i=i + needle.size();
            }

            return repetitions;
        }
};