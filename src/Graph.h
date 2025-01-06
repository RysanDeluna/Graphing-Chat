#pragma once
#include <memory>
#include <unordered_map>
#include <list>
#include <iostream>

// Adjascent list is better in this case, cos we only need to create the graph once
// - They are efficient for running across elements

struct Node {
	int id;
	std::list<std::shared_ptr<Node> > ptr;

	std::shared_ptr<Node> getNode(int id)
	{
		std::list<std::shared_ptr<Node>>::iterator it = ptr.begin();
		for (; it != ptr.end(); it++)
			if (it->get()->id == id) return *it;
		return nullptr;
	}
};

class Graph {
private:
	std::list<Node> adjList;
	std::list<bool> visited;
	int nEdges;
	int nNodes;

public:
	Graph(std::list<Node> nodeList) : 
		adjList(nodeList), 
		visited(std::list<bool> (false, nodeList.size())), 
		nNodes(nodeList.size()), 
		nEdges(0)
	{
		for (std::list<Node>::iterator it = adjList.begin(); it != adjList.end(); it++)
			nEdges += it->ptr.size();
	};
	Graph(int N);
	~Graph() = default;

	bool addEdge(int src, int dest);
	bool linked(int n1, int n2);
	void printGraph();
};