#include <iostream>
#include <vector>
#include <map>
using namespace std;

void resetTable(multimap<char, pair<int, bool>> & table)
{
    for(auto & element : table)
    {
        if(element.second.second==true)
        {
            element.second.second=false;
        }
    }
}

int countRowsUsed(multimap<char, pair<int, bool>> & table)
{
    bool rowOne=false;

    bool rowTwo=false;

    bool rowThree=false;

    for(const auto & element : table)
    {
        if(element.second.first==1)
        {
            if(element.second.second==true)
            {
                if(!rowOne)
                {
                    rowOne=true;
                }
            }
        }
        else if(element.second.first==2)
        {
            if(element.second.second==true)
            {
                if(!rowTwo)
                {
                    rowTwo=true;
                }
            }
        }
        else if(element.second.first==3)
        {
            if(element.second.second==true)
            {
                if(!rowThree)
                {
                    rowThree=true;
                }
            }
        }
    }

    int count=0;

    if(rowOne && rowTwo && rowThree)
    {
        return 3;
    }
    else if(!rowOne && rowTwo && rowThree)
    {
        return 2;
    }
    else if(rowOne && !rowTwo && rowThree)
    {
        return 2;
    }
    else if(rowOne && rowTwo && !rowThree)
    {
        return 2;
    }
    else if(rowOne && !rowTwo && !rowThree)
    {
        return 1;
    }
    else if(!rowOne && rowTwo && !rowThree)
    {
        return 1;
    }
    else if(!rowOne && !rowTwo && rowThree)
    {
        return 1;
    }

    return count;
}

vector<string> findWords(vector<string> & words)
{
    vector<string> result;

    if(words.empty())
    {
        return result;
    }

    multimap<char, pair<int, bool>> table;

    table.emplace('q', make_pair(1, false));
    
    table.emplace('Q', make_pair(1, false));

    table.emplace('w', make_pair(1, false));
    
    table.emplace('W', make_pair(1, false));

    table.emplace('e', make_pair(1, false));
    
    table.emplace('E', make_pair(1, false));

    table.emplace('r', make_pair(1, false));
    
    table.emplace('R', make_pair(1, false));

    table.emplace('t', make_pair(1, false));
    
    table.emplace('T', make_pair(1, false));

    table.emplace('y', make_pair(1, false));
    
    table.emplace('Y', make_pair(1, false));

    table.emplace('u', make_pair(1, false));
    
    table.emplace('U', make_pair(1, false));

    table.emplace('i', make_pair(1, false));
    
    table.emplace('I', make_pair(1, false));

    table.emplace('o', make_pair(1, false));
    
    table.emplace('O', make_pair(1, false));

    table.emplace('p', make_pair(1, false));
    
    table.emplace('P', make_pair(1, false));

    table.emplace('a', make_pair(2, false));
    
    table.emplace('A', make_pair(2, false));

    table.emplace('s', make_pair(2, false));
    
    table.emplace('S', make_pair(2, false));

    table.emplace('d', make_pair(2, false));
    
    table.emplace('D', make_pair(2, false));

    table.emplace('f', make_pair(2, false));
    
    table.emplace('F', make_pair(2, false));

    table.emplace('g', make_pair(2, false));
    
    table.emplace('G', make_pair(2, false));

    table.emplace('h', make_pair(2, false));
    
    table.emplace('H', make_pair(2, false));

    table.emplace('j', make_pair(2, false));
    
    table.emplace('J', make_pair(2, false));

    table.emplace('k', make_pair(2, false));
    
    table.emplace('K', make_pair(2, false));

    table.emplace('l', make_pair(2, false));
    
    table.emplace('L', make_pair(2, false));

    table.emplace('z', make_pair(3, false));
    
    table.emplace('Z', make_pair(3, false));

    table.emplace('x', make_pair(3, false));
    
    table.emplace('X', make_pair(3, false));

    table.emplace('c', make_pair(3, false));
    
    table.emplace('C', make_pair(3, false));

    table.emplace('v', make_pair(3, false));
    
    table.emplace('V', make_pair(3, false));

    table.emplace('b', make_pair(3, false));
    
    table.emplace('B', make_pair(3, false));

    table.emplace('n', make_pair(3, false));
    
    table.emplace('N', make_pair(3, false));

    table.emplace('m', make_pair(3, false));
    
    table.emplace('M', make_pair(3, false));

    const size_t wordsSize=words.size();

    for(int index=0;index<wordsSize;++index)
    {
        const size_t wordSize=words[index].size();

        string word=words[index];

        for(int i=0;i<wordSize;++i)
        {   
            char letter=word[i];

            auto searchResult=table.find(letter);

            if(table.find(letter)!=end(table))
            {
                if(!(searchResult->second.second))
                {
                    searchResult->second.second=true;
                }
            }
        }

        int rowsUsed=countRowsUsed(table);

        if(rowsUsed==1)
        {   
            result.emplace_back(word);
        }

        resetTable(table);
    }

    return result;
}