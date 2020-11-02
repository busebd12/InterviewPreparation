#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*
 * Approach: we use a hashtable (vector of priority queues) to map each student's id to their test scores sorted in
 * ascending order. Then, for each student id, we calculate the average of their five highest test scores and place
 * the average and their student id into a vector. Then, we place that vector in our vector<vector<int>> result.
 * Return vector<vector<int>> result.
 *
 * Time complexity: O(n log n) [where n is the length of the input vector<vector<int>> & items]
 * Space complexity: O(n)
 */

vector<vector<int>> highFive(vector<vector<int>>& items)
{
    vector<vector<int>> result;

    if(items.empty())
    {
        return result;
    }

    vector<priority_queue<int>> hashtable(1001, priority_queue<int>());

    for(const auto & item : items)
    {
        int id=item[0];

        int score=item[1];

        hashtable[id].push(score);
    }

    for(auto id=0;id<hashtable.size();++id)
    {
        if(hashtable[id].size() > 0)
        {
            int scores=5;

            int total=0;

            int count=0;

            while(count < scores)
            {
                auto score=hashtable[id].top();

                hashtable[id].pop();

                total+=score;

                count++;
            }

            int average=(total/scores);

            result.push_back({id, average});
        }
    }

    return result;
}