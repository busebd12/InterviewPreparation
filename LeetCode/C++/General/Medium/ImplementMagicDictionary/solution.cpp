#include <string>
#include <vector>
using namespace std;

class MagicDictionary
{
    private:
        vector<string> words;
    
    public:
        MagicDictionary()
        {
            
        }

        void buildDict(vector<string> dictionary)
        {
            for(string & word : dictionary)
            {
                words.push_back(word);
            }
        }

        bool search(string searchWord)
        {
            for(string & word : words)
            {
                if(word.size()==searchWord.size())
                {
                    if(canChange(word, searchWord)==true)
                    {
                        return true;
                    }
                }
            }
            
            return false;
        }
    
        bool canChange(string & word, string & searchWord)
        {
            int differences=0;
            
            int w=word.size();
            
            for(int i=0;i<w;i++)
            {
                if(word[i]!=searchWord[i])
                {
                    differences+=1;
                }
            }
            
            return differences==1;
        }
};