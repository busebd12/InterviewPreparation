#include <iostream>
#include <utility>
#include <vector>
using namespace std;

/*
 * Approach: use a vector<pair<int, int>> year to keep track of the number of days in each month depending on
 * whether or not the year is a leap year. Then, just return the number of days in a given month accordingly.
 *
 * Time complexity: O(1)
 * Space complexity: O(number of months in a year + 1)
 */

bool isLeapYear(int year)
{
    bool result{};

    if((year % 4)!=0)
    {
        result=false;
    }
    else if((year % 100)!=0)
    {
        result=true;
    }
    else if((year % 400)!=0)
    {
        result=false;
    }
    else
    {
        result=true;
    }

    return result;
}

int numberOfDays(int Y, int M)
{
    int months=12;

    vector<pair<int, int>> year(months + 1);

    year[1]=make_pair(31, 31);

    year[2]=make_pair(28, 29);

    year[3]=make_pair(31, 31);

    year[4]=make_pair(30, 30);

    year[5]=make_pair(31, 31);

    year[6]=make_pair(30, 30);

    year[7]=make_pair(31, 31);

    year[8]=make_pair(31, 31);

    year[9]=make_pair(30, 30);

    year[10]=make_pair(31, 31);

    year[11]=make_pair(30, 30);

    year[12]=make_pair(31, 31);

    return isLeapYear(Y) ? year[M].second : year[M].first;
}