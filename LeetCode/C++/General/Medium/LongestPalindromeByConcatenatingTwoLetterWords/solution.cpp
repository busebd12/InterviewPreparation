#include <string>
#include <unordered_map>
using namespace std;

/*
Time complexity: O(w) [where w is the length of words]
Space complexity: O(u) [where u is the number of unique words]
*/

class Solution
{
    public:
        int longestPalindrome(vector<string> & words)
        {
            int result=0;

            unordered_map<string, int> hashmap;

            for(string word : words)
            {
                if(hashmap.find(word)==hashmap.end()) //O(w)
                {
                    hashmap.emplace(word, 0);
                }

                hashmap[word]+=1;
            }

            bool alreadyHaveSingleton=false;

            for(string word : words) //O(w)
            {   
                auto wordItr=hashmap.find(word);

                if(wordItr!=hashmap.end())
                {
                    if(word[0]!=word[1])
                    {
                        string mirrorHalf="";

                        mirrorHalf.push_back(word[1]);

                        mirrorHalf.push_back(word[0]);

                        auto mirrorHalfItr=hashmap.find(mirrorHalf);

                        if(mirrorHalfItr!=hashmap.end())
                        {
                            result+=4;

                            hashmap[word]-=1;

                            if(hashmap[word]==0)
                            {
                                hashmap.erase(word);
                            }

                            hashmap[mirrorHalf]-=1;

                            if(hashmap[mirrorHalf]==0)
                            {
                                hashmap.erase(mirrorHalf);
                            }
                        }
                    }
                    else
                    {
                        if(hashmap[word]==1)
                        {
                            if(alreadyHaveSingleton==false)
                            {
                                alreadyHaveSingleton=true;

                                result+=2;

                                hashmap[word]-=1;

                                hashmap.erase(word);
                            }
                        }
                        else
                        {
                            int lengthAdded=0;

                            if((hashmap[word] % 2)==1)
                            {
                                if(alreadyHaveSingleton==false)
                                {
                                    alreadyHaveSingleton=true;

                                    lengthAdded=hashmap[word] * 2;

                                    result+=lengthAdded;
                                }
                                else
                                {
                                    lengthAdded=(hashmap[word] - 1) * 2;

                                    result+=lengthAdded;
                                }
                            }
                            else
                            {
                                lengthAdded=hashmap[word] * 2;

                                result+=lengthAdded;
                            }

                            hashmap[word]-=(lengthAdded / 2);

                            if(hashmap[word]==0)
                            {
                                hashmap.erase(word);
                            }
                        }
                    }
                }
            }

            return result;
        }
};