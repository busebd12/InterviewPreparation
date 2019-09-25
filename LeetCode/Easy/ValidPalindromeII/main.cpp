#include <iostream>
#include <string>
using namespace std;

/*
 * Approaches:
 *
 * 1) Brute force. For each letters in the input string, check to see if the string formed using
 * all other characters is a palindrome.
 *
 * Time complexity: O(n-squred) [where n is the length of the input string]
 * Space complexity: O(1)
 *
 * 2) Using two pointers, move from both ends of the input string towards the middle.
 * Each time we see two characters that don't match, check to see if the substring not including
 * the current, mismatched character forms a palindrome. By the time we reach the middle of the string,
 * if we haven't found any mismatched characters, then we know it's a palindrome.
 *
 * Time complexity: O(n) [where n is the length of the input string]
 * Space complexity: O(1)
 */


bool isPalindrome(const string & str)
{
    int m=int(str.size());

    int left=0;

    int right=m-1;

    while(left <= right)
    {
        if(str[left]==str[right])
        {
            left++;

            right--;
        }
        else
        {
            return false;
        }
    }

    return true;
}

bool validPalindrome(string s)
{
    if(s.empty())
    {
        return true;
    }

    int n=int(s.size());

    if(n <= 2)
    {
        return true;
    }

    for(int i=0;i<n;++i)
    {
        string copy{};

        for(int j=0;j<n;++j)
        {
            if(j!=i)
            {
                copy+=s[j];
            }
        }

        if(isPalindrome(copy))
        {
            return true;
        }
    }

    return false;
}

bool isPalindrome(const string & str, int left, int right)
{
    while(left <= right)
    {
        if(str[left]==str[right])
        {
            left++;

            right--;
        }
        else
        {
            return false;
        }
    }

    return true;
}

bool validPalindrome(string s)
{
    if(s.empty())
    {
        return true;
    }

    int n=int(s.size());

    if(n <= 2)
    {
        return true;
    }

    int left=0;

    int right=n-1;

    while(left <= right)
    {
        if(s[left]!=s[right])
        {
            return isPalindrome(s, left, right-1) || isPalindrome(s, left+1, right);
        }

        left++;

        right--;
    }

    return true;
}