#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <set>
#include <string>
#include <utility>
using namespace std;

class CuttingBitString
{
    public:
        string decimalToBinary(long Decimal)
        {   
            string binary{};
            
            while(Decimal!=0)
            {
                if(Decimal%2==0)
                {
                    binary.push_back('0');
                }
                else
                {
                    binary.push_back('1');
                }
                
                Decimal/=2;
            }
            
            reverse(begin(binary), end(binary));
            
            return binary;
        }
            
        void fillVector(vector<string> & PowersOfFive, int Length)
        {
            int exponent{};
            
            while(true)
            {
                long powerOfFive=pow(5, exponent);
                
                string powerOfFiveAsString=decimalToBinary(powerOfFive);
                
                if(powerOfFiveAsString.size() > Length)
                {
                    break;
                }
                else
                {   
                    PowersOfFive.emplace_back(powerOfFiveAsString);
                    
                    ++exponent;
                }
            }
        }
        
        int getMinHelper(string S, vector<string> PowersOfFive, size_t OriginalSize, int CharacterCount, int Count, bool FoundSubstring)
        {   
            if(S[S.size()-1]=='0')
            {   
                return -1;
            }
            
            if(Count==0)
            {
                auto search=find(begin(PowersOfFive), end(PowersOfFive), S);
                
                if(search!=end(PowersOfFive))
                {
                    return 1;
                }
            }
            
            if(CharacterCount==OriginalSize)
            {   
                return Count;
            }
            
            if(Count > 0 && !FoundSubstring)
            {   
                return -1;
            }
            
            int counter{};
            
            for(int index=PowersOfFive.size()-1;index>=0;--index)
            {
                ++counter;
                
                string::size_type location=S.find(PowersOfFive[index]);
                
                if(location!=string::npos)
                {   
                    int substringLength=PowersOfFive[index].size();
                    
                    S.erase(location, substringLength);
                    
                    ++Count;
                    
                    CharacterCount+=substringLength;
                    
                    FoundSubstring=true;
                    
                    break;
                }
            }
            
            if(counter==PowersOfFive.size() && FoundSubstring!=true)
            {
                FoundSubstring=false;
            }
            
            return getMinHelper(S, PowersOfFive, OriginalSize, CharacterCount, Count, FoundSubstring);
        }
    
        int getMin(string S)
        {
            vector<string> powersOfFive;
            
            fillVector(powersOfFive, S.size());
            
            int count{};
            
            int characterCount{};
            
            bool foundSubstring=false;
            
            size_t originalSize=S.size();
            
            int answer=getMinHelper(S, powersOfFive, originalSize, count, characterCount, foundSubstring);
            
            return answer;
        }
};