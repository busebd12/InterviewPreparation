#include <string>
using namespace std;

/*
Time complexity: O(n * m) [where n is the length of s1 and m is the length of s2]
Space complexity: O(1)
*/

class Solution
{
    public:
        string minWindow(string s1, string s2)
        {
            string result="";

            int currentMinLength=-1;

            int start=-1;

            int n=s1.size();

            int m=s2.size();

            int i=0;

            int j=0;

            while(i < n)
            {
                //Increment j through s2
                if(s1[i]==s2[j])
                {
                    j+=1;

                    //If j reaches the end of s2, then we have found all the letters of s2 within s1
                    if(j==m)
                    {
                        //Marks the end of the substring of s1 that contains all the characters of s2
                        int substringEnd=i;

                        int s1Index=substringEnd;

                        int s2Index=m - 1;

                        //Iterate backwards through s2 till we reach the first letter
                        while(s2Index >= 0)
                        {
                            if(s1[s1Index]==s2[s2Index])
                            {
                                s2Index-=1;
                            }

                            s1Index-=1;
                        }

                        //Mark the start of the s1 substring that contains all the letters of s2
                        int substringStart=s1Index + 1;

                        //Calculate the length of the substring
                        int length=(substringEnd - substringStart) + 1;

                        //Update currentMinLength accordingly
                        if(currentMinLength==-1 or length < currentMinLength)
                        {
                            currentMinLength=length;

                            start=substringStart;
                        }

                        //Start search for all the letters in s2 from the index after the start of the previous substring that contained all letters from s2
                        i=substringStart + 1;

                        //Reset j before we iterate through s2 again
                        j=0;
                    }
                }
                
                i+=1;
            }

            //If start is not -1, then we have a valid minimum window subsequence of s1 that contains all the letters of s2
            if(start!=-1)
            {
                result=s1.substr(start, currentMinLength);
            }

            return result;
        }
};