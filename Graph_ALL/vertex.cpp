//#pragma once

#include <string>
#include <utility>
#include <iostream>
#include <vector>
using namespace std;

class vertex;
class edge
{
private:
	vertex *sourceVertex;
	vertex *destinationVertex;
	int EdgeWeight;

public:

	//Costructor
	edge(vertex *srcVC, vertex *destVC, int EdgeWeight)
	{
		sourceVertex = srcVC;
		destinationVertex = destVC;
		EdgeWeight = EdgeWeight;
	}

	//Get the source Vertex Destination
	vertex* GetEdgeDestination()
	{
		return destinationVertex;
	}

	//Get the source Vertex weights
	int GetEdgeWeight()
	{
		return EdgeWeight;
	}
};

class vertex
{
public:
	string vertexName;
	vector<edge> edgesVector;
	vertex(string vertexname)
	{
		vertexName = vertexname;
	}

	void AppendEdge(vertex *v, int eweight)
	{
		edge enew(this, v, eweight);
		edgesVector.push_back(enew);
	}

	void RemovingEdge(string source)
	{
		for (int aj = 0; aj < edgesVector.size(); aj++)
		{
			edge currentEdge = edgesVector[aj];
			if (source == currentEdge.GetEdgeDestination()->vertexName)
			{
				edgesVector.erase(edgesVector.begin() + (aj));
				aj--;
			}
		}
	}

	string GetsSourceVertexName()
	{
		return vertexName;
	}
};
