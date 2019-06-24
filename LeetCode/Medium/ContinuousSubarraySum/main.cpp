#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_set>
using namespace std;

void dfs(vector<int> & nums, vector<int> & subarray, vector<int> & sums, const int & n, const int & targetSize, const int & k, int & sum, int index, bool & done)
{
    if(done)
    {
        return;
    }

    if(subarray.size() >= targetSize)
    {
        if(k==0)
        {
            if(sum==0)
            {
                sums.push_back(sum);

                done=true;
            }
        }
        else
        {
            if((sum%k)==0)
            {
                sums.push_back(sum);

                done=true;
            }
        }
    }

    for(int i=index;i<n;++i)
    {
        if(!subarray.empty())
        {
            if((subarray.back()+1)!=i)
            {
                continue;
            }
        }

        subarray.push_back(i);

        sum+=nums[i];

        dfs(nums, subarray, sums, n, targetSize, k, sum, i+1, done);

        subarray.pop_back();

        sum-=nums[i];
    }
}

bool checkSubarraySumTLE(vector<int> & nums, int k)
{
    if(nums.empty())
    {
        return false;
    }

    int n=int(nums.size());

    const int targetSize=2;

    int index=0;

    int sum=0;

    bool result=false;

    vector<int> subarray;

    vector<int> sums;

    bool done=false;

    dfs(nums, subarray, sums, n, targetSize, k, sum, index, done);

    return (sums.empty()) ? false : true;
}

bool checkSubarraySum(vector<int>& nums, int k)
{
    int n=int(nums.size());

    int sum=0;

    int previous=0;

    unordered_set<int> modk;

    for(int i=0;i<n;++i)
    {
        sum+=nums[i];

        int mod=((k==0) ? sum : sum % k);

        if(modk.count(mod))
        {
            return true;
        }

        modk.insert(previous);

        previous=mod;
    }

    return false;
}

int main()
{
    vector<int> nums={23, 2, 4, 6, 7};

    int k=6;

    cout << 23 % k << endl;

    /*vector<int> nums={23, 2, 6, 4, 7};

    int k=6;*/

    /*vector<int> nums={24, 2, 4, 6, 7};

    int k=-6;*/

    /*vector<int> nums={23, 2, 4, 6, 7};

    int k=0;*/

    /*vector<int> nums={0, 0};

    int k=0;*/

    /*vector<int> nums={23, 2, 4, 6, 7};

    int k=0;*/

    //cout << boolalpha << checkSubarraySumTLE(nums, k) << endl;

    cout << boolalpha << checkSubarraySum(nums, k) << endl;
}