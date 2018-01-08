#include <iostream>
#include <vector>
using namespace std;

bool allSizeOne(const vector<vector<int>> & matrix)
{
    for(int i=0;i<matrix.size();++i)
    {
        if(matrix[i].size() > 1)
        {
            return false;
        }
    }

    return true;
}

void spiralOrderHelper(const vector<vector<int>> & matrix, vector<vector<bool>> & used, vector<int> & elements, pair<int, int> start, int rowSize, int columnSize, int & stop, bool & started)
{
    pair<int, int> current=start;

    for(int a=current.first,b=current.second;b<(columnSize-stop);++b)
    {
        if(!used[a][b])
        {
            elements.emplace_back(matrix[a][b]);

            used[a][b]=true;
        }

        current.second=b;
    }

    for(int c=current.first,d=current.second;c<(rowSize-stop);++c)
    {
        if(!used[c][d])
        {
            elements.emplace_back(matrix[c][d]);

            used[c][d]=true;
        }

        current.first=c;
    }

    for(int e=current.first,f=current.second;f>=stop;--f)
    {
        if(!used[e][f])
        {
            elements.emplace_back(matrix[e][f]);

            used[e][f]=true;
        }

        current.second=f;
    }

    for(int g=current.first,h=current.second;g>=stop;--g)
    {
        if(!used[g][h])
        {
            elements.emplace_back(matrix[g][h]);

            used[g][h]=true;
        }

        current.first=g;
    }
}

vector<int> spiralOrder(vector<vector<int>> & matrix)
{
    vector<int> elements;

    if(matrix.empty())
    {
        return elements;
    }

    const int matrixSize=int(matrix.size());

    if(matrixSize==1)
    {
        const int rowSize=int(matrix[0].size());

        for(int index=0;index<rowSize;++index)
        {
            elements.emplace_back(matrix[0][index]);
        }

        return elements;
    }

    if(allSizeOne(matrix))
    {
        int x=0;

        for(int y=0;y<matrixSize;++y)
        {
            elements.emplace_back(matrix[y][x]);
        }

        return elements;
    }

    bool started=false;

    auto rows=matrixSize;

    auto columns=matrix[0].size();

    vector<vector<bool>> used(rows, vector<bool>(columns, false));

    int i=0;

    int stop=0;

    while(true)
    {
        if(i > 0)
        {
            started=true;
        }

        pair<int, int> start=make_pair(i, i);

        if(used[i][i])
        {
            break;
        }
        else
        {
            if(i > rows/2)
            {
                break;
            }

            spiralOrderHelper(matrix, used, elements, start, rows, columns, stop, started);

            i++;

            stop++;
        }
    }

    return elements;
}