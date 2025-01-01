#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

/*
Solution 1: Brute-force.

Time complexity: O(n^2) [where n=length of ideas]
Space complexity: O(n)
*/

class Solution
{
    public:
        long long distinctNames(vector<string> & ideas)
        {
            long long result=0;

            int n=ideas.size();

            unordered_set<string> hashset;

            for(string & idea : ideas)
            {
                hashset.insert(idea);
            }

            for(int i=0;i<n;i++)
            {
                string ideaA=ideas[i];
                
                for(int j=0;j<n;j++)
                {
                    if(i!=j)
                    {
                        string ideaB=ideas[j];
                        
                        swap(ideaA[0], ideaB[0]);

                        if(hashset.find(ideaA)==hashset.end() and hashset.find(ideaB)==hashset.end())
                        {   
                            result+=1;
                        }

                        swap(ideaA[0], ideaB[0]);
                    }
                }
            }

            return result;
        }
};

/*
Solution 2: see comments.

Time complexity: O(n)
Space complexity: O(n)
*/

class Solution
{
    public:
        long long distinctNames(vector<string> & ideas)
        {
            long long result=0;

            int n=ideas.size();

            //Map each first letter to group of suffixes
            vector<unordered_set<string>> hashset(26, unordered_set<string>());

            //Iterate through ideas and create the mappings
            for(string & idea : ideas)
            {
                char firstLetter=idea[0];

                //Since all letters are lowercase english letters, we can use the ascii value as the key in our hashset
                int asciiIndex=firstLetter - 'a';

                string suffix=idea.substr(1, string::npos);

                hashset[asciiIndex].insert(suffix);
            }

            //Iterate through all pairs of first letters
            for(int i=0;i<26;i++)
            {
                for(int j=i+1;j<26;j++)
                {
                    //Counter of the number of suffixes shared between the two sets
                    int commonSuffixes=0;
                    
                    //Loop through the set of suffixes for the first letter ascii value i
                    for(const string & suffix : hashset[i])
                    {
                        //If the second set also contains this suffix
                        if(hashset[j].count(suffix)==1)
                        {
                            commonSuffixes+=1;
                        }
                    }

                    //Number of remaining suffixes from the first set after removing the intersection
                    int remainingInFirstSet=hashset[i].size() - commonSuffixes;

                    //Number of remaining suffixes from the second set after removing the intersection
                    int remainingInSecondSet=hashset[j].size() - commonSuffixes;

                    //Total pairs possible between the two sets
                    //Note: we multiply by two because you can swap the order of a valid pair and it still counts towards the answer
                    //Example: the two ideas coffee and donuts. If the order is coffee then donuts, we have doffee and conuts.
                    //If the order is donuts then coffee, we have conuts and doffee
                    int totalUnique=2 * remainingInFirstSet * remainingInSecondSet;

                    result+=totalUnique;
                }
            }

            return result;
        }
};