#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <limits>
using namespace std;

/*
 * Approach:
 *
 * For each string in list1, map it to its index in a hashtable.
 * Then, for each string in list2 that is already in the hashtable, add it and the sum of the the indices
 * to a vector<pair<int, string>>. Then, find the minimum index sum in the vector<pair<int, string>>. Finally,
 * count the number of index sums equal to the minimum. Return that value.
 *
 * Time complexity: O(n + m) [where n is the length of list1 and m is the length of list2]
 * Space complexity: O(n + p) [where p is the number of pairs of strings that appear in both lists]
 */

vector<string> findRestaurant(vector<string> & list1, vector<string> & list2)
{
    vector<string> result;

    if(list1.empty() || list2.empty())
    {
        return result;
    }

    int n=int(list1.size());

    int m=int(list2.size());

    unordered_map<string, int> hashtable;

    for(int i=0;i<n;++i)
    {
        hashtable[list1[i]]=i;
    }

    vector<pair<int, string>> pairs;

    for(int j=0;j<m;++j)
    {
        if(hashtable.count(list2[j]))
        {
            pairs.push_back(make_pair(hashtable[list2[j]] + j, list2[j]));
        }
    }

    int minimumSum=numeric_limits<int>::max();

    for(const auto & p : pairs)
    {
        if(p.first <= minimumSum)
        {
            minimumSum=p.first;
        }
    }

    for(const auto & element : pairs)
    {
        if(element.first==minimumSum)
        {
            result.emplace_back(element.second);
        }
    }

    return result;
}