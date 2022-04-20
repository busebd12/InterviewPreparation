#include <queue>
#include <string>
#include <unordered_map>
using namespace std;

/*
Solution: see comments.

Time complexity: O(n + (u log u) + (u log u)) [where n is the length of s and u is the number of unique characters in s]

Space complexity: O(u)
*/

class Solution
{
    public:
        string reorganizeString(string s)
        {
            string result{};
            
            //Map each character to its frequency
            unordered_map<char, int> frequencies;
            
            //Create the frequency mappings
            for(auto & letter : s) //O(n)
            {
                frequencies[letter]+=1;
            }
            
            //Custom comparator for our max heap that will sort the characters in increasing order based on their frequency. So, the highest occurring character will be at the top and the frequency decreases as you go down in the heap
            auto comparator=[&frequencies] (auto & lhs, auto & rhs) {return frequencies[lhs] < frequencies[rhs];};
            
            priority_queue<char, vector<char>, decltype(comparator)> maxHeap(comparator);
            
            //IMPORTANT: only add one of each letter in s to the heap
            for(auto & [letter, frequency] : frequencies) //O(u)
            {
                maxHeap.emplace(letter); //O(log(u))
            }
            
            //While there are at least two different characters in the heap
            while(maxHeap.size() > 1) //O(u)
            {
                char first=maxHeap.top();
                
                maxHeap.pop();
                
                char second=maxHeap.top();
                
                maxHeap.pop();
                
                //Add the two different characters to the result string to make sure that two adjacent characters are not the same
                result.push_back(first);
                
                result.push_back(second);
                
                //If the frequency is greater than one, then there is still at least one more occurrence of the character left
                if(frequencies[first] > 1)
                {
                    frequencies[first]-=1;
                    
                    maxHeap.emplace(first); //O(log(u))
                }
                
                if(frequencies[second] > 1)
                {
                    frequencies[second]-=1;
                    
                    maxHeap.emplace(second); //O(log(u))
                }
            }
            
            //At this point, since there is only one character left in the heap, we have used up all other characters in s but one
            //The only way we can add one more occurrence of this last character is if the last character in the result string is different from this character
            if(result.back()!=maxHeap.top())
            {   
                char letter=maxHeap.top();
                
                maxHeap.pop();
                
                frequencies[letter]-=1;
                
                result.push_back(letter);
            }
            
            //In order for this re-arrangement of s to be valid, it has to be the same size as s
            //Otherwise, we didn't use all of the characters in s
            if(result.size()!=s.size())
            {
                result="";
            }
            
            return result;
        }
};