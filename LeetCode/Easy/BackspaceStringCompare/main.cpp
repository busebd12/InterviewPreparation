#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 * Approaches:
 *
 * 1) Iterating over the string S, if the current character is not a pound sign, we push it onto the stack.
 * If the character is a '#', then we have two cases. First, if the stack is not empty, then we pop from the stack.
 * If the stack is empty, we do nothing. We then form a string, s, with the characters remaining in the stack.
 * After repeating this process for the string T, we check to see if the two strings, s and t, are equal.
 *
 * Time complexity: O(n + m) [where n is the length of the string S and m is the length of the string T]
 * Space complexity: O(x + y) [where x is the number of non pound sign characers in S and y is the number of non pound sign characters in T]
 *
 *
 * 2) Two-pointers. We use two "pointers", i and j, to iterate over the strings S and T, respectively. We have the
 * following cases to consider:
 *
 * a) If the current character in S is a '#' and i is a valid index, increment the number of '#' for S.
 * b) If the current character is T is a '#' and j is a valid index, increment the number of '#' for T.
 * c) If the current character in S is a non # character, i is a valid index, and we have more than zero '#'s, decrement i (aka removing a character)
 * and the number of #'s in S
 * d) If the current character in T is a non # character, j is a valid index, and we have more than zero '#'s, decrement j and the number of #s in T
 * e) Else, if i is out-of-bounds or j is out-of-bounds or the current character in S is not equal to the current character in T, return false.
 * Otherwise, the two characters from S and T are equal and we just continue iterating through the two strings.
 *
 * Time complexity: O(n + m) [where n is the length of S and m is the length of T]
 * Space complexity: O(1)
 */

bool backspaceCompare(string S, string T)
{
    vector<char> stk;

    for(const char & c : S)
    {
        if(isalpha(c))
        {
            stk.push_back(c);
        }

        if(c=='#')
        {
            if(!stk.empty())
            {
                stk.pop_back();
            }
        }
    }

    string s(stk.begin(), stk.end());

    stk.clear();

    for(const char & c : T)
    {
        if(isalpha(c))
        {
            stk.push_back(c);
        }

        if(c=='#')
        {
            if(!stk.empty())
            {
                stk.pop_back();
            }
        }
    }

    string t(stk.begin(), stk.end());

    return s==t;
}


bool backspaceCompare(string S, string T)
{
    int n=int(S.size());

    int m=int(T.size());

    int i=n-1;

    int j=m-1;

    int sBackspaces=0;

    int tBackspaces=0;

    while(i >= 0 || j >= 0)
    {
        if(i >= 0 && S[i]=='#')
        {
            sBackspaces++;

            i--;
        }
        else if(j >= 0 && T[j]=='#')
        {
            tBackspaces++;

            j--;
        }
        else if(i >= 0 && isalpha(S[i]) && sBackspaces > 0)
        {
            i--;

            sBackspaces--;
        }
        else if(j >= 0 && isalpha(T[j]) && tBackspaces > 0)
        {
            j--;

            tBackspaces--;
        }
        else
        {
            if(i < 0 || j < 0 || S[i]!=T[j])
            {
                return false;
            }

            i--;

            j--;
        }
    }

    return true;
}