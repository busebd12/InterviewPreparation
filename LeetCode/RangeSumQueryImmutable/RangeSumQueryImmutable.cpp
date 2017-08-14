#include <iostream>
#include <vector>
using namespace std;

class NumArray
{
    public: 
        vector<int> v;

        NumArray(vector<int> nums)
        {
            v=nums;
        }

        int sumRange(int i, int j)
        {
            int sum=0;

            int end=i;

            while(end <= j)
            {
                sum+=v[end];

                ++end;
            }

            return sum;
        }
};