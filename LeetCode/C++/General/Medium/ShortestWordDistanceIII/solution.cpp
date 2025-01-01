#include <limits>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
    public:
        int shortestWordDistance(vector<string> & wordsDict, string word1, string word2)
        {
            int result=numeric_limits<int>::max();

            int w=wordsDict.size();

            unordered_map<string, set<int>> hashmap;

            for(int i=0;i<w;i++)
            {
                string word=wordsDict[i];

                if(hashmap.find(word)==hashmap.end())
                {
                    hashmap.emplace(word, set<int>());
                }

                hashmap[word].insert(i);
            }

            if(word1==word2)
            {
                auto behind=hashmap[word1].begin();

                auto ahead=next(hashmap[word1].begin());

                while(ahead!=hashmap[word1].end())
                {
                    int index1=*behind;
                    
                    int index2=*ahead;

                    int difference=index2 - index1;

                    result=min(result, difference);

                    behind++;

                    ahead++;
                }
            }
            else
            {
                for(int word1Index : hashmap[word1])
                {
                    auto itr=hashmap[word2].lower_bound(word1Index);

                    if(itr!=hashmap[word2].end())
                    {
                        int word2Index=*itr;

                        int distance=word2Index - word1Index;

                        result=min(result, distance);
                    }
                }

                for(int word2Index : hashmap[word2])
                {
                    auto itr=hashmap[word1].lower_bound(word2Index);

                    if(itr!=hashmap[word1].end())
                    {
                        int word1Index=*itr;

                        int distance=word1Index - word2Index;

                        result=min(result, distance);
                    }
                }
            }

            return result;
        }
};