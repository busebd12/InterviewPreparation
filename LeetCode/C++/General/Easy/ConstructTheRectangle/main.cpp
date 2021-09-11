#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

/*
 * Approaches:
 *
 * 1) Generate all possible pairs of Length and Width that meet our criteria and calcuate the area.
 * This got Time Limit Exceeded when the code was run.
 *
 * Time complexity: O(n-squared) [where is n is the input area]
 * Space complexity: O(1)
 *
 * 2) Similar logic to the first approach except that we loop width from [1, Length]. This code also
 * got Time Limit Exceeded when run.
 *
 * Time complexity: O(n * m) [where n is the input area and m is the chosen length value]
 * Space complexity: O(1)
 *
 * 3) If we look at the formula for area of a rectangle more closely, we see that, for cases where length and width are equal,
 * we have L * W <= A -----> W * W <= A -----> W^2 <= A ------>  √W <= A. By this derivation, we can see that the width will
 * always fall in the range [1, area]. So, we just set width equal to the square root of the area, and while area is not
 * divisible by the width, we decrement the width. Once we find a width that area is divisible by, we are done, and
 * we just return vector holding the length and the width.
 *
 * Time complexity: O(sqrt(n)) [where n is the input area]
 * Space complexity: O(1)
 */

vector<int> constructRectangle(int area)
{
    vector<int> result(2);

    if(area==0)
    {
        return {0, 0};
    }

    if(area==1)
    {
        return {1, 1};
    }

    long int previousDifference=0;

    for(long int Length=1;Length<=area;++Length)
    {
        for(long int Width=1;Width<=area;++Width)
        {
            if(Length * Width==area)
            {
               if(Length >= Width)
               {
                   if(result[0]==0 && result[1]==0)
                   {
                       result[0]=Length;

                       result[1]=Width;

                       previousDifference=static_cast<long int>(abs(Length - Width));
                   }
                   else
                   {
                       int difference=int(abs(Length - Width));

                       if(difference < previousDifference)
                       {
                           result[0]=Length;

                           result[1]=Width;

                           previousDifference=difference;
                       }
                   }
               }
            }
        }
    }

    return result;
}

vector<int> constructRectangle(int area)
{
    vector<int> result(2);

    if(area==0)
    {
        return {0, 0};
    }

    if(area==1)
    {
        return {1, 1};
    }

    long int previousDifference=0;

    for(long int Length=1;Length<=area;++Length)
    {
        for(long int Width=1;Width<=Length;++Width)
        {
            if(Length * Width==area)
            {
               if(result[0]==0 && result[1]==0)
               {
                   result[0]=Length;

                   result[1]=Width;

                   previousDifference=static_cast<long int>(abs(Length - Width));
               }
               else
               {
                   long int difference=static_cast<long int>(abs(Length - Width));

                   if(difference < previousDifference)
                   {
                       result[0]=Length;

                       result[1]=Width;

                       previousDifference=difference;
                   }
               }
            }
        }
    }

    return result;
}

vector<int> constructRectangle(int area)
{
    if(area==0)
    {
        return {0, 0};
    }

    if(area==1)
    {
        return {1, 1};
    }

    int width=int(sqrt(area));

    while(area%width!=0)
    {
        width--;
    }

    return vector<int>({area/width, width});
}