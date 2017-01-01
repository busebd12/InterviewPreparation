#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
#include <utility>
#include <sstream>
#include <map>
using namespace std;

string lengthOne(const int Number, map<int, string> & StringRepresentations)
{
	string result {};

	//since it is just one digit, just get the value it hashes to
	result+=StringRepresentations[Number];

	cout << result << endl;

	return result;
}

string lengthTwo(string S, map<int, string> & StringRepresentations)
{
	string result {};

	//auto found=

	int number=stoi(S);

	cout << "number in lengthTwo function: " << number << endl;

	//how many times our number can be divided by 10
	//use this to create the twenty, thirty, fourty, etc.
	int multiple=number/10;

	//get the rest of the number. so if original number was 35, this will get the 5
	int leftOver=number-(multiple*10);

	if(leftOver==0)
	{
		result+=StringRepresentations[multiple*10];
	}
	else
	{
		//numbers from 10 to 19
		if(multiple==1)
		{
			result+=StringRepresentations[number];
		}

		//else, numbers from 20-99
		else if(multiple > 1)
		{
			//get the twenty, thirty, fourty, fiftty, etc. part
			result+=StringRepresentations[(multiple*10)];

			result+="-";

			//get the one, two, three, four, etc. part
			result+=StringRepresentations[leftOver];
		}
	}

	cout << result << endl;

	return result;
}

string lengthThree(string S, map<int, string> & StringRepresentations)
{
	string result {};

	int number=stoi(S);

	cout << "number from lengthTwo function: " << number << endl;

	if(number==0)
	{
		return "";
	}

	//how many times our number can be divided by 100
	//use this to create the one-hundred, two-hundred, three-hundred, etc.
	int multiple=number/100;

	//get the rest of the number. so if original number was 135, this will get the 35
	int leftOver=number-(multiple*100);

	cout << "left over from lengthTwo function: " << leftOver << endl;

	if(leftOver==0)
	{
		result+=StringRepresentations[multiple];

		result+="-hundred";
	}
	//form the final string
	else
	{
		if(multiple >= 1)
		{
			//get the one, two, three, etc. for the one-hundred, two-hundred, three-hundred, etc. part
			result+=StringRepresentations[multiple];

			result+="-hundred";

			result+=" and ";

			string rest=to_string(leftOver);

			switch(rest.size())
			{
				case 1:
					result+=lengthOne(leftOver, StringRepresentations);
					break;

				case 2:
					result+=lengthTwo(rest, StringRepresentations);
					break;
			}	
		}
		else
		{
			result+=lengthTwo(to_string(leftOver), StringRepresentations);
		}
	}

	cout << result << endl;

	return result;
}

string lengthFour(string S, map<int, string> & StringRepresentations)
{
	string result {};

	int number=stoi(S);

	int multiple=number/1000;

	int leftOver=number-(multiple*1000);

	if(leftOver==0)
	{
		result+=StringRepresentations[multiple];

		result+="-thousand";
	}
	//form the final string
	else
	{
		//get the one, two, three, etc. for the one-thousand, two-thousand, three-thousand, etc. part
		result+=StringRepresentations[multiple];

		result+="-thousand ";

		string rest=to_string(leftOver);

		switch(rest.size())
		{
			case 1:
				result+="and ";

				result+=lengthOne(leftOver, StringRepresentations);

				break;

			case 2:
				result+="and ";

				result+=lengthTwo(rest, StringRepresentations);

				break;

			case 3:
				result+=lengthThree(rest, StringRepresentations);

				break;
		}
	}

	cout << result << endl;

	return result;
}

string lengthFive(string S, map<int, string> & StringRepresentations)
{
	string result {};

	int number=stoi(S);

	string thousandsPart=S.substr(0,2); 

	int multiple=number/10000;

	int leftOver=number-(multiple*10000);

	string rest=to_string(leftOver);

	if(leftOver==0)
	{	
		result+=lengthTwo(thousandsPart, StringRepresentations);

		result+=" thousand";
	}
	else
	{
		string thousandsPart=S.substr(0,2);

		result+=lengthTwo(thousandsPart, StringRepresentations);

		result+=" thousand ";

		switch(rest.size())
		{
			case 1:
				result+="and ";

				result+=lengthOne(leftOver, StringRepresentations);

				break;

			case 2:
				result+="and ";

				result+=lengthTwo(rest, StringRepresentations);

				break;

			case 3:
				result+=lengthThree(rest, StringRepresentations);

				break;

			case 4:
				string temp=rest.substr(1, string::npos);

				result+=lengthThree(temp, StringRepresentations);

				break;
		}
	}

	cout << result << endl;

	return result;
}

string lengthSix(string S, map<int, string> & StringRepresentations)
{
	string result {};

	int number=stoi(S);

	cout << "Number in length six function: "  << number << endl;

	int multiple=number/100000;

	//cout << "Multiple: " << multiple << endl;

	int leftOver=number-(multiple*100000);

	//cout << "Left over: " << leftOver << endl;

	string hundredThousandsPart=S.substr(0,2); 

	string rest=to_string(leftOver);

	//cout << "Size of left over: " << rest.size() << endl;

	if(leftOver==0)
	{	
		int firstDigit=S[0]-'0';

		result+=lengthOne(firstDigit, StringRepresentations);

		result+=" hundred thousand";
	}
	else
	{
		string hundredThousandsPart=S.substr(0,3);

		result+=lengthThree(hundredThousandsPart, StringRepresentations);

		result+=" thousand ";

		string temp;

		switch(rest.size())
		{
			case 1:
				result+="and ";

				result+=lengthOne(leftOver, StringRepresentations);

				break;

			case 2:
				//result+="and ";

				result+=lengthTwo(rest, StringRepresentations);

				break;

			case 3:
				result+=lengthThree(rest, StringRepresentations);

				break;

			case 4:
				temp=rest.substr(1, string::npos);

				//cout << "temp: " << temp << endl;

				//result+="and ";

				result+=lengthThree(temp, StringRepresentations);

				break;

			case 5:
				temp=rest.substr(2, string::npos);

				//result+="and ";

				result+=lengthThree(temp, StringRepresentations);

				break;
			
		}
	}

	cout << result << endl;

	return result;
}

