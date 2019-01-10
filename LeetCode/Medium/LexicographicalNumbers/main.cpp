#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

/*vector<int> lexicalOrder(int n)
{
    vector<int> result;

    if(n <= 0)
    {
        return result;
    }

    if(n==1)
    {
        result.emplace_back(n);

        return result;
    }

    vector<vector<string>> buckets(10, vector<string>());

    for(int number=1;number<=n;++number)
    {
        string s=to_string(number);

        int bucket=s[0]-'0';

        buckets[bucket].emplace_back(s);
    }

    for(auto & bucket : buckets)
    {
        sort(bucket.begin(), bucket.end());
    }

    for(auto & bucket : buckets)
    {
        for(auto & element : bucket)
        {
            int number=stoi(element);

            result.emplace_back(number);
        }
    }

    cout << "RESULT:" << endl;

    for(auto & number : result)
    {
        cout << number << " ";
    }

    cout << endl;

    return result;
}*/

/*vector<int> lexicalOrder(int n)
{
    vector<int> result;

    if(n <= 0)
    {
        return result;
    }

    if(n==1)
    {
        result.emplace_back(n);

        return result;
    }

    vector<set<string>> buckets(10, set<string>());

    for(int number=1;number<=n;++number)
    {
        string s=to_string(number);

        int bucket=s[0]-'0';

        buckets[bucket].insert(s);
    }

    for(auto & bucket : buckets)
    {
        for(auto & element : bucket)
        {
            int number=stoi(element);

            result.emplace_back(number);
        }
    }

    cout << "RESULT:" << endl;

    for(auto & number : result)
    {
        cout << number << " ";
    }

    cout << endl;

    return result;
}*/

vector<int> lexicalOrder(int n)
{
    vector<int> result;

    static map<string, int> ordered;

    auto orderedSize=int(ordered.size());

    if(orderedSize < n)
    {
        for(int number=orderedSize+1;number<n+1;++number)
        {
            ordered[to_string(number)]=number;
        }
    }

    for(auto & element : ordered)
    {
        if(element.second < n+1)
        {
            result.emplace_back(element.second);
        }
    }

    return result;
}

int main()
{
    int n=100;

    lexicalOrder(n);
}