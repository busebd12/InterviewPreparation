#include <array>
#include <iostream>
#include <string>
#include <unordered_map>

/*
 * Solutions:
 *
 * 1. Brute force. Using three for-loops we iterate over all possible windows (substrings).
 * For each window, we do the following
 *
 * a) use a hashtable that maps each unique character in t to its frequency.
 * b) for each character in the window, if the character appears in the hashtable, decrement its frequency.
 * c) if the frequency reaches zero, remove the character from the hashtable.
 *
 * After iterating over the window, if the hashtable is empty, then we know we found all letters from t in the window.
 * We keep track of the minimum size of such a window and update the result string to be the substring whose
 * size is smaller than result's.
 *
 * Time complexity: O(n^2) [where n is the length of the string s]
 * Space complexity: O(u) [where u is the number of unique characters in the string t]
 *
 *
 * 2. Sliding window, first attempt. We use a hashtable (std::unordered_map<char, int>) to map each unique letter in t
 * to its frequency. Then, we iterate over s with two-pointers and each time we add a letter to the sliding window that
 * appears in t, we decrement that letter's frequency in the hashtable. When all letters in the hashtable have frequency
 * 0, we know that our sliding window contains all letters from t. If the length of the string representing the current
 * sliding window is less than the result string, set the result string equal to the sliding window string. After interating
 * over s, the result string will be our answer.
 *
 * Time complexity: O(n^2 * u) [where n is the length of the string s and u is the number of unique characters in the string t]
 * Space complexity: O(u) [where u is the number unique characters in the string t]
 *
 * 3. Sliding window, improved. Similar to the second solution except that we don't construct the string from each sliding window,
 * we just compare the length of the sliding window with the best window length so far, and update the best window length
 * so far, if needed.
 *
 * Time complexity: O(n * u) [where n is the length of the string s and u is the number of unique letters in the string t]
 * Space complexity: O(u)
 *
 * 4. Sliding window, optimized. See this explanation --> https://leetcode.com/problems/minimum-window-substring/solution/
 *
 * Time complexity: O(n) [where n is the length of the input string s]
 * Space complexity: O(u1 + u2) [where u1 is the number of unique characters in s and u2 is the number of unique characters in t]
 *
 */

std::string minWindow(std::string s, std::string t)
{
    std::string result{};

    if(s.empty() || t.empty())
    {
        return result;
    }

    auto n=int(s.size());

    for(auto start=0;start<n;++start)
    {
        for(auto end=start;end<n;++end)
        {
            std::unordered_map<char, int> hashtable;

            for(const auto & letter : t)
            {
                hashtable[letter]++;
            }

            std::string str{};

            std::size_t count=0;

            for(auto current=start;current<=end;++current)
            {
                char letter=s[current];

                str+=letter;

                if(hashtable.count(letter))
                {
                    if(hashtable[letter] > 0)
                    {
                        hashtable[letter]--;
                    }

                    if(hashtable[letter]==0)
                    {
                        hashtable.erase(letter);
                    }
                }
            }

            if(hashtable.empty())
            {
                if(result.empty())
                {
                    result=str;
                }
                else
                {
                    if(str.length() < result.length())
                    {
                        result=str;
                    }
                }
            }
        }
    }

    return result;
}

bool allLettersFound(std::unordered_map<char, int> & hashtable)
{
    bool found=true;

    for(auto & [key, value] : hashtable)
    {
        if(value > 0)
        {
            found=false;

            break;
        }
    }

    return found;
}

std::string minWindow(std::string s, std::string t)
{
    std::string result{};

    if(s.empty() || t.empty())
    {
        return result;
    }

    if(s.size() < t.size())
    {
        return result;
    }

    if(s==t)
    {
        return s;
    }

    auto n=int(s.size());

    auto m=int(t.size());

    if(m==1)
    {
        bool found=false;

        for(auto index=0;index<n;++index)
        {
            if(s[index]==t[0])
            {
                found=true;

                break;
            }
        }

        return (found) ? t : result;
    }

    std::unordered_map<char, int> hashtable;

    for(const auto & letter : t)
    {
        hashtable[letter]++;
    }

    int back=0;

    int front=0;

    if(hashtable.count(s[back]))
    {
        hashtable[s[back]]--;
    }

    while(back <= n-1)
    {
        if(allLettersFound(hashtable))
        {
            std::string candidate{};

            for(auto index=back;index<=front;++index)
            {
                candidate+=s[index];
            }

            if(result.empty())
            {
                result=candidate;
            }
            else
            {
                if(candidate.length() < result.length())
                {
                    result=candidate;
                }
            }

            if(back < n)
            {
                if(hashtable.count(s[back]))
                {
                    hashtable[s[back]]++;
                }

                back++;
            }
        }
        else
        {
            if(hashtable.count(s[back]))
            {
                if(front==n-1)
                {
                    if(back < n)
                    {
                        hashtable[s[back]]++;

                        back++;
                    }
                }
            }
            else
            {
                if(back < n)
                {
                    back++;
                }
            }

            if(front < n-1)
            {
                front++;

                if(hashtable.count(s[front]))
                {
                    hashtable[s[front]]--;
                }
            }
        }
    }

    return result;
}

std::string minWindow(std::string s, std::string t)
{
    std::string result{};

    if(s.empty() || t.empty())
    {
        return result;
    }

    if(s.size() < t.size())
    {
        return result;
    }

    if(s==t)
    {
        return s;
    }

    auto n=int(s.size());

    auto m=int(t.size());

    if(m==1)
    {
        bool found=false;

        for(auto index=0;index<n;++index)
        {
            if(s[index]==t[0])
            {
                found=true;

                break;
            }
        }

        return (found) ? t : result;
    }

    std::pair<int, int> p(-1, -1);

    int length=-1;

    std::unordered_map<char, int> hashtable;

    for(const auto & letter : t)
    {
        hashtable[letter]++;
    }

    int back=0;

    int front=0;

    if(hashtable.count(s[back]))
    {
        hashtable[s[back]]--;
    }

    while(back <= n-1)
    {
        if(allLettersFound(hashtable))
        {
            int currentLength=(front - back) + 1;

            if(length==-1)
            {
                length=currentLength;

                p.first=back;

                p.second=front;
            }
            else
            {
                if(currentLength < length)
                {
                    length=currentLength;

                    p.first=back;

                    p.second=front;
                }
            }

            if(back < n)
            {
                if(hashtable.count(s[back]))
                {
                    hashtable[s[back]]++;
                }

                back++;
            }
        }
        else
        {
            if(hashtable.count(s[back]))
            {
                if(front==n-1)
                {
                    if(back < n)
                    {
                        hashtable[s[back]]++;

                        back++;
                    }
                }
            }
            else
            {
                if(back < n)
                {
                    back++;
                }
            }

            if(front < n-1)
            {
                front++;

                if(hashtable.count(s[front]))
                {
                    hashtable[s[front]]--;
                }
            }
        }
    }

    if(p.first > -1 && p.second > -1)
    {
        for(auto index=p.first;index<=p.second;++index)
        {
            result+=s[index];
        }
    }

    return result;
}