#include <iostream>
#include <cstdlib>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>
#include <functional>
#include <string>
#include <random>

#ifndef ANIMAL_H 
#define ANIMAL_H
class AnimalShelter;
class Animal
{
	friend class AnimalShelter;

	private:
		std::string type;
		int arrivalTime;
		std::string name;
	public:
		Animal(const std::string Type, const std::string Name, const int ArrivalTime): type(Type), name(Name), arrivalTime(ArrivalTime) {}

		Animal() {}

		std::string getType() const
		{
			return type;
		}

		int getArrivalTime() const
		{
			return arrivalTime;
		}

		friend bool operator < (const Animal & A1, const Animal & A2)
		{
			return A1.arrivalTime < A2.arrivalTime;
		}
};
#endif

#ifndef ANIMALSHELTER_H
#define ANIMALSHELTER_H
class AnimalShelter
{
	private:
		std::list<Animal> dogs;
		std::list<Animal> cats;
	public:
		AnimalShelter() {}

		void populate()
		{
			enqueue("Dog", "Fido", 10);

			enqueue("Cat", "Puss in Boots", 15);

			enqueue("Dog", "Air Bud", 1);

			enqueue("Cat", "Mrs. Norris", 2);

			enqueue("Dog", "Fred", 5);

			enqueue("Cat", "George", 6);	
		}

		void enqueue(const std::string Type, const std::string Name, const int ArrivalTime)
		{
			if(Type=="Dog" || Type=="dog")
			{
				dogs.emplace_back(Animal(Type, Name, ArrivalTime));

				dogs.sort();
			}
			else
			{
				cats.emplace_back(Animal(Type, Name, ArrivalTime));

				cats.sort();
			}
		}

		void dequeueAny()
		{
			/*dequeue the first thing in the list, regadless*/

			std::random_device rd;

			std::mt19937 gen(rd());

			std::uniform_int_distribution<> dis(1,2);

			int choice=dis(gen);

			switch(choice)
			{
				case 1:
					dequeueDog();

					break;

				case 2:
					dequeueCat();

					break;

				default:
					break;
			}
		}

		void dequeueDog()
		{
			/*dequeue the first dog you find in the list with the largest arrival time since that will indicate that animal has been there the longest*/

			auto oldestDog=std::max_element(dogs.begin(), dogs.end(), [] (const auto & dogOne, const auto & dogTwo) {return dogOne.arrivalTime < dogTwo.arrivalTime;});

			std::cout << "Congratulations, your dog's name is " << oldestDog->name << std::endl;

			dogs.pop_front();
		}

		void dequeueCat()
		{
			/*dequeue the first cat you find in the list with the largest arrival tiem since that will indicate that animal has been there the longest*/

			auto oldestCat=std::max_element(cats.begin(), cats.end(), [] (const auto & catOne, const auto & catTwo) {return catOne.arrivalTime < catTwo.arrivalTime;});

			std::cout << "Congratulations, your cat's name is " << oldestCat->name << std::endl;

			cats.pop_front();
		}

		int getSize() const
		{
			int size=dogs.size()+cats.size();

			return size;
		}

		void print() const
		{
			for(const auto & animal : dogs)
			{
				std::cout << animal.type << " ";
			}

			std::cout << std::endl;

			for(const auto & animal : cats)
			{
				std::cout << animal.type << " ";
			}

			std::cout << std::endl;
		}
};
#endif

using namespace std;

int main()
{
	int choice;

	AnimalShelter shelter;

	shelter.populate();	

	cout << "Welcome to your local, neighborhood animal shelter!" << endl;

	cout << "At the moment, all we have are dogs and cats." << endl;

	cout << "Please, choose from the following options:" << endl;

	cout << "Press 1 if you would like a dog" << endl;

	cout << "Press 2 if you would like a cat" << endl;

	cout << "Or, press 3 if you would like us to choose for you" << endl;

	cin >> choice;

	switch(choice)
	{
		case 1:
			shelter.dequeueDog();

			break;

		case 2:
			shelter.dequeueCat();

			break;

		case 3:
			shelter.dequeueAny();

			break;

		default:
			break;
	}
}