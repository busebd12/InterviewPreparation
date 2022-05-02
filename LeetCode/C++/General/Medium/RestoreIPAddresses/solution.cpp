#include <deque>
#include <string>
using namespace std;

class Solution
{
    public:
        bool isValid(deque<string> & octets)
        {
            for(auto & octet : octets)
            {
                //Each octet needs to be less than or equal to 255 and can only have one zero
                if(stoi(octet) > 255 || octet[0]=='0' && octet.size() > 1)
                {
                    return false;
                }
            }
            
            return true;
        }
    
        void dfs(vector<string> & result, string s, int n, deque<string> & octets, int index)
        {
            //If we reached the end of the input string
            if(index==n)
            {
                //IP address is made up of four octets
                if(octets.size()==4 && isValid(octets))
                {   
                    result.emplace_back(octets[0] + "." + octets[1] + "." + octets[2] + "." + octets[3]);
                }
            }
            
            //Length of the input string remaining
            int remaining=(n - index);
            
            //Each octet can have a max length of three
            for(int length=1;length<=3;length++)
            {
                //Make sure the length of the substring will not ne more than the length of the remaining input string
                if(length <= remaining)
                {
                    string octet=s.substr(index, length);

                    octets.push_back(octet);

                    dfs(result, s, n, octets, index + length);

                    octets.pop_back();
                }
            }
        }
    
        vector<string> restoreIpAddresses(string s)
        {
            vector<string> result;
            
            int n=s.size();
            
            deque<string> octets;
            
            int index=0;
            
            dfs(result, s, n, octets, index);
            
            return result;
        }
};