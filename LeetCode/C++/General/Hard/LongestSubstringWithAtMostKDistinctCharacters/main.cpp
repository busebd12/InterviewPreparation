#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

/*
 * Solution: we use two-pointers + the sliding window technique. We maintain a back and front "pointer" to iterate
 * through the string. As we iterate through the string, there are two different scenarios,
 *
 * a. the character, s[front], is not in our hashtable then we have two sub-cases: first, the hashtable already contains
 * k distinct characters, so we decrement the count of the character, s[back], in the hashtable. If the count is zero,
 * then we remove the character from the hashtable entirely. Then, we increment the back pointer. Second, there are
 * less than k distinct characters. In this case, we insert or increment the count of character in the hashtable,
 * calculate the max length so far, and increment the front pointer.
 *
 * b. the character, s[front], is already in the hashtable. In this case, we simply increment the count of the character,
 * calculate the max length so far, and increment the front pointer.
 *
 * Time complexity: O(n) [where n is the length of s]
 * Space complexity: O(u) [where u is the number of unique characters in s]
 */

class Solution
{
    public:
        int lengthOfLongestSubstringKDistinct(std::string s, int k)
        {
            if(s.empty() || k <= 0)
            {
                return 0;
            }

            std::unordered_map<char, int> hashtable;

            int n=int(s.size());

            int back=0;

            int front=0;

            int length=0;

            while(front < n)
            {
                char current=s[front];

                if(hashtable.count(current))
                {
                    hashtable[current]++;

                    length=std::max(length, (front - back) + 1);

                    front++;
                }
                else
                {
                    if(hashtable.size()==k)
                    {
                        char backCharacter=s[back];

                        hashtable[backCharacter]--;

                        if(hashtable[backCharacter]==0)
                        {
                            hashtable.erase(backCharacter);
                        }

                        back++;
                    }
                    else
                    {
                        hashtable[current]++;

                        length=std::max(length, (front - back) + 1);

                        front++;
                    }
                }
            }

            return length;
        }
};