#include <iostream>
#include <unordered_map>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class WordDictionary
{
    public:
        class Dictionary
        {
            public:
                unordered_map<int, vector<string>> dictionary;

                void addWord(string word)
                {
                    size_t wordSize=word.size();

                    if(wordSize!=0)
                    {
                        if(dictionary.find(wordSize)==dictionary.end())
                        {
                            dictionary.insert(make_pair(wordSize, vector<string>()));

                            dictionary[wordSize].emplace_back(word);
                        }
                        else
                        {
                            dictionary[wordSize].emplace_back(word);
                        }
                    }
                }

                bool isSame(string first, string second)
                {
                    size_t firstSize=first.size();

                    size_t secondSize=second.size();

                    if(firstSize!=secondSize)
                    {
                        return false;
                    }

                    for(size_t i=0;i<firstSize;++i)
                    {
                        if(first[i]!=second[i] && second[i]!='.')
                        {
                            return false;
                        }
                    }

                    return true;
                }

                bool search(string word)
                {
                    if(word.empty())
                    {
                        return false;
                    }

                    size_t wordSize=word.size();

                    if(dictionary.find(wordSize)==dictionary.end())
                    {
                        return false;
                    }

                    for(auto & w : dictionary[wordSize])
                    {
                        if(isSame(w, word))
                        {
                            return true;
                        }
                    }

                    return false;
                }
        };

        unique_ptr<Dictionary> d;

        WordDictionary()
        {
            d=make_unique<Dictionary>();
        }

        void addWord(string word)
        {
            d->addWord(word);
        }

        bool search(string word)
        {
            return d->search(word);
        }
};