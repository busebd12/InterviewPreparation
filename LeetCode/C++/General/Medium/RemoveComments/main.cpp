#include <iostream>
#include <string>
#include <vector>

/*
 * Inspired from the following solution: https://leetcode.com/problems/remove-comments/discuss/109216/Simple-C%2B%2B-Solution-One-pass-with-explanation
 *
 * Time complexity: O(c) [where c is the total number of characters]
 * Space complexity: O(m) [where m is the total number of non-comment related characters]
 */

class Solution
{
    public:
        std::vector<std::string> removeComments(std::vector<std::string> & source)
        {
            std::vector<std::string> result;

            if(source.empty())
            {
                return source;
            }

            std::string str{};

            int n=int(source.size());

            bool comment=false;

            for(const auto & line : source)
            {
                int m=int(line.size());

                for(int i=0;i<m;i++)
                {
                    if(!comment && i + 1 < m && line[i]=='/' && line[i + 1]=='/')
                    {
                        break;
                    }
                    else if(!comment && i + 1 < m && line[i]=='/' && line[i + 1]=='*')
                    {
                        comment=true;

                        i++;
                    }
                    else if(comment && i + 1 < m && line[i]=='*' && line[i + 1]=='/')
                    {
                        comment=false;

                        i++;
                    }
                    else if(!comment)
                    {
                        str+=line[i];
                    }
                }

                if(!comment && str.size() > 0)
                {
                    result.emplace_back(str);

                    str.clear();
                }
            }

            return result;
        }
};