#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

/*
 * Approach: Similar to checking if a string is a palindrome.
 * Starting from both ends of the string, move to the left and to the right,
 * checking, at each point, if both numbers appear in our hash table of
 * strobogrammatic digits and if a digits strobogrammatic equivalent is in the hash table.
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

bool isStrobogrammatic(string num)
{
    if(num.empty())
    {
        return true;
    }

    if(num.size()==1)
    {
        return (num[0]=='0' || num[0]=='1' || num[0]=='8');
    }

    unordered_map<char, char> strobogrammaticDigits;

    strobogrammaticDigits.insert(make_pair('0', '0'));

    strobogrammaticDigits.insert(make_pair('1', '1'));

    strobogrammaticDigits.insert(make_pair('6', '9'));

    strobogrammaticDigits.insert(make_pair('8', '8'));

    strobogrammaticDigits.insert(make_pair('9', '6'));

    int n=int(num.size());

    int left=0;

    int right=n-1;

    while(left <= right)
    {
        if(!strobogrammaticDigits.count(num[left]) || !strobogrammaticDigits.count(num[right]))
        {
            return false;
        }

        if(strobogrammaticDigits[num[left]]!=num[right])
        {
            return false;
        }

        left++;

        right--;
    }

    return true;
}