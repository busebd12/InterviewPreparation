#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int doWork(int N)
{
    unordered_map<int, unordered_set<int>> cache;

    for(int i=1;i<=N;++i)
    {
        for(int j=1;j<=N;++j)
        {
            if(i!=j)
            {
                if(!cache.count(i))
                {
                    cache.insert(make_pair(i, unordered_set<int>()));

                    if(!cache.count(j))
                    {
                        cache[i].insert(j);
                    }
                }
                else
                {
                    if(cache.count(j))
                    {
                        if(cache[j].find(i)==cache[j].end() || cache[j].empty())
                        {
                            cache[i].insert(j);
                        }
                    }
                    else
                    {
                        cache[i].insert(j);
                    }
                }
            }
        }
    }

    int count=0;

    for(auto element : cache)
    {
        if(!element.second.empty())
        {
            for(auto & number : element.second)
            {
                int current=(element.first ^ number);

                if(current <= N)
                {
                    count++;
                }
            }
        }
    }

    return count;
}

int doWork(int N)
{
    int count=0;

    for(int i=1;i<=N;++i)
    {
        for(int j=i+1;j<=N;++j)
        {
            int current=(i ^ j);

            if(current <= N)
            {
                count++;
            }
        }
    }

    return count;
}

int main(int argc, char** argv)
{
    int T=0;

    cin >> T;

    for(int testCase=0;testCase<T;++testCase)
    {
        int N=0;

        cin >> N;

        cout << doWork(N) << endl;
    }

    return 0;
}