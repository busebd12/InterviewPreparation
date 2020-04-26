#include <iostream>
#include <stack>
#include <vector>

/*
 * Solution: for each height in the input vector, we can trap water in-between two buildings that are taller than
 * the current height, one to the left and one to the right. To maximize the amount of water trapped, we want to
 * choose the tallest building to the left and the tallest building to the right. Then, we would simply fill the
 * space between the two tallest buildings till the water starts to overflow. However, we want to trap as much
 * water without it overflowing. So, how can we do this? By only trapping as much water as the minimum of the two
 * tallest buildings. Then, the total water trapped can be calculated as the minimum of the two tallest buildings,
 * one to the left and one to the right, minus the current height. We subtract the current height becuase the current
 * height could be greater than zero and that non-zero height takes away from the total space avaialable to trap the
 * water in. We pre-computer the heights of the tallest buildings to the left and right of each height, using O(n)
 * extra space to do so.
 *
 * Time complexity: O(n) [where n is the length of the input vector]
 * Space complexity: O(n)
 */

int trap(std::vector<int> & height)
{
    int result=0;

    if(height.empty())
    {
        return result;
    }

    auto n=int(height.size());

    std::vector<int> leftTallestBuilding(n, 0);

    leftTallestBuilding[0]=height[0];

    for(auto i=1;i<n;++i)
    {
        leftTallestBuilding[i]=std::max(leftTallestBuilding[i-1], height[i]);
    }

    std::vector<int> rightTallestBuilding(n, 0);

    rightTallestBuilding[n-1]=height[n-1];

    for(auto i=n-2;i>=0;--i)
    {
        rightTallestBuilding[i]=std::max(rightTallestBuilding[i+1], height[i]);
    }

    for(auto i=0;i<n;++i)
    {
        int trappedWater=std::min(leftTallestBuilding[i], rightTallestBuilding[i]) - height[i];

        result+=trappedWater;
    }

    return result;
}