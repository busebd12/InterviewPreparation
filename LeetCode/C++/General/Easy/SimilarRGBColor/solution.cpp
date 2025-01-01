#include <cmath>
#include <limits>
#include <string>
#include <vector>
using namespace std;

/*
Solution: inspired by these posts

1) https://goodtecher.com/leetcode-800-similar-rgb-color/

2) https://leetcode.com/problems/similar-rgb-color/solutions/138448/simple-java-sol/

Time complexity: O(n)
Space complexity: O(n)
*/

class Solution
{
    public:
        string similarRGB(string color)
        {
            string result="#";

            int n=color.size();

            vector<string> shorthandCodes={"00", "11", "22", "33", "44", "55", "66", "77", "88", "99", "aa", "bb", "cc", "dd", "ee", "ff"};

            for(int i=1;i<n;i+=2)
            {
                string hex=color.substr(i, 2);

                int decimal=stoi(hex, nullptr, 16);

                int number=numeric_limits<int>::max();

                string part="";

                for(string shorthandCode : shorthandCodes)
                {
                    int shorthandCodeDecimal=stoi(shorthandCode, nullptr, 16);

                    int difference=abs(decimal - shorthandCodeDecimal);

                    if(difference < number)
                    {
                        number=difference;

                        part=shorthandCode;
                    }
                }

                result.append(part);
            }

            return result;
        }
};