#include <deque>
#include <string>
#include <vector>

/*
Solution 1: see comments. Note, this solution gets Time Limit Exceeded when run.

Time complexity: O((high - low) + (d^2)) [where d is average number of digits per number in the range [low, high]]
Space complexity: O(t) [where t is the total number of digits from all the numbers in the range of [low, high]]
*/

class Solution
{
    public:
        vector<int> sequentialDigits(int low, int high)
        {
            vector<int> result{};
            
            //Iterate from low to high
            for(int number=low;number<=high;number++) //O(high - low)
            {
                //Holds the individual digits of the number
                deque<int> digits;

                int n=number;

                //Add the individual digits of the number to the deque
                while(n > 0) //O(d)
                {
                    int digit=n % 10;

                    digits.emplace_front(digit);

                    n/=10;
                }

                bool ascending=true;

                //Check to make sure that all the digits in the number fit the criteria
                for(int i=0;i<digits.size();i++) //O(d)
                {   
                    if(i + 1 < digits.size())
                    {
                        if((digits[i] + 1)!=digits[i + 1])
                        {
                            ascending=false;

                            break;
                        }
                    }
                }

                //If all the digits fit the criteria, then add the number to the result
                if(ascending)
                {   
                    result.emplace_back(number);
                }
            }

            return result;
        }
};

/*
Solution 2: see comments.

Time complexity: O(n * (d^2)) [where n is the difference between the lengths of the string versions of low and high and d is the length of the digits string]
Space complexity: O(d)
*/

class Solution
{
    public:
        vector<int> sequentialDigits(int low, int high)
        {
            vector<int> result;

            int lowLength=to_string(low).length();

            int highLength=to_string(high).length();

            string digits="123456789";

            int digitsLength=digits.length();

            while(lowLength <= highLength) //O(n) [where n is the difference between the lengths of the string versions of low and high]
            {
                for(int start=0;start+lowLength<=digitsLength;start++) //O(d) [where d is the length of digits]
                {
                    //Generate substrings of digits that start at length equal to the length of low and increasing in size until they reach the length of high
                    //Example: low=10 high=1000
                    //substrings:
                    //12, 23, 34, 45, 56, 67, 78, 89
                    //123, 234, 345, 456, 567, 789
                    //Convert the substring to a number
                    int number=stoi(digits.substr(start, lowLength)); //O(d)

                    //If the number is within the range of [low, high]
                    if(low <= number && number <= high)
                    {
                        //Add it to the result
                        result.emplace_back(number);
                    }
                }

                //Increment lowLength to generate the next length group of substrings
                lowLength+=1;
            }

            return result;
        }
};