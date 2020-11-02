#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

/*
 * Solution: we use recursion + backtracking to generate all possible combinations of valid strings and update the
 * maximum length as we go.
 *
 * Time complexity: O(2^n) [where n is the total number of strings]
 * Space complexity: O(n) [recursive stack space]
 */

class Solution
{
    public:

        bool allUnique(std::string & str)
        {
            std::unordered_set<char> us(str.begin(), str.end());

            return us.size()==str.size();
        }

        bool stringsConflict(std::unordered_set<char> & cache, std::string & str)
        {
            for(const auto & letter : str)
            {
                if(cache.count(letter))
                {
                    return true;
                }
            }

            return false;
        }

        void addLetters(std::unordered_set<char> & cache, std::string & str)
        {
            for(const auto & letter : str)
            {
                cache.insert(letter);
            }
        }

        void removeLetters(std::unordered_set<char> & cache, std::string & str)
        {
            for(const auto & letter : str)
            {
                if(cache.count(letter))
                {
                    cache.erase(letter);
                }
            }
        }

        void backtracking(std::vector<std::string> & arr, std::unordered_set<char> & cache, int n, int & result, int & length, int start)
        {
            for(int index=start;index<n;index++)
            {
                int size=int(arr[index].size());

                if(!allUnique(arr[index]) || stringsConflict(cache, arr[index]))
                {
                    continue;
                }

                addLetters(cache, arr[index]);

                length+=size;

                result=std::max(result, length);

                backtracking(arr, cache, n, result, length, index + 1);

                length-=size;

                removeLetters(cache, arr[index]);
            }
        }

        int maxLength(std::vector<std::string> & arr)
        {
            if(arr.empty())
            {
                return 0;
            }

            int n=int(arr.size());

            if(n==1)
            {
                return allUnique(arr[0]) ? int(arr[0].size()) : 0;
            }

            int result=0;

            int length=0;

            std::unordered_set<char> cache;

            int start=0;

            backtracking(arr, cache, n, result, length, start);

            return result;
        }
};