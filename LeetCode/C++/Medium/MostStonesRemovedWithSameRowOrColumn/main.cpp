#include <iostream>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

/*
 * Solutions: inspired from these posts --> https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/discuss/197668/Count-the-Number-of-Islands-O(N)
 * and https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/discuss/461523/C%2B%2B-DFS-counting-the-actual-moves
 *
 * 1. Recursion + DFS. Also, using a std::set<std::pair<int, int>> to keep track of the coordinates we have already
 * seen/visited. Note: this solution receives a TLE (time limit exceeded) when submitted).
 *
 * Time complexity: O(n^2) [where n is the number of stones]
 * Space complexity: O(n)
 *
 * 2. Recursion + DFS. Also, using a std::unordered_map<int, std::unordered_map<int, bool>> to keep track of the coordinates we have already seen/visited.
 * Note: this solution receives a TLE (time limit exceeded) when submitted).
 *
 * Time complexity: O(n^2)
 * Space complexity: O(n)
 *
 *
 * 3. Recursion + DFS + counting the number of removals. Also, using a std::unordered_set<std::string> to keep track of the coordinates we have already seen/visited.
 *
 * Time complexity: O(n^2)
 * Space complexity: O(n)
 *
 *
 * 4. Recursion + DFS + counting the number of removals. Also, using a std::unordered_map<std::string> to keep track of the coordinates we have already seen/visited.
 * Similar to the first two solutions but instead of iterating through all stones for each stone, we only consider the stones that share a common row or column.
 *
 * Time complexity: O(n^2)
 * Space complexity: O(n)
 */


class Solution
{
    public:
        void dfs(std::vector<std::vector<int>> & stones, std::set<std::pair<int, int>> & used, int row, int column)
        {
            used.insert(std::make_pair(row, column));

            for(const auto & stone : stones)
            {
                if(!used.count(std::make_pair(stone[0], stone[1])) && (stone[0]==row || stone[1]==column))
                {
                    dfs(stones, used, stone[0], stone[1]);
                }
            }
        }

        int removeStones(std::vector<std::vector<int>> & stones)
        {
            int n=int(stones.size());

            int islands=0;

            std::set<std::pair<int, int>> used;

            for(const auto & stone : stones)
            {
                auto p=std::make_pair(stone[0], stone[1]);

                if(!used.count(p))
                {
                    islands++;

                    dfs(stones, used, stone[0], stone[1]);
                }
            }

            int count=n - islands;

            return count;
        }
};


class Solution
{
    public:
        void dfs(std::vector<std::vector<int>> & stones, std::unordered_map<int, std::unordered_map<int, bool>> & used, int row, int column)
        {
            used[row][column]=true;

            for(const auto & stone : stones)
            {
                int nextRow=stone[0];

                int nextColumn=stone[1];

                if(!used[nextRow][nextColumn] && (nextRow==row || nextColumn==column))
                {
                    dfs(stones, used, nextRow, nextColumn);
                }
            }
        }

        int removeStones(std::vector<std::vector<int>> & stones)
        {
            int n=int(stones.size());

            int islands=0;

            std::unordered_map<int, unordered_map<int, bool>> used;

            for(const auto & stone : stones)
            {
                int row=stone[0];

                int column=stone[1];

                if(!used[row][column])
                {
                    islands++;

                    dfs(stones, used, stone[0], stone[1]);
                }
            }

            int count=n - islands;

            return count;
        }
};

class Solution
{
public:
    int dfs(std::unordered_map<int, std::vector<int>> & rowsHashtable, std::unordered_map<int, std::vector<int>> & columnsHashtable, std::unordered_set<std::string> & used, int row, int column)
    {
        int subproblem=0;

        for(const auto & nextColumn : rowsHashtable[row])
        {
            std::string key=std::to_string(row) + "-" + std::to_string(nextColumn);

            if(nextColumn!=column && !used.count(key))
            {
                used.insert(key);

                subproblem+=(1 + dfs(rowsHashtable, columnsHashtable, used, row, nextColumn));
            }
        }

        for(const auto & nextRow : columnsHashtable[column])
        {
            std::string key=std::to_string(nextRow) + "-" + std::to_string(column);

            if(nextRow!=row && !used.count(key))
            {
                used.insert(key);

                subproblem+=(1 + dfs(rowsHashtable, columnsHashtable, used, nextRow, column));
            }
        }

        return subproblem;
    }

    int removeStones(std::vector<std::vector<int>> & stones)
    {
        int n=int(stones.size());

        int islands=0;

        int result=0;

        std::unordered_set<std::string> used;

        std::unordered_map<int, std::vector<int>> rowsHashtable;

        std::unordered_map<int, std::vector<int>> columnsHashtable;

        for(const auto & stone : stones)
        {
            int row=stone[0];

            int column=stone[1];

            rowsHashtable[row].emplace_back(column);

            columnsHashtable[column].emplace_back(row);
        }

        for(const auto & stone : stones)
        {
            int row=stone[0];

            int column=stone[1];

            std::string key=std::to_string(row) + "-" + std::to_string(column);

            if(!used.count(key))
            {
                used.insert(key);

                result+=dfs(rowsHashtable, columnsHashtable, used, row, column);
            }
        }

        return result;
    }
};


class Solution
{
    public:
        void dfs(std::unordered_map<int, std::vector<int>> & rowsHashtable, std::unordered_map<int, std::vector<int>> & columnsHashtable, std::unordered_map<int, std::unordered_map<int, bool>> & used, int row, int column)
        {
            used[row][column]=true;

            for(const auto & nextColumn : rowsHashtable[row])
            {
                if(nextColumn!=column && !used[row][nextColumn])
                {
                    dfs(rowsHashtable, columnsHashtable, used, row, nextColumn);
                }
            }

            for(const auto & nextRow : columnsHashtable[column])
            {
                if(nextRow!=row && !used[nextRow][column])
                {
                    dfs(rowsHashtable, columnsHashtable, used, nextRow, column);
                }
            }
        }

        int removeStones(std::vector<std::vector<int>> & stones)
        {
            int n=int(stones.size());

            int islands=0;

            std::unordered_map<int, std::unordered_map<int, bool>> used;

            std::unordered_map<int, std::vector<int>> rowsHashtable;

            std::unordered_map<int, std::vector<int>> columnsHashtable;

            for(const auto & stone : stones)
            {
                int row=stone[0];

                int column=stone[1];

                rowsHashtable[row].emplace_back(column);

                columnsHashtable[column].emplace_back(row);
            }

            for(const auto & stone : stones)
            {
                int row=stone[0];

                int column=stone[1];

                if(!used[row][column])
                {
                    islands++;

                    dfs(rowsHashtable, columnsHashtable, used, row, column);
                }
            }

            return n - islands;
        }
};

