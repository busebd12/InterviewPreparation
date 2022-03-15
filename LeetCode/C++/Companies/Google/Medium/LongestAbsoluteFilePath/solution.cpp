#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <utility>
using namespace std;

/*
Solution: see comments

Time complexity: O(n) [where n is the length of the input string]
Space complexity: O(n) [where n is the length of the input string]
*/

class Solution
{
    public:
        int lengthLongestPath(string input)
        {
            int result=0;
    
            int pathLength=0;

            deque<pair<int, int>> stack;

            stringstream ss(input);

            string line{};

            char divider='\n';

            //We tokenize the input string by the divider '\n'
            while(getline(ss, line, divider))
            {
                //Count the number of '\t' characters in line to determine the level in the filesystem to which it belongs
                int level=count(begin(line), end(line), '\t');

                //Erase all '\t' characters but leave spaces (spaces are valid characters)
                line.erase(remove_if(begin(line), end(line), [](char & c) {return c=='\t';}), end(line));

                //If the current level is less than or equal to the current level we are at in the filesystem heirarchy,
                //then there are two scenarios: 1) there are more than one things in the current directory or 2) the current
                //level is above where we are in the filesystem and we need to go back up
                if(!stack.empty() && level <= stack.back().first)
                {
                    //Remove items from the stack that share the same level or till we reach the first level that is above where we are in the filesystem heirarchy
                    while(!stack.empty() && level <= stack.back().first)
                    {
                        pathLength-=stack.back().second;

                        stack.pop_back();
                    }
                }

                //Search for a '.' in the line
                auto dotIndex=line.find('.');

                //If the line contains a dot, it is a file
                bool isFile=(dotIndex!=string::npos);

                //Add the line size to the pathLength
                pathLength+=line.size();

                if(isFile)
                {
                    //We've reached a file, so compute the max file length
                    result=max(result, pathLength);

                    //Add the level and the length of the line
                    stack.emplace_back(level, line.size());
                }
                else
                {
                    //The current line is a directory, so we need to add 1 to the line size to account for the trailing '/' character
                    stack.emplace_back(level, line.size() + 1);

                    //Add 1 to pathLength to accouont for the trailing '/' character
                    pathLength+=1;
                }
            }

            return result;
        }
};