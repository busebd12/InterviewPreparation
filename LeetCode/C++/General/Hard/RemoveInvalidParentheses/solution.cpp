class Solution
{
    public:
        vector<string> removeInvalidParentheses(string s)
        {
            vector<string> result;

            unordered_set<string> seen;

            deque<string> queue;

            queue.push_back(s);

            while(!queue.empty())
            {
                int qSize=queue.size();

                for(int count=0;count<qSize;count++)
                {
                    string current=queue.front();

                    queue.pop_front();

                    //If we've already seen this string, skip it to avoid revisiting this state
                    if(seen.find(current)!=seen.end())
                    {
                        continue;
                    }

                    //Mark current as seen
                    seen.insert(current);

                    //If the current string is valid
                    if(isValid(current)==true)
                    {
                        //Add current to result
                        result.push_back(current);
                    }
                    else
                    {
                        //If result is empty, then we haven't found any valid string with the minimum number of invalid parentheses removed
                        //If result is not empty, then we have already found a valid string with the minimum number of invalid parentheses removed,
                        //and we don't want to remove any more ( or ) since that would remove more than the minimum
                        if(result.empty())
                        {
                            int m=current.size();
                            
                            //Iterate through the string and for each ( and ), remove it from the string and add the remaining substring to the queue
                            for(int index=0;index<m;index++)
                            {
                                if(current[index]=='(' or current[index]==')')
                                {
                                    string parenthesisRemoved=current.substr(0, index) + current.substr(index + 1, string::npos);

                                    queue.push_back(parenthesisRemoved);
                                }
                            }
                        }
                    }
                }
            }

            return result;
        }

        bool isValid(string & s)
        {
            int count=0;

            for(char character : s)
            {
                if(character=='(')
                {
                    count+=1;
                }
                else if(character==')')
                {
                    if(count > 0)
                    {
                        count-=1;
                    }
                    else
                    {
                        return false;
                    }
                }
            }

            return count==0;
        }
};