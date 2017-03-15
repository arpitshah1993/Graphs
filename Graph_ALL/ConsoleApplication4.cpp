
#include "DAGraph.h"
#include "graph.cpp"
#include <iostream>
#include <string>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include<fstream>
#include <tr1/unordered_map>
#include <cstdio>
#include <vector>
#include<sstream>
using namespace std;
using namespace std::tr1;

namespace std {
	template<typename T>
	std::string to_string(const T &n) {
		std::ostringstream s;
		s << n;
		return s.str();
	}
}

bool IsContainsGenerateNumber(std::vector<int> alreadyGeneratedNumber, int num)
{
	for (int i = 0; i < alreadyGeneratedNumber.size(); i++)
	{
		if (alreadyGeneratedNumber[i] == num)
			return true;
	}
	return false;
}
int getRandomUniqueNumber(std::vector<int> alreadyGeneratedNumber, int limit, int array[5])
{
	int creatednum = array[rand() % limit];

	while (IsContainsGenerateNumber(alreadyGeneratedNumber, creatednum))
	{
		creatednum = array[rand() % limit];
	}
	return creatednum;
}


int main()
{
	cout << "****************************************************************************************" << endl;
	cout << "******************************************Test case-1****************************************" << endl;
	SGraph CaseGraph1;
	vector<string> graphNames1;
	vector<vertex*> graphVertexname1;

	ifstream file1("fig1.csv");
	string Testvalue1;

	for (int aj = 0; aj < 9; aj++)
	{
		if (aj < 8)
		{
			getline(file1, Testvalue1, ',');
		}
		else
		{
			getline(file1, Testvalue1, '\n');
		}
		graphNames1.push_back(Testvalue1);
	}

	vertex* r = new vertex(graphNames1[1]);
	graphVertexname1.push_back(r);
	vertex* s = new vertex(graphNames1[2]);
	graphVertexname1.push_back(s);
	vertex* t = new vertex(graphNames1[3]);
	graphVertexname1.push_back(t);
	vertex* u = new vertex(graphNames1[4]);
	graphVertexname1.push_back(u);
	vertex* v = new vertex(graphNames1[5]);
	graphVertexname1.push_back(v);
	vertex* w = new vertex(graphNames1[6]);
	graphVertexname1.push_back(w);
	vertex* x = new vertex(graphNames1[7]);
	graphVertexname1.push_back(x);
	vertex* y = new vertex(graphNames1[8]);
	graphVertexname1.push_back(y);

	for (int ai = 0; ai < 8; ai++)
	{
		getline(file1, Testvalue1, ',');
		for (int aj = 0; aj < 8; aj++)
		{
			if (aj < 7)
			{
				getline(file1, Testvalue1, ',');
			}
			else
			{
				getline(file1, Testvalue1, '\n');
			}
			if (Testvalue1 == "1")
			{
				graphVertexname1[ai]->AppendEdge(graphVertexname1[aj], 0);
			}
		}
		CaseGraph1.SInsert(graphVertexname1[ai]);
	}
	CaseGraph1.PrintUndirect("t1.dot");
	cout << "Created t1.dot file" << endl<<endl;
	cout << "****************************************************************************************" << endl;
	cout << "******************************************Test case-2****************************************" << endl;
	SGraph TestCaseGraph2;
	vector<string> TestCaseName2;
	vector<vertex*> TestCasevertexname2;

	ifstream file2("fig2.csv");
	string value2;

	for (int aj = 0; aj < 7; aj++)
	{
		if (aj < 6)
		{
			getline(file2, value2, ',');
		}
		else
		{
			getline(file2, value2, '\n');
		}
		TestCaseName2.push_back(value2);
	}

	vertex* vertex1 = new vertex(TestCaseName2[1]);
	TestCasevertexname2.push_back(vertex1);
	vertex* vertex2 = new vertex(TestCaseName2[2]);
	TestCasevertexname2.push_back(vertex2);
	vertex* vertex3 = new vertex(TestCaseName2[3]);
	TestCasevertexname2.push_back(vertex3);
	vertex* vertex4 = new vertex(TestCaseName2[4]);
	TestCasevertexname2.push_back(vertex4);
	vertex* vertex5 = new vertex(TestCaseName2[5]);
	TestCasevertexname2.push_back(vertex5);
	vertex* vertex6 = new vertex(TestCaseName2[6]);
	TestCasevertexname2.push_back(vertex6);

	for (int ai = 0; ai < 6; ai++)
	{
		getline(file2, value2, ',');
		for (int aj = 0; aj < 6; aj++)
		{
			if (aj < 5)
			{
				getline(file2, value2, ',');
			}
			else
			{
				getline(file2, value2, '\n');
			}
			if (value2 == "1")
			{

				TestCasevertexname2[ai]->AppendEdge(TestCasevertexname2[aj], 0);
			}
		}
		TestCaseGraph2.SInsert(TestCasevertexname2[ai]);
	}
	TestCaseGraph2.PrintDirect("t2.dot");
	cout << "Created t2.dot file" << endl << endl;
	cout << "****************************************************************************************" << endl;
	cout << "******************************************Test case-3****************************************" << endl;
	SGraph TestCaseGraph3;
	vector<string> TestCaseNames3;
	vector<string> TestCaseNames3weight;
	int weights3;
	vector<vertex*> vertexname3;

	ifstream file3("fig3.csv");
	ifstream file3weight("fig3-w.csv");
	string value3;
	string value3w;

	for (int aj = 0; aj < 6; aj++)
	{
		if (aj < 5)
		{
			getline(file3, value3, ',');
		}
		else
		{
			getline(file3, value3, '\n');
		}
		TestCaseNames3.push_back(value3);
	}

	for (int aj = 0; aj < 6; aj++)
	{
		if (aj < 5)
		{
			getline(file3weight, value3w, ',');
		}
		else
		{
			getline(file3weight, value3w, '\n');
		}
		TestCaseNames3weight.push_back(value3w);
	}

	vertex* vertex31 = new vertex(TestCaseNames3[1]);
	vertexname3.push_back(vertex31);
	vertex* vertex32 = new vertex(TestCaseNames3[2]);
	vertexname3.push_back(vertex32);
	vertex* vertex33 = new vertex(TestCaseNames3[3]);
	vertexname3.push_back(vertex33);
	vertex* vertex34 = new vertex(TestCaseNames3[4]);
	vertexname3.push_back(vertex34);
	vertex* vertex35 = new vertex(TestCaseNames3[5]);
	vertexname3.push_back(vertex35);

	for (int ai = 0; ai < 5; ai++)
	{
		getline(file3, value3, ',');
		getline(file3weight, value3w, ',');
		for (int aj = 0; aj < 5; aj++)
		{
			if (aj < 4)
			{
				getline(file3, value3, ',');
				getline(file3weight, value3w, ',');
			}
			else
			{
				getline(file3, value3, '\n');
				getline(file3weight, value3w, '\n');
			}
			if (value3 == "1")
			{
				weights3 = atoi(value3w.c_str());
				vertexname3[ai]->AppendEdge(vertexname3[aj], weights3);
			}
		}
		TestCaseGraph3.SInsert(vertexname3[ai]);
	}
	TestCaseGraph3.PrintDirectWeightedGraph("t3.dot");

	cout << "Created t3.dot file" << endl << endl;
	cout << "****************************************************************************************" << endl;
	cout << "******************************************Test case-4****************************************" << endl;
	vertex* z = new vertex("z");
	z->AppendEdge(graphVertexname1[5], 0);
	z->AppendEdge(graphVertexname1[6], 0);
	z->AppendEdge(graphVertexname1[7], 0);
	CaseGraph1.SInsert(z);
	CaseGraph1.PrintUndirect("t4a.dot");

	CaseGraph1.deleteGivenVertex("s");
	CaseGraph1.deleteGivenVertex("x");
	for (int ai = 0; ai < 5; ai++)
	{
		if ("u" == CaseGraph1.actVertexList[ai]->vertexName)
		{
			CaseGraph1.actVertexList[ai]->RemovingEdge("t");
		}
		if ("t" == CaseGraph1.actVertexList[ai]->vertexName)
		{
			CaseGraph1.actVertexList[ai]->RemovingEdge("u");
		}
	}
	u->RemovingEdge("t");
CaseGraph1.PrintUndirect("t4b.dot");
	cout << "Created t4a.dot file"<< endl;
cout << "Created t4b.dot file" << endl << endl;
	cout <<"****************************************************************************************" << endl;
	cout << "******************************************Test case-5****************************************" << endl;
	SGraph TestCaseGraph5;
	vector<vertex*> vertexname5;

	vertex* testCase5a = new vertex("6");
	vertexname5.push_back(testCase5a);
	vertex* testCase5b = new vertex("7");
	vertexname5.push_back(testCase5b);
	vertex* testCase5c = new vertex("8");
	vertexname5.push_back(testCase5c);
	vertex* testCase5d = new vertex("9");
	vertexname5.push_back(testCase5d);
	vertex* testCase5e = new vertex("10");
	vertexname5.push_back(testCase5e);

	for (int ai = 0; ai < vertexname5.size(); ai++)
	{
		if (ai < 4)
		{
			vertexname5[ai]->AppendEdge(vertexname5[ai + 1], 0);
		}
		else
		{
			vertexname5[ai]->AppendEdge(vertexname5[ai - 4], 0);
		}

		TestCaseGraph5.SInsert(vertexname5[ai]);
	}
	vertex* testCase5f = new vertex("1");
	vertexname5.push_back(testCase5f);
	vertex* testCase5g = new vertex("2");
	vertexname5.push_back(testCase5g);
	vertex* testCase5h = new vertex("3");
	vertexname5.push_back(testCase5h);
	vertex* testCase5i = new vertex("4");
	vertexname5.push_back(testCase5i);
	vertex* testCase5j = new vertex("5");
	vertexname5.push_back(testCase5j);

	for (int ai = 0; ai < 5; ai++)
	{
		vertexname5[ai + 5]->AppendEdge(vertexname5[ai], 0);
		TestCaseGraph5.SInsert(vertexname5[ai + 5]);
	}
	TestCaseGraph5.PrintUndirect("t5a.dot");
	cout << "Created t5a.dot file" << endl;
	TestCaseGraph5.deleteGivenVertex("8");
	TestCaseGraph5.deleteGivenVertex("6");
	TestCaseGraph5.PrintUndirect("t5b.dot");
	cout << "Created t5b.dot file" << endl << endl;
	cout << endl << "****************************************************************************************" << endl;
	cout << "******************************************Test case-6****************************************" << endl;
	srand(time(NULL));
	SGraph TestCaseGraph6;
	vector<vertex*> vertexname6;

	int randArray[] = { 2,4,6,8,10 };
	vector<int> GenratedNum;
	int temp = getRandomUniqueNumber(GenratedNum, 5, randArray);
	vertex* testCase6a = new vertex(std::to_string(temp));
	vertexname6.push_back(testCase6a);
	GenratedNum.push_back(temp);
	temp = getRandomUniqueNumber(GenratedNum, 5, randArray);
	vertex* testCase6b = new vertex(std::to_string(temp));
	vertexname6.push_back(testCase6b);
	GenratedNum.push_back(temp);
	temp = (getRandomUniqueNumber(GenratedNum, 5, randArray));
	vertex* testCase6c = new vertex(std::to_string(temp));
	vertexname6.push_back(testCase6c);
	GenratedNum.push_back(temp);
	temp = (getRandomUniqueNumber(GenratedNum, 5, randArray));
	vertex* testCase6d = new vertex(std::to_string(temp));
	vertexname6.push_back(testCase6d);
	GenratedNum.push_back(temp);
	temp = (getRandomUniqueNumber(GenratedNum, 5, randArray));
	vertex* testCase6e = new vertex(std::to_string(temp));
	vertexname6.push_back(testCase6e);
	GenratedNum.push_back(temp);
	GenratedNum.clear();

	TestCaseGraph6.AddEdgeWithoutVertex(vertexname6, "2", "4");
	TestCaseGraph6.AddEdgeWithoutVertex(vertexname6, "2", "6");
	TestCaseGraph6.AddEdgeWithoutVertex(vertexname6, "4", "6");
	TestCaseGraph6.AddEdgeWithoutVertex(vertexname6, "4", "8");
	TestCaseGraph6.AddEdgeWithoutVertex(vertexname6, "6", "8");
	TestCaseGraph6.AddEdgeWithoutVertex(vertexname6, "6", "10");
	TestCaseGraph6.AddEdgeWithoutVertex(vertexname6, "8", "10");
	TestCaseGraph6.AddEdgeWithoutVertex(vertexname6, "8", "2");

	int randArray1[] = { 1,3,5,7,9 };
	temp = getRandomUniqueNumber(GenratedNum, 5, randArray1);
	vertex* test6f = new vertex(std::to_string(temp));
	vertexname6.push_back(test6f);
	GenratedNum.push_back(temp);
	temp = getRandomUniqueNumber(GenratedNum, 5, randArray1);
	vertex* test6g = new vertex(std::to_string(temp));
	vertexname6.push_back(test6g);
	GenratedNum.push_back(temp);
	temp = (getRandomUniqueNumber(GenratedNum, 5, randArray1));
	vertex* test6h = new vertex(std::to_string(temp));
	vertexname6.push_back(test6h);
	GenratedNum.push_back(temp);
	temp = (getRandomUniqueNumber(GenratedNum, 5, randArray1));
	vertex* test6i = new vertex(std::to_string(temp));
	vertexname6.push_back(test6i);
	GenratedNum.push_back(temp);
	temp = (getRandomUniqueNumber(GenratedNum, 5, randArray1));
	vertex* test6j = new vertex(std::to_string(temp));
	vertexname6.push_back(test6j);
	GenratedNum.push_back(temp);
	GenratedNum.clear();

	TestCaseGraph6.AddEdgeWithoutVertex(vertexname6, "1", "2");
	TestCaseGraph6.AddEdgeWithoutVertex(vertexname6, "3", "4");
	TestCaseGraph6.AddEdgeWithoutVertex(vertexname6, "5", "6");
	TestCaseGraph6.AddEdgeWithoutVertex(vertexname6, "7", "8");
	TestCaseGraph6.AddEdgeWithoutVertex(vertexname6, "9", "10");

	for (int aj = 0; aj < vertexname6.size(); aj++)
	{
		TestCaseGraph6.SInsert(vertexname6[aj]);
	}

	TestCaseGraph6.PrintDirect("t6a.dot");
	cout << "Created t6a.dot file" << endl;
	int deleteGivenVertex = randArray[rand() % 5];
	TestCaseGraph6.deleteGivenVertex(std::to_string(deleteGivenVertex));

	int delvertex1 = randArray1[rand() % 5];
	TestCaseGraph6.deleteGivenVertex(std::to_string(delvertex1));
	TestCaseGraph6.PrintDirect("t6b.dot");

	cout << "Created t6b.dot file" << endl << endl;
	cout << endl << "****************************************************************************************" << endl;
	cout << "******************************************Test case-7****************************************" << endl;

	DAGraph TestCaseGraph7;
	vector<string> names7;
	vector<string> names7w;
	int weights7;

	ifstream file7("fig3.csv");
	ifstream file7w("fig3-w.csv");
	string value7;
	string value7w;

	for (int aj = 0; aj < 6; aj++)
	{
		if (aj < 5)
		{
			getline(file7, value7, ',');
		}
		else
		{
			getline(file7, value7, '\n');
		}
		names7.push_back(value7);
	}

	for (int aj = 0; aj < 6; aj++)
	{
		if (aj < 5)
		{
			getline(file7w, value7w, ',');
		}
		else
		{
			getline(file7w, value7w, '\n');
		}
		names7w.push_back(value7w);
	}

	for (int aj = 0; aj < 5; aj++)
	{
		weights7 = atoi(names7w[aj + 1].c_str());
	}

	for (int ai = 0; ai < 5; ai++)
	{
		getline(file7w, value7w, ',');
		getline(file7, value7, ',');
		for (int aj = 0; aj < 5; aj++)
		{
			if (aj < 4)
			{
				getline(file7, value7, ',');
				getline(file7w, value7w, ',');
			}
			else
			{
				getline(file7, value7, '\n');
				getline(file7w, value7w, '\n');
			}
			if (value7 == "1")
			{
				weights7 = atoi(value7w.c_str());
				TestCaseGraph7.InsertEdge(names7[ai + 1], names7[aj + 1], weights7);
			}
		}
	}

	cout << "W\t \t s\t\t t\t\t y\t\t x\t\t z\t\t " << endl;
	cout << "-------------------------------------------------------------------------------------------------------" << endl;
	for (int aj = 0; aj<5; aj++)
	{
		cout << "\n" << names7w[aj + 1] << "\t \t";
		TestCaseGraph7.findShortestPath(names7[aj + 1]);
		TestCaseGraph7.GetDist(TestCaseGraph7.numOfVertices, names7[aj + 1]);
	}
	cout << endl << "****************************************************************************************" << endl;
	cout << "******************************************Test case-8****************************************" << endl;

	DAGraph TestCaseGraph8;
	TestCaseGraph8.IsUndirected = true;
	vector<string> names8;

	ifstream file8("fig3-w.csv");
	string value8;

	for (int aj = 0; aj < 6; aj++)
	{
		if (aj < 5)
		{
			getline(file8, value8, ',');
		}
		else
		{
			getline(file8, value8, '\n');
		}
		names8.push_back(value8);
	}

	int a[5][5];
	for (int ai = 0; ai < 5; ai++)
	{
		getline(file8, value8, ',');
		for (int aj = 0; aj < 5; aj++)
		{
			if (aj < 4)
			{
				getline(file8, value8, ',');
			}
			else
			{
				getline(file8, value8, '\n');
			}
			a[ai][aj] = atoi(value8.c_str());
		}
	}

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			int a1 = a[i][j];
			int a2 = a[j][i];
			if (a1 == -1)
			{
				a[i][j] = 100;
			}
			else if (a1 != -1 && a2 != -1 && i<j)
			{
				if (a1<a2)
				{
					a[i][j] = a[j][i] = a1;
				}
			}
		}
	}

	for (int ai = 0; ai < 5; ai++)
	{
		for (int aj = 0; aj < 5; aj++)
		{
			if ((a[ai][aj] > 0) && (a[ai][aj] < 50))
			{
				TestCaseGraph8.InsertEdge(names8[ai + 1], names8[aj + 1], a[ai][aj]);
			}
		}
	}

	cout << "W\t \t s\t\t t\t\t y\t\t x\t\t z\t\t " << endl;
	cout << "-------------------------------------------------------------------------------------------------------" << endl;
	for (int aj = 0; aj<names8.size() - 1; aj++)
	{
		cout << "\n" << names8[aj + 1] << "\t \t";
		TestCaseGraph8.findShortestPath(names8[aj + 1]);
		TestCaseGraph8.GetDist(TestCaseGraph8.numOfVertices, names8[aj + 1]);
	}

	cout << endl << "****************************************************************************************" << endl;
	cout << "******************************************Test case-9****************************************" << endl;


	DAGraph TestCaseGraph9;
	vector<string> names9;
	vector<string> names9w;
	int weights9;

	ifstream file9("fig3.csv");
	ifstream file9w("fig3-w.csv");
	string value9;
	string value9w;

	for (int aj = 0; aj < 6; aj++)
	{
		if (aj < 5)
		{
			getline(file9, value9, ',');
		}
		else
		{
			getline(file9, value9, '\n');
		}
		names9.push_back(value9);
	}

	for (int aj = 0; aj < 6; aj++)
	{
		if (aj < 5)
		{
			getline(file9w, value9w, ',');
		}
		else
		{
			getline(file9w, value9w, '\n');
		}
		names9w.push_back(value9w);
	}

	for (int aj = 0; aj < 5; aj++)
	{
		weights9 = atoi(names9w[aj + 1].c_str());
	}

	for (int ai = 0; ai < 5; ai++)
	{
		getline(file9w, value9w, ',');
		getline(file9, value9, ',');
		for (int aj = 0; aj < 5; aj++)
		{
			if (aj < 4)
			{
				getline(file9, value9, ',');
				getline(file9w, value9w, ',');
			}
			else
			{
				getline(file9, value9, '\n');
				getline(file9w, value9w, '\n');
			}
			if (value9 == "1")
			{
				weights9 = atoi(value9w.c_str());
				TestCaseGraph9.InsertEdge(names9[ai + 1], names9[aj + 1], weights9);
			}
		}
	}

	cout << "Vertex\t \t The GetPath from source vertex s to this vertex in G3\t\t" << endl;
	TestCaseGraph9.findShortestPath("s");
	TestCaseGraph9.GetPath(5, "s");
	cout << endl;
	cout << "Vertex\t \t The GetPath from source vertex s to this vertex in G3\t\t" << endl;
	TestCaseGraph9.findShortestPath("z");
	TestCaseGraph9.GetPath(5, "z");

	cout << endl<<"****************************************************************************************" << endl;
	cout << "******************************************Test case-10****************************************" << endl;

	DAGraph TestCaseGraph10;
	TestCaseGraph10.IsUndirected = true;
	vector<string> graphNames10;

	ifstream file10("fig3-w.csv");
	string Testvalue10;

	for (int aj = 0; aj < 6; aj++)
	{
		if (aj < 5)
		{
			getline(file10, Testvalue10, ',');
		}
		else
		{
			getline(file10, Testvalue10, '\n');
		}
		graphNames10.push_back(Testvalue10);
	}

	int ax[5][5];
	for (int ai = 0; ai < 5; ai++)
	{
		getline(file10, Testvalue10, ',');
		for (int aj = 0; aj < 5; aj++)
		{
			if (aj < 4)
			{
				getline(file10, Testvalue10, ',');
			}
			else
			{
				getline(file10, Testvalue10, '\n');
			}
			ax[ai][aj] = atoi(Testvalue10.c_str());
		}
	}

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			int ay1 = ax[i][j];
			int ay2 = ax[j][i];
			if (ay1 == -1)
			{
				ax[i][j] = 100;
			}
			else if (ay1 != -1 && ay2 != -1 && i<j)
			{
				if (ay1<ay2)
				{
					ax[i][j] = ax[j][i] = ay1;
				}
			}
		}
	}

	for (int ai = 0; ai < 5; ai++)
	{
		for (int aj = 0; aj < 5; aj++)
		{
			if ((ax[ai][aj] > 0) && (ax[ai][aj] < 50))
			{
				TestCaseGraph10.InsertEdge(graphNames10[ai + 1], graphNames10[aj + 1], ax[ai][aj]);
			}
		}
	}

	cout << "Vertex\t \t The GetPath from source vertex s to this vertex in G4\t\t" << endl;
	TestCaseGraph10.findShortestPath("s");
	TestCaseGraph10.GetPath(5, "s");
	cout << endl;
	cout << "Vertex\t \t The GetPath from source vertex s to this vertex in G4\t\t" << endl;
	TestCaseGraph10.findShortestPath("z");
	TestCaseGraph10.GetPath(5, "z");

	cout << endl << "****************************************************************************************" << endl;
	cout << "******************************************Test case-11****************************************" << endl;

	DAGraph TestCaseGraph11;
	vector<string> graphNames11;
	vector<string> graphNames11w;
	int weights11;
	ifstream file11("fig3.csv");
	ifstream file11w("fig3-w.csv");
	string Testvalue11;
	string Testvalue11w;


	for (int aj = 0; aj < 6; aj++)
	{
		if (aj < 5)
		{
			getline(file11, Testvalue11, ',');
		}
		else
		{
			getline(file11, Testvalue11, '\n');
		}
		graphNames11.push_back(Testvalue11);
	}

	for (int aj = 0; aj < 6; aj++)
	{
		if (aj < 5)
		{
			getline(file11w, Testvalue11w, ',');
		}
		else
		{
			getline(file11w, Testvalue11w, '\n');
		}
		graphNames11w.push_back(Testvalue11w);
	}

	for (int aj = 0; aj < 5; aj++)
	{
		weights11 = atoi(graphNames11w[aj + 1].c_str());
	}

	for (int ai = 0; ai < 5; ai++)
	{
		getline(file11w, Testvalue11w, ',');
		getline(file11, Testvalue11, ',');
		for (int aj = 0; aj < 5; aj++)
		{
			if (aj < 4)
			{
				getline(file11, Testvalue11, ',');
				getline(file11w, Testvalue11w, ',');
			}
			else
			{
				getline(file11, Testvalue11, '\n');
				getline(file11w, Testvalue11w, '\n');
			}
			if (Testvalue11 == "1")
			{
				weights11 = atoi(Testvalue11w.c_str());
				TestCaseGraph11.InsertEdge(graphNames11[ai + 1], graphNames11[aj + 1], weights11);
			}
		}
	}

	for (int aj = 0; aj< 5; aj++)
	{
		TestCaseGraph11.findShortestPath(graphNames11[aj + 1]);
		unordered_map<string, string> temp11a;
		temp11a = TestCaseGraph11.WritePathToStorage(11, graphNames11[aj + 1]);
		FILE *pFile11a;
		pFile11a = fopen("t11.dot", "w+");

		if (!pFile11a) {
			perror("File opening failed");
			return EXIT_FAILURE;
		}
		printDJGraph(&TestCaseGraph11, pFile11a, temp11a);
	}
	cout << "Max path: " << "x " << ":z " << " s" << ":y " << ":t" << endl;
	cout << "Created t11.dot file" << endl << endl;

	cout << endl << "****************************************************************************************" << endl;
	cout << "******************************************Test case-12****************************************" << endl;

	DAGraph TestCaseGraph12;
	vector<string> graphNames12;
	TestCaseGraph12.IsUndirected = true;

	ifstream file12("fig3-w.csv");
	string Testvalue12;

	for (int aj = 0; aj < 6; aj++)
	{
		if (aj < 5)
		{
			getline(file12, Testvalue12, ',');
		}
		else
		{
			getline(file12, Testvalue12, '\n');
		}
		graphNames12.push_back(Testvalue12);
	}

	int azc[5][5];
	for (int ai = 0; ai < 5; ai++)
	{
		getline(file12, Testvalue12, ',');
		for (int aj = 0; aj < 5; aj++)
		{
			if (aj < 4)
			{
				getline(file12, Testvalue12, ',');
			}
			else
			{
				getline(file12, Testvalue12, '\n');
			}
			azc[ai][aj] = atoi(Testvalue12.c_str());
		}
	}

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			int aa1 = azc[i][j];
			int aa2 = azc[j][i];
			if (aa1 == -1)
			{
				azc[i][j] = 120;
			}
			else if (aa1 != -1 && aa2 != -1 && i<j)
			{
				if (aa1<aa2)
				{
					azc[i][j] = azc[j][i] = aa1;
				}
			}
		}
		std::cout << std::endl;
	}

	for (int ai = 0; ai < 5; ai++)
	{
		for (int aj = 0; aj < 5; aj++)
		{
			if ((azc[ai][aj] > 0) && (azc[ai][aj] < 50))
			{
				TestCaseGraph12.InsertEdge(graphNames12[ai + 1], graphNames12[aj + 1], azc[ai][aj]);
			}
		}
	}

	for (int aj = 0; aj< 5; aj++)
	{
		TestCaseGraph12.findShortestPath(graphNames11[aj + 1]);
		unordered_map<string, string> temp12a;
		temp12a = TestCaseGraph12.WritePathToStorage(11, graphNames12[aj + 1]);
		FILE *pFile12a;
		pFile12a = fopen("t12.dot", "w+");

		if (!pFile12a) {
			perror("File opening failed");
			return EXIT_FAILURE;
		}
		printDJGraph(&TestCaseGraph12, pFile12a, temp12a);
	}
	cout << "Max path: " << "s " << ":y " << ":t " << ":x" << endl;
	cout << "Created t12.dot file" << endl << endl;
	
}

