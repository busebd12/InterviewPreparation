#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int getIndex(string X, string Y, int Index)
{
	if(X[Index]!=Y[Index] || Index==X.size() || Index==Y.size())
	{
		return Index;
	}

	return getIndex(X, Y, Index+1);
}

void solution(string X, string Y)
{
	if(X.empty() || Y.empty())
	{
		return;
	}

	if(X==Y)
	{
		cout << X.size() << " " << X << endl;

		cout << 0 << endl;

		cout << 0 << endl;

		return;
	}

	int index=getIndex(X, Y, 0);

	string prefix(begin(X), begin(X)+index);

	size_t prefixSize=prefix.size();

	if(prefix==X)
	{
		Y.erase(begin(Y), begin(Y)+index);

		cout << prefixSize << " " << prefix << endl;

		cout << 0 << " " << endl;

		cout << Y.size() << " " << Y << endl;
	}
	else if(prefix==Y)
	{
		X.erase(begin(X), begin(X)+index);

		cout << prefixSize << " " << prefix << endl;

		cout << X.size() << " " << X << endl;

		cout << 0 << " " << endl;
	}
	else
	{
		X.erase(begin(X), begin(X)+index);

		Y.erase(begin(Y), begin(Y)+index);

		cout << prefixSize << " " << prefix << endl;

		cout << X.size() << " " << X << endl;

		cout << Y.size() << " " << Y << endl;
	}
}