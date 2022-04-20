#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

/*
Solution: inspired by this post --> https://leetcode.com/problems/longest-happy-string/discuss/1707730/Java-100-intuitive-Assume-no-similar-char-can-be-next-to-each-other.
*/

class Solution
{
    public:
        string longestDiverseString(int a, int b, int c)
        {
            string result{};
            
            unordered_map<char, int> frequencies;
            
            frequencies['a']=a;
            
            frequencies['b']=b;
            
            frequencies['c']=c;
            
            auto comparator=[&frequencies] (auto & c1, auto & c2) {return frequencies[c1] < frequencies[c2];};
            
            priority_queue<char, vector<char>, decltype(comparator)> maxHeap(comparator);
            
            if(a > 0)
            {
                maxHeap.emplace('a');
            }
            
            if(b > 0)
            {
                maxHeap.emplace('b');
            }
            
            if(c > 0)
            {
                maxHeap.emplace('c');
            }
            
            string temp{};
            
            while(maxHeap.size() > 1)
            {
                char first=maxHeap.top();
                
                maxHeap.pop();
                
                char second=maxHeap.top();
                
                maxHeap.pop();
                
                temp.push_back(first);
                
                temp.push_back(second);
                
                if(frequencies[first] > 1)
                {
                    frequencies[first]--;
                    
                    maxHeap.emplace(first);
                }
                
                if(frequencies[second] > 1)
                {
                    frequencies[second]--;
                    
                    maxHeap.emplace(second);
                }
            }
            
            if(maxHeap.empty())
            {
                return temp;
            }
            
            char remaining=maxHeap.top();
            
            maxHeap.pop();
            
            temp.push_back(remaining);
            
            frequencies[remaining]-=1;
            
            for(auto letter : temp)
            {
                result.push_back(letter);
                
                if(letter==remaining && frequencies[remaining] > 0)
                {
                    result.push_back(remaining);
                    
                    frequencies[remaining]-=1;
                }
            }
            
            return result;
        }
    };