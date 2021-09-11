#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

/*
 * Solutions:
 *
 * 1. The algorithm works as follows:
 *
 *  a. Compute the sum for all sub-arrays of size k and map each start index of the sub-array to the sum in a hashtable
 *  (std::unordered_map<int, int>)
 *
 *
 *  b. Then, we use recursion + backtracking to generate all combinations/permutations of 3 indices, representing
 * the starting indices for the three non-overlapping sub arrays. Each time we have generated a group of three indices,
 * we validate to make sure that these indices, do in fact, describe three non-overlapping sub arrays. If this is the case,
 * then these indices are added to a overarching set of indices. By adding them to a set, we can take advantage of its
 * uniqueness and sorted properties to make sure that the set of indices has only unique triplets and that they are sorted
 * in lexicographical order.
 *
 * c. After we have generated all the necessary index triplets, we can iterate through them and
 * determine which one gives us the maximum sum.
 *
 * Time complexity: O((n * k) + O(2^n * (u * log(3)) + O(u * 3) [where n is the length of the input vector, k is the length
 * of the target sub-array, and u is the number of unique index triplets]
 *
 * Space complexity: O(m + u) [where m is the number of starting indices for all of the size k sub-arrays and u is the number
 * of unique index triplets]
 *
 * Note: this solution receives TLE (Time Limit Exceeded) when submitted.
 *
 *
 * 2. This solution was inspired by this post --> https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/discuss/654175/Calculate-Possible-Sum-at-every-Index
 * The algorithm works as follows:
 *
 *  a. We first compute the sums of all size k sub-arrays using a sliding window and store each sum tied to its starting
 *  index in a std::vector<int> sums.
 *
 *  b. Then, we use another std::vector<int>, leftBest, to hold, for each sum, sums[i], the index of the maximum element
 *  to the left of s[i] from the sums vector.
 *
 *  c. Next, we use another std::vector<int>, rightBest, to hold, for each sum, sums[i], the index of the maximum element
 *  to the right of s[i] from the sums vector.
 *
 *  These leftBest and rightBest vectors will show the best left and right indices from the left and right sub-arrays
 *  we want to find.
 *
 *  d. Now, we traverse the sums vector from index k to index s-k, treating each index as the index of the middle
 *  sub-array we are looking for. Based on this middle index, m, the left sub-array start index will be leftBest[m - k]
 *  and the right sub-array start index will be rightBest[m + k]. For each middle index, m, we calculate the sum of
 *  the three sub-arrays these three indices represent the start of and determine the maximum sum. Along the way,
 *  we update the three indices accordingly.
 *
 *  Time complexity: O(n + s) [where n is the length of the input vector and s is the length of the sums, leftBest, and rightBest vectors]
 *  Space complexity: O(s)
 */

class Solution
{
    public:
        bool isValid(std::set<int> & indices, int k)
        {
            std::vector<int> v(indices.begin(), indices.end());

            for(auto i=0;i<v.size()-1;i++)
            {
                if(v[i+1] - v[i] < k)
                {
                    return false;
                }
            }

            return true;
        }

        void backtracking(std::vector<int> & validIndices, std::set<std::set<int>> & indices, std::set<int> subarrayIndices, int k, int m, int start)
        {
            if(subarrayIndices.size()==m)
            {
                if(isValid(subarrayIndices, k))
                {
                    indices.insert(subarrayIndices);
                }
            }

            for(int index=start;index<int(validIndices.size());index++)
            {
                subarrayIndices.insert(validIndices[index]);

                backtracking(validIndices, indices, subarrayIndices, k, m, index + 1);

                subarrayIndices.erase(validIndices[index]);
            }
        }

        std::vector<int> maxSumOfThreeSubarrays(std::vector<int> & nums, int k)
        {
            std::vector<int> result;

            if(nums.empty() || k <= 0)
            {
                return result;
            }

            int n=int(nums.size());

            int m=3;

            std::unordered_map<int, int> hashtable;

            std::vector<int> validIndices;

            for(int i=0;i<n;i++)
            {
                int sum=0;

                int count=0;

                for(int j=i;j<(i + k)&&j<n;j++)
                {
                    sum+=nums[j];

                    count++;
                }

                if(count==k)
                {
                    hashtable[i]=sum;

                    validIndices.emplace_back(i);
                }
            }

            if(hashtable.size() < m)
            {
                return result;
            }

            std::set<std::set<int>> indices;

            std::set<int> subarrayIndices;

            int start=0;

            backtracking(validIndices, indices, subarrayIndices, k, m, start);

            int maxTotal=0;

            for(const auto & element : indices)
            {
                int total=0;

                for(const auto & index : element)
                {
                    total+=hashtable[index];
                }

                if(total > maxTotal)
                {
                    maxTotal=total;

                    if(!result.empty())
                    {
                        result.clear();
                    }

                    for(const auto & index : element)
                    {
                        result.emplace_back(index);
                    }
                }
            }

            return result;
        }
};


class Solution
{
    public:
        std::vector<int> maxSumOfThreeSubarrays(std::vector<int> & nums, int k)
        {
            std::vector<int> result;

            if(nums.empty() || k <= 0)
            {
                return result;
            }

            int n=int(nums.size());

            std::vector<int> sums(n - k + 1, 0);

            int x=0;

            int sum=0;

            for(;i<k;i++)
            {
                sum+=nums[i];
            }

            sums[0]=sum;

            for(;x<n;x++)
            {
                sum+=nums[x];

                sum-=nums[x - k];

                sums[x - k + 1]=sum;
            }

            int s=int(sums.size());

            std::vector<int> leftBest(s, 0);

            int bestIndex=0;

            int maxSum=sums[0];

            for(int i=0;i<s;i++)
            {
                if(sums[i] > maxSum)
                {
                    bestIndex=i;

                    maxSum=sums[i];
                }

                leftBest[i]=bestIndex;
            }

            std::vector<int> rightBest(s, 0);

            bestIndex=s-1;

            maxSum=sums[s-1];

            for(int i=s-1;i>=0;i--)
            {
                if(sums[i] >= maxSum)
                {
                    bestIndex=i;

                    maxSum=sums[i];
                }

                rightBest[i]=bestIndex;
            }

            int m=k;

            result.resize(3);

            int subarraySum=sums[leftBest[m - k]] + sums[m] + sums[rightBest[m + k]];

            result[0]=leftBest[m - k];

            result[1]=m;

            result[2]=rightBest[m + k];

            for(;m<s-k;m++)
            {
                int currentSum=sums[leftBest[m - k]] + sums[m] + sums[rightBest[m + k]];

                if(currentSum > subarraySum)
                {
                    result[0]=leftBest[m - k];

                    result[1]=m;

                    result[2]=rightBest[m + k];

                    subarraySum=currentSum;
                }
            }

            return result;
        }
};



