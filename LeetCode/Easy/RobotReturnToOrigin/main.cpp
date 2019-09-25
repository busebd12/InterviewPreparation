#include <iostream>
#include <string>
#include <utility>
using namespace std;

/*
 * Approach: Start with a pair representing a coordinate point set to (0, 0).
 * Then, for each letter move in the string, update the pair accordingly.
 * After the robot finishes all its movies, if we end up back where we started, i.e.
 * the point is (0, 0), then the robot returned to its origin.
 *
 * Time complexity: O(n) [where n is the length fo the input string]
 * Space complexity: O(1)
 */

bool judgeCircle(string moves)
{
    if(moves.empty())
    {
        return true;
    }

    pair<int, int> start(0, 0);

    for(const char & move : moves)
    {
        if(move=='U')
        {
            start.first++;
        }
        else if(move=='D')
        {
            start.first--;
        }
        else if(move=='L')
        {
            start.second--;
        }
        else if(move=='R')
        {
            start.second++;
        }
        else
        {
            continue;
        }
    }

    return start.first==0 && start.second==0;
}