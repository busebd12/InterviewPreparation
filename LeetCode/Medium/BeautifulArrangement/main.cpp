#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool isBeautiful(vector<int> & arrangement)
{
    int m=int(arrangement.size());

    int count=0;

    for(int i=1;i<=m;++i)
    {
        if((arrangement[i-1]%i)==0 || (i%arrangement[i-1])==0)
        {
            count++;
        }
    }

    return count==m;
}

void dfs(int N, vector<int> & arrangement, unordered_set<int> & numbers, int & count)
{
    if(arrangement.size()==N)
    {
        if(isBeautiful(arrangement))
        {
            count++;
        }
    }

    for(int i=1;i<=N;++i)
    {
        if(numbers.count(i))
        {
            continue;
        }

        arrangement.push_back(i);

        numbers.insert(i);

        dfs(N, arrangement, numbers, count);

        arrangement.pop_back();

        numbers.erase(i);
    }
}

int countArrangementTLE(int N)
{
    if(N <= 0)
    {
        return 0;
    }

    vector<int> arrangement(N);

    unordered_set<int> numbers;

    int count=0;

    int number=1;

    dfs(N, arrangement, numbers, count);

    return count;
}

void dfs(vector<bool> & visited, int N, int & count, int position)
{
    if(position > N)
    {
        count++;
    }

    for(int i=1;i<=N;++i)
    {
        if(!visited[i] && ((position%i)==0 || (i%position)==0))
        {
            visited[i]=true;

            dfs(visited, N, count, position+1);

            visited[i]=false;
        }
    }
}

int countArrangement(int N)
{
    if(N <= 0)
    {
        return 0;
    }

    int count=0;

    vector<bool> visited(N+1);

    int position=1;

    dfs(visited, N, count, position);

    return count;
}