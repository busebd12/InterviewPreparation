#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <vector>
using namespace std;

bool validIPv4Block(string & block)
{
    int number=0;

    if(block.size() > 0 && block.size() <= 3)
    {
        for(int i=0;i<block.size();++i)
        {
            char c=block[i];

            if(!isdigit(c) || (i==0 && c=='0' && block.size() > 1))
            {
                return false;
            }
            else
            {
                number*=10;

                number+=c-'0';
            }
        }

        return number <= 255;
    }

    return false;
}

bool validIPv6Block(string & block, string & validIPv6Chars)
{
    if(block.size() > 0 && block.size() <= 4)
    {
        for(int i=0;i<block.size();++i)
        {
            char c=block[i];

            if(validIPv6Chars.find(c)==string::npos)
            {
                return false;
            }
        }

        return true;
    }

    return false;
}

string validIPAddress(string IP)
{
    vector<string> answer={"IPv4", "IPv6", "Neither"};

    stringstream parser(IP);

    string block{};

    if(IP.substr(0, 4).find('.')!=string::npos)
    {
        for(int i=0;i<4;++i)
        {
            if(!getline(parser, block, '.') || !validIPv4Block(block))
            {
                return answer[2];
            }
        }

        return parser.eof() ? answer[0] : answer[2];
    }
    else if(IP.substr(0, 5).find(':')!=string::npos)
    {
        string validIPv6Chars="0123456789abcdefABCDEF";

        for(int i=0;i<8;++i)
        {
            if(!getline(parser, block, ':') || !validIPv6Block(block, validIPv6Chars))
            {
                return answer[2];
            }
        }

        return parser.eof() ? answer[1] : answer[2];
    }

    return answer[2];
}