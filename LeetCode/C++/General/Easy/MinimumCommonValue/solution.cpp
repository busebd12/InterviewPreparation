#include <vector>
using namespace std;

class Solution
{
    public:
        int getCommon(vector<int> & nums1, vector<int> & nums2)
        {
            int result=-1;

            int n=nums1.size();

            int m=nums2.size();

            int i=0;

            int j=0;

            while(i < n and j < m)
            {
                if(nums1[i] < nums2[j])
                {
                    i+=1;
                }
                else if(nums1[i] > nums2[j])
                {
                    j+=1;
                }
                else
                {
                    result=nums1[i];

                    break;
                }
            }

            return result;
        }
};