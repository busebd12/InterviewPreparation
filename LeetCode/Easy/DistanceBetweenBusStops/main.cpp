#include <iostream>
#include <vector>
using namespace std;

/*
 * Approach: there are two cases to consider.
 *
 * The first is our starting point is greater than our destination.
 * In this case, we iterate twice over the array. The first pass starts from the starting index and iterates
 * from left-to-right, until we reach the destination index, adding values to our clockwiseTotal integer variable.
 * If the index ever becomes greater than n-1, we mod it by n. The second pass starts from our destination index
 * and iterates from left-to-right until we reach our starting index, adding values to our counterClockwiseTotal
 * variable as we go.
 *
 * The second case is our starting point is less than our destination. We also will iterate twice over the vector.
 * The first pass starts from our starting index and loops till our destination index, adding values to our
 * clockwiseTotal as we go. The second pass starts from our destination index and loops till we reach our
 * starting index, add values to our counterClockwiseTotal variable as we go. If the index ever becomes greater
 * than n-1, we mod it by n.
 *
 * In either of these cases, the result is the minimum between the clockwiseTotal and counterClockwiseTotal.
 *
 * Time complexity: O(n) [where n is the length of the input vector]
 * Space complexity: O(1)
 *
 */

int distanceBetweenBusStops(vector<int>& distance, int start, int destination)
{
    if(distance.empty())
    {
        return 0;
    }

    if(start==destination)
    {
        return distance[start];
    }

    auto n=distance.size();

    int result=0;

    int clockwiseTotal=0;

    int counterClockwiseTotal=0;

    if(start > destination)
    {
        auto i=start;

        while(true)
        {
            if(i==destination)
            {
                break;
            }

            clockwiseTotal+=distance[i];

            i++;

            if(i > n-1)
            {
                i=i % n;
            }
        }

        for(auto j=destination;j<start;++j)
        {
            counterClockwiseTotal+=distance[j];
        }

        result=min(clockwiseTotal, counterClockwiseTotal);
    }
    else
    {
        for(auto i=start;i<destination;++i)
        {
            clockwiseTotal+=distance[i];
        }

        auto j=destination;

        while(true)
        {
            if(j==start)
            {
                break;
            }

            counterClockwiseTotal+=distance[j];

            j++;

            if(j > n-1)
            {
                j=j % n;
            }
        }

        result=min(clockwiseTotal, counterClockwiseTotal);
    }

    return result;
}