#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <cmath>
using namespace std;

/*This code is for the following question:
Assume you have a method isSubstring that checks 
whether or not a word is a substring of another.
Given two strings, s1 and s2, wrtie code to check if s2 is a rotation 
of s1 using only one call to isSubstring. 
*/

bool isRotation(string String1, string String2)
{
	/*The main logic is this:
	if we imagine that string 2 is a rotation of string 1, 
	then we can ask what the rotation point it. So, in a rotation,
	we cut string 1 into two parts, x and y, and rearrange them to get string 2.

	So, we need to check if there's a way to spit string 1 into x and y
	such that xy=string 1 and yx=string 2. Regardless of where the division
	between x and y is, one can see that yx will always be a substring of xyxy.
	That is, string 2 will always be a substring of string1string1
	*/

	int stringOneLength=String1.length();

	int stringTwoLength=String2.length();

	if(stringOneLength==stringTwoLength && stringOneLength > 0)
	{
		string s1s1=String1+String1;

		return isSubstring(s1s1, String2);
	}

	return false;
}
