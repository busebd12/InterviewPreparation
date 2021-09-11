#include <iostream>
#include <vector>
using namespace std;

/*
 * Approach: Loop over the flowerbed and if the flowerbed[i] is a zero and n is greater than zero,
 * then there are three cases to check. If i==0, then we need to check if the next flowerpot after it
 * is a 0. If it is, then we plant a flower at flowerbed[i]. Else ff i==m-1, then we need to check if the
 * previous flowerpot is empty. If it is, then we can plant a plant at flowerbed[i]. Else, if the
 * previous flower pot and next flowerpot are both empty, then we can plant a plant in the current flowerpot.
 * After each time we plant a plant, decrement n by one. After the for loop, just return whether or not n==0.
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 *
 */

bool canPlaceFlowers(vector<int>& flowerbed, int n)
{
    if(flowerbed.empty())
    {
        return false;
    }

    if(n==0)
    {
        return true;
    }

    int m=int(flowerbed.size());

    if(m==1 && n==1)
    {
        if(flowerbed[0]==0)
        {
            return true;
        }
    }

    for(int i=0;i<m;++i)
    {
        if(flowerbed[i]==0 && n > 0)
        {
            if(i==0)
            {
                if(flowerbed[i+1]==0)
                {
                    flowerbed[i]=1;

                    n--;
                }
            }
            else if(i==m-1)
            {
                if(flowerbed[i-1]==0)
                {
                    flowerbed[i]=1;

                    n--;
                }
            }
            else
            {
                if(flowerbed[i-1]==0 && flowerbed[i+1]==0)
                {
                    flowerbed[i]=1;

                    n--;
                }
            }
        }
    }

    return n==0;
}