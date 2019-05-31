#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

int getDistance(pair<int, int> x, pair<int, int> y)
{
    int xDifference=x.second-x.first;

    int yDifference=y.second-y.first;

    int dist=static_cast<int>(floor(sqrt(pow(xDifference, 2) + pow(yDifference, 2))));

    return dist;
}

vector<int> findDiagonalOrderTLE(vector<vector<int>> & matrix)
{
    vector<int> result;

    if(matrix.empty())
    {
        return result;
    }

    if(matrix.size()==1)
    {
        return matrix[0];
    }

    int difference=0;

    bool changedM=false;

    bool changedN=false;

    int N=int(matrix[0].size());

    int M=int(matrix.size());

    if(N > M)
    {
        difference=N-M;

        for(int count=0;count<difference;++count)
        {
            vector<int> row(N, 0);

            matrix.emplace_back(row);
        }

        changedM=true;
    }
    else
    {
        difference=M-N;

        for(int count=0;count<difference;++count)
        {
            for(int index=0;index<M;++index)
            {
                matrix[index].emplace_back(0);
            }
        }

        changedN=true;
    }

    if(changedM)
    {
        M=int(matrix.size());
    }

    if(changedN)
    {
        N=int(matrix[0].size());
    }


    vector<vector<bool>> table(M, vector<bool>(N, false));

    for(int i=0;i<M;++i)
    {
        for(int j=0;j<N;++j)
        {
            if(changedM)
            {
                if(i >= M-difference)
                {
                    continue;
                }
                else
                {
                    table[i][j]=true;
                }
            }

            if(changedN)
            {
                if(j >= N-difference)
                {
                    continue;
                }
                else
                {
                    table[i][j]=true;
                }
            }
        }
    }

    bool down=false;

    for(int index=0;index<N;++index)
    {
        pair<int, int> current(0, index);

        pair<int, int> end(index, 0);

        if(!table[current.first][current.second] && !table[end.first][end.second])
        {
            continue;
        }
        else
        {

            int limit=getDistance(current, end);

            if(down)
            {
                for(int count=0;count<=limit;++count)
                {
                    if(table[current.first][current.second])
                    {
                        result.emplace_back(matrix[current.first][current.second]);

                        table[current.first][current.second]=false;
                    }

                    current.first+=1;

                    current.second-=1;

                    if(current.second < 0 || current.first > M-1)
                    {
                        break;
                    }
                }

                down=false;
            }
            else
            {
                for(int count=0;count<=limit;++count)
                {
                    if(table[end.first][end.second])
                    {
                        result.emplace_back(matrix[end.first][end.second]);

                        table[end.first][end.second]=false;
                    }

                    end.first-=1;

                    end.second+=1;

                    if(end.second > N-1 || end.first < 0)
                    {
                        break;
                    }
                }

                down=true;
            }
        }
    }

    for(int index=1;index<M;++index)
    {
        pair<int, int> current(index, N-1);

        pair<int, int> end(N-1, index);

        if(!table[current.first][current.second] && !table[end.first][end.second])
        {
            continue;
        }
        else
        {
            int limit=getDistance(current, end);

            if(down)
            {
                for(int count=0;count<=limit;++count)
                {
                    if(table[current.first][current.second])
                    {
                        result.emplace_back(matrix[current.first][current.second]);

                        table[current.first][current.second]=false;
                    }

                    current.second-=1;

                    current.first+=1;

                    if(current.second < 0 || current.first > M-1)
                    {
                        break;
                    }
                }

                down=false;
            }
            else
            {
                for(int count=0;count<=limit;++count)
                {
                    if(table[end.first][end.second])
                    {
                        result.emplace_back(matrix[end.first][end.second]);

                        table[end.first][end.second]=false;
                    }

                    end.second+=1;

                    end.first-=1;

                    if(end.second > N-1 || end.first < 0)
                    {
                        break;
                    }
                }

                down=true;
            }
        }
    }

    return result;
}

vector<int> findDiagonalOrder(vector<vector<int>> & matrix)
{
    vector<int> result;

    if(matrix.empty())
    {
        return result;
    }

    const int N=int(matrix.size());

    const int M=int(matrix[0].size());

    for(int s=0;s<=(N+M-2);++s)
    {
        for(int x=0;x<=s;++x)
        {
            int i=x;

            int j=s-i;

            if((s % 2)==0)
            {
                swap(i, j);
            }

            if(i >= N || j >= M)
            {
                continue;
            }

            result.push_back(matrix[i][j]);
        }
    }

    return result;
}