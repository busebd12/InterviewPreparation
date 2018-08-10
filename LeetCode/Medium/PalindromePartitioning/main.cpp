#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isPalindrome(string str, int low, int high)
{
    while(low < high)
    {
        if(str[low]!=str[high])
        {
            return false;
        }

        low++;

        high--;
    }

    return true;
}

void helper(vector<vector<string>> & partitions, vector<string> & currentPartition, string str, int start, int n)
{
    if(start>=n)
    {
        partitions.emplace_back(currentPartition);

        return;
    }

    for(int i=start;i<n;++i)
    {
        if(isPalindrome(str, start, i))
        {
            currentPartition.emplace_back(str.substr(start, i-start+1));

            helper(partitions, currentPartition, str, i+1, n);

            currentPartition.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    vector<vector<string>> partitions;

    if(s.empty())
    {
        return partitions;
    }

    vector<string> currentPartition;

    int n=int(s.size());

    helper(partitions, currentPartition, s, 0, n);

    for(const auto & partition : partitions)
    {
        for(const auto & element : partition)
        {
            cout << element << " ";
        }

        cout << endl;
    }

    return partitions;
}