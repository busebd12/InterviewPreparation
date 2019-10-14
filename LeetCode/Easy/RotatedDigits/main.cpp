#include <iostream>
#include <cmath>
#include <unordered_map>
#include <vector>
using namespace std;

/*
 * Approaches:
 *
 * 1) For each number from [1, N] inclusive, do the following:
 *
 * a) Determine if all digits are valid
 * b) If all digits all valid, then create the rotated number by rotating each digit in the number
 * c) If the rotated number is different from the original number, increment our counter, goodNumbers.
 *
 * We use an unordered_map<int, int> to map all valid digits to their rotated counterparts.
 *
 * Time complexity: O(n * L) [where n is the total number of numbers from (1, N) and L is the average length of a number]
 * Space complexity: O(1) [we only store a constant amount of digits in our hashtable]
 *
 *
 * 2) Same approach as the first solution, but using a vector<int> instead of unordered_map<int, int> for our hashtable.
 *
 * Time complexity: O(n * L) [where n is the total number of numbers from (1, N) and L is the average length of a number]
 * Space complexity: O(1) [we only store a constant amount of digits in our hashtable]
 */

int rotatedDigits(int N)
{
    if(N <= 0)
    {
        return 0;
    }

    int goodNumbers=0;

    unordered_map<int, int> hashtable;

    hashtable[0]=0;

    hashtable[1]=1;

    hashtable[2]=5;

    hashtable[5]=2;

    hashtable[6]=9;

    hashtable[8]=8;

    hashtable[9]=6;

    for(int number=1;number<=N;++number)
    {
        int copy=number;

        bool allDigitsValid=true;

        int digits=0;

        while(copy)
        {
            int digit=copy % 10;

            if(!hashtable.count(digit))
            {
                allDigitsValid=false;

                digits++;
            }

            copy/=10;
        }

        if(allDigitsValid)
        {
            copy=number;

            int rotated=0;

            int power=0;

            while(copy)
            {
                int digit=copy % 10;

                int rotatedDigit=hashtable[digit];

                rotated+=(rotatedDigit * static_cast<int>(pow(10, power)));

                power++;

                copy/=10;
            }

            if(rotated!=number)
            {
                goodNumbers++;
            }
        }
    }

    return goodNumbers;
}

int rotatedDigits(int N)
{
    if(N <= 0)
    {
        return 0;
    }

    int goodNumbers=0;

    vector<int> hashtable(10, -1);

    hashtable[0]=0;

    hashtable[1]=1;

    hashtable[2]=5;

    hashtable[5]=2;

    hashtable[6]=9;

    hashtable[8]=8;

    hashtable[9]=6;

    for(int number=1;number<=N;++number)
    {
        int copy=number;

        bool allDigitsValid=true;

        int digits=0;

        while(copy)
        {
            int digit=copy % 10;

            if(hashtable[digit]==-1)
            {
                allDigitsValid=false;

                digits++;
            }

            copy/=10;
        }

        if(allDigitsValid)
        {
            copy=number;

            int rotated=0;

            int power=0;

            while(copy)
            {
                int digit=copy % 10;

                int rotatedDigit=hashtable[digit];

                rotated+=(rotatedDigit * static_cast<int>(pow(10, power)));

                power++;

                copy/=10;
            }

            if(rotated!=number)
            {
                goodNumbers++;
            }
        }
    }

    return goodNumbers;
}