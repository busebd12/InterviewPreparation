#include <string>
#include <vector>
using namespace std;

class Solution
{
    public:
        string shiftingLetters(string s, vector<int> & shifts)
        {
            int n=s.size();
            
            for(int i=n-2;i>=0;i--)
            {
                shifts[i]=(shifts[i + 1] + shifts[i]) % 26;
            }
            
            for(int i=0;i<n;i++)
            {
                int asciiValue=s[i] - 'a';
                
                int shiftedAsciiValue=asciiValue + shifts[i];
                
                shiftedAsciiValue=shiftedAsciiValue % 26;
                
                char shiftedLetter=char(shiftedAsciiValue + 'a');
                
                s[i]=shiftedLetter;
            }
            
            return s;
        }
};