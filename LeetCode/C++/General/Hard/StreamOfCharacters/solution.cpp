#include <memory>
#include <string>
#include <vector>
using namespace std;

struct TrieNode
{
    vector<unique_ptr<TrieNode>> children;

    bool endOfWord;

    TrieNode()
    {
        children.resize(26);

        endOfWord=false;
    }
};

class Trie
{
    private:
        unique_ptr<TrieNode> root;

    public:
        Trie()
        {
            root=make_unique<TrieNode>();
        }

        //Adds a word to the trie in reverse order
        //We add a word in reverse order because we are looking for suffixes instead of prefixes
        //In other words, at the same time we are iterating backwards through the stream, we will
        //be iterating backwards through words in the trie
        void addWord(const string & word)
        {
            TrieNode* node=root.get();

            for(int i=word.size()-1;i>=0;i--)
            {
                int asciiIndex=word[i] - 'a';

                if(node->children[asciiIndex]==nullptr)
                {
                    node->children[asciiIndex]=make_unique<TrieNode>();
                }

                node=node->children[asciiIndex].get();
            }

            node->endOfWord=true;
        }

        bool containsSuffix(deque<char> & stream)
        {
            int n=stream.size();

            TrieNode* node=root.get();

            for(int index=n-1;index>=0;index--)
            {
                int asciiIndex=stream[index] - 'a';

                //If the current trie node does not have the letter
                if(node->children[asciiIndex]==nullptr)
                {
                    return false;
                }

                node=node->children[asciiIndex].get();

                //If we've the reverse end of a word (the beginning) then we know this suffix exists in the trie
                if(node->endOfWord==true)
                {
                    return true;
                }
            }

            //At this point, we've iterated through all letters in the stream and no valid suffixes have been found in the trie
            return false;
        }

        TrieNode* getRoot() const
        {
            return root.get();
        }
};

class StreamChecker
{
    private:
        Trie trie;
        
        deque<char> stream;
    
    public:
        StreamChecker(vector<string> & words)
        {
            for(string & word : words)
            {
                trie.addWord(word);
            }
        }
        
        bool query(char letter)
        {
            stream.push_back(letter);

            return trie.containsSuffix(stream);
        }
};