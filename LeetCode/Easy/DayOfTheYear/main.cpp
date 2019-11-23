#include <iostream>
#include <sstream>
#include <utility>
#include <vector>
using namespace std;

/*
 * Approaches:
 *
 * 1. Use a stringstream object to parse the date string and store the year, month, and day parts.
 * Then, check whether or not the current year is a leap year. Finally, loop from month 1 up to and including
 * the target month and add the number of days from each month as we go to the dayOfTheyear integer variable.
 * Return the dayOfTheYear integer variable.
 *
 * Time complexity: O(n) [where n is the length of the input date string]
 * Space complexity: O(n)
 *
 *
 * 2. Almost the same logic, except that we parse the string without using a stringstream object.
 * Everything else stays the same.
 *
 * Time complexity: O(n) [where n is the length of the input date string]
 * Space complexity: O(n)
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

int dayOfYear(string date)
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

    stringstream ss(date);

    string buffer{};

    char delimeter='-';

    int count=0;

    int targetYear=0;

    int targetMonth=0;

    int day=0;

    while(getline(ss, buffer, delimeter))
    {
        switch(count)
        {
            case 0:
                targetYear=stoi(buffer);
                count++;
                break;

            case 1:
                targetMonth=stoi(buffer);
                count++;
                break;

            case 2:
                day=stoi(buffer);
                break;

            default:
                break;
        }
    }

    bool leapYear=isLeapYear(targetYear);

    int dayOfTheYear=0;

    for(int month=1;month<=targetMonth;++month)
    {
        if(month==targetMonth)
        {
            dayOfTheYear+=day;
        }
        else
        {
            if(leapYear)
            {
                dayOfTheYear+=year[month].second;
            }
            else
            {
                dayOfTheYear+=year[month].first;
            }
        }
    }

    return dayOfTheYear;
}

int dayOfYear(string date)
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

    string buffer{};

    char delimeter='-';

    int count=0;

    int targetYear=0;

    int targetMonth=0;

    int day=0;

    auto n=date.size();

    for(auto i=0;i<n;)
    {
        while(i < n && date[i]!=delimeter)
        {
            buffer+=date[i];

            ++i;
        }

        switch(count)
        {
            case 0:
                targetYear=stoi(buffer);
                count++;
                break;

            case 1:
                targetMonth=stoi(buffer);
                count++;
                break;

            case 2:
                day=stoi(buffer);
                break;

            default:
                break;
        }

        buffer.clear();

        ++i;

    }

    bool leapYear=isLeapYear(targetYear);

    int dayOfTheYear=0;

    for(int month=1;month<=targetMonth;++month)
    {
        if(month==targetMonth)
        {
            dayOfTheYear+=day;
        }
        else
        {
            if(leapYear)
            {
                dayOfTheYear+=year[month].second;
            }
            else
            {
                dayOfTheYear+=year[month].first;
            }
        }
    }

    return dayOfTheYear;
}