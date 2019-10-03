#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

/*
 * Approaches:
 *
 * 1) Brute force. Map each element in the array to its frequency using a hashtable (unordered_map<int, int>).
 * Then, find all the elements with the maximum frequency from the hashtable and insert them into another hashtable.
 * Finally, loop over the array with two nested loops to cover all subarrays. While iterating over each subarray,
 * if the current element is a maximum frequency element, decrement its frequency in the hashtable. If the frequency
 * falls to zero, then we know we have a subarray with the same degree as the original array. The smallest subarray
 * size is our answer.
 *
 * Time complexity: O(n-squared) [where n is the size of the input vector]
 * Space complexity: O(n + m) [where n is the size of the input vector and m is the number of maximum frequency elements]
 *
 *
 * 2) For each element in our input vector, map each it to a vector<int>, where the first element is the number's frequency,
 * the second element is the index of its first occurrence, and the third element is the index of its last occurrence
 * in the input vector. Then, for each maximum frequency number, compare the distance between its last occurrence index
 * and its first occurrence index, plus one (arrays/vectors are zero based) and the smallest distance is our answer.
 *
 * Time complexity: O(n) [where n is the size of the input vector]
 * Space complexity: O(n)
 */

int findShortestSubArray(vector<int>& nums)
{
    if(nums.empty())
    {
        return 0;
    }

    int n=int(nums.size());

    unordered_map<int, int> hashtable;

    unordered_map<int, int> mostFrequentElements;

    for(const int & number : nums)
    {
        hashtable[number]++;
    }

    auto degree=max_element(hashtable.begin(), hashtable.end(), [] (auto & x1, auto & x2) {return x1.second < x2.second;});

    int frequency=degree->second;

    for(const auto & element : hashtable)
    {
        if(element.second==frequency)
        {
            mostFrequentElements[element.first]=element.second;
        }
    }

    int result=-1;

    for(int i=0;i<n;++i)
    {
        int length=0;

        bool done=false;

        for(int j=i;j<n;++j)
        {
            if(mostFrequentElements.count(nums[j]))
            {
                if(mostFrequentElements[nums[j]] > 0)
                {
                    mostFrequentElements[nums[j]]--;
                }
            }

            length++;

            if(mostFrequentElements.count(nums[j]))
            {
                if(mostFrequentElements[nums[j]]==0)
                {
                    done=true;

                    break;
                }
            }
        }

        if(done)
        {
            if(result==-1)
            {
                result=length;
            }
            else
            {
                result=min(result, length);
            }
        }

        for(auto & element : mostFrequentElements)
        {
            if(element.second < frequency)
            {
                element.second=frequency;
            }
        }
    }

    return result;
}

int findShortestSubArray(vector<int> & nums)
{
    if(nums.empty())
    {
        return 0;
    }

    int n=int(nums.size());

    unordered_map<int, vector<int>> hashtable;

    int maxFrequency=0;

    for(int i=0;i<n;++i)
    {
        if(!hashtable.count(nums[i]))
        {
            hashtable[nums[i]]={1, i, i};
        }
        else
        {
            hashtable[nums[i]][0]++;

            hashtable[nums[i]][2]=i;
        }

        maxFrequency=max(maxFrequency, hashtable[nums[i]][0]);
    }

    int result=n;

    for(auto & element : hashtable)
    {
        if(element.second[0]==maxFrequency)
        {
            int currentDistance=(element.second[2] - element.second[1]) + 1;

            if(currentDistance < result)
            {
                result=currentDistance;
            }
        }
    }

    return result;
}