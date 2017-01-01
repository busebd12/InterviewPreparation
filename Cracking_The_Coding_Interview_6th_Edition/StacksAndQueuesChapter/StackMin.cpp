#include <iostream>
#include <cstdlib>
#include <map>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <queue>
#include <functional>
#include "Stack.h"
using namespace std;

int main()
{
	Stack<char> s;

	s.push('a');

	s.push('g');

	s.push('z');

	s.push('l');

	s.push('e');

	s.print();

	cout << endl;

	s.getMinimumElement();
}