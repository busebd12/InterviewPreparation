#include <cmath>
#include <iostream>
#include <unordered_set>
#include <vector>

/*
 * Solutions:
 *
 * 1. For each interval in A, we iterate through each interval in B and if two intervals overlap, we fill
 * an std::unordered_set<int> with all the numbers in the A interval. Next, we loop through all the numbers
 * in the B interval and the first number that is already in the unordered_set<int> is the start of the intersection
 * of the two intervals, and the last number that is already in the unordered_set<int> is the ending of the intersection
 * of the two intervals. We then put the start and enfd of the intersection into a vector and put the intersection vector
 * into the result vector of vectors.
 *
 * Time complexity: O(n * (m + d1 + d2)) [where n is the length of A, m is the length of B, d1 is the average number
 * of numbers in each interval in A and d2 is the average number of numbers in each interval in B)
 *
 * Space complexity: O(T) [where T is the total number of integers specified by all the intervals in A] if you don't count the space needed for the output
 * Space complexity: O(T + I) [where T is the total number of integers specified by all the intervals in A and I is the
 * total number of resulting intersections]
 *
 *
 * 2. If we look at when two intervals intersect more closely, then we see that two intervals can only intersect if
 * the minimum of the starts of the two intervals is less than or equal to the maximum of the endings of the two intervals.
 * With this in mind, for each interval in A, we loop through each interval in B and if the interval from A intersects
 * with the interval in B, then the intersection of the two intervals will be the minimum between the start of interval
 * A and the start of interval B and the maximum between the ending of interval A and the ending of interval B.
 *
 * Time complexity: O(n * m) [where n is the length of A and m is the length of B]
 * Space complexity: O(1) [if you do not count the total number of resulting intersections]
 * Space complexity: O(I) [where I is the total number of resulting intersections]
 *
 *
 * 3. Another way of looking at this questions is that the process of determining the intersections closely resembles
 * the merge portion of merge sort. With this in mind, we use the "two-pointer" method and iterate through A and B
 * simultaneously and if the interval from A intersects with the interval from B, we determine the intersection using
 * the same logic from the second solution. Like the merge operation within merge sort, we have to figure out which
 * "pointer" to increment, i or j. If the ending of the A interval is less than the ending of the B interval, then
 * there is still the change that the next interval in A, after the current one, can fit into the current B interval
 * as well, so increment i. Else, increment j.
 *
 * Time complexity: O(n + m) [where n is the length of A and m is the length of B]
 * Space complexity: O(1) --> if you don't count the space needed for the resulting intersections
 * Space complexity: O(I) [where I is the total number of resulting intersections]
 */

std::vector<std::vector<int>> intervalIntersection(std::vector<std::vector<int>> & A, std::vector<std::vector<int>> & B)
{
    std::vector<std::vector<int>> result;

    if(A.empty() || B.empty())
    {
        return result;
    }

    for(auto & aInterval : A)
    {
        auto aStart=aInterval[0];

        auto aEnd=aInterval[1];

        for(auto & bInterval : B)
        {
            auto bStart=bInterval[0];

            auto bEnd=bInterval[1];

            bool aFitsIntoB=(bStart <= aStart && aStart <= bEnd) || (bStart <= aEnd && aEnd<= bEnd);

            bool bFitsIntoA=(aStart <= bStart && bStart <= aEnd) || (aStart <= bEnd && bEnd <= aEnd);

            if(aFitsIntoB || bFitsIntoA)
            {
                std::unordered_set<int> cache;

                std::vector<int> intersection(2, 0);

                for(auto number=aStart;number<=aEnd;++number)
                {
                    cache.insert(number);
                }

                bool foundStartOfIntersection=false;

                for(auto number=bStart;number<=bEnd;++number)
                {
                    if(cache.count(number))
                    {
                        if(!foundStartOfIntersection)
                        {
                            foundStartOfIntersection=true;

                            intersection[0]=number;
                        }

                        intersection[1]=number;
                    }
                }

                result.emplace_back(intersection);
            }
        }
    }

    return result;
}

bool hasIntersection(std::vector<int> & range1, std::vector<int> & range2)
{
    return std::max(range1[0], range2[0]) <= std::min(range1[1], range2[1]);
}

std::vector<int> getIntersection(std::vector<int> & range1, std::vector<int> & range2)
{
    return std::vector<int>{std::max(range1[0], range2[0]), std::min(range1[1], range2[1])};
}

std::vector<std::vector<int>> intervalIntersection(std::vector<std::vector<int>> & A, std::vector<std::vector<int>> & B)
{
    std::vector<std::vector<int>> result;

    if(A.empty() || B.empty())
    {
        return result;
    }

    for(auto & aInterval : A)
    {
        for(auto & bInterval : B)
        {
            if(hasIntersection(aInterval, bInterval))
            {
                result.emplace_back(getIntersection(aInterval, bInterval));
            }
        }
    }

    return result;
}


bool hasIntersection(std::vector<int> & range1, std::vector<int> & range2)
{
    return std::max(range1[0], range2[0]) <= std::min(range1[1], range2[1]);
}

std::vector<int> getIntersection(std::vector<int> & range1, std::vector<int> & range2)
{
    return std::vector<int>{std::max(range1[0], range2[0]), std::min(range1[1], range2[1])};
}

std::vector<std::vector<int>> intervalIntersection(std::vector<std::vector<int>> & A, std::vector<std::vector<int>> & B)
{
    std::vector<std::vector<int>> result;

    if(A.empty() || B.empty())
    {
        return result;
    }

    auto aSize=A.size();

    auto bSize=B.size();

    for(auto i=0,j=0;i<aSize&&j<bSize;)
    {
        if(hasIntersection(A[i], B[j]))
        {
            result.emplace_back(getIntersection(A[i], B[j]));
        }

        if(A[i][1] < B[j][1])
        {
            ++i;
        }
        else
        {
            ++j;
        }
    }

    return result;
}