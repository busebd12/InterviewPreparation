#include <deque>
#include <string>
#include <vector>
using namespace std;

/*
Solution: see comments.

Time complexity: O(n * (l + q) + (q log q) + (q))
[where n is the length of s, l is the average number of letters between the {}, and q is the average size of the deque]

Space complexity: O(t) [where t is the total number of formed words]
*/

class Solution
{
    public:
        vector<string> expand(string s)
        {
            vector<string> result;
            
            int n=s.size();
            
            //Queue to hold the words as we create them using breadth-first search
            deque<string> queue;
            
            //Start with the empty string
            queue.emplace_back("");
            
            //List of letters that occur within the {}
            vector<char> letters;
            
            for(int i=0;i<n;) //O(n)
            {
                //If we find a {
                if(s[i]=='{') //O(l)
                {
                    int j=i+1;
                    
                    while(j < n && s[j]!='}')
                    {
                        //Add each letter to the list of letters
                        if(s[j]!=',')
                        {
                            letters.emplace_back(s[j]);
                        }
                        
                        j++;
                    }
                    
                    i=j;
                }
                //Since we've found the closing }, we can use the letters found within the {} to further construct the words
                else if(s[i]=='}') //O(q)
                {
                    auto qSize=queue.size();
                    
                    for(int count=0;count<qSize;count++)
                    {
                        //Remove each word from the queue
                        auto current=queue.front();
                        
                        queue.pop_front();
                        
                        //Append each letter from the list of letters to the current word and add it back into the queue
                        for(auto & letter : letters)
                        {
                            queue.emplace_back(current + letter);
                        }
                    }
                    
                    letters.clear();
                    
                    i++;
                }
                //Just a single letter
                else //O(q)
                {
                    auto qSize=queue.size();
                    
                    for(int count=0;count<qSize;count++)
                    {
                        //Remove each word from the queue
                        auto current=queue.front();
                        
                        queue.pop_front();
                        
                        //Append the letter to each word and add the word back into the queue
                        queue.emplace_back(current + s[i]);
                    }
                    
                    i++;
                }
            }
            
            //After we've generated all the words, we need to sort them to ensure that they are in lexicographical order
            sort(begin(queue), end(queue)); //O(q log q)
            
            //Add each word from the queue into our result vector
            for(auto & word : queue) //O(q)
            {
                result.emplace_back(word);
            }
            
            return result;
        }
};