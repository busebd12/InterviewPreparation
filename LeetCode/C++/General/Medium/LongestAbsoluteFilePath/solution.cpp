#include <string>
#include <sstream>
#include <unordered_map>
using namespace std;

/*
Time complexity: O(n) [where n is the length of the input]
Space complexity: O(n)
*/

class Solution
{
    public:
        int lengthLongestPath(string input)
        {
            int result=0;
            
            unordered_map<int, int> hashtable;
    
            char delimeter='\n';

            string part{};

            stringstream ss(input);

            while(getline(ss, part, delimeter))
            {
                if(!part.empty())
                {
                    auto lastTabIndex=part.find_last_of('\t');

                    int tabs=0;

                    if(lastTabIndex!=string::npos)
                    {
                        tabs=(lastTabIndex - 0) + 1;
                    }

                    int lineLength=part.size() - tabs;

                    int priorLength=0;
                    
                    if(hashtable.find(tabs - 1)!=end(hashtable))
                    {
                        priorLength=hashtable[tabs - 1];
                    }

                    if(part.find('.')!=string::npos)
                    {
                        int filePathLength=priorLength + lineLength;
                        
                        result=max(result, filePathLength);
                    }

                    int updatedLength=priorLength + lineLength + 1;

                    hashtable[tabs]=updatedLength;
                }
            }
            
            return result;
        }
};