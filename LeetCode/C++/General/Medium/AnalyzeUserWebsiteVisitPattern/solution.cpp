#include <algorithm>
#include <map>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>

/*
Solution: inspired from this post --> https://leetcode.com/problems/analyze-user-website-visit-pattern/discuss/1797973/C%2B%2B-Brute-force-with-brief-inline-explanations
*/

class Solution
{
    public:
        vector<string> mostVisitedPattern(vector<string> & username, vector<int> & timestamp, vector<string>& website)
        {
            vector<string> result{};

            int n=username.size();

            vector<int> indices(n, 0);

            for(int i=0;i<n;i++)
            {
                indices[i]=i;
            }

            //Sort the indices based on the timestamps
            sort(begin(indices), end(indices), [&timestamp] (auto & lhs, auto & rhs) {return timestamp[lhs] < timestamp[rhs];});

            //Map each pattern to its frequency (score)
            unordered_map<string, int> patternFrequencies;

            //Map each username to the websites they visited
            unordered_map<string, vector<string>> usernameToWebsitesMap;

            //Iterate through usernames and websites to create mappings
            for(auto & index : indices)
            {
                string user=username[index];

                string site=website[index];

                usernameToWebsitesMap[user].emplace_back(site);
            }

            for(auto & [user, websites] : usernameToWebsitesMap)
            {
                //If the user visited more than 3 websites
                if(websites.size() > 3)
                {
                    int w=websites.size();

                    //List of distinct patterns of the user
                    unordered_set<string> distinctPatterns;

                    for(int a=0;a<w;a++)
                    {
                        for(int b=a+1;b<w;b++)
                        {
                            for(int c=b+1;c<w;c++)
                            {
                                string pattern=websites[a] + "-" + websites[b] + "-" + websites[c];

                                distinctPatterns.insert(pattern);
                            }
                        }
                    }

                    //Increment the frequency (score) for each pattern
                    for(auto & pattern : distinctPatterns)
                    {
                        patternFrequencies[pattern]+=1;
                    }
                }
                //If the user visited exactly three websites
                else if(websites.size()==3)
                {
                    string pattern=websites[0] + "-" + websites[1] + "-" + websites[2];

                    patternFrequencies[pattern]+=1;
                }   
            }

            //Map to group all patterns by their score
            map<int, set<string>> scoreToPatternsMap;

            //Group patterns by their score
            for(auto & [pattern, score] : patternFrequencies)
            {
                scoreToPatternsMap[score].insert(pattern);
            }

            //Since std::map stores its keys in ascending order, after grouping patterns by their score, the list of patterns that have 
            //the highest score is the value of the last <key, value> pair in the scoreToPatternsMap
            //The lexicographically smallest such pattern from that list is the first pattern in the list since std::set maintains its elements in sorted order
            string answer=*(begin(rbegin(scoreToPatternsMap)->second));

            //Parse the individual websites from the pattern
            stringstream ss(answer);

            char delimiter='-';

            string token{};

            while(getline(ss, token, delimiter))
            {
                result.emplace_back(token);
            }

            return result;
        }
};