#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <unordered_map>
#include <vector>

/*std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target)
{
    std::vector<std::vector<int>> result;

    if(nums.size() < 4)
    {
        return result;
    }

    auto n=nums.size();

    std::set<std::vector<int>> cache;

    for(auto a=0;a<n-3;++a)
    {
        for(auto b=a+1;b<n-2;++b)
        {
            for(auto c=b+1;c<n-1;++c)
            {
                for(auto d=c+1;d<n;++d)
                {
                    int sum=nums[a] + nums[b] + nums[c] + nums[d];

                    if(sum==target)
                    {
                        std::vector<int> quadruplet(4, 0);

                        quadruplet[0]=nums[a];

                        quadruplet[1]=nums[b];

                        quadruplet[2]=nums[c];

                        quadruplet[3]=nums[d];

                        std::sort(quadruplet.begin(), quadruplet.end());

                        cache.insert(quadruplet);
                    }
                }
            }
        }
    }

    for(const auto & element : cache)
    {
        result.push_back(element);
    }

    return result;
}*/

/*bool isValidQuadruplet(std::vector<int> & sum, std::unordered_map<int, int> hashtable, std::set<std::vector<int>> & cache, const int & target)
{
    bool isValid=true;

    std::vector<int> erasedValues;

    int total=0;

    for(const auto & number : sum)
    {
        if(!hashtable.count(number))
        {
            isValid=false;
        }
        else
        {
            hashtable[number]--;

            total+=number;

            if(hashtable[number]==0)
            {
                hashtable.erase(number);

                erasedValues.push_back(number);
            }
        }
    }

    if(!erasedValues.empty())
    {
        for(const auto & value : erasedValues)
        {
            hashtable[value]++;
        }
    }

    return isValid && total==target;
}

std::vector<std::vector<int>> threeSum(std::vector<int> & nums, int target)
{
    std::vector<std::vector<int>> result;

    auto n=nums.size();

    for(auto i=0;i<n;++i)
    {
        auto left=i+1;

        auto right=n-1;

        while(left < right)
        {
            auto sum=nums[i] + nums[left] + nums[right];

            if(sum==target)
            {
                std::vector<int> triplet(3, 0);

                triplet[0]=nums[i];

                triplet[1]=nums[left];

                triplet[2]=nums[right];

                result.push_back(triplet);

                while(left < right && nums[left]==triplet[1])
                {
                    left++;
                }

                while(left < right && nums[right]==triplet[2])
                {
                    right--;
                }
            }
            else if(sum < target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        while(i+1 < n && nums[i]==nums[i+1])
        {
            i++;
        }
    }

    return result;
}

std::vector<std::vector<int>> fourSum(std::vector<int> & nums, int target)
{
    std::vector<std::vector<int>> result;

    if(nums.size() < 4)
    {
        return result;
    }

    std::unordered_map<int, int> hashtable;

    std::set<std::vector<int>> cache;

    std::sort(nums.begin(), nums.end());

    for(const auto & number : nums)
    {
        hashtable[number]++;
    }

    for(const auto & number : nums)
    {
        int desired=target-number;

        auto threeSums=threeSum(nums, desired);

        if(!threeSums.empty())
        {
            for(auto & threeSum : threeSums)
            {
                threeSum.push_back(number);

                if(isValidQuadruplet(threeSum, hashtable, cache, target))
                {
                    std::sort(threeSum.begin(), threeSum.end());

                    cache.insert(threeSum);
                }
            }
        }
    }

    if(!cache.empty())
    {
        for(const auto & element : cache)
        {
            result.push_back(element);
        }
    }

    return result;
}*/

/*void backtracking(std::vector<int> & nums, std::vector<std::vector<int>> & result, std::vector<int> quadruplet, const int & target, int sum, int start)
{
    if(!quadruplet.empty())
    {
        std::copy(quadruplet.begin(), quadruplet.end(), std::ostream_iterator<int>(std::cout, " "));

        std::cout << std::endl;
    }

    if(quadruplet.size()==4 && sum==target)
    {
        result.push_back(quadruplet);

        return;
    }

    const auto n=nums.size();

    for(auto i=start;i<n;++i)
    {
        quadruplet.push_back(nums[i]);

        sum+=nums[i];

        backtracking(nums, result, quadruplet, target, sum, i+1);

        sum-=nums[i];

        quadruplet.pop_back();
    }
}

std::vector<std::vector<int>> fourSum(std::vector<int> & nums, int target)
{
    std::vector<std::vector<int>> result;

    if(nums.empty())
    {
        return result;
    }

    std::sort(nums.begin(), nums.end());

    std::vector<int> quadruplet;

    int start=0;

    int sum=0;

    backtracking(nums, result, quadruplet, target, sum, start);

    for(const auto & element : result)
    {
        std::copy(element.begin(), element.end(), std::ostream_iterator<int>(std::cout, " "));

        std::cout << std::endl;
    }

    return result;
}*/

std::vector<std::vector<int>> fourSum(std::vector<int> & nums, int target)
{
    std::vector<std::vector<int>> result;

    if(nums.size() < 4)
    {
        return result;
    }

    auto n=nums.size();

    std::sort(nums.begin(), nums.end());

    std::set<std::vector<int>> cache;

    for(auto i=0;i<n-3;++i)
    {
        for(auto j=i+1;j<n-2;++j)
        {
            auto left=j+1;

            auto right=n-1;

            while(left < right)
            {
                int sum=nums[i] + nums[j] + nums[left] + nums[right];

                if(sum==target)
                {
                    std::vector<int> quadruplet(4, 0);

                    quadruplet[0]=nums[i];

                    quadruplet[1]=nums[j];

                    quadruplet[2]=nums[left];

                    quadruplet[3]=nums[right];

                    cache.insert(quadruplet);

                    left++;

                    right--;
                }
                else if(sum < target)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
    }

    for(const auto & element : cache)
    {
        result.push_back(element);
    }

    return result;
}

std::vector<std::vector<int>> fourSum(std::vector<int> & nums, int target)
{
    std::vector<std::vector<int>> result;

    if(nums.size() < 4)
    {
        return result;
    }

    auto n=nums.size();

    std::sort(nums.begin(), nums.end());

    for(auto i=0;i<n-3;++i)
    {
        for(auto j=i+1;j<n-2;++j)
        {
            auto left=j+1;

            auto right=n-1;

            while(left < right)
            {
                int sum=nums[i] + nums[j] + nums[left] + nums[right];

                if(sum==target)
                {
                    std::vector<int> quadruplet(4, 0);

                    quadruplet[0]=nums[i];

                    quadruplet[1]=nums[j];

                    quadruplet[2]=nums[left];

                    quadruplet[3]=nums[right];

                    result.push_back(quadruplet);

                    while(left < right && nums[left]==quadruplet[2])
                    {
                        left++;
                    }

                    while(left < right && nums[right]==quadruplet[3])
                    {
                        right--;
                    }
                }
                else if(sum < target)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }

            while(j < n-2 && nums[j]==nums[j+1])
            {
                j++;
            }
        }

        while(i < n-3 && nums[i]==nums[i+1])
        {
            i++;
        }
    }

    return result;
}