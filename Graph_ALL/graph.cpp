
#include "vertex.cpp"
#include <string>
#include <fstream>
class SGraph
{
public:
	vector<vertex*> actVertexList;
	SGraph() 
	{
	}

	void SInsert(vertex *vet)
	{
		actVertexList.push_back(vet);
	}

	void PrintUndirect(string filename)
	{
		std::ofstream outputFile;
		outputFile.open(filename.c_str());
		outputFile << " strict graph { node[shape = ellipse]; ";

		for (int i = 0; i < actVertexList.size(); i++)
		{
			outputFile << actVertexList[i]->vertexName << " ";
		}
		outputFile << ";";

		for (int i = 0; i < actVertexList.size(); i++)
		{
			for (int j = 0; j < actVertexList[i]->edgesVector.size(); j++)
			{
				edge edgei = actVertexList[i]->edgesVector[j];
				outputFile << actVertexList[i]->vertexName << "--" << edgei.GetEdgeDestination()->GetsSourceVertexName() << ";";
			}
		}

		outputFile << "}";
	}

	void deleteGivenVertex(string vertexName)
	{
		for (int aj = 0; aj < actVertexList.size(); aj++)
		{
			actVertexList[aj]->RemovingEdge(vertexName);
			if (vertexName == actVertexList[aj]->vertexName)
			{
				actVertexList.erase(actVertexList.begin() + (aj));
				aj--;
			}
		}
	}

	
	void AddEdgeWithoutVertex(vector<vertex* > VertexList, string sourceEdgeName, string destinationEdgeName)
	{
		vertex* destinationVertexNode = NULL;
		for (int i = 0; i < VertexList.size(); i++)
		{
			if (VertexList[i]->vertexName == destinationEdgeName)
			{
				destinationVertexNode = VertexList[i];
			}
		}
		for (int i = 0; i < VertexList.size(); i++)
		{
			if (VertexList[i]->vertexName == sourceEdgeName)
			{
				VertexList[i]->AppendEdge(destinationVertexNode, 0);
			}
		}
	}

	void PrintDirect(string filename)
	{
		std::ofstream outputFile;
		outputFile.open(filename.c_str());
		outputFile << " strict digraph { node[shape = ellipse]; ";

		for (int i = 0; i < actVertexList.size(); i++)
		{
			outputFile << actVertexList[i]->vertexName << " ";
		}
		outputFile << ";";

		for (int i = 0; i < actVertexList.size(); i++)
		{
			for (int j = 0; j < actVertexList[i]->edgesVector.size(); j++)
			{
				edge edgei = actVertexList[i]->edgesVector[j];
				outputFile << actVertexList[i]->vertexName << "->" << edgei.GetEdgeDestination()->GetsSourceVertexName() << ";";
			}
		}

		outputFile << "}";
	}

	void PrintDirectWeightedGraph(string outputFileName)
	{
		std::ofstream outputFile;
		outputFile.open(outputFileName.c_str());
		outputFile << " strict digraph { node[shape = ellipse]; ";

		for (int i = 0; i < actVertexList.size(); i++)
		{
			outputFile << actVertexList[i]->vertexName << " ";
		}
		outputFile << ";";

		for (int i = 0; i < actVertexList.size(); i++)
		{
			for (int j = 0; j < actVertexList[i]->edgesVector.size(); j++)
			{
				edge edgeCurrent = actVertexList[i]->edgesVector[j];
				outputFile << actVertexList[i]->vertexName << "->" << edgeCurrent.GetEdgeDestination()->GetsSourceVertexName() << "[label = " << edgeCurrent.GetEdgeWeight() << "];";
			}
		}
		outputFile << "}";
	}
};
