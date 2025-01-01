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


/*
1/13/2023 solution
*/

class Codec
{
    public:

        // Encodes a list of strings to a single string.
        string encode(vector<string> & strs)
        {
            string encoded="$";

            int n=strs.size();

            for(string & str : strs)
            {
                string compressed=getCompressedString(str);

                encoded.append(compressed);

                encoded.push_back('$');
            }

            return encoded;
        }

        // Decodes a single string to a list of strings.
        vector<string> decode(string s)
        {
            vector<string> words;

            stringstream wordStream(s);

            string token="";

            char wordDelimeter='$';

            while(getline(wordStream, token, wordDelimeter))
            {
                if(!token.empty())
                {
                    string word="";

                    stringstream letterStream(token);

                    string part="";

                    char letterDelimeter='|';

                    while(getline(letterStream, part, letterDelimeter))
                    {
                        if(!part.empty())
                        {
                            int poundIndex=part.find('#');

                            int times=stoi(part.substr(0, poundIndex));

                            string asciiString="";

                            char letter='$';

                            if(part.find('d')==string::npos)
                            {
                                asciiString=part.substr(poundIndex + 1, string::npos);

                                int ascii=stoi(asciiString);

                                letter=char(ascii);
                            }
                            else
                            {
                                letter=part.back();
                            }

                            for(int count=0;count<times;count++)
                            {
                                word.push_back(letter);
                            }
                        }
                    }

                    words.push_back(word);
                }
            }

            return words;
        }

        string getCompressedString(string & str)
        {
            string compressed="|";

            int L=str.size();

            int count=1;

            char character=str[0];

            for(int i=1;i<L;i++)
            {
                if(str[i]==character)
                {
                    count+=1;
                }
                else
                {
                    compressed.append(to_string(count));

                    compressed.push_back('#');

                    if(!isdigit(character))
                    {
                        int ascii=int(character);

                        compressed.append(to_string(ascii));
                    }
                    else
                    {
                        compressed.push_back('d');
                        
                        compressed.push_back(character);
                    }

                    compressed.push_back('|');

                    character=str[i];

                    count=1;
                }
            }

            if(count > 0)
            {
                compressed.append(to_string(count));

                compressed.push_back('#');

                if(!isdigit(character))
                {
                    int ascii=int(character);

                    compressed.append(to_string(ascii));
                }
                else
                {
                    compressed.push_back('d');
                    
                    compressed.push_back(character);
                }

                compressed.push_back('|');
            }

            return compressed;
        }
};