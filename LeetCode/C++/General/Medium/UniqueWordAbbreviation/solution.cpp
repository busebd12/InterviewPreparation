#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class ValidWordAbbr
{
    private:
        unordered_map<string, unordered_set<string>> hashmap;
    
    public:
        ValidWordAbbr(vector<string> & dictionary) //O(d * w) [where d is the length of dictionary and w is the average length of a word in the dictionary]
        {
            for(string word : dictionary)
            {
                if(word.size() < 3)
                {
                    hashmap[word].insert(word);
                }
                else
                {
                    string abbreviation=getAbbreviation(word);

                    hashmap[abbreviation].insert(word);
                }
            }
        }
        
        bool isUnique(string word) //O(d)
        {
            string abbreviation=getAbbreviation(word);

            //If the abbreviation is unique and does not exist in the hashmap yet
            if(hashmap.find(abbreviation)==hashmap.end())
            {
                return true;
            }

            //If the abbreviation already in the hashmap, the only word that is allowed to have that abbreviation is the input word to this function
            if(hashmap[abbreviation].size()==1 and *(hashmap[abbreviation].begin())==word)
            {
                return true;
            }

            return false;
        }

        string getAbbreviation(string & word) //O(w) [where w is the average length of a word]
        {
            string abbreviation="";

            int w=word.size();

            abbreviation.push_back(word[0]);

            int count=w - 2;

            abbreviation.push_back((count % 10) + '0');

            count=count / 10;

            abbreviation.push_back((count % 10) + '0');

            count=count / 10;

            abbreviation.push_back(word[w - 1]);

            return abbreviation;
        }
};