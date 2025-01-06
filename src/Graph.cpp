#include "Graph.h"

Graph::Graph(int N) 
{
	nNodes = N;
	nEdges = 0;
	visited = std::list<bool>(false, N);
	while (N > 0)
	{
		Node n = { N-- };
		adjList.push_front(n);
	}
}

static std::list<Node>::iterator findIterator(int id, std::list<Node>* list)
{
	std::list<Node>::iterator it = list->begin();
	for (; it != list->end(); it++)
		if (it->id == id) return it;
	return it;
}

bool Graph::addEdge(int src, int dest)  // src and dest represents their ids
{
	int found = 0;
	std::list<Node>::iterator it = adjList.begin();
	std::list<Node>::iterator itsrc = findIterator(src, &adjList);
	std::list<Node>::iterator itdest = findIterator(dest, &adjList);
	
	if (itsrc == adjList.end() || 
		itdest == adjList.end() || 
		itsrc->getNode(dest) != nullptr) return false;

	itsrc->ptr.push_back(std::make_shared<Node>(*itdest));  // Add the pointer to the node's adjascent list
	nEdges += 1;
	return true;
}

bool Graph::linked(int n1, int n2)
{
	auto n1It = findIterator(n1, &adjList);
	for (auto it = n1It->ptr.begin(); it != n1It->ptr.end(); it++)
		if (it->get()->id == n2) return true;
	return false;
}

void Graph::printGraph()
{
	for (auto it = adjList.begin(); it != adjList.end(); it++)
	{
		std::cout << "( " << it->id << " )";
		for (auto itN = it->ptr.begin(); itN != it->ptr.end(); itN++)
			std::cout << " -> " << itN->get()->id;
		std::cout << std::endl;
	}
}