#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "Node.h"
#include <iostream>
#include <array>
#include <functional>
#include <typeinfo>
#include <string>
const int TABLE_SIZE=5;
template <typename T>
class HashTable
{
	private:
		std::array<std::array<Node<T>, TABLE_SIZE>, TABLE_SIZE> hashTable;
		std::array<std::array<bool, TABLE_SIZE>, TABLE_SIZE> spots;

	public:
		HashTable()
		{
			for(int index=0;index<spots.size();++index)
			{
				for(int position=0;position<spots.at(index).size();++position)
				{
					spots.at(index).at(position)=false;
				}
			}
		}

		int hashFunction(const Node<T> & Node)
		{
			auto key=Node.getData();

			std::hash<decltype(Node.getData())> hash_function {};

			int hash=hash_function(key);

			if(hash < 0)
			{
				hash*=-1;
			}

			//std::cout << "The hash value return by the STL hash function for the key " << key << " is " << hash << std::endl;

			if(hash > TABLE_SIZE)
			{
				hash%=TABLE_SIZE;
			}

			//std::cout << "The hash value for the key " << key << " is " << hash << std::endl;

			return hash;
		}

		void insert(const Node<T> & Node)
		{
			int hashValue=hashFunction(Node);

			auto & location=hashTable.at(hashValue);

			std::cout << "Going to insert " << Node.getData() << std::endl;

			for(int index=0;index<location.size();++index)
			{
				if(spots.at(hashValue).at(index)==false)
				{
					//std::cout << "Found a spot that is not taken!" << std::endl;

					//std::cout << "The size of the data at the spot in the array before we insert is: " << location.at(index).getData().size() << std::endl;

					location.at(index)=Node;

					//std::cout << "The size of the data at the spot in the array after we insert is: " << location.at(index).getData().size() << std::endl;

					//std::cout << "The data that is in the spot in the array: " << location.at(index).getData() << std::endl;

					//std::cout << std::endl;

					spots.at(hashValue).at(index)=true;

					break;
				}
			}
		}

		void remove(const Node<T> & Node)
		{
			int hashValue=hashFunction(Node);

			auto & location=hashTable.at(hashValue);

			for(int index=0;index<location.size();++index)
			{
				auto elementData=location.at(index).getData();

				auto & element=location.at(index);

				if(elementData==Node.getData())
				{
					decltype(Node.getData()) Data {};

					element.setData(Data);

					spots.at(hashValue).at(index)=false;
				}
			}
		}

		bool contains(const Node<T> & Node)
		{
			int hashValue=hashFunction(Node);

			auto location=hashTable.at(hashValue);

			auto result=find_if(begin(location), end(location), [Node] (const auto & element) {return element.getData()==Node.getData();});

			if(result!=end(location))
			{
				return true;
			}

			return false;
		}

		int getSize() const
		{
			int size {};

			for(int index=0;index<hashTable.size();++index)
			{
				size+=hashTable.at(index).size();
			}

			return size;
		}

		void print()
		{
			for(int index=0;index<hashTable.size();++index)
			{
				for(int position=0;position<hashTable.at(index).size();++position)
				{					
					if(hashTable.at(index).at(position).getData().size()!=0)
					{
						std::cout << hashTable.at(index).at(position).getData() << std::endl;
					}
				}
			}
		}
};
#endif