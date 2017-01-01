#include <iostream>
#include <map>
#include <string>
#include <cstdlib>
using namespace std;

class BracketSequenceDiv1
{
	private:
		map<string, long long> cache;

	public:
		long count(string Input)
		{
			size_t stringSize=Input.size();

    		long long answer;

    		long long firstHalf;

    		long long secondHalf;

    		/* Base case --> empty string, return 0 */

		    if(Input.size()==0)
		    {
		    	 return 0;
		    }

		    /* Memoization looks at the cache first. */

		    if(cache.find(Input)!=end(cache))
		    {
		    	 return cache[Input];
		    }
		    	

		 	 //When we erase the first character
		    answer=count(Input.substr(1));


		    //If we are left with only closing brackets/parenthesis, then just return whatever our answer is so for since that's all we can do
		    if(Input[0]==')' || Input[0]==']')
		    {
		        cache[Input]=answer;

		        return answer;
		    }

		    	/*
		    	 For each closing brace/parenthesis that matches the first character,
		       split the string in two at that point, and recurse on the first half and the
		       second half, adding one to account for empty strings. Dont forget to add in the products.
		    	*/

		    for (int i=1;i<stringSize;++i)
		    {
		        if ((Input[0]=='(' && Input[i]==')') || (Input[0]=='[' && Input[i]==']'))
		        {
		            firstHalf=count(Input.substr(1, i-1))+1;

		            secondHalf=count(Input.substr(i+1))+1;

		            answer+=(firstHalf*secondHalf);
		        }
		    }

		    cache[Input]=answer;

		    return answer;
		}
};

int main(int argc, char* argv[])
{
	BracketSequenceDiv1 B;

	string input="()[]";

	string input="())";

	string input="()()";

	string input="([)]";
	
	string input="())[]][]([]()]]()]]]";
	
	cout << B.count(input) << endl;
}