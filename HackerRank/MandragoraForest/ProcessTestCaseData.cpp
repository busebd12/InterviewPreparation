#include <iostream>
#include <cstdlib>
#include <vector>
#include <deque>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <cmath>
#include <iterator>
#include <numeric>
#include <cctype>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

void createSolutions(ifstream & File, vector<long long int> & Solutions)
{
	vector<long long int> solutions;

	string line;

	int counter {};

	while(getline(File, line))
	{
		long solution=stol(line);

		//cout << "Processing solution: " << solution << endl;

		Solutions.push_back(solution);

		++counter;
	}

	cout << "Processed " << counter << " solutions" << endl;

	cout << endl;
}

void createAllTestCases(vector<vector<long long int>> & TestCases)
{
	vector<long long int> testCase;

	//adjust the bufferSize as you see fit
	const size_t bufferSize=7267363;

	ifstream testCaseFile ("TestCaseOne.txt", ifstream::binary);

	char* buffer;

	if(testCaseFile.is_open())
	{
		//get the length of the file
		testCaseFile.seekg(0, testCaseFile.end);

		size_t length=testCaseFile.tellg();

		testCaseFile.seekg(0, testCaseFile.beg);

		buffer=new char[bufferSize];

		cout << "Reading " << length << " characters" << endl;

		cout << endl;

		//read the entire file into one char buffer
		testCaseFile.read(buffer, length);

		if(testCaseFile)
		{
			cout << "All " << length << " characters read successfully" << endl;
		}
		else
		{
			cout << "Error: only " << testCaseFile.gcount() << " could be read" << endl;
		}

		testCaseFile.close();
	}

	string line {};

	int count=0;

	for(int index=6;index<bufferSize;++index)
	{
		while(buffer[index]!='\n')
		{
			line+=buffer[index];

			index++;
		}

		auto space=find(line.begin(), line.end(), ' ');

		if(space==line.end())
		{
			line.clear();
		}

		else if(space!=line.end())
		{
			//cout << "line " << count << ": " << line << endl;

			istringstream is(line);

			long number;

			while(is >> number)
			{
				//cout << number << endl;

				testCase.push_back(number);
			}

			//cout << "Adding vector " << count << endl;

			//copy(testCase.begin(), testCase.end(), ostream_iterator<long>(cout, " "));

			//cout << endl;

			TestCases.push_back(testCase);

			++count;

			testCase.clear();

			line.clear();
		}
	}
	
	cout << endl;

	//free the electrons
	delete [] buffer;
}

void removeLines(ostream & outFile)
{
	const size_t bufferSize=7267363;

	ifstream testCaseFile ("TestCaseOne.txt", ifstream::binary);

	char* buffer;

	if(testCaseFile.is_open())
	{
		//get the length of the file
		testCaseFile.seekg(0, testCaseFile.end);

		size_t length=testCaseFile.tellg();

		testCaseFile.seekg(0, testCaseFile.beg);

		buffer=new char[bufferSize];

		cout << "Reading " << length << " characters" << endl;

		cout << endl;

		//read the entire file into one char buffer
		testCaseFile.read(buffer, length);

		if(testCaseFile)
		{
			cout << "All " << length << " characters read successfully" << endl;
		}
		else
		{
			cout << "Error: only " << testCaseFile.gcount() << " could be read" << endl;
		}

		testCaseFile.close();
	}

	string line {};

	int count=0;

	for(int index=6;index<bufferSize;++index)
	//for(int index=7267277;index<bufferSize;++index)
	{
		//cout << "at index " << index << ": " << buffer[index] << endl;
	
		while(buffer[index]!='\n')
		{
			if(index==bufferSize)
			{
				break;
			}
			else
			{
				line+=buffer[index];

				index++;
			}
		}

		auto space=find(line.begin(), line.end(), ' ');

		if(space==line.end())
		{
			cout << "Going to skip line: " << line << endl;

			line.clear();
		}

		else if(space!=line.end())
		{
			cout << "Going to write line number " << count << ": " << line << " to the edited file" << endl;

			if(count==79080)
			{
				outFile << line;
			}
			else
			{
				outFile << line << endl;
			}

			line.clear();
		}

		++count;
	}
	
	cout << endl;

	//free the electrons
	delete [] buffer;
}

/*
int main(int argc, char* argv [])
{
	vector<vector<long>> testCases;

	ifstream testCasesFile;

	ifstream testCaseSolutions;

	testCasesFile.open("TestCaseOne.txt");

	if(testCasesFile.is_open())
	{
		createAllTestCases(testCasesFile);
	}

	testCasesFile.close();

	if(testCaseSolutions.is_open())
	{
		createSolutions(testCaseSolutions);
	}

	testCaseSolutions.close();

	string line;

	int counter {};

	vector<long> testCase;

	while(getline(testCasesFile, line))
	{
		int numberOfValues;

		if(counter > 0)
		{
			if(line.size() <= 6)
			{
				cout << "About to process " <<  line << " numbers" << endl;

				int numberOfValues=stoi(line);
			}
			else
			{
				int valueCounter {};

				istringstream is(line);

				long number;

				while(is >> number)
				{
					//cout << number << endl;

					testCase.push_back(number);

					++valueCounter;
				}

				cout << "Added " << valueCounter << " numbers to the vector" << endl;

				testCases.push_back(testCase);
			}			
		}

		++counter;
	}
}
*/

