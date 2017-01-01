#include "HashTable.h"
#include <cstdlib>
#include <random>
#include <algorithm>
using namespace std;
 
 int main()
 {
 	HashTable<string> hash_table;

 	cout << "The size of the hash table is " << hash_table.getSize() << endl;

 	Node<string> node1;

 	node1.setData("C++");

 	Node<string> node2;

 	node2.setData("C#");

 	Node<string> node3;

 	node3.setData("LaTeX");

 	Node<string> node4;

 	node4.setData("Python");

 	Node<string> node5;

 	node5.setData("Java");

 	hash_table.insert(node1);

 	hash_table.insert(node2);

 	hash_table.insert(node3);

 	hash_table.insert(node4);

 	hash_table.insert(node5);

 	hash_table.print();

 	cout << "Does the hash table contain C++?: " << boolalpha << hash_table.contains(node1) << endl;

 	hash_table.remove(node1);

 	cout << "Does the hash table contain C++?: " << boolalpha << hash_table.contains(node1) << endl;
 }