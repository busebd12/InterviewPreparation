#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

/*
Solution: based on these resources

1) https://www.youtube.com/watch?v=uFSp4Y5Gsio
2) https://leetcode.com/problems/longest-increasing-subsequence-ii/solutions/2560010/c-segment-tree-with-illustration-explanation/

Time complexity: O(n * log(n)) [where n=length of nums]
Space complexity: O(n)
*/

class MaximumSegmentTree
{
    private:
        vector<int> tree;

        int maxAmountOfNumbers;

    public:
        MaximumSegmentTree(int amountOfNumbers)
        {
            maxAmountOfNumbers=amountOfNumbers;

            int treeHeight=(int)(ceil(log2(maxAmountOfNumbers)));

            int treeSize=(2 * pow(2, treeHeight)) - 1;

            tree.resize(treeSize);
        }

        int query(int queryRangeStart, int queryRangeEnd)
        {
            int rootIndex=0;

            int nodeRangeStart=0;

            int nodeRangeEnd=maxAmountOfNumbers - 1;

            return queryHelper(rootIndex, nodeRangeStart, nodeRangeEnd, queryRangeStart, queryRangeEnd);
        }

        int queryHelper(int rootIndex, int nodeRangeStart, int nodeRangeEnd, int queryRangeStart, int queryRangeEnd)
        {
            if(queryRangeStart <= nodeRangeStart and nodeRangeEnd <= queryRangeEnd)
            {
                return tree[rootIndex];
            }

            if(queryRangeEnd < nodeRangeStart or nodeRangeEnd < queryRangeStart)
            {
                return numeric_limits<int>::min();
            }

            int middle=nodeRangeStart + (nodeRangeEnd - nodeRangeStart)/2;

            int leftChildIndex=2 * rootIndex + 1;

            int rightChildIndex=2 * rootIndex + 2;

            int leftChildMax=queryHelper(leftChildIndex, nodeRangeStart, middle, queryRangeStart, queryRangeEnd);

            int rightChildMax=queryHelper(rightChildIndex, middle + 1, nodeRangeEnd, queryRangeStart, queryRangeEnd);

            return max(leftChildMax, rightChildMax);
        }

        void update(int treeIndex, int value)
        {
            int rootIndex=0;

            int nodeRangeStart=0;

            int nodeRangeEnd=maxAmountOfNumbers - 1;

            updateHelper(rootIndex, nodeRangeStart, nodeRangeEnd, treeIndex, value);
        }

        void updateHelper(int rootIndex, int nodeRangeStart, int nodeRangeEnd, int treeIndex, int value)
        {
            if(treeIndex < nodeRangeStart or treeIndex > nodeRangeEnd)
            {
                return;
            }

            if(nodeRangeStart==nodeRangeEnd)
            {
                tree[rootIndex]=max(tree[rootIndex], value);

                return;
            }

            int middle=nodeRangeStart + (nodeRangeEnd - nodeRangeStart)/2;

            int leftChildIndex=(2 * rootIndex) + 1;

            int rightChildIndex=(2 * rootIndex) + 2;

            updateHelper(leftChildIndex, nodeRangeStart, middle, treeIndex, value);

            updateHelper(rightChildIndex, middle + 1, nodeRangeEnd, treeIndex, value);

            tree[rootIndex]=max(tree[leftChildIndex], tree[rightChildIndex]);
        }

        int getMax()
        {
            return tree[0];
        }
};

class Solution
{
    public:
        int lengthOfLIS(vector<int> & nums, int k)
        {
            int result=0;

            const int limit=1e5 + 1;

            MaximumSegmentTree tree(limit);

            for(int number : nums)
            {
                int left=max(0, number - k);

                int right=number - 1;

                int lengthEndingWithCurrentNumber=1 + tree.query(left, right);

                tree.update(number, lengthEndingWithCurrentNumber);
            }

            result=tree.getMax();

            return result;
        }
};