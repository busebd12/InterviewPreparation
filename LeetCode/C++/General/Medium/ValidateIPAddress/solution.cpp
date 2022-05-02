#include <algorithm>
#include <sstream>
#include <string>

/*
Time complexity: O(n) [where n is the length of queryIP]
Space complexity: O(n)
*/

class Solution
{
    public:
        bool isValidIPv6Part(string part)
        {
            if(part.size() > 4)
            {
                return false;
            }
            
            auto compareLikeThis=[] (char c)
            {
                return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
            };
            
            return all_of(begin(part), end(part), compareLikeThis);
        }
    
        bool isValidIPv4Octet(string octet)
        {
            if(all_of(begin(octet), end(octet), [] (char & c) {return isdigit(c);})==false)
            {
                return false;
            }
            
            if(octet.size() > 3)
            {
                return false;
            }
            
            if(stoi(octet) > 255 || (octet[0]=='0' && octet.size() > 1))
            {
                return false;
            }
            
            return true;
        }
    
        string validIPAddress(string queryIP)
        {
            string result="";
            
            bool hasPeriods=false;
            
            if(queryIP.find('.')!=string::npos)
            {
                hasPeriods=true;
            }
            
            if(hasPeriods==true)
            {
                result="IPv4";
                
                int octets=0;
                
                stringstream ss(queryIP);
                
                string octet{};
                
                char delimeter='.';
                
                while(getline(ss, octet, delimeter))
                {
                    if(!octet.empty())
                    {   
                        if(isValidIPv4Octet(octet)==false)
                        {
                            result="Neither";
                            
                            break;
                        }
                        
                        octets+=1;
                    }
                }
                
                int periods=count(begin(queryIP), end(queryIP), '.');
                
                if(periods != 3 || octets != 4)
                {
                    result="Neither";
                }
            }
            else
            {
                result="IPv6";
                
                int parts=0;
                
                stringstream ss(queryIP);
                
                string part{};
                
                char delimeter=':';
                
                while(getline(ss, part, delimeter))
                {
                    if(!part.empty())
                    {
                        if(!isValidIPv6Part(part))
                        {
                            result="Neither";
                            
                            break;
                        }
                        
                        parts+=1;
                    }
                }
                
                int colons=count(begin(queryIP), end(queryIP), ':');
                
                if(colons != 7 || parts != 8)
                {
                    result="Neither";
                }
            }
            
            return result;
        }
};