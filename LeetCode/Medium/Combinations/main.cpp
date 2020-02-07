#include <iostream>
#include <vector>

/*
 * Solution: we use backtracking to generate the combinations. When the combination reaches size k, we add it to
 * the combinations vector.
 *
 * Time complexity: O(n^k)
 * Space complexity: O(n^k)
 */

void backtracking(int n, std::vector<std::vector<int>> & combinations, std::vector<int> combination, int k, int start)
{
    if(combination.size()==k)
    {
        combinations.push_back(combination);
    }

    for(int i=start;i<=n;++i)
    {
        combination.push_back(i);

        backtracking(n, combinations, combination, k, i+1);

        combination.pop_back();
    }
}

std::vector<std::vector<int>> combine(int n, int k)
{
    std::vector<std::vector<int>> combinations;

    if(n==0 || k==0)
    {
        return combinations;
    }

    if(n < k)
    {
        return combinations;
    }

    std::vector<int> combination;

    int start=1;

    backtracking(n, combinations, combination, k, start);

    return combinations;
}