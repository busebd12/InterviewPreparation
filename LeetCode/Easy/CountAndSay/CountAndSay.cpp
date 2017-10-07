#include <iostream>
#include <string>
using namespace std;

string countAndSay(int n)
{
	if(n <= 0)
	{
		return 0;
	}
	
	if(n==1)
	{
		return "1";
	}
	
	if(n==2)
	{
		return "11";
	}
	
	string result=countAndSay(n-1);
	
	string answer{};
	
	char currentNumber=result[0];
	
	int count=1;
	
	for(int index=1;index<result.size();++index)
	{
		if(result[index]==currentNumber)
		{
			++count;
		}
		else
		{
			answer+=to_string(count);
			
			answer+=currentNumber;
			
			currentNumber=result[index];
			
			count=1;
		}
	}
	
	answer+=to_string(count);
	
	answer+=currentNumber;
	
	return answer;
}