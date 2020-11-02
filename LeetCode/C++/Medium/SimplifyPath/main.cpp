#include <iostream>
#include <sstream>
#include <string>
#include <vector>

/*
 * Solution: we use a stringstream object and getline to split the input path on the "/" characters.
 * We also use a vector to keep track of the valid parts of our path. Then, we have some cases to consider
 * while iterating over the string
 *
 * 1. we see the character . --> do nothing
 * 2. we see the characters .. --> if our stack has at least one directory in it, then remove that directory
 * 3. anything else gets added to our stack
 *
 * After storing the canonical path in our vector, we remove the trailing / character (if there is one).
 * Finally, we put the contents of our vector into our string result variable and return the result.
 *
 * Time complexity: O(n) [where n is the length of the input string]
 * Space complexity: O(n)
 */

std::string simplifyPath(std::string path)
{
    std::string result{};

    if(path.empty())
    {
        return result;
    }

    if(path[0]!='/')
    {
        return result;
    }

    std::vector<std::string> stack={"/"};

    std::stringstream ss(path);

    std::string buffer{};

    char slash='/';

    while(std::getline(ss, buffer, slash))
    {
        if(!buffer.empty())
        {
            if(buffer.size()==1)
            {
                if(buffer!=".")
                {
                    stack.push_back(buffer);

                    stack.emplace_back("/");
                }
            }
            else if(buffer.size()==2)
            {
                if(buffer=="..")
                {
                    if(stack.size() >= 3)
                    {
                        stack.pop_back();

                        stack.pop_back();
                    }
                }
                else
                {
                    stack.push_back(buffer);

                    stack.emplace_back("/");
                }
            }
            else
            {
                stack.push_back(buffer);

                stack.emplace_back("/");
            }
        }
    }

    if(stack.size() > 1)
    {
        stack.pop_back();
    }

    for(const auto & element : stack)
    {
        result+=element;
    }

    return result;
}