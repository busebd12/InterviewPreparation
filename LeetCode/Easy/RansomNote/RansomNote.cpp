#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool canConstruct(string ransomeNote, string magazine)
{
    if(!ransomeNote.empty() && magazine.empty())
    {
        return false;
    }
    
    if(ransomeNote.empty() && magazine.empty())
    {
        return true;
    }
    
    if(ransomeNote.empty() && !magazine.empty())
    {
        return true;
    }

    unordered_map<char, int> magazineMap;

    unordered_map<char, int> ransomeNoteMap;

    for(const auto & letter : magazine)
    {
        magazineMap[letter]++;
    }

    for(const auto & letter : ransomeNote)
    {
        ransomeNoteMap[letter]++;
    }

    for(const auto & letter : ransomeNote)
    {
        if(magazineMap.find(letter)==end(magazineMap))
        {
            return false;
        }
        else
        {
            if(ransomeNoteMap[letter] > magazineMap[letter])
            {
                return false;
            }
        }
    }

    return true;
}