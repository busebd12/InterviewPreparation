#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

/*
 * Approach: we first calculate the total sum of the vector. Then, we divide that sum by three to give us the target
 * sum for each of the three parts of the vector. Next, we try to find the first partition of the vector. If we can't
 * find it, then we return false. Then, we try to find the second partition of the vector. If we can't find it, then
 * we return false. Finally, we try to find the third partition of the array. If we can't find it, return false.
 * Else, we return true.
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

bool canThreePartsEqualSum(vector<int>& A)
{
    if(A.empty())
    {
        return true;
    }

    int n=int(A.size());

    int total=accumulate(A.begin(), A.end(), 0);

    int targetSum=total/3;

    int i=0;

    int firstSum=0;

    while(i < n)
    {
        if(firstSum==targetSum)
        {
            break;
        }

        firstSum+=A[i];

        i++;
    }

    if(i==n-1 && firstSum!=targetSum)
    {
        return false;
    }

    int secondSum=0;

    while(i < n)
    {
        if(secondSum==targetSum)
        {
            break;
        }

        secondSum+=A[i];

        i++;
    }

    if(i==n-1 && secondSum!=targetSum)
    {
        return false;
    }

    int thirdSum=0;

    while(i < n)
    {
        if(thirdSum==targetSum)
        {
            break;
        }

        thirdSum+=A[i];

        i++;
    }

    return thirdSum==targetSum;
}