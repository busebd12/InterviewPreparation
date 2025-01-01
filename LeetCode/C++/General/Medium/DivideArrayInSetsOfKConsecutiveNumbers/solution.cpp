#include <map>
#include <vector>
using namespace std;

class Solution
{
    public:
        bool isPossibleDivide(vector<int> & nums, int k)
        {
            int n=nums.size();

            if((n % k)!=0)
            {
                return false;
            }

            map<int, int> hashmap;

            for(int number : nums) //O(n) [where n is the length of nums]
            {
                if(hashmap.find(number)==hashmap.end())
                {
                    hashmap.emplace(number, 0); //O(log(u)) [where u is the total number of unqiue values in nums]
                }

                hashmap[number]+=1;
            }

            while(!hashmap.empty()) //O(u) [where u is the number of unique elements in nums]
            {
                vector<int> set;

                auto itr=hashmap.begin();

                while(itr!=hashmap.end() and set.size() < k) //O(k)
                {
                    if(!set.empty() and itr->first - 1 != set.back())
                    {
                        return false;
                    }
                    
                    set.emplace_back(itr->first);

                    itr->second-=1;

                    itr++;
                }

                if(set.size()!=k)
                {
                    return false;
                }

                for(int number : set) //O(k)
                {
                    if(hashmap[number]==0)
                    {
                        hashmap.erase(number); //O(log(u))
                    }
                }
            }

            return true;
        }
};

class Solution
{
    public:
        bool isPossibleDivide(vector<int> & nums, int k)
        {
            int n=nums.size();

            if((n % k)!=0)
            {
                return false;
            }

            map<int, int> hashmap;

            for(int number : nums) //O(n) [where n is the length of nums]
            {
                if(hashmap.find(number)==hashmap.end())
                {
                    hashmap.emplace(number, 0); //O(log(u)) [where u is the total number of unique values in nums]
                }

                hashmap[number]+=1;
            }

            while(!hashmap.empty()) //O(u)
            {
                auto itr=hashmap.begin();

                int start=itr->first;

                for(int number=start;number<start + k;number++) //O(k)
                {
                    if(hashmap.find(number)==hashmap.end())
                    {
                        return false;
                    }

                    hashmap[number]-=1;

                    if(hashmap[number]==0)
                    {
                        hashmap.erase(number); //O(log(u))
                    }
                }
            }

            return true;
        }
};