#include <iostream>
#include <vector>
#include <unordered_map>
#include <random>
using namespace std;

class RandomizedSet
{
    public:
        vector<int> nums;

        unordered_map<int, int> m;

        int index;

        RandomizedSet()
        {
            index=0;
        }

        bool insert(int val)
        {
            if(!m.count(val))
            {
                nums.emplace_back(val);

                m.insert(make_pair(val, index));

                index++;

                return true;
            }
            else
            {
                return false;
            }
        }

        bool remove(int val)
        {
            if(m.count(val))
            {
                int removedIndex=m[val];

                if(removedIndex==nums.size()-1)
                {
                    nums.pop_back();
                }
                else
                {
                    int lastIndex=m[nums.back()];

                    m[nums.back()]=removedIndex;

                    swap(nums[lastIndex], nums[removedIndex]);

                    nums.pop_back();
                }

                m.erase(val);

                --index;

                return true;
            }
            else
            {
                return false;
            }
        }

        int getRandom()
        {
            random_device seeder;

            mt19937 engine(seeder());

            int start=0;

            int end=int(nums.size()-1);

            uniform_int_distribution<int> dist(start, end);

            int i=dist(engine);

            return nums[i];
        }
};