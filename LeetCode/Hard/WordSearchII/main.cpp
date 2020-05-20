#include <array>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

/*
 * Solutions:
 *
 * 1. Brute force. For each word, we search for it in the board using recursion + backtracking.
 * If we find it, then we add it to our list of found words. At the end, we return the list of found
 * words.
 *
 * Time complexity: O(w * l * rows * colums) [where w is the total number of words; l is the average length of a word; rows is the number of rows in the board;
 * columns is the number of columns on the baord]
 *
 * Space complexity: O(rows * columns)
 *
 * 2. Recursion, backtracking, and a Trie. We put all the words into a Trie. Then, for each letter in the board,
 * we check to see if that letter is present in the Trie. If it is, we try to recursively walk as far as we can
 * down the path in the Trie starting from that letter as we recursively traverse the board. If we ever reach the
 * end of a path in the Trie for a particular word, we add the word to our list of found words. At the end, we return
 * all the found words.
 *
 * Time complexity: O(w * l) [where w is the total number of words and l is the average length of each word]
 * Space complexity: O(w) [where w is the total number of words]
 */

class Solution
{
    public:

        bool onBoard(int rows, int columns, int row, int column)
        {
            return ((row >= 0 && row < rows) && (column >= 0 && column < columns));
        }

        bool backtracking(std::vector<std::vector<char>> & board, std::string & word, int rows, int columns, int row, int column, int index)
        {
            if(index==word.size())
            {
                return true;
            }

            if(!onBoard(rows, columns, row, column))
            {
                return false;
            }

            if(board[row][column]!=word[index])
            {
                return false;
            }

            char currentState=board[row][column];

            board[row][column]='#';

            bool result=(backtracking(board, word, rows, columns, row-1, column, index+1) || backtracking(board, word, rows, columns, row+1, column, index+1) || backtracking(board, word, rows, columns, row, column-1, index+1) || backtracking(board, word, rows, columns, row, column+1, index+1));

            board[row][column]=currentState;

            return result;
        }

        bool exist(std::vector<std::vector<char>> & board, std::string & word)
        {
            int rows=int(board.size());

            int columns=int(board[0].size());

            int index=0;

            for(auto row=0; row<rows; ++row)
            {
                for(auto column=0; column<columns; ++column)
                {
                    if(backtracking(board, word, rows, columns, row, column, index))
                    {
                        return true;
                    }
                }
            }

            return false;
        }

        std::vector<std::string> findWords(std::vector<std::vector<char>> & board, std::vector<std::string> & words)
        {
            std::vector<std::string> result;

            if(board.empty()||words.empty())
            {
                return result;
            }

            for(auto &word : words)
            {
                if(exist(board, word))
                {
                    result.emplace_back(word);
                }
            }

            return result;
        }
};


class Solution
{
    private:
        struct TrieNode
        {
            bool endOfWord;

            bool found;

            std::string word;

            std::array<std::unique_ptr<TrieNode>, 26> children;

            TrieNode()
            {
                endOfWord=false;

                found=false;

                word="";
            }
        };

        std::unique_ptr<TrieNode> root;

        void insert(std::string & word)
        {
            TrieNode* node=root.get();

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

            node->word=word;
        }

    public:
        Solution()
        {
            root=std::make_unique<TrieNode>();
        }

        bool onBoard(int & rows, int & columns, int row, int column)
        {
            return ((row >= 0 && row < rows) && (column >= 0 && column < columns));
        }

        void dfs(std::vector<std::vector<char>> & board, std::vector<std::string> & result, TrieNode* node, int rows, int columns, int row, int column)
        {
            if(node==nullptr)
            {
                return;
            }

            node=node->children[board[row][column] - 'a'].get();

            if(node!=nullptr)
            {
                if(node->endOfWord==true)
                {
                    if(node->found==false)
                    {
                        node->found=true;

                        result.emplace_back(node->word);
                    }
                }
            }

            char currentState=board[row][column];

            board[row][column]='#';

            std::array<std::pair<int, int>, 4> directions={{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};

            for(auto & direction : directions)
            {
                int nextRow=row + direction.first;

                int nextColumn=column + direction.second;

                if(onBoard(rows, columns, nextRow, nextColumn) && board[nextRow][nextColumn]!='#')
                {
                    dfs(board, result, node, rows, columns, nextRow, nextColumn);
                }
            }

            board[row][column]=currentState;
        }

        std::vector<std::string> findWords(std::vector<std::vector<char>> & board, std::vector<std::string> & words)
        {
            std::vector<std::string> result;

            if(board.empty() || words.empty())
            {
                return result;
            }

            int rows=int(board.size());

            int columns=int(board[0].size());

            for(auto & word : words)
            {
                insert(word);
            }

            for(auto row=0;row<rows;++row)
            {
                for(auto column=0;column<columns;++column)
                {
                    TrieNode* node=root.get();

                    int index=board[row][column] - 'a';

                    if(node->children[index]!=nullptr)
                    {
                        dfs(board, result, node, rows, columns, row, column);
                    }
                }
            }

            return result;
        }
};