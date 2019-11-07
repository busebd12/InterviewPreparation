#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/*
 * Approaches:
 *
 * 1. For each trust vector, we map each person to all the different people they trust in a hashtable (unordered_map<int, unordered_set<int>>).
 * Then, in order to satisfy the criteria to the be the town judge, a person must trust no one. In other words, that person
 * cannot be a key in our hashtable. Otherwise, there "trust" would hash to at least one person. Next, everyone else must trust the town judge.
 * In terms of our hashtable, this means that all other keys must have the judge in their unordered_set<int> that they map to.
 *
 * Time complexity: O(N + J) [where N is the number of people in the town and J is the number of potential judges]
 * Space complexity: O(N + J)
 *
 *
 * 2. If we look at this problem as a graph problem, then for each trust pair, a to b, that represents one degree/edge leaving
 * vertex a and one degree/edge entering into b. Once we frame the problem this way, our solution is to find the vertex that
 * has N-1 degrees/edges going into it (aka everyone trusts that person) and zero edges/degrees leaving it (aka this person doesn't trust anyone).
 *
 * Time complexity: O(N + T) [where N is the number of people in the town and T is the length of the trusts data structure]
 * Space complexity: O(N)
 */

 bool everybodyTrustsJudge(const unordered_map<int, unordered_set<int>> & hashtable, const int & judge)
{
    bool everybodyTrusts=true;

    for(const auto & element : hashtable)
    {
        if(!element.second.count(judge))
        {
            everybodyTrusts=false;

            break;
        }
    }

    return everybodyTrusts;
}

int findJudge(int N, vector<vector<int>> & trust)
{
    int judge=-1;

    if(N <= 0)
    {
        return judge;
    }

    if(trust.empty())
    {
        return N;
    }

    unordered_map<int, unordered_set<int>> hashtable;

    for(const auto & v : trust)
    {
        hashtable[v[0]].insert(v[1]);
    }

    unordered_set<int> judgeCandidates;

    for(int person=1;person<=N;++person)
    {
        if(!hashtable.count(person))
        {
            judgeCandidates.insert(person);
        }
    }

    if(judgeCandidates.empty())
    {
        return judge;
    }

    for(auto itr=judgeCandidates.begin();itr!=judgeCandidates.end();)
    {
        if(everybodyTrustsJudge(hashtable, *itr))
        {
            ++itr;
        }
        else
        {
            itr=judgeCandidates.erase(itr);
        }
    }

    if(!judgeCandidates.empty() && judgeCandidates.size()==1)
    {
        judge=(*(judgeCandidates.begin()));
    }

    return judge;
}

int findJudge(int N, vector<vector<int>>& trust)
{
    vector<int> inDegrees(N+1, 0);

    vector<int> outDegrees(N+1, 0);

    int judge=-1;

    int T=int(trust.size());

    for(int index=0;index<T;++index)
    {
        inDegrees[trust[index][1]]++;

        outDegrees[trust[index][0]]++;
    }

    for(int i=1;i<=N;++i)
    {
        if(inDegrees[i]==N-1 && outDegrees[i]==0)
        {
            judge=i;

            break;
        }
    }

    return judge;
}