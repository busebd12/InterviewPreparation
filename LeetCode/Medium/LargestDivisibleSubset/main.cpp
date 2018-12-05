#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool validSubset(vector<int> & subset, int subsetSize)
{
    if(subsetSize==2)
    {
        if((subset[0] % subset[1])!=0 && (subset[1] % subset[0])!=0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        for(int i=0;i<subsetSize;++i)
        {
            for(int j=0;j<subsetSize;++j)
            {
                if(i!=j)
                {
                    if((subset[i]%subset[j])!=0 && (subset[j]%subset[i])!=0)
                    {
                        return false;
                    }
                }
            }
        }

        return true;
    }
}

vector<vector<int>> generateSubsets(vector<int> & nums)
{
    vector<vector<int>> subsets;

    subsets.emplace_back(vector<int>());

    for(auto & number : nums)
    {
        int size=int(subsets.size());

        for(int i=0;i<size;++i)
        {
            auto subset=subsets[i];

            bool okay=true;

            for(auto & x : subset)
            {
                if((number % x)!=0 && (x % number)!=0)
                {
                    okay=false;

                    break;
                }
            }

            if(okay)
            {
                subset.emplace_back(number);

                subsets.emplace_back(subset);
            }
        }
    }

    return subsets;
}

vector<int> largestDivisibleSubset(vector<int> & nums)
{
    vector<int> result;

    if(nums.empty())
    {
        return result;
    }

    int n=int(nums.size());

    if(n==1)
    {
        return nums;
    }

    auto subsets=generateSubsets(nums);

    cout << "SUBSETS:" << endl;

    for(auto & subset : subsets)
    {
        if(!subset.empty())
        {
            for(auto & element : subset)
            {
                cout << element << " ";
            }

            cout << endl;
        }
    }

    cout << endl;

    int largest=0;

    for(auto & subset : subsets)
    {
        int subsetSize=int(subset.size());

        if(subsetSize > largest)
        {
            result=subset;

            largest=subsetSize;
        }
    }

    /*
    for(auto & subset : subsets)
    {
        int subsetSize=int(subset.size());

        if(subsetSize >= 2)
        {
            if(validSubset(subset, subsetSize))
            {
                cout << "VALID SUBSET:" << endl;

                for(auto & element : subset)
                {
                    cout << element << " ";
                }

                cout << endl;

                if(subsetSize >= largest)
                {
                    result=subset;

                    largest=subsetSize;
                }
            }
        }
    }*/

    cout << "ANSWER:" << endl;

    for(const auto & element : result)
    {
        cout << element << " ";
    }

    cout << endl;

    return result;
}

int main()
{
    vector<int> nums0={1, 2, 3};

    largestDivisibleSubset(nums0);

    vector<int> nums1={1, 2, 4, 8};

    //largestDivisibleSubset(nums1);
}