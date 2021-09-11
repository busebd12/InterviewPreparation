#include <iostream>
#include <memory>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

/*
 * Solution: the idea is to use a trie (prefix tree) to store all the sentences. Then, as the user types in their
 * input string, we find all the strings in the trie that have the input string as a prefix and add them to a maxHeap
 * of pairs, where each pair is a sentence and its frequency.
 *
 * Time complexities:
 * AutocompleteSystem constructor: O(s * l) [where s the total number of sentences and l is the average length of a sentences]
 * Input function: O(p + q) [where p is the total length of the input prefix and q is the total number of nodes in the trie traversed for the input prefix]
 *
 * Space complexity: O(s * l + (m * log(m))) [where m is the total number of hot sentences to return based on each prefix]
 */
class AutocompleteSystem
{
    private:
        class TrieNode
        {
        public:
            bool endOfWord;

            std::string sentence;

            int frequency;

            std::unordered_map<char, std::unique_ptr<TrieNode>> children;

            TrieNode()
            {
                endOfWord=false;

                sentence="";

                frequency=0;
            }
        };

        void insert(std::string & sentence, int & times)
        {
            auto node=root.get();

            for(const auto & letter : sentence)
            {
                if(!node->children.count(letter))
                {
                    node->children[letter]=std::make_unique<TrieNode>();
                }

                node=node->children[letter].get();
            }

            node->endOfWord=true;

            node->sentence=sentence;

            node->frequency+=times;
        }

        bool contains(std::string & prefix)
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

    public:
        std::unique_ptr<TrieNode> root;

        TrieNode* current;

        std::string prefix;

        struct comparator
        {
            bool operator() (const std::pair<std::string, int> & p1, const std::pair<std::string, int> & p2)
            {
                if(p1.second!=p2.second)
                {
                    return p1.second < p2.second;
                }
                return p1.second==p2.second && p1.first > p2.first;
            }
        };

        std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, comparator> maxHeap;

        AutocompleteSystem(std::vector<std::string> & sentences, std::vector<int> & times)
        {
            root=std::make_unique<TrieNode>();

            for(auto i=0;i<sentences.size();++i)
            {
                insert(sentences[i], times[i]);
            }

            current=root.get();

            prefix="";
        }

        void dfsIterative(TrieNode* node)
        {
            std::stack<TrieNode*> stk;

            stk.push(node);

            while(!stk.empty())
            {
                auto current=stk.top();

                stk.pop();

                if(current->sentence!="")
                {
                    maxHeap.emplace(std::make_pair(current->sentence, current->frequency));
                }

                for(auto & child : current->children)
                {
                    stk.push(child.second.get());
                }
            }
        }

        void dfs(TrieNode* node)
        {
            if(node->sentence!="")
            {
                maxHeap.emplace(std::make_pair(node->sentence, node->frequency));
            }

            for(auto & child : node->children)
            {
                dfs(child.second.get());
            }
        }

        std::vector<std::string> input(char c)
        {
            std::vector<std::string> top3;

            if(c=='#')
            {
                int times=1;

                insert(prefix, times);

                prefix="";

                current=root.get();
            }
            else
            {
                prefix+=c;

                if(current!=nullptr && current->children.count(c))
                {
                    current=current->children[c].get();

                    dfs(current);

                    while(!maxHeap.empty() && top3.size() < 3)
                    {
                        auto top=maxHeap.top();

                        top3.push_back(top.first);

                        maxHeap.pop();
                    }

                    while(!maxHeap.empty())
                    {
                        maxHeap.pop();
                    }
                }
                else
                {
                    current=nullptr;
                }
            }

            return top3;
        }
};
