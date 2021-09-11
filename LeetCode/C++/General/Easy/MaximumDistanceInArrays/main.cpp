#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

/*
 * Approaches:
 *
 * 1) Brute force. For each minimum in each array, calcuate the difference with each
 * maximum not in the same array. Take the largest of those values. This solution
 * got Time Limit Exceeded when run.
 *
 * Time complexity: O(m-squared) [where m is the number of arrays]
 * Space complexity: O(1)
 *
 * 2) Similar to the first approach but store each minimum and maximum for each array as
 * pairs in a vector of pairs. Then, calcuate the largest difference.
 *
 * Time complexity: O(n-squared) [where n is the size of the vector containing all pairs of minimums and maximums]
 * Space complexity: O(p) [where p is the total number minimum and maximum pairs]
 *
 * 3) Similar to calculating the minimum and maximum value in an array. Have two variables,
 * currentMinimum and currentMaximum. These are set to the first element in the first array and
 * the last element in the first array, respectively. Then, iterate over the rest of the arrays
 * and calculate the difference accordingly.
 *
 * Time complexity: O(m)
 * Space complexity: O(1)
 */

int maxDistance(vector<vector<int>>& arrays)
{
    int result=0;

    if(arrays.empty())
    {
        return result;
    }

    int m=int(arrays.size());

    for(int i=0;i<m;++i)
    {
        int minimum=arrays[i][0];

        for(int j=0;j<m;++j)
        {
            if(j!=i)
            {
                int last=int(arrays[j].size()-1);

                int maximum=arrays[j][last];

                int dist=abs(minimum - maximum);

                result=max(result, dist);
            }
        }
    }

    return result;
}

int maxDistance(vector<vector<int>>& arrays)
{
    int result=0;

    if(arrays.empty())
    {
        return result;
    }

    vector<pair<int, int>> minMaxPairs;

    for(const auto & array : arrays)
    {
        minMaxPairs.emplace_back(make_pair(array.front(), array.back()));
    }

    int n=int(minMaxPairs.size());

    for(int i=0;i<n;++i)
    {
        int minimum=minMaxPairs[i].first;

        for(int j=0;j<n;++j)
        {
            if(j!=i)
            {
                int maximum=minMaxPairs[j].second;

                int dist=abs(minimum - maximum);

                result=max(result, dist);
            }
        }
    }

    return result;
}

int maxDistance(vector<vector<int>> & arrays)
{
    int result=0;

    if(arrays.empty())
    {
        return result;
    }

    int m=int(arrays.size());

    int currentMinimum=arrays[0].front();

    int currentMaximum=arrays[0].back();

    for(int i=1;i<m;++i)
    {
        result=max(result, max(abs(arrays[i].front() - currentMaximum), abs(arrays[i].back() - currentMinimum)));

        currentMinimum=min(currentMinimum, arrays[i].front());

        currentMaximum=max(currentMaximum, arrays[i].back());
    }

    return result;
}