#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

/*
 * Approach:
 * Map each of the roman letters and the special subtraction cases to their numeric counterparts.
 * Then, loop through the string and substitute appropriately.
 *
 * Time Complexity: O(n) [where n in the size of the input string]
 *
 * Space Complexity: O(1) [Since the number of roman letters is a constant]
 */

int romanToInt(string s)
{
    int result=0;

    unordered_map<char, int> table;

    table.insert(make_pair('I', 1));

    table.insert(make_pair('V', 5));

    table.insert(make_pair('X', 10));

    table.insert(make_pair('L', 50));

    table.insert(make_pair('C', 100));

    table.insert(make_pair('D', 500));

    table.insert(make_pair('M', 1000));

    unordered_map<string, int> subtractionMap;

    subtractionMap.insert(make_pair("IV", 4));

    subtractionMap.insert(make_pair("IX", 9));

    subtractionMap.insert(make_pair("XL", 40));

    subtractionMap.insert(make_pair("XC", 90));

    subtractionMap.insert(make_pair("CD", 400));

    subtractionMap.insert(make_pair("CM", 900));

    int n=int(s.size());

    for(int index=0;index<n;)
    {
        char current=s[index];

        if(current=='I')
        {
            string str{};

            if(s[index+1]=='V')
            {
                str+=current;

                str+=s[index+1];

                result+=subtractionMap[str];

                index+=2;
            }
            else if(s[index+1]=='X')
            {
                str+=current;

                str+=s[index+1];

                result+=subtractionMap[str];

                index+=2;
            }
            else
            {
                result+=table[current];

                index++;
            }
        }
        else if(current=='X')
        {
            string str{};

            if(s[index+1]=='L')
            {
                str+=current;

                str+=s[index+1];

                result+=subtractionMap[str];

                index+=2;
            }
            else if(s[index+1]=='C')
            {
                str+=current;

                str+=s[index+1];

                result+=subtractionMap[str];

                index+=2;
            }
            else
            {
                result+=table[current];

                index++;
            }
        }
        else if(current=='C')
        {
            string str{};

            if(s[index+1]=='D')
            {
                str+=current;

                str+=s[index+1];

                result+=subtractionMap[str];

                index+=2;
            }
            else if(s[index+1]=='M')
            {
                str+=current;

                str+=s[index+1];

                result+=subtractionMap[str];

                index+=2;
            }
            else
            {
                result+=table[current];

                index++;
            }
        }
        else
        {
            result+=table[current];

            index++;
        }
    }

    return result;
}