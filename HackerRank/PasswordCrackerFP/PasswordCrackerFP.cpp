#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;

string passwordCracker(map<string, int> PasswordMap, string LoginAttempt, string FoundPasswordsConcatenated, string FoundPasswordsWithSpaces, int LoginAttemptSize, int Index)
{
	if(Index==LoginAttemptSize)
	{
		if(FoundPasswordsConcatenated==LoginAttempt)
		{
			FoundPasswordsWithSpaces.pop_back();

			return FoundPasswordsWithSpaces;
		}
		else
		{
			return "WRONG PASSWORD";
		}
	}

	int newStartingIndex{};

	string currentPassword{};

	for(int index=Index;index<LoginAttemptSize;++index)
	{
		currentPassword+=LoginAttempt[index];

		newStartingIndex=index;

		auto itr=PasswordMap.find(currentPassword);

		if(itr!=end(PasswordMap))
		{
			FoundPasswordsConcatenated+=currentPassword;

			FoundPasswordsWithSpaces+=(currentPassword + " ");

			break;
		}
	}

	return passwordCracker(PasswordMap, LoginAttempt, FoundPasswordsConcatenated, FoundPasswordsWithSpaces, LoginAttemptSize, newStartingIndex+1);
}

string passwordCrackerHelper(vector<string> Passwords, string LoginAttempt)
{
	int startingIndex{};

	string foundPasswordsConcatenated{};

	string foundPasswordsWithSpaces{};

	size_t loginAttemptSize=LoginAttempt.size();

	size_t passwordsSize=Passwords.size();

	map<string, int> passwordMap;

	for(int index=0;index<passwordsSize;++index)
	{
		passwordMap.emplace(Passwords[index], index);
	}

	string result=passwordCracker(passwordMap, LoginAttempt, foundPasswordsConcatenated, foundPasswordsWithSpaces, loginAttemptSize, startingIndex);

	return result;
}