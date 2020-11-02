#include <deque>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

/*
 * Solutions:
 *
 * 1. As we loop through the input number, we do the following
 *
 * a. Convert each digit to its full number
 * b. If the number is already in our hashtable, then add the corresponding Roman string the number maps to to our deque
 * c. If the number is not in the hashtable, then build the corresponding Roman string using the numbers in the numbers vector and strings in our hashtable.
 * After the string is built, add it to our deque.
 *
 * After we have finishing looping through our input number, build our result string using all the strings in the deque.
 *
 * Time complexity: O(d) [where d is the number of digits in our input number]
 * Space complexity: O(1)
 *
 * 2. Same logic as the first solution just using a vector<string> instead of unordered_map<int, string> for our hashtable.
 *
 * Time complexity: O(d) [where d is the number of digits in the input number]
 * Space complexity: O(1)
 */

std::string intToRoman(int num)
{
    std::string result{};

    std::deque<std::string> dq;

    std::unordered_map<int, std::string> hashtable={{1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"}, {10, "X"}, {40, "XL"}, {50, "L"}, {90, "XC"}, {100, "C"}, {400, "CD"}, {500, "D"}, {900, "CM"}, {1000, "M"}};

    std::vector<int> numbers={1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};

    int power=0;

    while(num > 0)
    {
        int number=static_cast<int>(pow(10, power));

        number*=num % 10;

        if(hashtable.count(number))
        {
            dq.push_front(hashtable[number]);
        }
        else
        {
            std::string str{};

            auto i=numbers.size()-1;

            while(number > 0)
            {
                while(number >= numbers[i])
                {
                    str+=hashtable[numbers[i]];

                    number-=numbers[i];
                }

                i--;
            }

            dq.push_front(str);
        }

        power++;

        num/=10;
    }

    while(!dq.empty())
    {
        result+=dq.front();

        dq.pop_front();
    }

    return result;
}

std::string intToRoman(int num)
{
    std::string result{};

    std::deque<std::string> dq;

    std::vector<std::string> hashtable(4000);

    hashtable[1]="I";

    hashtable[4]="IV";

    hashtable[5]="V";

    hashtable[9]="IX";

    hashtable[10]="X";

    hashtable[40]="XL";

    hashtable[50]="L";

    hashtable[90]="XC";

    hashtable[100]="C";

    hashtable[400]="CD";

    hashtable[500]="D";

    hashtable[900]="CM";

    hashtable[1000]="M";

    std::vector<int> numbers={1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};

    int power=0;

    while(num > 0)
    {
        int number=static_cast<int>(pow(10, power));

        number*=num % 10;

        if(hashtable[number]!="")
        {
            dq.push_front(hashtable[number]);
        }
        else
        {
            std::string str{};

            auto i=numbers.size()-1;

            while(number > 0)
            {
                while(number >= numbers[i])
                {
                    str+=hashtable[numbers[i]];

                    number-=numbers[i];
                }

                i--;
            }

            dq.push_front(str);
        }

        power++;

        num/=10;
    }

    while(!dq.empty())
    {
        result+=dq.front();

        dq.pop_front();
    }

    return result;
}