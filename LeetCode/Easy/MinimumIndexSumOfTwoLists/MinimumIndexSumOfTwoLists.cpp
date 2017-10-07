vector<string> findRestaurant(vector<string>& list1, vector<string>& list2)
{
    vector<string> answer;

    if(list1.empty() || list2.empty())
    {
        return answer;
    }

    unordered_map<string, pair<int, int>> cache;

    const size_t list1Size=list1.size();

    const size_t list2Size=list2.size();

    for(int i=0;i<list1Size;++i)
    {
        auto indexCountPair=make_pair(1, i);

        cache.insert(make_pair(list1[i], indexCountPair));
    }

    for(int j=0;j<list2Size;++j)
    {
        string choice=list2[j];

        if(cache.find(choice)!=end(cache))
        {
            cache[choice].first++;

            cache[choice].second+=j;
        }
    }

    int indexSum=list1Size-1 + list2Size-1;

    for(const auto & element : cache)
    {
        if(element.second.first >= 2)
        {
            if(element.second.second < indexSum)
            {
                indexSum=element.second.second;
            }
        }
    }

    for(const auto & element : cache)
    {
        if(element.second.first >= 2)
        {
            if(element.second.second==indexSum)
            {
                answer.emplace_back(element.first);   
            }
        }
    }

    return answer;
}