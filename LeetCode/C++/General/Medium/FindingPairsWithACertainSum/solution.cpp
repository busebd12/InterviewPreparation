#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class FindSumPairs
{
    private:
        unordered_map<int, int> hashmap;

        vector<int> first;

        vector<int> second;
    
    public:
        FindSumPairs(vector<int> & nums1, vector<int> & nums2)
        {
            first=nums1;

            second=nums2;
            
            for(int number : nums2) //O(m) [where m is the length of nums2]
            {
                if(hashmap.find(number)==hashmap.end())
                {
                    hashmap.emplace(number, 0);
                }

                hashmap[number]+=1;
            }

            sort(first.begin(), first.end()); //O(n log n) [where n is the length of first]
        }
        
        void add(int index, int val)
        {
            hashmap[second[index]]-=1;
            
            second[index]+=val;

            if(hashmap.find(second[index])==hashmap.end())
            {
                hashmap.emplace(second[index], 0);
            }

            hashmap[second[index]]+=1;
        }
        
        int count(int tot)
        {
            int pairs=0;
            
            for(int i=0;i<first.size() and first[i] < tot;i++) //O(n) [where n is the length of first]
            {
                int target=tot - first[i];

                if(hashmap.find(target)!=hashmap.end())
                {
                    pairs+=hashmap[target];
                }
            }

            return pairs;
        }
};