#include <deque>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/*
Solution 1: see comments. Note, this solution gets Time Limit Exceeded when run.

Time complexity: O(n + (n * l)) [where n is the length of s and l is the average length of the string representations of the numbers 0-9]
Space complexity: O(u) [where u is the number of unique letters in s]
*/

class Solution
{
    public:
        string originalDigits(string s)
        {
            string result{};
            
            int n=s.size();
            
            //Hashtable to map 0-9 to string representations
            vector<string> hashtable(10, "");
            
            //Create mappings
            hashtable[0]="zero";
            
            hashtable[1]="one";
            
            hashtable[2]="two";
            
            hashtable[3]="three";
            
            hashtable[4]="four";
            
            hashtable[5]="five";
            
            hashtable[6]="six";
            
            hashtable[7]="seven";
            
            hashtable[8]="eight";
            
            hashtable[9]="nine";

            //Hashtable to map characters in s to their frequencies
            unordered_map<char, int> characterFrequencies;
            
            //Create frequency mappings
            for(auto letter : s) //O(n)
            {
                characterFrequencies[letter]++;
            }
            
            //Buckets used to keep track of how many of each number, 0-9, we have
            vector<int> numberFrequencies(10, 0);
            
            //While we have characters left in s to process
            while(n > 0) //O(n)
            {
                //Iterate from 0 to 9 and see how many numbers we can create from s
                for(int number=0;number<10;number++)
                {
                    int found=0;

                    //Go through the characters in the string representation of the number
                    for(auto letter : hashtable[number]) //O(l)
                    {   
                        //If the frequency of the character is greater than zero
                        if(characterFrequencies[letter] > 0)
                        {   
                            //We can use the character to form the string representation of the number
                            found++;
                        }
                    }
                    
                    //If we find all the characters for the string representation of the number in s
                    if(found==hashtable[number].size())
                    {
                        //Increment the total times we have this number in s
                        numberFrequencies[number]++;

                        //Decrement the frequency of each character
                        for(auto letter : hashtable[number]) //O(l)
                        {   
                            characterFrequencies[letter]--;
                            
                            //Decrement the value of n - meaning we used up that many characters from s
                            n--;
                        }
                    }
                }
            }
            
            //Loop through the buckets representing how many of each number, 0-9, we have
            for(int number=0;number<10;number++)
            {
                //If we have at least one of the number
                if(numberFrequencies[number] > 0)
                {
                    int times=numberFrequencies[number];
                    
                    //Add however many of the number we have to the string
                    for(int count=0;count<times;count++)
                    {
                        result.push_back(number + '0');
                    }
                }
            }
            
            return result;
        }
};

/*
Solution 2: inspired from this post --> https://leetcode.com/problems/reconstruct-original-digits-from-english/discuss/1841714/C%2B%2B-oror-Kind-of-Topological-sort-oror-Uncommon-letter

Time complexity: O(n + l) [where n is the length of s and l is the average length of the string representations of the numbers 0-9]
Space complexity: O(u) [where u is the number of unique letters in s]
*/

class Solution
{
    public:
        string originalDigits(string s)
        {
            string result{};
            
            int n=s.size();
            
            //Hashtable to map 0-9 to string representations
            vector<string> strings(10, "");
            
            //Create mappings
            strings[0]="zero";
            
            strings[1]="one";
            
            strings[2]="two";
            
            strings[3]="three";
            
            strings[4]="four";
            
            strings[5]="five";
            
            strings[6]="six";
            
            strings[7]="seven";
            
            strings[8]="eight";
            
            strings[9]="nine";
            
            //Hashtable to map characters in s to their frequencies
            unordered_map<char, int> characterFrequencies;
            
            //Create frequency mappings
            for(auto letter : s)
            {
                characterFrequencies[letter]++;
            }
            
            //Map integer representations of letters to the particular number from 0-9
            vector<int> hashtable(26, 0);
            
            //Create mappings
            hashtable['z' - 'a']=0;
            
            hashtable['w' - 'a']=2;
            
            hashtable['u' - 'a']=4;
            
            hashtable['x' - 'a']=6;
            
            hashtable['g' - 'a']=8;
            
            hashtable['h' - 'a']=3;
            
            hashtable['o' - 'a']=1;
            
            hashtable['f' - 'a']=5;
            
            hashtable['i' - 'a']=9;
            
            hashtable['s' - 'a']=7;
            
            //queue of characters that uniquely identify the string representation of each number
            deque<char> queue={'z', 'w', 'u', 'x', 'g', 'h', 'o', 'f', 'i', 's'};

            //Buckets used to keep track of how many of each number, 0-9, we have
            vector<int> numberFrequencies(10, 0);
            
            while(!queue.empty())
            {
                auto letter=queue.front();
                
                queue.pop_front();
                
                //How many times does this letter appear in s
                int count=characterFrequencies[letter];
                
                //If it appears more than zero times
                if(count > 0)
                {
                    //Get the number that this letter is part of the string representation for
                    int index=hashtable[letter - 'a'];
                    
                    for(int i=0;i<count;i++)
                    {
                        //Use index to index into the correct spot in the strings vector to access the correct string number representation
                        for(auto c : strings[index]) //O(l)
                        {
                            //Decrement the frequency of each character
                            characterFrequencies[c]--;
                        }
                    }

                    //Increment the number of times we are able to creat this number from s
                    numberFrequencies[index]+=count;
                }
            }
            
            //Loop through the buckets representing how many of each number, 0-9, we have
            for(int number=0;number<10;number++)
            {
                //If we have at least one of the number
                if(numberFrequencies[number] > 0)
                {
                    int times=numberFrequencies[number];
                    
                    //Add however many of the number we have to the string
                    for(int count=0;count<times;count++)
                    {
                        result.push_back(number + '0');
                    }
                }
            }
            
            return result;
        }
};