#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

/*
 * Solution:
 *
 * The encode function works as follows
 *
 * Step 1 --> concatenate all the input strings together.
 * Step 2 --> Append a | and # character to the end of the encoded string.
 * Step 3 --> Append the sizes of each input string to the end of the encoded string. Each size is separated by the # character
 *
 * Time complexity: O((n * l) + n) [where n is the number of input string and l is the average length of each string]
 * Space complexity: O(e) [where e is the size of the encoded string]
 *
 * The decode function works as follows
 *
 * Step 1 --> Parse the lengths for all the input strings out from the encoded string and add them to a vector.
 * Step 2 --> Remove the | and # characters from the end of the encoded string.
 * Step 3 --> Iterate through each of the sizes and use the size to parse out the appropriate string from the remaining
 * encoded string and add it to the std::vector<std::string> result.
 *
 * Time complexity: O(e) [where e is the length of the encoded string]
 * Space complexity: O(n) [where n is the number of string sizes]
 *
 */

class Codec
{
    public:

        // Encodes a list of strings to a single string.
        std::string encode(std::vector<std::string> & strs)
        {
            std::string encoded{};

            if(strs.empty())
            {
                return encoded;
            }

            int n=int(strs.size());

            for(auto & str : strs)
            {
                if(str.empty())
                {
                    encoded+="empty";
                }
                else
                {
                    encoded+=str;
                }
            }

            encoded+='|';

            encoded+='#';

            for(int i=n-1;i>=0;i--)
            {
                encoded+=std::to_string(strs[i].size());

                encoded+='#';
            }

            encoded.pop_back();

            return encoded;
        }

        // Decodes a single string to a list of strings.
        std::vector<std::string> decode(std::string s)
        {
            std::vector<std::string> result;

            if(s.empty())
            {
                return result;
            }

            std::vector<int> lengths;

            std::string length{};

            while(!s.empty() && s.back()!='|')
            {
                if(s.back()=='#')
                {
                    std::reverse(length.begin(), length.end());

                    lengths.emplace_back(std::stoi(length));

                    length.clear();
                }
                else
                {
                    length+=s.back();
                }

                s.pop_back();
            }

            s.pop_back();


            int sSize=int(s.size());

            int i=0;

            for(auto & length : lengths)
            {

                std::string str{};

                if(length==0)
                {
                    for(int count=0;count<5&&i<sSize;count++,i++)
                    {
                        str+=s[i];
                    }
                }
                else
                {
                    for(int count=0;count<length&&i<sSize;count++,i++)
                    {
                        str+=s[i];
                    }
                }

                if(str=="empty")
                {
                    result.emplace_back("");
                }
                else
                {
                    result.emplace_back(str);
                }
            }

            return result;
        }
};