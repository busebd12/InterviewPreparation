#include <memory>
#include <string>
#include <vector>
using namespace std;

/*
Solution 1: brute force recursive backtracking. Note, this solution receives Time Limit Exceeded when run.
*/

class Solution
{
    public:
        vector<vector<string>> wordSquares(vector<string> & words)
        {
            vector<vector<string>> result;

            int sideLength=words[0].size();

            vector<string> square;

            helper(words, result, square, sideLength);

            return result;
        }

        void helper(vector<string> & words, vector<vector<string>> & result, vector<string> & square, int sideLength)
        {
            if(square.size()==sideLength)
            {
                if(isValidSquare(square, sideLength)==true)
                {
                    result.push_back(square);
                }

                return;
            }

            for(string & word : words)
            {
                square.push_back(word);

                helper(words, result, square, sideLength);

                square.pop_back();
            }
        }

        bool isValidSquare(vector<string> & square, int sideLength)
        {
            for(int k=0;k<sideLength;k++)
            {
                for(int index=0;index<sideLength;index++)
                {
                    if(square[k][index]!=square[index][k])
                    {
                        return false;
                    }
                }
            }

            return true;
        }
};

/*
Solution 2: Trie + recursive backtracking
*/

struct TrieNode
{
    vector<unique_ptr<TrieNode>> children;

    vector<string> wordsWithThisPrefix;

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

        void addWord(string & word)
        {
            TrieNode* node=root.get();

            for(char letter : word)
            {
                int asciiIndex=letter - 'a';

                if(node->children[asciiIndex]==nullptr)
                {
                    node->children[asciiIndex]=make_unique<TrieNode>();
                }

                node->wordsWithThisPrefix.push_back(word);

                node=node->children[asciiIndex].get();
            }

            node->endOfWord=true;
        }

        vector<string> getWordsThatStartWithPrefix(string & prefix)
        {
            vector<string> words;

            TrieNode* node=root.get();

            for(char letter : prefix)
            {
                int asciiIndex=letter - 'a';

                if(node->children[asciiIndex]==nullptr)
                {
                    return words;
                }

                node=node->children[asciiIndex].get();
            }

            for(string & word : node->wordsWithThisPrefix)
            {
                words.push_back(word);
            }

            return words;
        }

        TrieNode* getRoot()
        {
            return root.get();
        }
};

class Solution
{
    public:
        vector<vector<string>> wordSquares(vector<string> & words)
        {
            vector<vector<string>> result;

            int sideLength=words[0].size();

            vector<string> square;

            Trie trie;

            for(string & word : words)
            {
                trie.addWord(word);
            }

            for(string & word : words)
            {
                square.push_back(word);

                helper(words, result, trie, square, sideLength);

                square.pop_back();
            }

            return result;
        }

        void helper(vector<string> & words, vector<vector<string>> & result, Trie & trie, vector<string> & square, int sideLength)
        {
            if(square.size()==sideLength)
            {
                result.push_back(square);

                return;
            }

            int index=square.size();

            string prefix="";

            for(string & word : square)
            {
                prefix.push_back(word[index]);
            }

            vector<string> nextWords=trie.getWordsThatStartWithPrefix(prefix);

            if(nextWords.empty())
            {
                return;
            }

            for(string & nextWord : nextWords)
            {
                square.push_back(nextWord);

                helper(words, result, trie, square, sideLength);

                square.pop_back();
            }
        }
};

/*
Solution 3: trie + recursive backtracking
*/


struct TrieNode
{
    vector<unique_ptr<TrieNode>> children;

    vector<int> wordsWithThisPrefix;

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

        void addWord(string & word, int index)
        {
            TrieNode* node=root.get();

            for(char letter : word)
            {
                int asciiIndex=letter - 'a';

                if(node->children[asciiIndex]==nullptr)
                {
                    node->children[asciiIndex]=make_unique<TrieNode>();
                }

                node->wordsWithThisPrefix.push_back(index);

                node=node->children[asciiIndex].get();
            }

            node->endOfWord=true;
        }

        vector<string> getWordsThatStartWithPrefix(vector<string> & words, string & prefix)
        {
            vector<string> targetWords;

            TrieNode* node=root.get();

            for(char letter : prefix)
            {
                int asciiIndex=letter - 'a';

                if(node->children[asciiIndex]==nullptr)
                {
                    return targetWords;
                }

                node=node->children[asciiIndex].get();
            }

            for(int index : node->wordsWithThisPrefix)
            {
                targetWords.push_back(words[index]);
            }

            return targetWords;
        }

        TrieNode* getRoot()
        {
            return root.get();
        }
};

class Solution
{
    public:
        vector<vector<string>> wordSquares(vector<string> & words)
        {
            vector<vector<string>> result;

            int w=words.size();

            int sideLength=words[0].size();

            vector<string> square;

            Trie trie;

            for(int index=0;index<w;index++)
            {
                trie.addWord(words[index], index);
            }

            for(string & word : words)
            {
                square.push_back(word);

                helper(words, result, trie, square, sideLength);

                square.pop_back();
            }

            return result;
        }

        void helper(vector<string> & words, vector<vector<string>> & result, Trie & trie, vector<string> & square, int sideLength)
        {
            if(square.size()==sideLength)
            {
                result.push_back(square);

                return;
            }

            int index=square.size();

            string prefix="";

            for(string & word : square)
            {
                prefix.push_back(word[index]);
            }

            vector<string> nextWords=trie.getWordsThatStartWithPrefix(words, prefix);

            if(nextWords.empty())
            {
                return;
            }

            for(string & nextWord : nextWords)
            {
                square.push_back(nextWord);

                helper(words, result, trie, square, sideLength);

                square.pop_back();
            }
        }
};