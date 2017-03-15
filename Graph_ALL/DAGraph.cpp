
#include <fstream>
#include <iostream>
#include <iomanip>
#include <istream>
#include <sstream>
#include <tr1/unordered_map>
#include "DAGraph.h"
#include <string>
using namespace std;
using namespace std::tr1;

//Initialize the nodes for finding the given path
void DAGraph::Initialize()
{
	for (std::vector<VertexNode*>::iterator it = AdjacencyVector.begin(); it != AdjacencyVector.end(); it++)
	{
		(*it)->distance = 999;
		(*it)->previous = NULL;
		(*it)->done = false;
		VertexNode* currentNode = (*it)->next;
		while (currentNode != NULL)
		{
			currentNode->distance = 999;
			currentNode->done = false;
			currentNode->previous = NULL;
			currentNode = currentNode->next;
		}
	}
}


//string path to storage
unordered_map<string, string> DAGraph::WritePathToStorage(int givenNumber, string vertexName)
{
	unordered_map<string, string> edgesCollection;
	VertexNode* SN = getVertex(vertexName);
	int index = 1;
	for (std::vector<VertexNode*>::iterator it = AdjacencyVector.begin(); it != AdjacencyVector.end(); it++)
	{
		if (index == givenNumber)
		{
			if ((*it)->NodeData != vertexName)
			{
				std::vector<string> pathCollection;
				pathCollection.push_back((*it)->NodeData);
				if ((*it)->previous != NULL)
				{
					pathCollection.push_back(((*it)->previous)->NodeData);
					VertexNode* NodeX = (*it)->previous;
					while (NodeX->NodeData != vertexName)
					{
						pathCollection.push_back((NodeX->previous)->NodeData);
						NodeX = NodeX->previous;
					}
				}
				while (pathCollection.size() > 0)
				{
					string edgename1 = pathCollection.back();
					pathCollection.erase(pathCollection.end() - 1);
					if (pathCollection.size() > 0)
					{
						string edgename2 = pathCollection.back();
						edgesCollection.insert({ edgename1, edgename2 });
					}
				}
			}
		}
		index++;
	}
	return edgesCollection;
}


//geting shortest distatnce for vertices
void DAGraph ::GetDist(int givenNumber, string vertexName)
{
	//std::cout << "\n   Vertex Name \t Distance from source vertex " << vertexName ;
	VertexNode* SN = getVertex(vertexName);
	for (std::vector<VertexNode*>::iterator edgeIndex = AdjacencyVector.begin(); edgeIndex != AdjacencyVector.end(); edgeIndex++)
	{
		std::vector<string> EdgecCollection;
		int weight = 0;

		EdgecCollection.push_back((*edgeIndex)->NodeData);

		if ((*edgeIndex)->previous != NULL)
		{

			EdgecCollection.push_back(((*edgeIndex)->previous)->NodeData);
			//cout << "\nPath: "<<(*edgeIndex)->NodeData <<"   "<< (((*edgeIndex)->previous) -> NodeData) << endl;
			weight += getWeight((*edgeIndex)->previous, (*edgeIndex));
			VertexNode* x = (*edgeIndex)->previous;
			while (x->NodeData != vertexName)
			{

				EdgecCollection.push_back((x->previous)->NodeData);
				//cout << ((x->previous) -> NodeData) << endl;
				weight += getWeight(x->previous, x);
				x = x->previous;
			}
		}
		//std::cout << "\n" << "\t" << vertexName << "\t\t" << (*edgeIndex)->NodeData << "\t";
		//std::cout << "\t\t" << weight << "\t\t";
		std::cout << weight << "\t\t";
		while (EdgecCollection.size() > 0)
		{
			EdgecCollection.erase(EdgecCollection.end() - 1);
		}
	}
	std::cout << "\n";
}

//getting all the edges
void DAGraph::GetPath(int giveNumber, string vertexName)
{
	VertexNode* NodeVertex = getVertex(vertexName);
	int index = 1;
	for (std::vector<VertexNode*>::iterator edgeIndex = AdjacencyVector.begin(); edgeIndex != AdjacencyVector.end(); edgeIndex++)
	{
		if (index <= giveNumber)
		{
			if ((*edgeIndex)->NodeData != vertexName)
			{
				std::vector<string> edgeCollection;
				int wt = 0;

				edgeCollection.push_back((*edgeIndex)->NodeData);

				if ((*edgeIndex)->previous != NULL)
				{

					edgeCollection.push_back(((*edgeIndex)->previous)->NodeData);
					wt += getWeight((*edgeIndex)->previous, (*edgeIndex));
					VertexNode* x = (*edgeIndex)->previous;
					while (x->NodeData != vertexName)
					{

						edgeCollection.push_back((x->previous)->NodeData);
						wt += getWeight(x->previous, x);
						x = x->previous;
					}
				}
				if (edgeCollection.size() > 1)
				{
					std::cout << "\n\t" << (*edgeIndex)->NodeData << " \t\t";
					index++;
				}

				while (edgeCollection.size() > 0)
				{
					std::cout << edgeCollection.back() << " ";
					edgeCollection.erase(edgeCollection.end() - 1);
				}
			}
			else
			{
				std::cout << "\n\t" << (*edgeIndex)->NodeData << " \t\t" << "nil" << " ";
			}
		}
	}
	std::cout << "\n";
}

