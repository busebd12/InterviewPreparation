#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/*
 * Approaches:
 *
 * 1. Keep track of the frequency of each number using a hashtable (unordered_map<int, int>) and choose the largest
 * number with frequency of one.
 *
 * Time complexity: O(n) [where n is the length of the input vector]
 * Space complexity: O(n)
 *
 * 2. Similar logic as the first solution. However, since we know that the largest a number will be is 1000,
 * we can go ahead and allocate only 1001 spots in our hashtable. Also, since the amount of space needed for
 * our hashtable does not depend on the size of the input, it will be constant space used. The rest of the logic is
 * very similar.
 *
 * Time complexity: O(n) [where n is the length of the input vector]
 * Space complexity: O(1001) --> O(1)
 *
 * 3. We sort the input vector and then just keep track of the largest number that appears once.
 *
 * Time complexity: O(n log n) [where n is the length of the input vector]
 * Space complexity: O(1)
 */

int largestUniqueNumber(vector<int>& A)
{
    unordered_map<int, int> hashtable;

    for(const auto & number : A)
    {
        hashtable[number]++;
    }

    int result=-1;

    for(const auto & element : hashtable)
    {
        if(element.second==1)
        {
            if(result==-1 || element.first > result)
            {
                result=element.first;
            }
        }
    }

    return result;
}

int largestUniqueNumber(vector<int>& A)
{
    vector<int> hashtable(1001, 0);

    for(const auto & number : A)
    {
        hashtable[number]++;
    }

    int result=-1;

    for(auto i=0;i<hashtable.size();++i)
    {
        if(hashtable[i]==1)
        {
            if(result==-1 || i > result)
            {
                result=i;
            }
        }
    }

    return result;
}

int largestUniqueNumber(vector<int>& A)
{
    sort(A.begin(), A.end());

    int result=-1;

    auto n=A.size();

    for(auto i=0;i<n;)
    {
        int current=A[i];

        int count=0;

        while(i < n && A[i]==current)
        {
            count++;

            i++;
        }

        if(count==1)
        {
            if(result==-1 || current > result)
            {
                result=current;
            }
        }
    }

    return result;
}