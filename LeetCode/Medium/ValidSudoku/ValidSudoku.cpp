bool allDots(const vector<vector<char>> & board)
{
    const size_t boardSize=board.size();

    const size_t rowSize=board[0].size();

    for(int i=0;i<boardSize;++i)
    {
        for(int j=0;j<rowSize;++j)
        {
            if(board[i][j]!='.')
            {
                return false;
            }
        }
    }

    return true;
}

bool checkSubSquares(const vector<vector<char>> & board)
{
    int number=0;

    int count=0;

    unordered_set<char> s;

    for(int i=1,index=1;i<=9;++i,++index)
    {
        if(index > 1)
        {
            if((index-1)!=1)
            {
                if(index <= 3)
                {
                    if((3 % (index-1))==0)
                    {
                        number+=3;
                    }
                }
                else
                {
                    if((index-1)%3==0)
                    {
                        number+=3;

                        count=0;
                    }
                }
            }
        }

        for(int b=number;b<number+3;++b)
        {
            for(int c=count;c<count+3;++c)
            {
                char current=board[b][c];
                
                if(current!='.')
                {
                    if(s.find(current)!=end(s))
                    {
                        return false;
                    }
                    else
                    {
                        s.insert(current);
                    }
                }
            }
        }

        s.clear();

        count+=3;
    }
    
    return true;
}

bool checkColumns(const vector<vector<char>> & board, const size_t boardSize, const size_t rowSize)
{
    for(int x=0;x<boardSize;++x)
    {
        unordered_set<char> s;

        for(int y=0;y<rowSize;++y)
        {
            auto current=board[y][x];

            if(current!='.')
            {
                if(s.find(current)!=end(s))
                {
                    return false;
                }
                else
                {
                    s.insert(current);
                }
            }
        }
    }
    
    return true;
}

bool checkRows(const vector<vector<char>> & board, const size_t boardSize, const size_t rowSize)
{
    for(int i=0;i<boardSize;++i)
    {
        unordered_set<char> s;

        for(int j=0;j<rowSize;++j)
        {
            auto current=board[i][j];

            if(current!='.')
            {
                if(s.find(current)!=end(s))
                {
                    return false;
                }
                else
                {
                    s.insert(current);
                }
            }
        }
    }
    
    return true;
}

bool isValidSudoku(const vector<vector<char>> & board)
{
    if(board.empty())
    {
        return true;
    }

    if(allDots(board))
    {
        return true;
    }

    const size_t boardSize=board.size();

    const size_t rowSize=board[0].size();

    if(!checkRows(board, boardSize, rowSize))
    {
        return false;
    }

    if(!checkColumns(board, boardSize, rowSize))
    {
        return false;
    }
    
    if(!checkSubSquares(board))
    {
        return false;
    }

    return true;
}