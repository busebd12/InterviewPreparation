#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <map>
#include <unordered_map>
using namespace std;

bool mapsAreEqual(const unordered_multimap<char, int> & m1, const unordered_multimap<string, int> & m2)
{
	return m1.size()==m2.size() && equal(begin(m1), end(m1), begin(m2), [] (const auto & element1, const auto & element2) {return element1.second==element2.second;});
}

bool wordPattern(string pattern, string str)
{
    if(pattern.empty() || str.empty())
    {
        return false;
    }
    
    unordered_multimap<char, int> patternMap;
    
    unordered_multimap<string, int> strMap;
    
    int count=1;
    
    for(int index=0;index<pattern.size();++index)
    {
    	char letter=pattern[index];
    	
    	if(patternMap.find(letter)==end(patternMap))
    	{
    		patternMap.emplace(letter, count);
    		
    		++count;
    	}
    	else
    	{
    		auto result=patternMap.find(letter);
    		
    		patternMap.emplace(make_pair(letter, result->second));
    	}
    }
    
    count=1;
    
    string currentWord{};
    
    for(int index=0;index<str.size();++index)
	{
		if(!isspace(str[index]))
		{
			currentWord+=str[index];
			
			if(index==str.size()-1)
			{
				if(strMap.find(currentWord)==end(strMap))
				{
					strMap.emplace(currentWord, count);
					
					++count;
				}
				else
				{
					auto result=strMap.find(currentWord);
					
					strMap.emplace(make_pair(currentWord, result->second));
				}
			}
		}
		else
		{
			if(strMap.find(currentWord)==end(strMap))
			{
				strMap.emplace(currentWord, count);
				
				++count;
			}
			else
			{
				auto result=strMap.find(currentWord);
				
				strMap.emplace(make_pair(currentWord, result->second));
			}
			
			currentWord.clear();
		}
	}
	
	return mapsAreEqual(patternMap, strMap);
}
