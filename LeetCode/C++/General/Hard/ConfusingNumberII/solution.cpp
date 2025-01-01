#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
    public:
        int confusingNumberII(int n)
        {
            int result=0;

            unordered_map<int, int> hashmap;

            hashmap.emplace(0, 0);

            hashmap.emplace(1, 1);

            hashmap.emplace(6, 9);

            hashmap.emplace(8, 8);

            hashmap.emplace(9, 6);

            long start=0;

            helper(hashmap, n, result, start);

            return result;
        }

        void helper(unordered_map<int, int> & hashmap, int n, int & result, long start)
        {
            if(isConfusing(hashmap, start)==true)
            {
                result+=1;
            }

            for(auto & [digit, rotated] : hashmap)
            {
                long next=(start * 10) + rotated;

                if(next <= n and next!=0)
                {
                    helper(hashmap, n, result, next);
                }
            }
        }

        bool isConfusing(unordered_map<int, int> & hashmap, long number)
        {
            long rotated=0;

            long copy=number;

            while(copy > 0)
            {
                int digit=copy % 10;

                rotated=(rotated * 10) + hashmap[digit];

                copy=copy / 10;
            }

            return rotated!=number;
        }
};

class Solution
{
    public:
        int confusingNumberII(int n)
        {
            int result=0;

            vector<int> hashmap(10, -1);

            hashmap[0]=0;

            hashmap[1]=1;

            hashmap[6]=9;

            hashmap[8]=8;

            hashmap[9]=6;

            long start=0;

            helper(hashmap, n, result, start);

            return result;
        }

        void helper(vector<int> & hashmap, int n, int & result, long start)
        {
            if(isConfusing(hashmap, start)==true)
            {
                result+=1;
            }

            for(int digit=0;digit<10;digit++)
            {
                if(hashmap[digit]!=-1)
                {
                    int rotated=hashmap[digit];
                    
                    long next=(start * 10) + rotated;

                    if(next <= n and next!=0)
                    {
                        helper(hashmap, n, result, next);
                    }
                }
            }
        }

        bool isConfusing(vector<int> & hashmap, long number)
        {
            long rotated=0;

            long copy=number;

            while(copy > 0)
            {
                int digit=copy % 10;

                rotated=(rotated * 10) + hashmap[digit];

                copy=copy / 10;
            }

            return rotated!=number;
        }
};