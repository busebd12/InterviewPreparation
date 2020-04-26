#include <cctype>
#include <deque>
#include <iostream>
#include <string>
#include <vector>

/*
 * Solution: we iterate through the digits of the input number and add chunks of three to a deque. If we can't get three
 * digits, we pad the front of the deque with zeroes until we have three digits. We are using a deque since we need
 * to iterate over the digits from left-to-right in order to form the English version. Once we have three digits in the
 * deque, we convert those three numbers into the English word/words version. Then, we append the resulting string to
 * the front of our output string since we read the words from left-to-right.
 *
 * Time complexity: O(d^2 + l) [where d is the number of digits in the input number and l is the length of the output string]
 * Space complexity: O(d)
 */

std::string chunkToEnglish(std::deque<int> & chunk, std::vector<std::string> & onesPlace, std::vector<std::string> & tensPlace, std::vector<std::string> & multiplesOfTen, std::string & ending)
{
    std::string english{};

    auto n=int(chunk.size());

    for(auto i=0;i<n;++i)
    {
        int digit=chunk[i];

        if(i==0)
        {
            if(digit==0)
            {
                continue;
            }
            else
            {
                english+=onesPlace[digit];

                english+=" ";

                english+="Hundred";

                english+=" ";
            }
        }
        else if(i==1)
        {
            if(digit==0)
            {
                continue;
            }
            else
            {
                if(digit==1)
                {
                    english+=tensPlace[chunk[i+1]];
                }
                else
                {
                    english+=multiplesOfTen[digit];

                    if(chunk[i+1] > 0)
                    {
                        english+=" ";

                        english+=onesPlace[chunk[i+1]];
                    }
                }

                i+=2;
            }
        }
        else
        {
            if(digit==0)
            {
                continue;
            }

            english+=onesPlace[digit];
        }
    }

    if(!english.empty())
    {
        if(!std::isspace(english.back()))
        {
            english+=" ";
        }

        english+=ending;

        english+=" ";
    }

    return english;
}

std::string numberToWords(int num)
{
    if(num==0)
    {
        return "Zero";
    }

    std::string result{};

    std::vector<std::string> onesPlace={"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};

    std::vector<std::string> tensPlace={"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

    std::vector<std::string> multiplesOfTen={"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    int count=1;

    std::string ending{};

    std::deque<int> chunk;

    while(num)
    {
        switch(count)
        {
            case 2:
                ending="Thousand";
                break;

            case 3:
                ending="Million";
                break;

            case 4:
                ending="Billion";
                break;

            default:
                break;
        }

        while(num && chunk.size() < 3)
        {
            chunk.emplace_front(num % 10);

            num/=10;
        }

        if(num==0)
        {
            break;
        }

        std::string subproblem=chunkToEnglish(chunk, onesPlace, tensPlace, multiplesOfTen, ending);

        if(!subproblem.empty())
        {
            result=subproblem + result;
        }

        chunk.clear();

        count++;
    }

    while(chunk.size() < 3)
    {
        chunk.emplace_front(0);
    }

    std::string last=chunkToEnglish(chunk, onesPlace, tensPlace, multiplesOfTen, ending);

    if(!last.empty())
    {
        result=last + result;
    }

    while(!result.empty() && std::isspace(result.back()))
    {
        result.pop_back();
    }

    return result;
}