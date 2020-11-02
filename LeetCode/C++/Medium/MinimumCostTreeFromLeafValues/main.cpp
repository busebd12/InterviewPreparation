#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

/*
 * Solution: inspired from this answer --> https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/discuss/478708/RZ-Summary-of-all-the-solutions-I-have-learned-from-Discuss-in-Python
 * The idea is that each time we compute the value of the parent node, we want the value to be larger than the previous parent node,
 * but only by the smallest amount possible. How do we do this? Well, since each non-left node is formed by multiplying two leaf nodes:
 * the largest in the left subtree and the largest in the right subtree, we want the product of the two leaf nodes that
 * will form the current parent node value to be larger than the product of the two prior left nodes, but only by the smallest
 * possible amount. Therefore, the algorithm is as follows:
 *
 * while the input vector size is greater than one:
 *
 * 1. find the minimum number in the vector
 * 2. find the next smallest neighbouring number, either to the left or to the right of the current number
 * 3. the product of these two numbers will be the value of the parent node
 * 4. add the value of the parent node to our result sum
 * 5. delete the minimum number from the vector
 *
 * Time complexity: O(n^2)
 * Space complexity: O(1)
 */

int mctFromLeafValues(std::vector<int> & arr)
{
    int result=0;

    if(arr.empty())
    {
        return result;
    }

    while(arr.size() > 1)
    {
        auto minItr=std::min_element(arr.begin(), arr.end());

        int minIndex=minItr - arr.begin();

        int secondNode=0;

        if(minIndex==0)
        {
            secondNode=arr[minIndex+1];
        }
        else if(minIndex==arr.size()-1)
        {
            secondNode=arr[minIndex-1];
        }
        else
        {
            secondNode=std::min(arr[minIndex+1], arr[minIndex-1]);
        }

        int parentNode=((*minItr) * secondNode);

        result+=parentNode;

        arr.erase(minItr);
    }

    return result;
}