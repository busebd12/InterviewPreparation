#include <cmath>
#include <iostream>
#include <string>

/*
 * Solutions:
 *
 * 1. Generate all substrings of the input string and check for the one that is the longest palindrome.
 *
 * Time complexity: O(n-cubed)
 * Space complexity: O(n-cubed)
 *
 * 2. We pick each letter in the string as the center of a potential palindrome and expand to the left and right
 * of the center letter until the substring is no longer a palindrome to cover the odd length palindromes.
 * To handle the even length palindromes, we choose each letter and the letter to the right of it as our center
 * and expand in the same manner.
 *
 * Time complexity: O(n-squared)
 * Space complexity: O(n-squared)
 *
 * 3. Same idea as the second solution, but we only keep track of the maximum substring length instead of constructing
 * each substring every time. At the end, we construct the answer substring based on the starting position and maximum length.
 *
 * Time complexity: O(n-squared)
 * Space complexity: O(1)
 */


bool isPalindrome(std::string s)
{
    auto left=0;

    auto right=s.size()-1;

    while(left < right)
    {
        if(s[left]!=s[right])
        {
            return false;
        }

        left++;

        right--;
    }

    return true;
}

std:: string longestPalindrome(std:: string s)
{
    std::string result{};

    if(s.empty())
    {
        return result;
    }

    auto n=s.size();

    for(auto length=1;length<=n;++length)
    {
        for(auto start=0;start+length<=n;++start)
        {
            if(isPalindrome(s.substr(start, length)))
            {
                std::string substring=s.substr(start, length);

                if(substring.size() > result.size())
                {
                    result=substring;
                }
            }
        }
    }

    return result;
}

void expand(const std::string & s, int left, int right, const int & n, std::string & result)
{
    while((left >= 0 && right < n) && (s[left]==s[right]))
    {
        if(s.substr(left, (right - left) + 1).size() > result.size())
        {
            result=s.substr(left, (right - left) + 1);
        }

        left--;

        right++;
    }
}

std::string longestPalindrome(std::string s)
{
    const int n=int(s.size());

    std::string result{};

    for(int i=0;i<n;++i)
    {
        expand(s, i, i, n, result);

        expand(s, i, i+1, n, result);
    }

    return result;
}

void expand(const std::string & s, int left, int right, const int & n, int & start, int & maxLength)
{
    while((left >= 0 && right < n) && (s[left]==s[right]))
    {
        left--;

        right++;
    }

    int length=(right - left) - 1;

    if(length > maxLength)
    {
        maxLength=length;

        start=left + 1;
    }
}

std::string longestPalindrome(std::string s)
{
    const int n=int(s.size());

    std::string result{};

    int maxLength=0;

    int start=0;

    for(int i=0;i<n;++i)
    {
        expand(s, i, i, n, start, maxLength);

        expand(s, i, i+1, n, start, maxLength);
    }

    return s.substr(start, maxLength);
}