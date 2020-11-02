#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <unordered_set>
#include <vector>

/*
 * Solutions:
 *
 * 1. Slinding-window, brute force. We maintain a vector of size X that contain the X indices of our sliding window.
 * Then, we calculate the number of customers satisfied, taking into account our sliding window. If the number of
 * customers is more than the current maximum, we update our result. After this, we increment all the indicies in our
 * sliding window by one and repeat the process.
 *
 * Time complexity: O(n * n-X) [where n is the length of the customers and grumpy vector]
 * Space complexity: O(X)
 *
 * 2. A more efficient sliding window approach. Here, as we moving our sliding window through the input vector, we keep
 * track of three sums: leftSum (for the left third of the vector), slidingWindowSum, and rightSum (for the right third
 * of the array). As the sliding window moves through the input vector, the total number of satisfied customers will be
 * calculated as leftSum + slidingWindowSum + rightSum.
 *
 * Time complexity: O(n) [where n is the length of the customers and grumpy vector]
 * Space complexity: O(1)
 */

int maxSatisfied(std::vector<int> & customers, std::vector<int> & grumpy, int X)
{
    int result=std::numeric_limits<int>::min();

    if(customers.empty())
    {
        return result;
    }

    int n=int(customers.size());

    std::vector<int> slidingWindow(X);

    for(auto index=0;index<X;++index)
    {
        slidingWindow[index]=index;
    }

    while(slidingWindow[X-1] < n)
    {
        std::unordered_set<int> cache(slidingWindow.begin(), slidingWindow.end());

        int current=0;

        for(auto index=0;index<n;++index)
        {
            if(cache.count(index))
            {
                current+=customers[index];
            }
            else
            {
                if(!grumpy[index])
                {
                    current+=customers[index];
                }
            }
        }

        result=std::max(result, current);

        std::for_each(slidingWindow.begin(), slidingWindow.end(), [] (int & index) {index+=1;});
    }

    return result;
}

int maxSatisfied(std::vector<int> & customers, std::vector<int> & grumpy, int X)
{
    int result=0;

    if(customers.empty())
    {
        return result;
    }

    int n=int(customers.size());

    int leftSum=0;

    int slidingWindowSum=0;

    int rightSum=0;

    for(auto index=0;index<X;++index)
    {
        slidingWindowSum+=customers[index];
    }

    for(auto index=X;index<n;++index)
    {
        if(!grumpy[index])
        {
            rightSum+=customers[index];
        }
    }

    result+=(leftSum + slidingWindowSum + rightSum);

    int left=0;

    int right=X-1;

    while(right < n)
    {
        if(right + 1 < n)
        {
            right++;

            slidingWindowSum+=customers[right];

            slidingWindowSum-=customers[left];

            if(!grumpy[left])
            {
                leftSum+=customers[left];
            }

            left++;

            if(!grumpy[right])
            {
                rightSum-=customers[right];
            }

            result=std::max(result, (leftSum + slidingWindowSum + rightSum));
        }
        else
        {
            break;
        }
    }

    return result;
}