#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
using namespace std;

/*
 * Approaches:
 *
 * 1) Generate all possible pairs (i, j). If a pair has absolute value difference of k, then increment result.
 * We use a hashtable (unordered_map<int, unordered_set<int>>) to make sure that the pairs are unique.
 * This solution got Time Limit Exceeded (TLE)
 *
 * Time complexity: O(n-squared) [where n is the length of nums]
 * Space complexity: O(number of unique pairs in nums)
 *
 * 2) Sort the nums vector. Then, we calculate the absolute difference of the pairs in a similar manner as the
 * preivous solution. Again, we use a hashtable (unordered_map<int, unordered_set<int>>) to make sure that the pairs are unique.
 *
 * Time complexity: O(n-squared) [where n is the length of the nums vector]
 * Space complexity: O(number of unique pairs)
 *
 * 3) We map each number to the number of times it appears in the input vector using a hashtable (unordered_map<int, int>).
 * Then, loop over the hashtable and for each element, check the following: if k is zero and the current number
 * appears more than once, then we know we can subtract the two numbers to get zero, so increment our result.
 * Or, if k is greater than zero and the sum of the current number plus k appears in the map, then we know there
 * are two numbers, the current one and the one we subtract with to get k, in the map. So, increment our result.
 *
 * Time complexity: O(n) [where n is the number of elements in our input vector]
 * Space complexity: O(n)
 */

int findPairs(vector<int> & nums, int k)
{
    if(nums.empty())
    {
        return 0;
    }

    int result=0;

    unordered_map<int, unordered_set<int>> hashtable;

    int n=int(nums.size());

    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(j!=i)
            {
                int first=nums[i];

                int second=nums[j];

                int difference=abs(first - second);

                if(difference==k)
                {
                    if(hashtable.count(first) && hashtable.count(second))
                    {
                        if(!hashtable[first].count(second) && !hashtable[second].count(first))
                        {
                            hashtable[first].insert(second);

                            hashtable[second].insert(first);

                            result++;
                        }
                    }
                    else
                    {
                        hashtable[first].insert(second);

                        hashtable[second].insert(first);

                        result++;
                    }
                }
            }
        }
    }

    return result;
}

int findPairs(vector<int> & nums, int k)
{
    if(nums.empty())
    {
        return 0;
    }

    int result=0;

    int n=int(nums.size());

    sort(nums.begin(), nums.end());

    unordered_map<int, unordered_set<int>> hashtable;

    for(int i=0;i<n;++i)
    {
        if(i > 0)
        {
            if(nums[i]!=nums[i-1])
            {
                for(int j=i+1;j<n;++j)
                {
                    int difference=abs(nums[i] - nums[j]);

                    if(difference==k)
                    {
                        if(!hashtable.count(nums[i]) || !hashtable[nums[i]].count(nums[j]))
                        {
                            hashtable[nums[i]].insert(nums[j]);

                            result++;
                        }
                    }
                }
            }
        }
        else
        {
            for(int j=i+1;j<n;++j)
            {
                int difference=abs(nums[i] - nums[j]);

                if(difference==k)
                {
                    if(!hashtable.count(nums[i]) || !hashtable[nums[i]].count(nums[j]))
                    {
                        hashtable[nums[i]].insert(nums[j]);

                        result++;
                    }
                }
            }
        }
    }

    return result;
}

int findPairs(vector<int> & nums, int k)
{
    if(nums.empty())
    {
        return 0;
    }

    int result=0;

    unordered_map<int, int> hashtable;

    for(const int & number : nums)
    {
        hashtable[number]++;
    }

    for(const auto & element : hashtable)
    {
        int sum=element.first + k;

        if((k==0 && element.second > 1) || (k > 0 && hashtable.count(sum)))
        {
            result++;
        }
    }

    return result;
}