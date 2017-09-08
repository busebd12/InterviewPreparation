#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> constructRectangle(int area)
{
    unordered_map<int, pair<int, int>> table;

    vector<int> factors;

    vector<int> result;

    if(area==0)
    {
        return result;
    }

    for(int i=1;i<=area;++i)
    {
        if((area % i)==0)
        {   
            factors.emplace_back(i);
        }
    }

    const size_t factorsSize=factors.size();

    for(int x=factorsSize-1;x>=0;--x)
    {
        for(int y=factorsSize-1;y>=0;--y)
        {
            int length=factors[x];

            int width=factors[y];

            if(length*width==area)
            {
                if(length >= width)
                {
                    int difference=length-width;

                    pair<int, int> dimensions(length, width);

                    table.emplace(difference, dimensions);
                }
            }
        }
    }

    auto itr=min_element(begin(table), end(table), [](decltype(table)::value_type& l, decltype(table)::value_type& r) -> bool {return l.first < r.first;});

    result.emplace_back(itr->second.first);

    result.emplace_back(itr->second.second);

    return result;
}

vector<int> constructRectangle(int area)
{
	int w=sqrt(area);

	while((area % w)!=0)
	{
		--w;
	}

	return {area/w, w};
}