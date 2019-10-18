#include <iostream>
#include "graph.h"
using namespace std;

void main()
{
	Graph g;
	g.getGraph("graphmatrix.txt");
	g.DFS();
	cout << "The cost is: " << g.kruskal() << endl;
	system("pause");
}