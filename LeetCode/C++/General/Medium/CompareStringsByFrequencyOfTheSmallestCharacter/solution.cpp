#include <set>
#include <string>
#include <vector>
using namespace std;

class Solution
{
    public:
        vector<int> numSmallerByFrequency(vector<string> & queries, vector<string> & words)
        {
            vector<int> result;

            int q=queries.size();

            int w=words.size();

            result.resize(q, 0);

            multiset<int> hashset;

            for(string & word : words)
            {
                int frequency=getFrequencyOfSmallestCharacter(word);

                hashset.insert(frequency);
            }

            for(int i=0;i<q;i++)
            {
                string query=queries[i];

                int frequency=getFrequencyOfSmallestCharacter(query);

                auto itr=hashset.upper_bound(frequency);

                int dist=distance(itr, hashset.end());

                result[i]=dist;
            }

            return result;
        }

        int getFrequencyOfSmallestCharacter(string & word)
        {
            int frequency=-1;

            vector<int> frequencies(26, 0);

            for(char & letter : word)
            {
                int asciiIndex=letter - 'a';

                frequencies[asciiIndex]+=1;
            }

            for(int asciiIndex=0;asciiIndex<26;asciiIndex++)
            {
                if(frequencies[asciiIndex] > 0)
                {
                    frequency=frequencies[asciiIndex];

                    break;
                }
            }

            return frequency;
        }
};

class Solution
{
    public:
        vector<int> numSmallerByFrequency(vector<string> & queries, vector<string> & words)
        {
            vector<int> result;

            int q=queries.size();

            int w=words.size();

            result.resize(q, 0);

            vector<int> frequencyBuckets(11, 0);

            for(string & word : words)
            {
                int frequency=getFrequencyOfSmallestCharacter(word);

                frequencyBuckets[frequency]+=1;
            }

            for(int i=0;i<q;i++)
            {
                string query=queries[i];

                int frequency=getFrequencyOfSmallestCharacter(query);

                for(int j=0;j<11;j++)
                {
                    if(j > frequency and frequencyBuckets[j] > 0)
                    {
                        result[i]+=frequencyBuckets[j];
                    }
                }
            }

            return result;
        }

        int getFrequencyOfSmallestCharacter(string & word)
        {
            int frequency=-1;

            vector<int> frequencies(26, 0);

            for(char & letter : word)
            {
                int asciiIndex=letter - 'a';

                frequencies[asciiIndex]+=1;
            }

            for(int asciiIndex=0;asciiIndex<26;asciiIndex++)
            {
                if(frequencies[asciiIndex] > 0)
                {
                    frequency=frequencies[asciiIndex];

                    break;
                }
            }

            return frequency;
        }
};