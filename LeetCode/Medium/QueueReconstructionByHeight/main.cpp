#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

struct Compare
{
    constexpr bool operator()(pair<int, int> & a, pair<int, int> & b) const noexcept
    {
        return a.first < b.first || (a.first==b.first && a.second > b.second);
    }
};

vector<pair<int, int>> reconstructQueue(vector<pair<int, int>> & people)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

    for(auto & person : people)
    {
        pq.push(person);
    }

    vector<pair<int, int>> answer;

    while(!pq.empty())
    {
        answer.insert(answer.begin() + pq.top().second, pq.top());

        pq.pop();
    }

    return answer;
}