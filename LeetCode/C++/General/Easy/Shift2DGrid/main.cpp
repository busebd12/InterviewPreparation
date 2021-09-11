#include <deque>
#include <iostream>
#include <vector>
using namespace std;

/*
 * Approach: we place all the numbers from the grid into a deque.
 * Then, we remove the last element from the deque and place it at the front of the deque k times.
 * This is the rotation step. Finally, we move the elements of the deque to our vector<vector<int>> result
 * and then return result.
 *
 * Time complexity: O((n * m) + k) [where n is the number rows in the grid; m is the number of columns in the grid; k is number of rotations]
 * Space complexity: O(n * m)
 */

vector<vector<int>> shiftGrid(vector<vector<int>> & grid, int k)
{
    deque<int> dq;

    vector<vector<int>> result;

    auto n=grid.size();

    auto m=grid[0].size();

    for(const auto & row : grid)
    {
        for(const auto & number : row)
        {
            dq.push_back(number);
        }
    }

    for(int count=0;count<k;++count)
    {
        int last=dq.back();

        dq.pop_back();

        dq.push_front(last);
    }

    for(auto i=0;i<n;++i)
    {
        vector<int> row;

        for(auto j=0;j<m;++j)
        {
            row.emplace_back(dq.front());

            dq.pop_front();
        }

        result.push_back(row);
    }

    return result;
}