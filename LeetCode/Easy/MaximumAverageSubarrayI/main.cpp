#include <iostream>
#include <vector>
#include <limits>
#include <numeric>
#include <cmath>
using namespace std;

/*
 * Approaches:
 *
 * 1) Loop over all sub-arrays of length k and find the maximum average.
 *
 * Time complexity: O(nk) [where n is the length of the input vector]
 * Space complexity: O(1)
 *
 * 2) We maintain a sliding window size of k and a rolling sum. Each time we move up one element in the array,
 * we add that element to our rolling sum and subtract the last element in our window from the sum. Then, the next
 * to last element from the prior window become the new last element in the new window of size k. Calculate the average
 * as we go along.
 *
 * Time complexity: O(n) [where n is the length of the input vector]
 * Space complexity: O(1)
 *
 * 3) Same slinding window approach as the second solution, just written a lot cleaner.
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

double findMaxAverage(vector<int> & nums, int k)
{
    if(nums.empty())
    {
        return 0.0;
    }

    int n=int(nums.size());

    if(n==1 && k==1)
    {
        return double(nums[0]);
    }

    if(n==k)
    {
        double total=accumulate(nums.begin(), nums.end(), 0.0);

        return double(total/k);
    }

    double minimum=-1;

    bool minimumStart=true;

    double maximum=-1;

    bool maximumStart=true;

    for(int i=0;i<n;++i)
    {
        if(i+(k-1) < n)
        {
            double total=0;

            for(int j=i,count=0;count<k;++j,++count)
            {
                total+=nums[j];
            }

            double average=double(total/k);

            if(average < 0)
            {
                if(minimumStart==true)
                {
                    minimum=average;

                    minimumStart=false;
                }
                else
                {
                    if(average >= minimum)
                    {
                        minimum=average;
                    }
                }
            }
            else
            {
                if(maximumStart==true)
                {
                    maximum=average;

                    maximumStart=false;
                }
                else
                {
                    if(average >= maximum)
                    {
                        maximum=average;
                    }
                }

            }
        }
    }

    double result{};

    if(minimumStart && !maximumStart)
    {
        result=maximum;
    }
    else if(!minimumStart && maximumStart)
    {
        result=minimum;
    }
    else
    {
        result=max(minimum, maximum);
    }

    return result;
}

double findMaxAverage(vector<int>& nums, int k)
{
    if(nums.empty())
    {
        return 0.0;
    }

    if(k==0)
    {
        return 0.0;
    }

    int n=int(nums.size());

    if(n==1 && k==1)
    {
        return double(nums[0]);
    }

    if(n==k)
    {
        double total=accumulate(nums.begin(), nums.end(), 0.0);

        return double(total/k);
    }

    double sum=0.0;

    double minimum=-1;

    double maximum=-1;

    bool minimumStart=false;

    bool maximumStart=false;

    int i=0;

    for(;i<k;++i)
    {
        sum+=nums[i];
    }

    double average=double(sum/k);

    if(average < 0)
    {
        if(minimumStart==false)
        {
            minimum=average;

            minimumStart=true;
        }
        else
        {
            if(average >= minimum)
            {
                minimum=average;
            }
        }
    }
    else
    {
        if(maximumStart==false)
        {
            maximum=average;

            maximumStart=true;
        }
        else
        {
            if(average >= maximum)
            {
                maximum=average;
            }
        }
    }

    int x=0;

    int lastElement=nums[x];

    for(int j=i;j<n;++j)
    {
        sum-=lastElement;

        sum+=nums[j];

        double average=double(sum/k);

        if(average < 0)
        {
            if(minimumStart==false)
            {
                minimum=average;

                minimumStart=true;
            }
            else
            {
                if(average >= minimum)
                {
                    minimum=average;
                }
            }
        }
        else
        {
            if(maximumStart==false)
            {
                maximum=average;

                maximumStart=true;
            }
            else
            {
                if(average >= maximum)
                {
                    maximum=average;
                }
            }
        }

        x++;

        lastElement=nums[x];
    }

    double result=0.0;

    if(minimumStart==false && maximumStart==true)
    {
        result=maximum;
    }
    else if(maximumStart==false && minimumStart==true)
    {
        result=minimum;
    }
    else
    {
        result=max(minimum, maximum);
    }

    return result;
}

double findMaxAverage(vector<int> & nums, int k)
{
    if(nums.empty())
    {
        return 0.0;
    }

    if(k==0)
    {
        return 0.0;
    }

    int n=int(nums.size());

    if(n==1 && k==1)
    {
        return double(nums[0]);
    }

    if(n==k)
    {
        double total=accumulate(nums.begin(), nums.end(), 0.0);

        return double(total/k);
    }

    double sum=0.0;

    double result=numeric_limits<long>::min();

    for(int i=0;i<n;++i)
    {
        sum+=nums[i];

        if(i >= k)
        {
            sum-=nums[i-k];
        }

        if(i >= k-1)
        {
            result=max(result, sum/k);
        }
    }

    return result;
}