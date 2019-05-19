#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
using namespace std;

int getHammingDistance(int & first, int & second)
{
    int differences=0;

    bitset<sizeof(first)> bset1(first);

    bitset<sizeof(second)> bset2(second);

    string str1=bset1.to_string();

    string str2=bset2.to_string();

    int n=int(str1.size());

    for(int i=0;i<n;++i)
    {
        if(str1[i]!=str2[i])
        {
            differences++;
        }
    }

    return differences;
}

int totalHammingDistanceBruteForce(vector<int> & nums)
{
    int total=0;

    unordered_map<int, unordered_set<int>> pairIndices;

    int n=int(nums.size());

    for(int i=0;i<n;++i)
    {
        pairIndices.insert(make_pair(i, unordered_set<int>()));
    }

    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(i!=j)
            {
                if(pairIndices[j].find(i)==pairIndices[j].end())
                {
                    pairIndices[i].insert(j);
                }
            }
        }
    }

    for(auto & element : pairIndices)
    {
        int first=nums[element.first];

        for(auto index : element.second)
        {
            int second=nums[index];

            int hammingDistance=getHammingDistance(first, second);

            total+=hammingDistance;
        }
    }

    return total;
}

int totalHammingDistance(vector<int> & nums)
{
    int n=int(nums.size());

    int result=0;

    for(int i=0;i<32;++i)
    {
        int ones=0;

        int zeroes=0;

        for(int j=0;j<n;++j)
        {
            if(((nums[j] >> i) & 1)==1)
            {
                ones++;
            }
            else
            {
                zeroes++;
            }
        }

        result+=(ones * zeroes);
    }

    return result;
}