//find the shortest path using DJ algorithem
void DAGraph ::findShortestPath(string vNodeName)
{
	Initialize();
	string v1 = vNodeName;
	VertexNode* t = getVertex(v1);
	t->distance = 0;
	for (int i = 0; i < numOfVertices; i++)
	{
		VertexNode* t = getVertex(vNodeName);
		t->done = true;
		VertexNode* temp = t->next;
		while (temp != NULL)
		{
			if (!getVertex(temp->NodeData)->done)
				UpdateDataRelaxation(t, temp);
			temp = temp->next;
		}
		t = getMin();
		if (t != NULL)
			vNodeName = t->NodeData;
		else
			break;
	}
}

//get minimum value node
VertexNode* DAGraph ::getMin()
{
	int min = 999;
	VertexNode* SingleNode = NULL;
	for (std::vector<VertexNode*>::iterator it = AdjacencyVector.begin(); it != AdjacencyVector.end(); it++)
	{
		if ((*it)->distance < min && (*it)->done == false)
		{
			min = (*it)->distance;
			SingleNode = getVertex((*it)->NodeData);
		}
	}
	return SingleNode;
}


//update all the data after changes
void DAGraph ::UpdateDataRelaxation(VertexNode* uNode, VertexNode* vNode)
{
	int w = getWeight(uNode, vNode);
	if (vNode->distance > (uNode->distance + w))
	{
		updateVertexData(vNode->NodeData, (uNode->distance + w), uNode);
	}
}

//update all the vertex data
void DAGraph::updateVertexData(string vNode, int new_distance, VertexNode* new_previous)
{
	for (std::vector<VertexNode*>::iterator it = AdjacencyVector.begin(); it != AdjacencyVector.end(); it++)
	{
		if ((*it)->NodeData == vNode)
		{
			(*it)->distance = new_distance;
			(*it)->previous = new_previous;
		}
		VertexNode* tNode = (*it)->next;
		while (tNode != NULL)
		{
			if (tNode->NodeData == vNode)
			{
				tNode->distance = new_distance;
				tNode->previous = new_previous;
			}
			tNode = tNode->next;
		}
	}
}

//insert the edge
void DAGraph ::InsertEdge(string NodeV1, string NodeV2, int NodeWeight)
{
	bool add = true;
	InsertVertex(NodeV1);
	InsertVertex(NodeV2);

	VertexNode* temp = getVertex(NodeV1);
	while (temp->next != NULL)
	{
		if (temp->next->NodeData == NodeV2)
		{
			add = false;
			break;
		}
		else
			temp = temp->next;
	}
	if (add)
	{
		temp->next = new VertexNode(NodeV2, NodeWeight);
		num_Edges++;
	}
	add = true;
	if (IsUndirected)
	{
		VertexNode* temp = getVertex(NodeV2);
		while (temp->next != NULL)
		{
			if (temp->next->NodeData == NodeV1)
			{
				add = false;
				break;
			}
			else
				temp = temp->next;
		}
		if (add)
		{
			temp->next = new VertexNode(NodeV1, NodeWeight);
			num_Edges++;
		}
	}
}


//getting weight for the edge
int DAGraph::getWeight(VertexNode* uNodeName, VertexNode* vNodeName)
{
	VertexNode* it = getVertex(uNodeName->NodeData);
	VertexNode* currentNode = it->next;
	while (currentNode != NULL)
	{
		if (currentNode->NodeData == vNodeName->NodeData)
		{
			return currentNode->NodeWeight;
		}
		currentNode = currentNode->next;
	}
	return 999;
}

//insert the vertex
void DAGraph ::InsertVertex(string vNodeName)
{
	if (!IsVertexExist(vNodeName))
	{
		VertexNode* vertex = new VertexNode(vNodeName);
		AdjacencyVector.push_back(vertex);
		numOfVertices++;
	}
}



//delete the given edge
void DAGraph ::deleteEdge(string NodeName1, string NodeName2)
{
	if (getVertex(NodeName1) != NULL && getVertex(NodeName2) != NULL)
	{
		VertexNode* V1 = getVertex(NodeName1);
		VertexNode* temp = NULL;
		VertexNode* prev = V1;
		temp = V1->next;
		while (temp != NULL)
		{
			if (temp->NodeData == NodeName2)
			{
				if (temp->next == NULL)
				{
					prev->next = NULL;
					num_Edges--;
				}
				else
				{
					prev->next = temp->next;
					num_Edges--;
					break;
				}
			}
			prev = temp;
			temp = temp->next;
		}

		if (IsUndirected) //removing edges in IsUndirected graph
		{
			VertexNode* V2 = getVertex(NodeName2);
			VertexNode* temp = NULL;
			VertexNode* prev = V2;
			temp = V2->next;
			while (temp != NULL)
			{
				if (temp->NodeData == NodeName1)
				{
					if (temp->next == NULL)
					{
						prev->next = NULL;
						num_Edges--;
					}
					else
					{
						prev->next = temp->next;
						num_Edges--;
						break;
					}
				}
				prev = temp;
				temp = temp->next;
			}
		}
	}
}

///check whether given vertex exist or not.
bool DAGraph::IsVertexExist(string search_key)
{

	for (std::vector<VertexNode*>::iterator it = AdjacencyVector.begin(); it != AdjacencyVector.end(); it++)
		if ((*it)->NodeData == search_key)
			return true;
	return false;
}

//getting the name of vertex
VertexNode* DAGraph::getVertex(string search_key)
{

	for (std::vector<VertexNode*>::iterator it = AdjacencyVector.begin(); it != AdjacencyVector.end(); it++)
		if ((*it)->NodeData == search_key)
		{
			return *it;
		}
	return NULL;
}

