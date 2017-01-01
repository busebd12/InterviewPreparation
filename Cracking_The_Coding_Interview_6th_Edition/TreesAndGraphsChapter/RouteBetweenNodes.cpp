#include "Graph.h"
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
using namespace std;


/*
The basic idea is this: 
we start breadth first search at whatever node we want as our beginning node
and during the search, if we come across the other node, we know that there 
exists a path between the two nodes
*/

template <typename T>
bool breadthFirstSearch(const Graph<T> & G, char NodeOne, char NodeTwo)
{
	bool result;

	vector<Vertex<T>> visitedNodes;

	map<Vertex<T>, bool> visited;

	for(const auto & vertex : G.getAdjacencyList())
	{
		visited.insert(make_pair(visited[vertex.first.getData()], false));
	}

	auto startingVertex=find_if(G.getAdjacencyList().begin(), G.getAdjacencyList().end(), [NodeOne] (const auto & element) {return element.first.getData()==NodeOne;});

	queue<Vertex<T>> Q;

	visited[startingVertex->first.getData()]=true;

	Q.push(startingVertex->first);

	while(!Q.empty())
	{
		auto headVertex=Q.front();

		if(headVertex.getData()==NodeTwo)
		{
			cout << "Found a path between " << NodeOne << " and " << headVertex.getData() << endl;

			result=true;

			break;
		}
		else
		{
			result=false;
		}

		visitedNodes.emplace_back(headVertex);

		auto adjacentVertices=G.getAdjacencyList().at(headVertex);

		Q.pop();

		for(auto & vertex : adjacentVertices)
		{
			if(visited[vertex.getData()]==false)
			{
				visited[vertex.getData()]=true;

				Q.push(vertex);
			}
		}
	}

	return result;
}

int main()
{
	Graph<char> G;

	G.addVertexPair('A', 'B');

	G.addVertexPair('A', 'D');

	G.addVertexPair('A', 'G');

	G.addVertexPair('B', 'E');

	G.addVertexPair('B', 'F');

	G.addVertexPair('B', 'A');

	G.addVertexPair('C', 'H');

	G.addVertexPair('D', 'A');

	G.addVertexPair('D', 'F');

	G.addVertexPair('E', 'B');

	G.addVertexPair('E', 'G');

	G.addVertexPair('F', 'B');

	G.addVertexPair('F', 'C');

	G.addVertexPair('F', 'D');

	G.addVertexPair('G', 'A');

	G.addVertexPair('G', 'E');

	G.addVertexPair('H', 'C');

	G.print();

	cout << endl;

	cout << "The number of nodes in the graph is: " << G.getNumberOfElements() << endl;

	bool result=breadthFirstSearch(G, 'A', 'F');

	cout << "Result of searching for a path between the two nodes: " << boolalpha << result << endl;

}