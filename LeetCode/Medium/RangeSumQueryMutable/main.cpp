#include <iostream>
#include <vector>
using namespace std;

class NumArray
{
    public:
        vector<int> numbers;

        NumArray(vector<int> nums)
        {
            numbers=nums;
        }

        void update(int i, int val)
        {
            numbers[i]=val;
        }

        int sumRange(int i, int j)
        {
            int sum=0;

            if(numbers.empty())
            {
                return sum;
            }

            for(int x=i;x<=j;++x)
            {
                sum+=numbers[x];
            }

            return sum;
        }
};
