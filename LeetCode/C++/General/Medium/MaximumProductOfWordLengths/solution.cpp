#include <string>
#include <vector>
using namespace std;

/*
Time complexity: O(n^2 * l) [where n is the number of words and l is the average length of a word]
Space complexity: O(n)
*/

class Solution
{
    public:
        int maxProduct(vector<string> & words)
        {
            int result=0;
            
            int n=words.size();
            
            for(int i=0;i<n;i++)
            {
                //Store the frequencies for the letters in words[i]
                vector<int> frequencies(26, 0);
                
                for(char letter : words[i])
                {
                    int index=letter - 'a';
                    
                    frequencies[index]+=1;
                }
                
                for(int j=i+1;j<n;j++)
                {
                    bool shareCommonLetters=false;
                    
                    for(char letter : words[j])
                    {
                        int index=letter - 'a';
                        
                        //If a letter from words[j] also appears in words[i], then these two words share common letters
                        if(frequencies[index] > 0)
                        {
                            shareCommonLetters=true;
                            
                            break;
                        }
                    }
                    
                    //Found two words that don't share common letters
                    if(shareCommonLetters==false)
                    {
                        int length=words[i].size() * words[j].size();
                        
                        result=max(result, length);
                    }
                }
            }
            
            return result;
        }
};