#include <vector>
using namespace std;

/*
Solution: inspired by these references

1. Blog post --> https://leetcode.com/problems/range-sum-query-mutable/discuss/1406686/C%2B%2BJavaPython-Binary-Indexed-Tree

2. YouTube video --> https://www.youtube.com/watch?v=RgITNht_f4Q

3. GeeksForGeeks blog post --> https://www.geeksforgeeks.org/binary-indexed-tree-or-fenwick-tree-2/#:~:text=To%20update%20a%20value%2C%20simply,index%20in%20this%20new%20array.
*/

class BinaryIndexedTree
{
    private:
        vector<int> tree;
    
    public:
        BinaryIndexedTree()
        {
            
        }
    
        BinaryIndexedTree(int size)
        {
            tree.resize(size + 1, 0);
        }
    
        int getSum(int index)
        {
            int sum=0;
            
            for(;index>0;index-=(index & (-index)))
            {
                sum+=tree[index];
            }
            
            return sum;
        }
    
        void addValue(int index, int value)
        {
            for(;index<tree.size();index+=(index & (-index)))
            {
                tree[index]+=value;
            }
        }
};

class NumArray
{
    private:
        BinaryIndexedTree binaryIndexedTree;
    
        vector<int> numbers;
    
    public:
        NumArray(vector<int> & nums)
        {
            this->binaryIndexedTree=BinaryIndexedTree(nums.size());
            
            this->numbers=nums;
            
            for(int i=0;i<nums.size();i++)
            {
                binaryIndexedTree.addValue(i + 1, numbers[i]);
            }
        }

        void update(int index, int val)
        {
            int difference=val - numbers[index];
            
            binaryIndexedTree.addValue(index + 1, difference);
            
            numbers[index]=val;
        }

        int sumRange(int left, int right)
        {
            return binaryIndexedTree.getSum(right + 1) - binaryIndexedTree.getSum(left);
        }
};