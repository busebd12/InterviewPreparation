#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

/*
 * Solutions:
 *
 * 1. Sort the input vector and then return the kth largest number from the end of the vector.
 *
 * Time complexity: O(n log n) [where n is the length of the input vector]
 * Space complexity: O(1)
 *
 * 2. Store all the numbers from the input in a multiset. The multiset will order them in ascending order.
 * Then, loop from the end of the multiset backwards k spots. Return that number.
 *
 * Time complexity: O((n log n) + k) [where n is the length of the input vector]
 * Space complexity: O(n)
 *
 * 3. Maintain a min heap (the samllest number is always at the top of the heap) by adding numbers to the heap
 * until the size exceeds k. Then, remove the top element from the heap. After we iterate through the entire
 * input vector, the min heap will hold the k largest elements, and the kth largest element will be at the top
 * of the min heap.
 *
 * Time complexity: O(n log(k)) [where n is the length of the input vector and k is the size of the heap]
 * Space complexity: O(log(k))
 *
 * 4. Place all the numbers from the input vector into a max heap and then pop the first k-1 numbers from the heap.
 * Finally, return the top element of the heap. This top element will be the kth largest number.
 *
 * Time complexity: O(n + log(k)) [where n is the length of the input vector]
 * Space complexity: O(n)
 *
 * 5. Use the nth_element algorithm from the STL to place the kth largest element in the spot it would normally be
 * in if the input vector was sorted in ascending order. Then, just return the kth largest element.
 *
 * Time complexity: O(n) [where n is the length of the input vector]
 * Space complexity: O(1)
 */

int findKthLargest(std::vector<int> & nums, int k)
{
    std::sort(nums.begin(), nums.end());

    return nums[nums.size() - k];
}

int findKthLargest(std::vector<int> & nums, int k)
{
    std::multiset<int> ms;

    for(const auto & number : nums)
    {
        ms.insert(number);
    }

    int kthLargest=0;

    for(auto itr=ms.rbegin();itr!=ms.rend();++itr)
    {
        if(k==0)
        {
            break;
        }

        kthLargest=*itr;

        k--;
    }

    return kthLargest;
}

int findKthLargest(std::vector<int> & nums, int k)
{
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    for(const auto & number : nums)
    {
        minHeap.emplace(number);

        if(minHeap.size() > k)
        {
            minHeap.pop();
        }
    }

    return minHeap.top();
}

int findKthLargest(std::vector<int> & nums, int k)
{
    std::priority_queue<int, std::vector<int>, std::less<int>> maxHeap(nums.begin(), nums.end());

    while(k > 1)
    {
        maxHeap.pop();

        k--;
    }

    return maxHeap.top();
}

int findKthLargest(std::vector<int> & nums, int k)
{
    std::nth_element(nums.begin(), nums.end() - k, nums.end());

    return nums[nums.size() - k];
}