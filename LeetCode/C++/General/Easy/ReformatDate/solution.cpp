#include <string>
#include <sstream>
#include <unordered_map>
using namespace std;

/*
Time complexity: O(d) [where d is the length of date]
Space complexity: O(d)
*/

class Solution
{
    public:
        string reformatDate(string date)
        {
            string result="";

            unordered_map<string, string> hashmap={{"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"}, {"May", "05"}, {"Jun", "06"}, {"Jul", "07"}, {"Aug", "08"}, {"Sep", "09"}, {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}};

            stringstream dateStream(date);

            string day="";

            dateStream >> day;

            string month="";

            dateStream >> month;

            string year="";

            dateStream >> year;

            result.append(year);

            result.push_back('-');

            result.append(hashmap[month]);

            result.push_back('-');

            if(day.size() < 4)
            {
                result.push_back('0');

                result.push_back(day[0]);
            }
            else
            {
                result.append(day.substr(0, 2));
            }

            return result;
        }
};