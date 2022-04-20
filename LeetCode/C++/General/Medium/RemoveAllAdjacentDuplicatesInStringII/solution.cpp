#include <deque>
#include <iterator>
#include <list>
#include <string>
#include <utility>
#include <vector>
using namespace std;

/*
Solution 1: see comments. Note, this solution gets Time Limit Exceeded when submitted.

Time complexity: O((n^2) + (i * l))
[where n is the length of the linked list, i is the number of iterators, and l is the average length between last and first]

Space complexity: O(n)
*/
class Solution
{
    public:
        string removeDuplicates(string s, int k)
        {
            string result{};

            //Store characters of s as a linked list
            list<char> characters(begin(s), end(s));

            //While the linked list is not empty
            while(!characters.empty()) //O(n)
            {   
                //vector of linked list iterators
                vector<pair<list<char>::iterator, list<char>::iterator>> iterators;

                auto back=begin(characters);

                auto front=begin(characters);

                //While front is not at the end of the linked list
                while(front!=end(characters)) //O(n)
                {
                    //Count the number of duplicate characters
                    int count=0;

                    //While the iterators back and front point to duplicate characters
                    while(front!=end(characters) && *(back)==*(front) && count < k)
                    {
                        front++;

                        count++;
                    }

                    //If we've found k duplicate characters, then add the iterators pointing to the first and last of the k duplicate characters to the vector
                    if(count==k)
                    {
                        iterators.emplace_back(back, front);
                    }

                    //Move back until it matches front
                    while(back!=front)
                    {
                        back++;
                    }
                }

                //If we didn't find any iterators, then there are no more removals we can do
                if(iterators.empty())
                {
                    break;
                }

                //Go through the iterators and delete the range of k duplicate characters from the linked list
                for(auto [first, last] : iterators) //O(i * l) [where ]
                {
                    //Make sure first and last iterators are not equal to end since we can't dereference the end iterator
                    if(first!=end(characters) && last!=end(characters))
                    {
                        characters.erase(first, last);
                    }
                }
            }

            //Add the remaining letters to the result string
            for_each(begin(characters), end(characters), [&result] (auto & letter) {result.push_back(letter);});

            return result;
        }
};

/*
Solution 2: See comments.

Time complexity: O(n) [where n is the length of s]
Space complexity: O(n)
*/
class Solution
{
    public:
        string removeDuplicates(string s, int k)
        {
            string result{};

            //Stack of pairs - each pair is made up of the character and how many times we've seen it so far
            deque<pair<char, int>> stack;
            
            for(auto & letter : s)
            {
                //If the stack is empty
                if(stack.empty())
                {
                    //Add the first character
                    stack.emplace_back(letter, 1);
                }
                //The stack is not empty
                else
                {
                    //If the current letter is the same as the letter on the top of the stack
                    if(letter==stack.back().first)
                    {
                        //Get the current letter and count from the stack
                        auto [c, count]=stack.back();
                        
                        stack.pop_back();
                        
                        //If the total number of duplicate letters with the addition of the current one is still less than k, increment the count of the current letter and add it back onto the stack
                        if(count + 1 < k)
                        {
                            stack.emplace_back(c, count + 1);
                        }
                    }
                    //The current letter is different than the letter on the top of the stack
                    else
                    {
                        stack.emplace_back(letter, 1);
                    }
                }
            }
            
            //While the stack is not empty
            while(!stack.empty())
            {
                auto [letter, count]=stack.front();
                
                stack.pop_front();
                
                //Add the remaining letters to the result string
                for(int i=0;i<count;i++)
                {
                    result.push_back(letter);
                }
            }
            
            return result;
        }
};