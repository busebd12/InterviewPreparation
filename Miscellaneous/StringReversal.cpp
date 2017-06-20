#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string reverseString(string Input, int Start, int End)
{
	if(Start==Input.size()/2 || End==Input.size()/2)
	{
		return Input;
	}
	else
	{
		swap(Input[Start], Input[End]);
	}

	return reverseString(Input, ++Start, --End);
}