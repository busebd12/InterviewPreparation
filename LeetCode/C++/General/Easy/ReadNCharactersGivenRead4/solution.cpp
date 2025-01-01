/*
Time complexity: O(n)
Space complexity: O(n)
*/

class Solution
{
    public:
        /**
        * @param buf Destination buffer
        * @param n   Number of characters to read
        * @return    The number of actual characters read
        */
        int read(char *buf, int n)
        {
            //Buffer used to hold the four characters read from the file
            char buffer4[4]={0};

            //The minimum number of times we have to call the read4 function
            //Eeach time we call read4, we are guaranteed to read four characters into buffer4
            int times=n / 4;

            int index=0;

            for(int count=0;count<times;count++)
            {
                //Read four characters in buffer4
                int charactersRead=read4(buffer4);

                //Copy characters from buffer4 into buf
                for(int i=0;i<charactersRead;i++)
                {
                    buf[index]=buffer4[i];

                    index+=1;
                }
            }

            //Check how many characters are left to be read
            int charactersLeft=n % 4;

            //If there is at least one character left to be read
            if(charactersLeft!=0)
            {
                //Read characters from the file and store in buffer4
                int charactersRead=read4(buffer4);

                //To prevent overflow, we will take the minimum between charactersLeft and charactersRead
                int size=min(charactersLeft, charactersRead);

                //Copy characters from buffer4 to buf
                for(int i=0;i<size;i++)
                {
                    buf[index]=buffer4[i];

                    index+=1;
                }
            }
            
            return index;
        }
};