#include <iostream>
#include <vector>

/*
 * Solution: based on the following videos
 * https://www.youtube.com/watch?v=sqPTR_v4qFA
 * https://www.youtube.com/watch?v=-r1cL8lCLeM
 *
 * Time complexity: O(n) [where n is the length of the input data vector]
 * Space complexity: O(1)
 */

bool validUtf8(std::vector<int> & data)
{
    if(data.empty())
    {
        return false;
    }

    auto n=data.size();

    for(auto i=0;i<n;)
    {
        int bytes=0;

        if(data[i] >= 255)
        {
            return false;
        }
        else if((data[i] & 128)==0)
        {
            bytes=1;
        }
        else if((data[i] & 224)==192)
        {
            bytes=2;
        }
        else if((data[i] & 240)==224)
        {
            bytes=3;
        }
        else if((data[i] & 248)==240)
        {
            bytes=4;
        }
        else
        {
            return false;
        }

        int validNMinusOneBits=bytes-1;

        if(i + validNMinusOneBits > n-1)
        {
            return false;
        }

        for(auto j=i+1,count=0;count<validNMinusOneBits;++j,++count)
        {
            if((data[j] & 192)!=128)
            {
                return false;
            }
        }

        i+=bytes;
    }

    return true;
}