#include <iostream>
#include <vector>
using namespace std;

/*
 * Approach: while there are candies left, keep distributing candies to the next person in increasing amounts by one candy each time.
 * After distributing the amount of candy subtract it from the overall candy supply. If we get to a case where the amount of candy
 * to distribute to the current person is more than the amount of candy we have left, just give that person the rest of the candy.
 *
 * Time complexity: O(candies * num_people) [where candies is the amount of candy to start with and num_people is the number of people we are giving candy to]
 * Space complexity: O(num_people)
 *
 */

vector<int> distributeCandies(int candies, int num_people)
{
    vector<int> result(num_people, 0);

    int candy=1;

    bool done=false;

    while(!done)
    {
        for(auto i=0;i<num_people;++i)
        {
            if(candies==0)
            {
                done=true;

                break;
            }

            if(candies < candy)
            {
                result[i]+=candies;

                candies=0;
            }
            else
            {
                result[i]+=candy;

                candies-=candy;

                candy++;
            }
        }
    }

    return result;
}