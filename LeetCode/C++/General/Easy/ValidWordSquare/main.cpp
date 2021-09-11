#include <iostream>
#include <vector>
#include <string>
#include <deque>
using namespace std;

/*
 * Approaches:
 *
 * 1) Store each row in a deque and then for each element in the column check to see if it matches
 * the corresponding element in the row. The edge cases to watch out for are if the column size does
 * not match the row size or if the number of rows and columns are not the same.
 *
 * Time complexity: O(n * (n + m)) [where n is the number of rows in the vector and m is the number of columns]
 * Space complexity: O(n)
 *
 * 2) Same logic just without extra space and more efficient
 *
 * Time complexity: O(n * m) [where n is the number of rows and m is the number of columns]
 * Space complexity: O(1)
 */

bool validWordSquare(vector<string>& words)
{
    if(words.empty())
    {
        return true;
    }

    if(words.size()==1)
    {
        return true;
    }

    int n=int(words.size());

    if(n > words[0].size())
    {
        return false;
    }

    for(int i=0;i<n;++i)
    {
        deque<char> dq;

        for(int j=0;j<words[i].size();++j)
        {
            dq.push_back(words[i][j]);
        }

        for(int k=0;k<words[i].size();++k)
        {
            if(k >= n || k >= words[i].size())
            {
                break;
            }

            if(words[k][i]!=dq.front())
            {
                return false;
            }
            else
            {
                dq.pop_front();
            }
        }

        if(!dq.empty())
        {
            return false;
        }
    }

    return true;
}

bool validWordSquare(vector<string> & words)
{
    for(int i=0;i<words.size();i++)
    {
        for(int j=0;j<words[i].size();j++)
        {
            if(words.size() <= j || words[j].size() <= i)
            {
                return false;
            }

            if(words[i][j]!=words[j][i])
            {
                return false;
            }
        }
    }

    return true;
}