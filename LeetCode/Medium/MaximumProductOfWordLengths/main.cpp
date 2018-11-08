#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cmath>
#include <iterator>
using namespace std;

int maxProduct(vector<string> & words)
{
    int maxProduct=0;

    if(words.size() <= 1)
    {
        return maxProduct;
    }

    unordered_map<int, int> table;

    int n=(int)words.size();

    for(int i=0;i<n;++i)
    {
        int fingerprint=0;

        for(auto & letter : words[i])
        {
            int shiftedResult=(1 << (letter - 'a'));

            fingerprint|=shiftedResult;
        }

        if(!table.count(fingerprint) || words[i].size() > words[table[fingerprint]].size())
        {
            table[fingerprint]=i;
        }
    }

    for(auto itr1=table.begin();itr1!=table.end();++itr1)
    {
        for(auto itr2=next(itr1, 1);itr2!=table.end();++itr2)
        {
            int result=(itr1->first & itr2->first);

            if(result==0)
            {
                maxProduct=max(maxProduct, static_cast<int>(words[itr1->second].size() * words[itr2->second].size()));
            }
        }
    }

    return maxProduct;
}