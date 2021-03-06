#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <limits>
using namespace std;

/*
 * Approaches:
 *
 * 1) Generate the m by n matrix. Then, execute all the operations against the matrix, find the maximum number,
 * and count the number of times the maximum number appears. This solution received memory limit exceeded when run.
 *
 * Time complexity: O(m * n)
 * Space complexity: O(m * n)
 *
 * 2) We can use a multimap and map each (x, y) coordinate pair to the value in the matrix at that
 * (x, y) coordinate. We represent that by mapping x --> (y, value at that point in the matrix) in
 * the multimap. As execute each operation against the matrix, we check to see if the current x-coordinate, i,
 * is already in the multimap. If it is, then we have to check if the specific (i, j) coordinate pair is in the multimap.
 * If it is, then we simply increment the value at the coordinate (i, j). If j is not already in the map, then
 * we add the pair (i, j) to the map with a value of 1. If the x-coordinate, i, is not in the map at all, then we
 * add the pair (i, j) to the map with a value of 1. Then, we find the maximum element and count the number of times
 * the maximum element appears in the hashtable. This solution received time limit exceeded when run.
 *
 * Time complexity: O(number of operations * (a * b) log n)
 * Space complexity: O(number of (i, j) coordinate pairs generated by the number of operations)
 *
 *
 * 3) Here, we take advantage of the fact that as we apply each operation, we change, at minimum, the product
 * of a times b total cells in the matrix. And, since we are incrementing the value in all cells for each operation,
 * the number of times the maximum number will appear is the total number of common cells that are changed each time
 * by each operation. Taking the minimum between (m, operation[0]) and (n, operation[1]) for each operation, will
 * keep track of that total number of common cells changed each time.
 *
 * Time complexity: O(number of operations on the matrix)
 * Space complexity: O(1)
 */

int maxCount(int m, int n, vector<vector<int>>& ops)
{
    int result=0;

    if(m==0 || n==0)
    {
        return result;
    }

    if(ops.empty())
    {
        return m * n;
    }

    vector<vector<int>> matrix(m, vector<int>(n, 0));

    for(const vector<int> & operation : ops)
    {
        for(int i=0;i<operation[0];++i)
        {
            for(int j=0;j<operation[1];++j)
            {
                matrix[i][j]++;
            }
        }
    }

    int maximum=numeric_limits<int>::min();

    for(int i=0;i<m;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(matrix[i][j] >= maximum)
            {
                maximum=matrix[i][j];
            }
        }
    }

    for(int i=0;i<m;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(matrix[i][j]==maximum)
            {
                result++;
            }
        }
    }

    return result;
}

int maxCount(int m, int n, vector<vector<int>> & ops)
{
    int result=0;

    if(m==0 || n==0)
    {
        return result;
    }

    if(ops.empty())
    {
        return m * n;
    }

    multimap<int, pair<int, int>> hashtable;

    for(const vector<int> & operation : ops)
    {
        int a=operation[0];

        int b=operation[1];

        for(int i=0;i<a;++i)
        {
            for(int j=0;j<b;++j)
            {
                if(hashtable.count(i))
                {
                    bool found=false;

                    auto range=hashtable.equal_range(i);

                    for(auto itr=range.first;itr!=range.second;++itr)
                    {
                        if(itr->second.first==j)
                        {
                            found=true;

                            break;
                        }
                    }

                    if(!found)
                    {
                        pair<int, int> innerPair(j, 1);

                        hashtable.insert(make_pair(i, innerPair));
                    }
                    else
                    {
                        auto range=hashtable.equal_range(i);

                        for(auto itr=range.first;itr!=range.second;++itr)
                        {
                            if(itr->second.first==j)
                            {
                                itr->second.second++;
                            }
                        }
                    }
                }
                else
                {
                    pair<int, int> innerPair(j, 1);

                    hashtable.insert(make_pair(i, innerPair));
                }
            }
        }
    }

    int maximum=numeric_limits<int>::min();

    for(const auto & element : hashtable)
    {
        if(element.second.second >= maximum)
        {
            maximum=element.second.second;
        }
    }

    for(const auto & element : hashtable)
    {
        if(element.second.second==maximum)
        {
            result++;
        }
    }

    return result;
}

int maxCount(int m, int n, vector<vector<int>> & ops)
{
    int result=0;

    if(m==0 || n==0)
    {
        return result;
    }

    if(ops.empty())
    {
        return m * n;
    }

    for(const vector<int> & operation : ops)
    {
        m=min(m, operation[0]);

        n=min(n, operation[1]);
    }

    return m * n;
}