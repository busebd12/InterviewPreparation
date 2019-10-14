#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/*
 * Approaches:
 *
 * 1) Brute force. Loop over A and B in a nested format and for each number in A,
 * search for an index (there could be duplicate numbers) where that number appears
 * in B. Assign that index to our result vector.
 *
 * Time complexity: O(n-squared) [where n is the size of A and B]
 * Space complexity: O(1)
 *
 * 2) Use a hashtable. For each number in B, store all the indices at which is appears in a vector.
 * Then, for each number in A, retrieve its index in B from the back of the vector of indices associated
 * with the number from A.
 *
 * Time complexity: O(n) [where n is the size of A and B]
 * Space complexity: O(n)
 */

vector<int> anagramMappings(vector<int>& A, vector<int>& B)
{
    if(A.empty() || B.empty())
    {
        return {};
    }

    size_t n=A.size();

    vector<int> result(n, 0);

    for(size_t i=0;i<n;++i)
    {
        int target=A[i];

        for(size_t j=0;j<n;++j)
        {
            if(B[j]==target)
            {
                result[i]=j;
            }
        }
    }

    return result;
}

vector<int> anagramMappings(vector<int> & A, vector<int> & B)
{
    if(A.empty() || B.empty())
    {
        return {};
    }

    size_t n=A.size();

    vector<int> result(n, 0);

    unordered_map<int, vector<int>> hashtable;

    for(size_t i=0;i<n;++i)
    {
        hashtable[B[i]].push_back(i);
    }

    for(size_t j=0;j<n;++j)
    {
        result[j]=hashtable[A[j]].back();

        hashtable[A[j]].pop_back();
    }

    return result;
}