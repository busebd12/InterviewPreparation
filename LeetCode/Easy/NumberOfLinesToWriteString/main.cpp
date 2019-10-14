#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 * Approach: For each letter in S, add its width to the current line width. If the current line width
 * becomes greater than the line width limit, 100, then, we increment the number of lines and add the overflow
 * width to the next line's width. If the current line width is equal to the line limit, 100, then we increase
 * the number of lines and reset the current line width. After looping over the string, the first spot in result vector
 * will be the number of lines and the second spot will be the width of the last line.
 *
 * Time complexity: O(n) [where n is the length of the string S]
 * Space complexity: O(1)
 */

vector<int> numberOfLines(vector<int> & widths, string S)
{
    vector<int> result(2, 0);

    if(widths.empty() || S.empty())
    {
        return result;
    }

    int lines=0;

    int limit=100;

    int currentLineWidth=0;

    for(char & letter : S)
    {
        int letterWidth=widths[((letter - 'a') % 26)];

        currentLineWidth+=letterWidth;

        if(currentLineWidth > limit)
        {
            lines++;

            currentLineWidth=letterWidth;
        }
        else if(currentLineWidth==limit)
        {
            lines++;

            currentLineWidth=0;
        }
    }

    result[0]=(currentLineWidth > 0) ? lines+1 : lines;

    result[1]=currentLineWidth;

    return result;
}