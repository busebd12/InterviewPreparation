#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int compareVersion(string version1, string version2)
{
    stringstream ss1(version1);

    stringstream ss2(version2);

    string line;

    vector<int> v1;

    vector<int> v2;

    while(getline(ss1, line, '.'))
    {
        v1.emplace_back(stoi(line));
    }

    while(getline(ss2, line, '.'))
    {
        v2.emplace_back(stoi(line));
    }

    while(v1.size() < v2.size())
    {
        v1.emplace_back(0);
    }

    while(v2.size() < v1.size())
    {
        v2.emplace_back(0);
    }

    int v1Size=int(v1.size());

    for(int i=0;i<v1Size;++i)
    {
        if(v1[i]!=v2[i])
        {
            return ((v1[i] > v2[i]) ? 1 : -1);
        }
    }

    return 0;
}