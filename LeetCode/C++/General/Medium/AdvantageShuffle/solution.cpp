#include <set>
#include <vector>
using namespace std;

/*
Solution: multiset + upper_bound (binary search)

Time complexity: O((n * log(n)) + (n * log(n))) [where n is the length of nums1 and nums2]
Space complexity: O(n)
*/

class Solution
{
    public:
        vector<int> advantageCount(vector<int> & nums1, vector<int> & nums2)
        {
            vector<int> result;

            int n=nums1.size();

            result.resize(n, -1);

            multiset<int> values;

            for(int number : nums1) //O(n)
            {
                values.insert(number); //O(log(n))
            }

            for(int i=0;i<n;i++) //O(n)
            {
                int target=nums2[i];

                //Search for first number larger than nums2[i] in nums[1]
                auto itr=values.upper_bound(target); //O(log(n))

                //If we find such a value
                if(itr!=values.end())
                {
                    //Put it in its place in the result vector
                    result[i]=*(itr);

                    values.erase(itr); //O(log(n))
                }
                //Else, no such value exists in the multiset
                else
                {
                    //Just take the smallest element available in the multiset to allow later searches to have the best chance at finding an upper_bound result
                    result[i]=*(values.begin());

                    values.erase(values.begin()); //O(log(n))
                }
            }

            return result;
        }
};