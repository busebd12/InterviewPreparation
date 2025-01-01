class Solution
{
    public:
        int minFlips(int a, int b, int c)
        {
            int result=0;

            int size=sizeof(int) * 8;

            for(int place=size-1;place>=0;place-=1)
            {
                int aBit=(a >> place) & 1;

                int bBit=(b >> place) & 1;

                int cBit=(c >> place) & 1;

                bool orResult=((aBit | bBit)==cBit);

                if(orResult==false)
                {
                    if(cBit==0)
                    {
                        if(aBit==1 and bBit==1)
                        {
                            result+=2;
                        }
                        else
                        {
                            result+=1;
                        }
                    }
                    else
                    {
                        if(aBit!=1 and bBit!=1)
                        {
                            result+=1;
                        }
                    }
                }
            }

            return result;
        }
};