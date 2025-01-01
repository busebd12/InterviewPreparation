#include <vector>
using namespace std;

/*
Solution: binary search.

Time complexity: O(f log f) [where f is the length of fonts]
Space complexity: O(1)
*/

class Solution
{
    public:
        int maxFont(string text, int w, int h, vector<int> & fonts, FontInfo fontInfo)
        {
            int result=-1;

            int f=fonts.size();

            int low=0;

            int high=f - 1;

            while(low <= high)
            {
                int middle=(low + (high - low)/2);

                int fontSize=fonts[middle];

                if(canFitTextOnScreen(text, w, h, fontInfo, fontSize)==true)
                {
                    result=fontSize;

                    low=middle + 1;
                }
                else
                {
                    high=middle - 1;
                }
            }

            return result;
        }

        bool canFitTextOnScreen(string & text, int w, int h, FontInfo & fontInfo, int fontSize)
        {
            int totalWidth=0;

            for(char character : text)
            {   
                int characterWidth=fontInfo.getWidth(fontSize, character);

                int characterHeight=fontInfo.getHeight(fontSize);

                totalWidth+=characterWidth;

                if(totalWidth > w or characterHeight > h)
                {
                    return false;
                }
            }

            return true;
        }
};