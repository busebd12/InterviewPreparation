#include <algorithm>
#include <deque>
#include <string>

/*
Solution 1: Brute force breadth-first search. Note, this solution gets Time Limit Exceeded when run.
*/
class Solution
{
    public:
        bool isMonotoneIncreasing(string str)
        {
            bool allOnes=all_of(begin(str), end(str), [] (auto & letter) {return letter=='1';});

            bool allZeros=all_of(begin(str), end(str), [] (auto & letter) {return letter=='0';});

            auto firstZeroIndex=str.find_first_of('0');

            auto lastZeroIndex=str.find_last_of('0');

            auto firstOneIndex=str.find_first_of('1');

            auto lastOneIndex=str.find_last_of('1');

            bool monotoneIncreasing=(firstZeroIndex < firstOneIndex && lastZeroIndex < firstOneIndex && firstOneIndex < lastOneIndex);

            return allZeros || allOnes || monotoneIncreasing;
        }
    
        int minFlipsMonoIncr(string s)
        {
            int result=0;

            deque<string> queue;

            queue.emplace_back(s);

            bool done=false;

            while(!queue.empty())
            {
                int qSize=queue.size();

                for(int count=0;count<qSize;count++)
                {
                    auto current=queue.front();

                    queue.pop_front();

                    if(isMonotoneIncreasing(current))
                    {
                        done=true;

                        break;
                    }

                    int n=current.size();

                    for(int index=0;index<n;index++)
                    {
                        string copy=current;

                        if(copy[index]=='1')
                        {
                            copy[index]='0';
                        }
                        else
                        {
                            copy[index]='1';
                        }

                        queue.emplace_back(copy);
                    }
                }

                if(done)
                {
                    break;
                }

                result++;
            }
            
            return result;
        }
};

/*
Solution 2: inspired from this post --> https://leetcode.com/problems/flip-string-to-monotone-increasing/discuss/1831565/Seen-as-a-parenthesis-pairing-problem

Time complexity: O(n) [where n is the length of s]
Space complexity: O(1)
*/

class Solution
{
    public:
        int minFlipsMonoIncr(string s)
        {
            int result=0;

            int count=0;
            
            for(auto letter : s)
            {
                if(letter=='1')
                {
                    count++;
                }
                else
                {
                    if(count > 0)
                    {
                        count--;
                        
                        result++;
                    }
                }
            }
            
            return result;
        }
};