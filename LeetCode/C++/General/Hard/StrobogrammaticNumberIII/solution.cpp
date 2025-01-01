#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
    public:
        int strobogrammaticInRange(string low, string high)
        {
            int result=0;

            unordered_map<int, int> hashmap={{0, 0}, {1, 1}, {6, 9}, {8, 8}, {9, 6}};

            string number="";

            helper(hashmap, low, high, number, result);

            number="0";

            helper(hashmap, low, high, number, result);

            number="1";

            helper(hashmap, low, high, number, result);

            number="8";

            helper(hashmap, low, high, number, result);

            return result;
        }

        void helper(unordered_map<int, int> & hashmap, string & low, string & high, string number, int & result)
        {
            if(number.size() > high.size())
            {
                return;
            }

            //If (number is "0" or number.size() > 1 and first digit in number is not 0) and (low <= number and number <= high)
            if((number=="0" or number.front()!='0') and compare(low, number)==true and compare(number, high)==true)
            {
                result+=1;
            }

            //Iterate through {0, 0}, {1, 1}, {6, 9}, {8, 8}, {9, 6} pairs to create all possible next level of number strings
            for(auto & [left, right] : hashmap)
            {
                //0 + number + 0
                //1 + number + 1
                //6 + number + 9
                //8 + number + 8
                //9 + number + 6
                helper(hashmap, low, high, to_string(left) + number + to_string(right), result);
            }
        }

        bool compare(string & first, string & second)
        {
            return (first.size() < second.size()) or (first.size()==second.size() and second >= first);
        }
};