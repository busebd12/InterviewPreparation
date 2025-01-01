#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

/*
 * Approach:
 * Find the shortest length string.
 * Then, loop over the shortest string, adding characters to the common prefix as we go,
 * until we find a character that is not shared by the other strings.
 *
 * Time Complexity: O(m * n) [where m is the length of the shortest string and n is the number of input strings]
 *
 * Space Complexity: O(1) [if we don't count the length of the resulting longest common prefix]
 */

bool isCommon(vector<string> & strs, char current, int index)
{
    for(string & str : strs)
    {
        if(str[index]!=current)
        {
            return false;
        }
    }

    return true;
}

string longestCommonPrefix(vector<string> & strs)
{
    if(strs.empty())
    {
        return "";
    }

    if(strs.size()==1)
    {
        return strs[0];
    }

    string result="";

    string prefix="";

    int shortestLength=numeric_limits<int>::max();

    for(string & s : strs)
    {
        if(int(s.size()) <= shortestLength)
        {
            shortestLength=int(s.size());
        }
    }

    string shortest="";

    for(string & s : strs)
    {
        if(int(s.size())==shortestLength)
        {
            shortest=s;

            break;
        }
    }

    for(int i=0;i<shortestLength;++i)
    {
        char current=shortest[i];

        if(isCommon(strs, current, i))
        {
            prefix+=current;
        }
        else
        {
            result=prefix;

            prefix.clear();

            break;
        }
    }

    if(result.empty() && prefix.size() > 0)
    {
        result=prefix;
    }

    return result;
}

/*
3/2/2023 solution using Trie
*/

class TrieNode
{
    private:
        vector<unique_ptr<TrieNode>> children;

        int nonNullChildren;

        char firstNonNullLetter;

        bool endOfWord;

    public:
        TrieNode()
        {
            children.resize(26);
            
            nonNullChildren=0;

            firstNonNullLetter='$';

            endOfWord=false;
        }

        vector<unique_ptr<TrieNode>> & getChildren()
        {
            return children;
        }

        int getNonNullChildren()
        {
            return nonNullChildren;
        }

        void incrementNonNullChildren()
        {
            nonNullChildren+=1;
        }

        char getFirstNonNullLetter()
        {
            return firstNonNullLetter;
        }

        void setFirstNonNullLetter(char letter)
        {
            firstNonNullLetter=letter;
        }

        bool getEndOfWord()
        {
            return endOfWord;
        }

        void setEndOfWord()
        {
            endOfWord=true;
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

        void insert(string & word)
        {
            TrieNode* node=root.get();

            for(char letter : word)
            {
                int asciiIndex=letter - 'a';

                if(node->getChildren()[asciiIndex]==nullptr)
                {
                    node->getChildren()[asciiIndex]=make_unique<TrieNode>();

                    if(node->getNonNullChildren()==0)
                    {
                        node->setFirstNonNullLetter(letter);
                    }

                    node->incrementNonNullChildren();
                }

                node=node->getChildren()[asciiIndex].get();
            }

            node->setEndOfWord();
        }

        string getLongestCommonPrefix()
        {
            string prefix="";

            TrieNode* node=root.get();

            while(node!=nullptr)
            {
                if(node->getEndOfWord()==true or node->getNonNullChildren() > 1)
                {
                    break;
                }

                char letter=node->getFirstNonNullLetter();

                prefix.push_back(letter);

                int asciiIndex=letter - 'a';

                node=node->getChildren()[asciiIndex].get();
            }

            return prefix;
        }
};

class Solution
{
    public:
        string longestCommonPrefix(vector<string> & strs)
        {
            string result="";

            Trie trie;

            for(string str : strs)
            {
                trie.insert(str);
            }

            result=trie.getLongestCommonPrefix();

            return result;
        }
};