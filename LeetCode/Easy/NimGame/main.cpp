#include <iostream>
using namespace std;

/*
 * Approach: https://leetcode.com/problems/nim-game/discuss/73749/Theorem%3A-all-4s-shall-be-false
 *
 * Time complexity: O(1)
 * Space complexity: O(1)
 */
bool canWinNim(int n)
{
    return ((n % 4)!=0);
}