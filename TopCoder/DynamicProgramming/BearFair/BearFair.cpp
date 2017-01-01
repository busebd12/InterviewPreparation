#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstdlib>
using namespace std;

class BearFair
{
	public:
		bool meetsCriteria(vector<int> Elements, int HintsMatched, int N, int B, int Q)
		{
			size_t elementsSize=Elements.size();

			bool distinctElements=false;

			bool correctNumberOfElements=false;

			bool sizeIsEven=false;

			bool elementsBetweenOneAndB=false;

			bool halfEvens=false;

			bool halfOdds=false;

			bool allHintsMatched=false;

			distinctElements=(adjacent_find(begin(Elements), end(Elements))==end(Elements)) ? true : false;

			correctNumberOfElements=(elementsSize==N) ? true : false;

			sizeIsEven=(elementsSize%2==0) ? true : false;

			int count=count_if(begin(Elements), end(Elements), [Elements, B] (const auto & element) {return (1 <= element) && (element <= B);});

			elementsBetweenOneAndB=(count==elementsSize) ? true : false;

			int evens=count_if(begin(Elements), end(Elements), [Elements] (const auto & element) {return element%2==0;});

			halfEvens=(elementsSize/2==evens) ? true : false;

			int odds=count_if(begin(Elements), end(Elements), [Elements] (const auto & element) {return element%2==1;});

			halfOdds=(elementsSize/2==odds) ? true : false;

			allHintsMatched=(HintsMatched==Q) ? true : false;

			bool result=(distinctElements && correctNumberOfElements && sizeIsEven && elementsBetweenOneAndB && halfEvens && halfOdds && allHintsMatched);

			return result;
		}

		string isFair(int N, int B, vector<int> UpTo, vector<int> Quantity)
		{
			const string unfair="unfair";

			const string fair="fair";

			if(UpTo.empty() || Quantity.empty())
			{
				return unfair;
			}

			if(N <= 0 || B <= 0)
			{
				return unfair;
			}

			size_t q=Quantity.size();

			if(!is_sorted(begin(UpTo), end(UpTo)))
			{
				sort(begin(UpTo), end(UpTo));
			}

			if(!is_sorted(begin(Quantity), end(Quantity)))
			{
				sort(begin(Quantity), end(Quantity));
			}

			vector<pair<vector<int>, int>> hintMap;

			vector<int> elements;

			int hintsMatched{};

			int totalOdds{};

			int totalEvens{};

			for(int i=0;i<q;++i)
			{
				for(int element=1;element<=UpTo[i];++element)
				{
					if(element%2==0)
					{
						totalEvens++;
					}
					else
					{
						totalOdds++;
					}

					cout << "Adding element: " << element << endl;

					cout << endl;

					elements.emplace_back(element);
				}

				hintMap.emplace_back(make_pair(elements, Quantity[i]));

				elements.clear();
			}

			if(totalEvens < N/2 || totalOdds < N/2)
			{
				return unfair;
			}

			size_t hintMapSize=hintMap.size();

			sort(begin(hintMap), end(hintMap), [](const auto & First, const auto & Second){return First.second > Second.second;});

			for(int index=0;index<hintMapSize;++index)
			{
				int count{};

				if(index==0)
				{
					for(int position=0;position<hintMap[index].second;++position)
					{
						int element=hintMap[index].first[position];

						elements.emplace_back(element);
					}

					cout << "Elements: " << endl;

					copy(begin(elements), end(elements), ostream_iterator<int>(cout, " "));

					cout << endl;

					cout << endl;

					++hintsMatched;
				}

				if(index > 0)
				{
					for(int spot=0;spot<hintMap[index].second;++spot)
					{
						int element=hintMap[index-1].first[spot];

						if(element==elements[spot])
						{
							cout << element << " matches " << elements[spot] << endl;

							cout << endl;

							count++;

							cout << "count: " << count << endl;

							cout << endl;
						}

						if(count==hintMap[index].second)
						{
							cout << count << " matches " << hintMap[index].second << endl;

							cout << endl;

							++hintsMatched;

							break;
						}
					}
				}
			}

			bool result=meetsCriteria(elements, hintsMatched, N, B, q);

			return (result) ? fair : unfair;
		}                                                                 
};

int main(int argc, char* argv[])
{
	BearFair B;

	/*
	int n=4;

	int b=6;

	vector<int> upTo={3, 6};

	vector<int> quantity={2, 4};

	//returns fair
	*/

	/*
	int n=4;

	int b=6;

	vector<int> upTo={3, 6};

	vector<int> quantity={2, 3};

	//returns unfair
	*/
	

	
	int n=2;

	int b=6;

	vector<int> upTo={1, 2, 3};

	vector<int> quantity={1, 1, 2};

	//returns unfair
	

	/*
	int n=4;

	int b=1000;

	vector<int> upTo={400, 600};

	vector<int> quantity={4, 0};

	//returns unfair
	*/

	cout << B.isFair(n, b, upTo, quantity) << endl;
}