#include <deque>
#include <string>
#include <unordered_map>

/*
Solution 1: see comments.

Time complexity: O(m + (n * m)) [where n is the length of s and m is the length of p]
Space complexity: O(u + m) [where u is the number of unique characters in p]
*/

class Solution
{
    public:
        vector<int> findAnagrams(string s, string p)
        {
            vector<int> result;
            
            int n=s.size();
            
            int m=p.size();
            
            //Map each letter in the anagram p to its frequency
            unordered_map<char, int> frequencies;
            
            //Create the frequency mappings
            for(auto & letter : p)
            {
                frequencies[letter]+=1;
            }
            
            int back=0;
            
            int front=0;
            
            //Keep track of indices for a potential anagram
            deque<int> indices;
            
            while(front < n)
            {
                //If the character a s[front] is part of the string p
                if(frequencies.find(s[front])!=end(frequencies))
                {
                    //If the frequency of the character s[front] is greater than zero
                    //This means we haven't used the character in the anagram yet
                    if(frequencies[s[front]] > 0)
                    {   
                        //Decrement the frequency of the s[front] character since we are "using" it in the current potential anagram
                        frequencies[s[front]]-=1;
                        
                        indices.emplace_back(front);
                        
                        //If the number of indices is equal to the length of p, then we have found an anagram
                        if(indices.size()==m)
                        {
                            //Add the starting index to the result
                            result.emplace_back(indices.front());
                        }
                        
                        front+=1;
                    }
                    //Else, the current character is in p but we have already used up all the occurences of it
                    else
                    {
                        frequencies[s[indices.front()]]+=1;
                        
                        indices.pop_front();
                        
                        back+=1;
                    }
                }
                //Else, the character s[front] is not in p
                else
                {   
                    //Move back up in the string until it meets front
                    while(back < front)
                    {
                        //Increment the frequency of the character since we are done with it
                        frequencies[s[indices.front()]]+=1;
                        
                        //Remove the index from indices
                        indices.pop_front();
                        
                        back+=1;
                    }
                    
                    //Since back and front both are at the index of a letter that is not in p, move them both up one index in s
                    front+=1;
                    
                    back+=1;
                }
            }
            
            return result;
        }
};

/*
Solution 2: almost the same as the first solution except that we don't use a deque to keep track of the length of the potential anagram.

Time complexity: O(m + (n * m)) [where n is the length of s and m is the length of p]
Space complexity: O(u) [where u is the number of unique characters in p]
*/

class Solution
{
    public:
        vector<int> findAnagrams(string s, string p)
        {
            vector<int> result;
            
            int n=s.size();
            
            int m=p.size();
            
            unordered_map<char, int> frequencies;
            
            for(auto & letter : p)
            {
                frequencies[letter]+=1;
            }
            
            int back=0;
            
            int front=0;
            
            while(front < n)
            {
                if(frequencies.find(s[front])!=end(frequencies))
                {
                    if(frequencies[s[front]] > 0)
                    {   
                        frequencies[s[front]]-=1;
                        
                        int length=(front - back) + 1;
                        
                        if(length==m)
                        {   
                            result.emplace_back(back);
                        }
                        
                        front+=1;
                    }
                    else
                    {   
                        frequencies[s[back]]+=1;
                        
                        back+=1;
                    }
                }
                else
                {   
                    while(back < front)
                    {   
                        frequencies[s[back]]+=1;
                        
                        back+=1;
                    }
                    
                    front+=1;
                    
                    back+=1;
                }
            }
            
            return result;
        }
};