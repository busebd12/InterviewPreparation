#include <vector>
using namespace std;

/*
Time complexity: O(n + m) [where n is the length of v1 and m is the length of v2]
Space complexity: O(n + m)
*/

class ZigzagIterator
{
    private:
        vector<int> first;

        vector<int> second;

        int firstSize;

        int secondSize;

        int i;

        int j;

        bool pickFromFirst;
    
    public:
        ZigzagIterator(vector<int> & v1, vector<int> & v2)
        {
            first=v1;

            second=v2;

            firstSize=first.size();

            secondSize=second.size();

            i=0;

            j=0;

            pickFromFirst=true;
        }

        int next()
        {
            int number=-1;
            
            if(firstHasNext()==true and secondHasNext()==true)
            {
                if(pickFromFirst==true)
                {
                    number=first[i];

                    i+=1;

                    pickFromFirst=false;
                }
                else
                {
                    number=second[j];

                    j+=1;

                    pickFromFirst=true;
                }
            }
            else if(firstHasNext()==true)
            {
                number=first[i];

                i+=1;
            }
            else if(secondHasNext()==true)
            {
                number=second[j];

                j+=1;
            }

            return number;
        }

        bool hasNext()
        {
            return firstHasNext() or secondHasNext();
        }

        bool firstHasNext()
        {
            return i < firstSize;
        }

        bool secondHasNext()
        {
            return j < secondSize;
        }
};