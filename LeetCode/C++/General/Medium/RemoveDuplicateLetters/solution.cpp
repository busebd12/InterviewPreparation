#include <deque>
#include <string>
#include <vector>
using namespace std;

/*
Solution: inspired from this post --> https://leetcode.com/problems/remove-duplicate-letters/discuss/1859583/c%2B%2B-solution-using-stack

Time complexity: O(n) [where n is the length of s]
Space complexity: O(n)
*/

class Solution
{
    public:
        string removeDuplicateLetters(string s)
        {
            string result{};
            
            int n=s.size();
            
            deque<char> stack;
            
            //Map each character to its frequency
            vector<int> frequencies(26, 0);
            
            //Keep track of whether we've seen each character before in the string
            vector<bool> seen(26, false);
            
            //Calculate the frequency for each letter in the string
            for(auto & letter : s)
            {
                frequencies[letter - 'a']++;
            }
            
            //Iterate through s
            for(int i=0;i<n;i++)
            {
                char c=s[i];
                
                //Stack is empty 
                if(stack.empty())
                {
                    //Push character onto the stack
                    stack.emplace_back(c);
                    
                    //Decrement the frequency of the character
                    frequencies[c - 'a']--;
                    
                    //Mark the character as seen
                    seen[c - 'a']=true;
                }
                else
                {
                    //While the following conditions hold:
                    //1. Stack is not empty
                    //2. The current character comes before the character at the top of the stack in the alphabet
                    //3. The frequency of the character at the top of the stack is greater than zero - we will encounter this character again 
                    //later on in the string, so it is safe to remove it from the stack
                    //4. We haven't seen the current character before in the string
                    while(!stack.empty() && c < stack.back() && frequencies[stack.back() - 'a'] > 0 && seen[c - 'a']==false)
                    {
                        //Mark the character at the top of the stack as unseen
                        seen[stack.back() - 'a']=false;
                        
                        //Remove the top character from the stack
                        stack.pop_back();
                    }
                    
                    //If we haven't seen the current character before in the string
                    if(seen[c - 'a']==false)
                    {
                        //Add it to the stack
                        stack.emplace_back(c);
                        
                        //Decrement the frequency
                        frequencies[c - 'a']--;
                        
                        //Mark it as seen
                        seen[c - 'a']=true;
                    }
                    //Else, we've seen the current character before
                    else
                    {
                        //Decrement the frequency
                        frequencies[c - 'a']--;
                    }
                }
            }
            
            //Form the result string from the letters in the stack
            for(const auto & letter : stack)
            {
                result.push_back(letter);
            }
            
            return result;
        }
};