#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <ctime>
using namespace std;

class Solution
{
public:

    vector<int> numbers;

    Solution(vector<int> nums)
    {
        numbers=nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset()
    {
        return numbers;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle()
    {
        vector<int> unshuffled=numbers;

        random_device rd;

        mt19937 generator(rd());

        std::shuffle(unshuffled.begin(), unshuffled.end(), generator);

        return unshuffled;
    }
};