#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <numeric>
#include <map>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <bitset>
#include <sstream>
using namespace std;

unsigned int swapBits(unsigned int x)
{
    // Get all even bits of x
    unsigned int even_bits=x & 0xAAAAAAAA;  //0xAAAAAAAA -- binary with all even bits as 1's
 
    // Get all odd bits of x
    unsigned int odd_bits=x & 0x55555555; //0x55555555 -- binary with all odd bits as 1's
 
    even_bits >>= 1;  // Right shift even bits

    odd_bits <<= 1;   // Left shift odd bits
 
    return (even_bits | odd_bits); // Combine even and odd bits
}

int main()
{
	unsigned int number=41;

	cout << swapBits(number) << endl;
}