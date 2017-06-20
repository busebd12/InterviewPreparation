#include <iostream>
#include <bitset>
#include <string>
#include <cmath>
using namespace std;

class ConsecutiveOnes
{
	public:
		long get(long N, int K)
		{
			string mBinary{};

			long n=N;

			long consecutiveOnes{};

			long m{};

			while(true)
			{
				mBinary=bitset<64>(n).to_string();

				//cout << "After creating binary string" << endl;

				//cout << endl;

				size_t mBinarySize=mBinary.size();

				if(consecutiveOnes > 0)
				{
					consecutiveOnes=0;

					//cout << "Set consecutiveOnes to zero" << endl;

					//cout << endl;
				}

				for(int index=0;index<mBinarySize;++index)
				{
					if(mBinary[index]=='1')
					{
						//cout << "Consecutive ones before incrementing: " << consecutiveOnes << endl;

						//cout << endl;

						++consecutiveOnes;

						//cout << "Consecutive ones after incrementing: " << consecutiveOnes << endl;

						//cout << endl;

						if(consecutiveOnes >= K)
						{
							//cout << "Consecutive ones is greater than or equal to K" << endl;

							//cout << endl;

							break;
						}
					}
					else
					{
						consecutiveOnes=0;
					}
				}

				if(consecutiveOnes >= K)
				{
					int power{};

					for(int index=mBinary.length()-1;index>=1;--index)
					{
						if(mBinary[index]=='1')
						{
							//cout << "mBinary[index]=='1'" << endl;

							//cout << endl;

							m+=pow(2, power);

							//cout << "m: " << m << endl;

							//cout << endl;
						}

						++power;

						//cout << "power: " << power << endl;

						//cout << endl;
					}

					//cout << "right before breaking out of the while loop" << endl;

					//cout << endl;

					break;
				}
				else
				{
					++n;

					consecutiveOnes=0;
				}
			}

			return m;
		}
};

int main(int argc, char** argv)
{
	ConsecutiveOnes C;

	/*
	long n=1;

	int k=2;

	//returns 3
	*/

	/*
	long n=5;

	int k=2;

	//returns 6
	*/
	

	/*
	long n=7;

	int k=2;

	//returns 7
	*/
	

	
	int long n=364269800189924;

	int k=33;

	//returns 364273356242943
	

	cout << C.get(n, k) << endl;
}