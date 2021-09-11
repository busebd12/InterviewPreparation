#include <iostream>
#include <vector>

/*
 * Solution: the idea to have a variable, index, that keeps track of where we will place up to two copies of each number from the input vector.
 * For each number in the vector, we count how many times that number appears. Then, we place either one copy or two copies
 * of that number in the proper spot/spots, incrementing our index variable after we place the number in its spot.
 *
 * Time complexity: O(n * k) => O(n * 2) since we are allowed only two copies maximum for each number => O(n)
 * Space complexity: O(1)
 */

int removeDuplicates(std::vector<int> & nums)
{
    if(nums.empty())
    {
        return 0;
    }

    int n=int(nums.size());

    int k=2;

    int index=0;

    int count=0;

    for(auto i=0;i<n;)
    {
        int number=nums[i];

        while(i < n && nums[i]==number)
        {
            count++;

            i++;
        }

        if(count==1)
        {
            nums[index]=number;

            index++;

            count=0;
        }

        if(count > 1)
        {
            for(int x=0;x<k;++x)
            {
                nums[index]=number;

                index++;
            }

            count=0;
        }
    }

    return index;
}