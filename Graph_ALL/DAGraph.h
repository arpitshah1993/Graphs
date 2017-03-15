#ifndef DGRAPH_H
#define DGRAPH_H
#include <vector>
#include <tr1/unordered_map>
#include<string>
#include<stdio.h>
#include<iostream>
#include<exception>
#include<math.h>
#include<cstdlib>

using namespace std;
using namespace std::tr1;
class VertexNode
{
public:
	int NodeWeight;
	VertexNode(string val, int wt) : NodeData(val), next(0), NodeWeight(wt), distance(999), previous(0), done(false) {}
	VertexNode() : NodeData("0"), next(0), NodeWeight(0), distance(999), previous(0), done(false) {}
	VertexNode(string val) : NodeData(val), next(0), NodeWeight(0), distance(999), previous(0), done(false) {}
	string NodeData;
	int distance;
	VertexNode* previous;
	VertexNode* next;
	bool done;
};

class DAGraph
{
public:
	DAGraph()
	{
	}
	void deleteEdge(string, string);
	int getWeight(VertexNode*, VertexNode*);
	void InsertEdge(string, string, int NodeWeight = 0);
	VertexNode* getVertex(string);
	void findShortestPath(string);
	void updateVertexData(string, int, VertexNode*);
	void UpdateDataRelaxation(VertexNode*, VertexNode*);
	void GetDist(int, string);
	VertexNode* getMin();
	void InsertVertex(string);
	void GetPath(int, string);
	unordered_map<string, string> WritePathToStorage(int, string);
	int num_Edges;
	bool IsUndirected;
	std::vector<VertexNode*> AdjacencyVector;
	bool IsVertexExist(string);
	void Initialize();
	int numOfVertices = 0;
};

//print the dj graph
inline void printDJGraph(DAGraph* GraphPrint, FILE* filestream, unordered_map<string, string> ListOfEdges)
{
	if (GraphPrint->IsUndirected)
		fprintf(filestream, "strict graph {\n");
	else
		fprintf(filestream, "digraph BST {\n");
	fprintf(filestream, "    node [fontname=\"Arial\"];\n");
	std::vector<VertexNode*> sizeOfAdjacenecyList = GraphPrint->AdjacencyVector;
	if (sizeOfAdjacenecyList.size() == 0)
		fprintf(filestream, "\n");
	else
	{
		for (std::vector<VertexNode*>::iterator vertexNode = sizeOfAdjacenecyList.begin(); vertexNode != sizeOfAdjacenecyList.end(); vertexNode++)
		{

			VertexNode* currentNode = (*vertexNode)->next;
			if (currentNode != NULL)
			{
				while (currentNode != NULL)
				{
					string nodeNameX1 = (*vertexNode)->NodeData;
					string nodeNameX2 = currentNode->NodeData;
					unordered_map<string, string>::iterator iter;
					bool color = false;
					iter = ListOfEdges.find(nodeNameX1);
					if (iter != ListOfEdges.end())
					{
						if (iter->second == nodeNameX2)
							color = true;
					}
					if (GraphPrint->IsUndirected)
					{
						if (color)
							fprintf(filestream, "    %s -- %s[color=\"red\"];\n", (*vertexNode)->NodeData.c_str(), currentNode->NodeData.c_str());
						else
							fprintf(filestream, "    %s -- %s[label= %d ][color=\"blue\"];\n", (*vertexNode)->NodeData.c_str(), currentNode->NodeData.c_str(), currentNode->NodeWeight);
					}
					else
					{
						if (color)
							fprintf(filestream, "    %s -> %s[color=\"red\"];\n", (*vertexNode)->NodeData.c_str(), currentNode->NodeData.c_str());
						else
							fprintf(filestream, "    %s -> %s[label= %d ][color=\"red\"];\n", (*vertexNode)->NodeData.c_str(), currentNode->NodeData.c_str(), currentNode->NodeWeight);
					}
					currentNode = currentNode->next;
				}
			}
			fprintf(filestream, "    %s;\n", (*vertexNode)->NodeData.c_str());
		}
	}
	fprintf(filestream, "}\n");
}
#endif
