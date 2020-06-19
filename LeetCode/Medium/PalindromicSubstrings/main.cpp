#include <iostream>
#include <string>

/*
 * Solutions:
 *
 * 1. Brute force. Generate all the substrings of the input string and count how many of them are palindromes.
 *
 * Time complexity: O(n^3) [where n is the length of the input string]
 * Space complexity: O(n^2)
 *
 * 2. Brute force improved. Instead of constructing each substring, we iterate over the indices representing each substring
 * and check if it is a palindrome.
 *
 * Time complexity: O(n^3)
 * Space complexity: O(1)
 *
 * 3. Brute force improved even more. Same idea as the second solution but with a different inner loop.
 *
 * Time complexity: O(n^2)
 * Space complexity: O(1)
 *
 * 4. Treat every haracter and every two characters next to each other as the center of a palindrome.
 * Expand in both directions around the center.
 *
 * Time complexity: O(n^2)
 * Space complexity: O(1)
 */

bool isPalindrome(std::string & str)
{
    int left=0;

    int right=int(str.size()-1);

    while(left < right)
    {
        if(str[left]!=str[right])
        {
            return false;
        }

        left++;

        right--;
    }

    return true;
}

int countSubstrings(std::string s)
{
    int result=0;

    if(s.empty())
    {
        return result;
    }

    int n=int(s.size());

    for(int start=0;start<n;start++)
    {
        for(int length=1;length<=n-start;length++)
        {
            std::string substring=s.substr(start, length);

            if(isPalindrome(substring))
            {
                result++;
            }
        }
    }

    return result;
}

bool isPalindrome(std::string & str, int start, int end)
{
    while(start < end)
    {
        if(str[start]!=str[end])
        {
            return false;
        }

        start++;

        end--;
    }

    return true;
}

int countSubstrings(std::string s)
{
    int result=0;

    if(s.empty())
    {
        return result;
    }

    int n=int(s.size());

    for(int start=0;start<n;start++)
    {
        for(int length=1;length<=n-start;length++)
        {
            int end=(start + length) - 1;

            if(isPalindrome(s, start, end))
            {
                result++;
            }
        }
    }

    return result;
}

bool isPalindrome(std::string & str, int start, int end)
{
    while(start < end)
    {
        if(str[start]!=str[end])
        {
            return false;
        }

        start++;

        end--;
    }

    return true;
}

int countSubstrings(std::string s)
{
    int result=0;

    if(s.empty())
    {
        return result;
    }

    int n=int(s.size());

    for(int start=0;start<n;start++)
    {
        for(int end=start;end<n;end++)
        {
            if(isPalindrome(s, start, end))
            {
                result++;
            }
        }
    }

    return result;
}

int countSubstrings(std::string s)
{
    int result=0;

    if(s.empty())
    {
        return result;
    }

    int n=int(s.size());

    for(int index=0;index<n;index++)
    {
        int left=index-1;

        int right=index+1;

        result++;

        while(right < n && s[right]==s[index])
        {
            result++;

            right++;
        }

        while(left >= 0 && right < n && s[left]==s[right])
        {
            result++;

            left--;

            right++;
        }
    }

    return result;
}