string lengthSeven(string S, map<int, string> & StringRepresentations)
{
	string result {};

	int number=stoi(S);

	cout << "Number in lengthSeven function: " << number << endl;

	string newNumber=to_string(number);

	if(newNumber.size()==5)
	{
		result+=lengthFive(newNumber, StringRepresentations);
	}

	int multiple=number/1000000;

	int leftOver=number-(multiple*1000000);

	//cout << "multiple in the lengthSeven function: " << multiple << endl;

	//cout << "Left over in the lengthSeven function: " << leftOver << endl;

	string rest=to_string(leftOver);

	cout << "Size of left over: " << rest.size() << endl;

	int millions=S[0]-'0';

	if(leftOver==0)
	{	
		result+=lengthOne(millions, StringRepresentations);

		result+=" million";
	}
	else
	{
		result+=lengthOne(millions, StringRepresentations);

		result+=" million";

		switch(rest.size())
		{
			case 1:
				result+=" ";

				result+=lengthOne(leftOver, StringRepresentations);

				break;

			case 2:
				result+=" ";

				result+=lengthTwo(rest, StringRepresentations);

				break;

			case 3:
				result+=" ";

				result+=lengthThree(rest, StringRepresentations);

				break;

			case 4:
				result+=" ";

				result+=lengthFour(rest, StringRepresentations);

				break;

			case 5:
				result+=" ";

				result+=lengthFive(rest, StringRepresentations);

				break;

			case 6:
				result+=" ";

				result+=lengthSix(rest, StringRepresentations);

				break;

		}
	}
	

	cout << result << endl;

	return result;	
}

string lengthEight(string S, map<int, string> & StringRepresentations)
{
	string result {};

	int number=stoi(S);

	int multiple=number/10000000;

	int leftOver=number-(multiple*10000000);

	cout << "left over: " << leftOver << endl;

	string rest=to_string(leftOver);

	cout << "Size of left over: " << rest.size() << endl;

	string tenMillionsPart=S.substr(0,2);

	cout << tenMillionsPart << endl;

	if(leftOver==0)
	{
		result+=lengthTwo(tenMillionsPart, StringRepresentations);

		cout << result << endl;

		result+=" million";
	}
	else
	{
		result+=lengthTwo(tenMillionsPart, StringRepresentations);

		result+=" million";

		string temp;

		switch(rest.size())
		{
			case 1:
				result+=" ";

				result+=lengthOne(leftOver, StringRepresentations);

				break;

			case 2:
				result+=" and ";

				result+=lengthTwo(rest, StringRepresentations);

				break;

			case 3:
				result+=" ";

				result+=lengthThree(rest, StringRepresentations);

				break;

			case 4:
				result+=" ";

				result+=lengthFour(rest, StringRepresentations);

				break;

			case 5:
				result+=" ";

				result+=lengthFive(rest, StringRepresentations);

				break;

			case 6:
				result+=" ";

				result+=lengthSix(rest, StringRepresentations);

				break;

			case 7:
				result+=" ";

				temp=rest.substr(1, string::npos);

				result+=lengthSeven(temp, StringRepresentations);	
		}
	}

	cout << result << endl;

	return result;
}

void preFillMap(map<int, string> & Map)
{
	Map.insert({1, "one"});
	Map.insert({2, "two"});
	Map.insert({3, "three"});
	Map.insert({4, "four"});
	Map.insert({5, "five"});
	Map.insert({6, "six"});
	Map.insert({7, "seven"});
	Map.insert({8, "eight"});
	Map.insert({9, "nine"});
	Map.insert({10, "ten"});
	Map.insert({11, "eleven"});
	Map.insert({12, "twelve"});
	Map.insert({13, "thirteen"});
	Map.insert({14, "fourteen"});
	Map.insert({15, "fifteen"});
	Map.insert({16, "sixteen"});
	Map.insert({17, "seventeen"});
	Map.insert({18, "eighteen"});
	Map.insert({19, "nineteen"});
	Map.insert({20, "twenty"});
	Map.insert({30, "thirty"});
	Map.insert({40, "forty"});
	Map.insert({50, "fifty"});
	Map.insert({60,"sixty"});
	Map.insert({70, "seventy"});
	Map.insert({80, "eighty"});
	Map.insert({90, "ninety"});
}

int main(int argc, char *argv [])
{
	map<int, string> stringRepresentations;

	preFillMap(stringRepresentations);

	int number=71010010;

	string S=to_string(number);

	switch(S.size())
	{
		case 1:
			lengthOne(number, stringRepresentations);

			break;

		case 2:
			lengthTwo(S, stringRepresentations);

			break;

		case 3:
			lengthThree(S, stringRepresentations);

			break;

		case 4:
			lengthFour(S, stringRepresentations);

			break;

		case 5:
			lengthFive(S, stringRepresentations);

			break;

		case 6:
			lengthSix(S, stringRepresentations);

			break;

		case 7:
			lengthSeven(S, stringRepresentations);

			break;

		case 8:
			lengthEight(S, stringRepresentations);

			break;

		default:
			break;
	}
}