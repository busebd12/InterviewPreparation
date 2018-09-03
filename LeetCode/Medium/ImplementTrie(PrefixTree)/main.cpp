#include <iostream>
#include <unordered_map>
#include <memory>
using namespace std;

class Trie
{
    public:
        class TrieNode
        {
            public:
                unordered_map<char, TrieNode*> children;

                bool endOfWord;
        };

        TrieNode* root;

        Trie()
        {
            root=new TrieNode();
        }

        ~Trie()
        {
            delete root;
        }

        void insert(string word)
        {
            TrieNode* current=root;

            for(size_t i=0;i<word.size();++i)
            {
                if(current->children.find(word[i])!=current->children.end())
                {
                    current=current->children[word[i]];

                    if(i==word.size()-1)
                    {
                        current->endOfWord=true;
                    }
                }
                else
                {
                    TrieNode* temp=new TrieNode();

                    temp->endOfWord=(i==word.size()-1) ? true : false;

                    current->children[word[i]]=temp;

                    current=temp;
                }
            }
        }

        bool search(string word)
        {
            TrieNode* current=root;

            for(size_t i=0;i<word.size();++i)
            {
                if(current->children.find(word[i])!=current->children.end())
                {
                    current=current->children[word[i]];
                }
                else
                {
                    return false;
                }
            }

            return current->endOfWord ? true : false;
        }

        bool startsWith(string word)
        {
            TrieNode* current=root;

            for(size_t i=0;i<word.size();++i)
            {
                if(current->children.find(word[i])!=current->children.end())
                {
                    current=current->children[word[i]];
                }
                else
                {
                    return false;
                }
            }

            return true;
        }
};

int main()
{

}