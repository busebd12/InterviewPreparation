#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

/*
 * Appproaches:
 *
 * 1. Use two for loops to generate all the consecutive sub-arrays of length k
 * in calories and calculate the sum of each sub-array. If the sum is less than
 * lower, subtract one from our integer variable, points. If the sum is greater
 * than upper, add one to our integer variable, points. After loopin over the
 * calories vector, return points. This solution got Time Limit Exceeded.
 *
 * Time complexity: O(n * k) [where n is the length of the calories vector and k is the input integer k]
 * Space complexity: O(1)
 *
 *
 * 2. Use two-pointers to generate all the consecutive sub-arrays of length k
 * in calories and calculate the sum of each sub-array. If the sum is less than
 * lower, subtract one from our integer variable, points. If the sum is greater
 * than upper, add one to our integer variable, points. After loopin over the
 * calories vector, return points. This solution got Time Limit Exceeded.
 *
 * Time complexity: O(n * k) [where n is the length of the calories vector and k is the input integer k]
 * Space complexity: O(1)
 *
 * 3. Instead of using two-pointers to keep track of all sub-arrays from the calories vector,
 * we use two pointers to maintain a sliding-window of the sum for each contigous sub-array.
 * After calculating the sum, we update our T variable accordingly.
 *
 * Time complexity: O(k + n-k);
 * Space complexity: O(1)
 */

int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper)
{
    int points=0;

    if(calories.empty() || k==0)
    {
        return points;
    }

    auto n=calories.size();

    for(auto i=0;(i+k-1)<n;++i)
    {
        int T=0;

        for(auto j=i,count=0;count<k;++count,++j)
        {
            T+=calories[j];
        }

        if(T < lower)
        {
            points--;
        }

        if(T > upper)
        {
            points++;
        }
    }

    return points;
}

int getSum(vector<int> & calories, int i, int j)
{
    int sum=0;

    for(int index=i;index<=j;++index)
    {
        sum+=calories[index];
    }

    return sum;
}

int dietPlanPerformance(vector<int> & calories, int k, int lower, int upper)
{
    int points=0;

    if(calories.empty() || k==0)
    {
        return points;
    }

    auto n=calories.size();

    int i=0;

    int j=k-1;

    while(j < n)
    {
        int T=getSum(calories, i, j);

        if(T < lower)
        {
            points--;
        }

        if(T > upper)
        {
            points++;
        }

        i++;

        j++;
    }

    return points;
}

int dietPlanPerformance(vector<int> & calories, int k, int lower, int upper)
{
    int points=0;

    if(calories.empty() || k==0)
    {
        return points;
    }

    auto n=calories.size();

    int i=0;

    int j=k-1;

    int T=0;

    int count=0;

    int tail=calories[i];

    while(j < n)
    {
        if(count==0)
        {
            T=getSum(calories, i, j);
        }
        else
        {
            T-=tail;

            T+=calories[j];
        }

        if(T < lower)
        {
            points--;
        }

        if(T > upper)
        {
            points++;
        }

        tail=calories[i];

        count++;

        i++;

        j++;
    }

    return points;
}

int dietPlanPerformance(vector<int> & calories, int k, int lower, int upper)
{
    int points=0;

    if(calories.empty() || k==0)
    {
        return points;
    }

    auto n=calories.size();

    int j=k-1;

    int T=accumulate(calories.begin(), calories.begin()+k, 0);

    while(j < n)
    {
        if(T < lower)
        {
            points--;
        }

        if(T > upper)
        {
            points++;
        }

        j++;

        if(j >= n)
        {
            break;
        }

        T-=calories[j-k];

        T+=calories[j];
    }

    return points;
}