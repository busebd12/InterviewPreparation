#include <array>
#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>

/*
 * Solutions:
 *
 * 1. We use two classes: TrieNode and Trie. TrieNode has the following members
 *
 * a. a boolean endOfWord to mark where the inserted word ends
 * b. a std::unordered_map<char, std::unique_ptr<TrieNode>> to store the current nodes children in the trie
 *
 * The Trie class has the following
 *
 * a. A pointer to the root TrieNode
 *
 * b. The insert function. To insert a string, we start from the root node and keep adding missing characters from the string
 * into the trie until we reach the end of the string. When we reach the end, we set the last nodes endOfWord boolean to true.
 * This marks this node as the end of the inserted word.
 *
 * Time complexity: O(s) [where s is the length of the input string]
 * Space complexity: O(s)
 *
 * c. The search function. To search for a string, we simply iterate through the string and check if the trie contains each character.
 * When we reach a letter that is not in the trie, we return false. Once we reach the end of the string, we return true.
 *
 * Time complexity: O(s) [where s is the length of the input string]
 * Space complexity: O(1)
 *
 * d. The startsWith function. This functions checks if a prefix is in the trie. The logic is the same as the search function.
 *
 * Time complexity: O(p) [where p is the length of the prefix to search for]
 * Space complexity: O(1)
 *
 * 2. Almost the same as the first solution except we use a std::vector<std::unique_ptr<TrieNode>> to hold children of
 * a TrieNode instead of an std::unordered_map.
 *
 * 3. lmost the same as the first solution except we use a std::array<std::unique_ptr<TrieNode>> to hold children of
 * a TrieNode instead of an std::unordered_map.
 */

struct TrieNode
{
    bool endOfWord;

    std::unordered_map<char, std::unique_ptr<TrieNode>> children;

    TrieNode()
    {
        endOfWord=false;
    }
};

class Trie
{
    std::unique_ptr<TrieNode> root;

    public:
        Trie()
        {
            root=std::make_unique<TrieNode>();
        }

        void insert(std::string word)
        {
            auto node=root.get();

            for(const auto & letter : word)
            {
                if(!node->children.count(letter))
                {
                    node->children[letter]=std::make_unique<TrieNode>();
                }

                node=node->children[letter].get();
            }

            node->endOfWord=true;
        }

        bool search(std::string word)
        {
            auto node=root.get();

            for(const auto & letter : word)
            {
                if(!node->children.count(letter))
                {
                    return false;
                }

                node=node->children[letter].get();
            }

            return node->endOfWord;
        }

        bool startsWith(std::string prefix)
        {
            auto node=root.get();

            for(const auto & letter : prefix)
            {
                if(!node->children.count(letter))
                {
                    return false;
                }

                node=node->children[letter].get();
            }

            return true;
        }
};

struct TrieNode
{
    bool endOfWord;

    std::array<std::unique_ptr<TrieNode>, 26> children;

    TrieNode()
    {
        endOfWord=false;
    }
};

class Trie
{
    std::unique_ptr<TrieNode> root;

    public:
        Trie()
        {
            root=std::make_unique<TrieNode>();
        }

        void insert(std::string word)
        {
            auto node=root.get();

            for(const auto & letter : word)
            {
                int index=letter - 'a';

                if(node->children[index]==nullptr)
                {
                    node->children[index]=std::make_unique<TrieNode>();
                }

                node=node->children[index].get();
            }

            node->endOfWord=true;
        }

        bool search(std::string word)
        {
            auto node=root.get();

            for(const auto & letter : word)
            {
                int index=letter - 'a';

                if(node->children[index]==nullptr)
                {
                    return false;
                }

                node=node->children[index].get();
            }

            return node->endOfWord;
        }

        bool startsWith(std::string prefix)
        {
            auto node=root.get();

            for(const auto & letter : prefix)
            {
                int index=letter - 'a';

                if(node->children[index]==nullptr)
                {
                    return false;
                }

                node=node->children[index].get();
            }

            return true;
        }
};

struct TrieNode
{
    bool endOfWord;

    std::vector<std::unique_ptr<TrieNode>> children;

    TrieNode()
    {
        endOfWord=false;

        children.resize(26);
    }
};

class Trie
{
    std::unique_ptr<TrieNode> root;

    public:
        Trie()
        {
            root=std::make_unique<TrieNode>();
        }

        void insert(std::string word)
        {
            auto node=root.get();

            for(const auto & letter : word)
            {
                int index=letter - 'a';

                if(node->children[index]==nullptr)
                {
                    node->children[index]=std::make_unique<TrieNode>();
                }

                node=node->children[index].get();
            }

            node->endOfWord=true;
        }

        bool search(std::string word)
        {
            auto node=root.get();

            for(const auto & letter : word)
            {
                int index=letter - 'a';

                if(node->children[index]==nullptr)
                {
                    return false;
                }

                node=node->children[index].get();
            }

            return node->endOfWord;
        }

        bool startsWith(std::string prefix)
        {
            auto node=root.get();

            for(const auto & letter : prefix)
            {
                int index=letter - 'a';

                if(node->children[index]==nullptr)
                {
                    return false;
                }

                node=node->children[index].get();
            }

            return true;
        }
};