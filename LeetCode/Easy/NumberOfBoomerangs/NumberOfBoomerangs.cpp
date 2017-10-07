#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>

int numberOfBoomerangs(vector<pair<int, int>> & points)
{
    int result=0;

    const size_t pointsSize=points.size();

    for(int index=0;index<pointsSize;++index)
    {
    	unordered_map<long, int> distanceMap(pointsSize);

    	for(int j=0;j<pointsSize;++j)
    	{
    		if(i==j)
    		{
    			continue
    		}
    		else
    		{
    			int dy=points[i].second-points[j].second;

    			int dx=points[i].first-points[j].first;

    			int Distance=(dy*dy)+(dx*dx);

    			++distanceMap[Distance];
    		}
    	}

    	for(const auto & element : distanceMap)
    	{
    		if(element.second > 1)
    		{
    			result+=(element.second*(element.second-1));
    		}
    	}
    }

    return result;
}