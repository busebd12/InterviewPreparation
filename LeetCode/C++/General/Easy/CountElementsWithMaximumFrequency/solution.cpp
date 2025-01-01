#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

class Solution
{
    public:
        int maxFrequencyElements(vector<int> & nums)
        {
            int result=0;

            int n=nums.size();

            unordered_map<int, int> frequencies;

            for(auto number : nums)
            {
                if(!frequencies.count(number))
                {
                    frequencies.insert(make_pair(number, 0));
                }

                frequencies[number]+=1;
            }

            int max_frequency=0;

            for(auto [number, frequency] : frequencies)
            {
                max_frequency=max(max_frequency, frequency);
            }

            for(auto [number, frequency] : frequencies)
            {
                if(frequency==max_frequency)
                {
                    result+=frequency;
                }
            }

            return result;
        }
};

class Solution
{
    public:
        int maxFrequencyElements(vector<int> & nums)
        {
            int result=0;

            int max_value=101;

            vector<int> frequencies(max_value, 0);

            for(auto number : nums)
            {
                frequencies[number]+=1;
            }

            int max_frequency=0;

            for(int number=0;number<max_value;number+=1)
            {
                max_frequency=max(max_frequency, frequencies[number]);
            }

            for(int number=0;number<max_value;number+=1)
            {
                int frequency=frequencies[number];
                
                if(frequency==max_frequency)
                {
                    result+=frequency;
                }
            }

            return result;
        }
};