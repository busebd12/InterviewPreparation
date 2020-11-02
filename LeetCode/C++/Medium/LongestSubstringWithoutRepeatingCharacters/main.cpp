#include <cmath>
#include <deque>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>

/*
 * Evolution of solutions:
 *
 * 1. Generate all substrings of the input string and find the longest one that has all distinct letters.
 *
 * Time complexity: O(n-cubed) [where n is the length of the input string]
 * Space complexity: O(s) [where s is the number of substrings that can be formed from the input string]
 *
 * 2. Same logic but using a vector of integers to store the letters as their ascii values instead of an unordered_set<char>.
 *
 * Time complexity: O(n-cubed) [where n is the length of the input string]
 * Space complexity: O(1)
 *
 * 3. We maintain a sliding window (via a deque) of unique characters and every time we come across a duplicate character,
 * we adjust our window. We use an unordered_set<char> to keep track of the uniqueness of the characters.
 *
 * Time complexity: O(n-squared) [where n is the length of the input string]
 * Space complexity: O(n)
 *
 *
 * 4. Same approach as the third solution except we don't every travel backwards along the string, only forwards.
 *
 * Time complexity: O(n) [where n is the length of the input string]
 * Space complexity: O(n)
 *
 * 5. Instead of using two data-structures to maintain our sliding window, we only use one, an unordered_map<char, int> hashtable.
 * In this hashtable, map each character to its index. When we come across a duplicate character, we simply move the left-side
 * of our sliding window up to the index of the duplicate character and our sliding window starts over again.
 *
 * Time complexity: O(n * L) [where n is the length of the input string and L is average length of a sliding window]
 * Space complexity: O(n)
 *
 * 6. Insted of maintaining our sliding window by index, whenever we come across a duplicate character, we erase
 * all the characters from our sliding window from our hashtable and then start the window over with the current character.
 *
 * Time complexity: O(n * L) [where n is the length of the input string and L is the length of the average sliding window]
 * Space complexity: O(n)
 *
 * 7. While iterating over the string, we keep inserting characters into our hashtable (unordered_set<char>) until
 * we encounter a duplicate character. At this point, we simply delete characters from our hashtable until it no
 * longers contains duplicate characters. This way, our sliding window will always contain unique characters.
 *
 * Time complexity: O(n) [where n is the length of the input string]
 * Space complexity: O(n)
 *
 */

int lengthOfLongestSubstring(std::string s)
{
    auto n=s.size();

    int result=0;

    for(auto length=1;length<=n;++length)
    {
        for(auto start=0;start+length<=n;++start)
        {
            std::unordered_set<char> cache;

            bool allDistinct=true;

            for(const auto & letter : s.substr(start, length))
            {
                if(cache.count(letter))
                {
                    allDistinct=false;

                    break;
                }
                else
                {
                    cache.insert(letter);
                }
            }

            if(allDistinct)
            {
                result=std::max(result, int(s.substr(start, length).size()));
            }
        }
    }

    return result;
}

int lengthOfLongestSubstring(std::string s)
{
    auto n=s.size();

    int result=0;

    for(auto length=1;length<=n;++length)
    {
        for(auto start=0;start+length<=n;++start)
        {
            std::vector<int> cache(255, 0);

            bool allDistinct=true;

            for(const auto & letter : s.substr(start, length))
            {
                if(cache[int(letter)])
                {
                    allDistinct=false;

                    break;
                }
                else
                {
                    cache[int(letter)]++;
                }
            }

            if(allDistinct)
            {
                result=std::max(result, int(s.substr(start, length).size()));
            }
        }
    }

    return result;
}

int lengthOfLongestSubstring(std::string s)
{
    int result=0;

    if(s.empty())
    {
        return result;
    }

    auto n=s.size();

    std::deque<char> slidingWindow;

    std::unordered_map<char, int> hashtable;

    auto i=0;

    while(i < n)
    {
        if(hashtable.count(s[i]))
        {
            result=std::max(result, static_cast<int>(slidingWindow.size()));

            auto distance=i - hashtable[s[i]];

            if(distance > 1)
            {
                auto j=slidingWindow.size();

                int count=0;

                while(count < distance-1)
                {
                    j--;

                    count++;
                }

                char newSlidingWindowFront=slidingWindow[j];

                while(slidingWindow.front()!=newSlidingWindowFront)
                {
                    hashtable.erase(slidingWindow.front());

                    slidingWindow.pop_front();
                }

                hashtable[s[i]]=i;

                slidingWindow.push_back(s[i]);
            }
            else
            {
                slidingWindow.clear();

                hashtable.clear();

                hashtable[s[i]]=i;

                slidingWindow.push_back(s[i]);
            }
        }
        else
        {
            hashtable[s[i]]=i;

            slidingWindow.push_back(s[i]);
        }

        i++;
    }

    if(!slidingWindow.empty())
    {
        result=std::max(result, static_cast<int>(slidingWindow.size()));
    }

    return result;
}

int lengthOfLongestSubstring(std::string s)
{
    int result=0;

    if(s.empty())
    {
        return result;
    }

    auto n=s.size();

    std::unordered_map<char, int> hashtable;

    auto i=0;

    auto j=0;

    while(j < n)
    {
        if(hashtable.count(s[j]))
        {
            result=std::max(result, static_cast<int>(hashtable.size()));

            auto distance=j - hashtable[s[j]];

            if(distance > 1)
            {
                while(i <= hashtable[s[j]])
                {
                    hashtable.erase(s[i]);

                    i++;
                }

                char newSlidingWindowFront=s[i];

                hashtable[s[j]]=j;
            }
            else
            {
                i=j;

                hashtable.clear();

                hashtable[s[j]]=j;
            }
        }
        else
        {
            hashtable[s[j]]=j;
        }

        j++;
    }

    result=std::max(result, int(hashtable.size()));

    return result;
}

int lengthOfLongestSubstring(std::string s)
{
    int result=0;

    if(s.empty())
    {
        return result;
    }

    auto n=s.size();

    std::unordered_map<char, int> hashtable;

    auto i=0;

    auto j=0;

    while(j < n)
    {
        if(hashtable.count(s[j]))
        {
            result=std::max(result, static_cast<int>(hashtable.size()));

            while(i <= hashtable[s[j]])
            {
                hashtable.erase(s[i]);

                i++;
            }
        }

        hashtable[s[j]]=j;

        j++;
    }

    result=std::max(result, int(hashtable.size()));

    return result;
}

int lengthOfLongestSubstring(std::string s)
{
    if(s.empty())
    {
        return 0;
    }

    auto n=s.size();

    auto i=0;

    int result=0;

    std::unordered_set<char> hashtable;

    while(i < n)
    {
        if(hashtable.count(s[i]))
        {
            result=std::max(result, int(hashtable.size()));

            hashtable.clear();

            int j=i-1;

            if(j >= 0)
            {
                hashtable.insert(s[j]);
            }
        }

        hashtable.insert(s[i]);

        i++;
    }

    if(!hashtable.empty())
    {
        result=std::max(result, int(hashtable.size()));
    }

    return result;
}

int lengthOfLongestSubstring(std::string s)
{
    int result=0;

    if(s.empty())
    {
        return result;
    }

    auto n=s.size();

    std::unordered_set<char> hashtable;

    auto i=0;

    auto j=0;

    while(j < n)
    {
        if(!hashtable.count(s[j]))
        {
            hashtable.insert(s[j]);

            result=std::max(result, static_cast<int>(hashtable.size()));

            j++;
        }
        else
        {
            hashtable.erase(s[i]);

            i++;
        }
    }

    return result;
}