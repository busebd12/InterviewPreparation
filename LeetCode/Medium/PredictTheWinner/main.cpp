#include <iostream>
#include <vector>
using namespace std;

bool dfs(vector<int> & nums, int player1Score, int player2Score, int front, int back, bool turn)
{
    if(front==back)
    {
        if(turn)
        {
            player1Score+=nums[front];
        }
        else
        {
            player2Score+=nums[front];
        }

        return player1Score >= player2Score;
    }
    else
    {
        if(turn)
        {
            if(dfs(nums, player1Score+nums[front], player2Score, front+1, back, false) || dfs(nums, player1Score+nums[back], player2Score, front, back-1, false))
            {
                return true;
            }
        }
        else
        {
            if(dfs(nums, player1Score, player2Score+nums[front], front+1, back, true) && dfs(nums, player1Score, player2Score+nums[back], front, back-1, true))
            {
                return true;
            }
        }
    }

    return false;
}

bool PredictTheWinner(vector<int> & nums)
{
    int n=int(nums.size());

    int front=0;

    int back=n-1;

    int player1Score=0;

    int player2Score=0;

    bool turn=true;

    return dfs(nums, player1Score, player2Score, front, back, turn);
}