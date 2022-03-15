#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
    public:
        vector<string> fullJustify(vector<string> & words, int maxWidth)
        {
            vector<string> result;
        
            int n=words.size();

            int i=0;

            //iterate through all the input words
            while(i < n)
            {
                
                /*
                Step 1 - Greedly grab as many words as will fit in a line while still allowing spaces so that the line will be fully justified.

                How do we do that? Well, we know that each line is only allowed to have a width of maxWidth. This means that the line can
                only have a total of maxWidth characters, including spaces. So, out of the maxWidth number of characters, how many of those
                can be letters and how many of them can be spaces? Let's look at an example:

                Say the maxWidth of the line is 20. So, the line can only have a total of 20 characters in it. Now, let's say that we have greedly
                grabbed four words so far and the total number of characters between those four words is seventeen (the total length of all four words combined).
                At this point, we are only left with three characters. Also, the next word in our list has more than three letters, so we can't add it to the
                current line. So, what do we use to fill in the last three remaining spots? Spaces! Okay, cool, how do choose where the spaces go in order to
                spread them out evenly between the words? Well, in a sentence you usually place a minimum of once space between each word, except for the last one.
                So, how spots do we have where we can put spaces? The number of spots is equal to the total number of words in the sentence (or line) minus one.

                Example: Iliketoeatcake. => I <space> like <space> to <space> eat <space> cake. (5 words, 4 spots for spaces)

                Therefore, we keeping adding words to our line as long as the total number of characters combined with the spots between each word
                needed for spaces is less than or equal to the maxWidth of the line. Once the length of the line would exceed maxWidth if we added
                the next word from the list, we stop adding words.
                */
                int lineWidth=maxWidth;

                int totalWords=0;

                int totalLetters=0;

                int totalSpaces=0;

                int spotsForSpaces=0;

                vector<string> wordsInLine;

                while(true)
                {   
                    totalLetters+=words[i].size();

                    totalWords++;

                    if(totalWords > 1)
                    {
                        spotsForSpaces=totalWords - 1;
                    }

                    if(totalLetters + spotsForSpaces <= maxWidth)
                    {
                        wordsInLine.push_back(words[i]);

                        i++;

                        if(i==n)
                        {
                            break;
                        }
                    }
                    else
                    {
                        totalWords--;

                        totalLetters-=words[i].size();

                        break;
                    }
                }

                //Step 2 - keep track of when we reach the last line of text
                bool isLastLine=false;

                if(i==n)
                {
                    isLastLine=true;
                }

                totalSpaces=maxWidth - totalLetters;

                spotsForSpaces=totalWords - 1;

                /*
                Step 3 - Divide the total number of spaces for the current line into buckets.

                Part of this question asks us to divide the spaces between as evenly as possible.
                Now, if the number of spaces in the current line is evenly divisible by the total number of
                places for those spaces, then placing the spaces between the words is easy. The tricky
                part is when the number of spaces is not divisible by the places for the spaces.
                For example, if we have eight spaces to put in the line, and there are three spots,
                we can't put an even number of spaces in all three spots since eight is not evenly
                divisible by three. So, how do we choose how many spaces go in each spot? Well, since
                the problem asks us to add more spaces in the left spots than the right spots, that's what
                we'll do. How do we do this? By the use of buckets.

                We will have a total of (# of words in the line minus one) number of buckets.

                Example line: I <space> like <space> to <space> eat <space> pizza (5 words, 4 spots for spaces, 5-1=4 so 4 buckets)

                Then, we simply iterate over the buckets from left to right and deposit one space in each bucket. We go in a left-to-right
                fashion because we are supposed to favor left spots over right spots. We keep iterating like this until we are out of spaces.
                At this point, all the spaces will have been divided as evenly as possible among the buckets.
                */
                vector<int> buckets;

                buckets.resize(1);

                if(spotsForSpaces > 0)
                {
                    buckets.resize(spotsForSpaces);
                }

                int spaceCount=0;

                while(spaceCount < totalSpaces)
                {   
                    for(int index=0;index<buckets.size()&&spaceCount < totalSpaces;index++)
                    {
                        buckets[index]++;

                        spaceCount++;
                    }
                }

                /*
                Step 4 - Build the fully justified line by combing the words and spaces.

                We iterate over the collection of words that will be added to line and do the following:
                1) Add the word to the line
                2) If this is the last line of text, and the current word is not the last word in the line,
                add a single space after it (since it is the last line, no extra spaces between the words is allowed) and
                decrement the number of spaces (to ensure that we add the correct number).
                Else, this is not the last line in the text and we simply add as many spaces after the word as there are
                in the current bucket. Then, we increment the index keeping track of which bucket we are at (as long as the next
                index is valid).
                */
                string line{};

                int bucketIndex=0;

                for(int index=0;index<wordsInLine.size();index++)
                {   
                    line+=wordsInLine[index];

                    if(isLastLine)
                    {   
                        if(index < wordsInLine.size()-1)
                        {
                            line+=' ';

                            totalSpaces--;
                        }
                    }
                    else
                    {
                        if(bucketIndex < buckets.size())
                        {
                            for(int count=0;count<buckets[bucketIndex];count++)
                            {
                                line+=' ';
                            }

                            bucketIndex++;
                        }
                    }
                }

                /*
                Step 5 - If this is the last line of text, add the remaining spaces to the end of the line
                */
                if(isLastLine)
                {   
                    for(int count=0;count<totalSpaces;count++)
                    {
                        line+=' ';
                    }
                }

                /*
                Step 6 - add the line to the vector of lines
                */
                result.emplace_back(line);
            }

            return result;
        }
};