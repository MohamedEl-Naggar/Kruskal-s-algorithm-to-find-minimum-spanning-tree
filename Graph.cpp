#include "Graph.h"
#include <iostream>
#include <fstream>

Graph::Graph()
{
	V = 20;
	E = 0;
}


Graph::~Graph()
{
	
}

void Graph::getGraph(string fname)
{
	ifstream file(fname);
	if (!file.is_open())
		cout << "Cannot open file";
	else
		for (int i = 0; i < V; i++)
			for (int j = 0; j < V; j++)
				file >> AdjMatrix[i][j];

	for (int i = 0; i < V; i++)
		for (int j = i+1; j < V; j++)
			if (AdjMatrix[i][j] > 0)
			{
				edges[E].u = i;
				edges[E].v = j;
				edges[E].w = AdjMatrix[i][j];
				E++;
			}
	cout << "This is what the graph looks like: " << endl << endl;
	
	for (int i = -1; i < V; i++)
	{
		for (int j = -1; j < V; j++)
			if (i == -1)
				cout << char(j + 65) << "  ";
			else
				if (j == -1)
					cout << char(i + 65) << "  ";
				else
			if (AdjMatrix[i][j] == 0)
				cout << "00 ";
			else
				cout << AdjMatrix[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	cout << "There are " << E << " edges:" << endl;
	for (int i = 0; i < E; i++)
		cout << char(edges[i].u + 65) << " " << char(edges[i].v + 65) << " " << edges[i].w << endl;
}
void Graph::visit(int k)
{
	val[k] = ++order;
	for (int t = 0; t < V; t++)
		if (AdjMatrix[k][t] != 0)
			if (val[t] == -2)
				visit(t);
}
void Graph::DFS()
{
	int corder = 0;
	int unseen = -2;
	for (int k = 0; k < V; k++)
		val[k] = unseen;
	for (int k = 0; k < V; k++)
		if (val[k] == unseen)
			visit(k);
	cout << "Order of depth first traversal is: ";
	for (int i = 0; i < V; i++)
		for (int j = 0; j < V; j++)
		{
			if (corder == val[j])
			{
				cout << char(j + 65);
				corder++;
				if (i != V - 1)
					cout << " --> ";
				break;
			}
		}

	cout << endl;
}
int Graph::kruskal()
{
	for(int i=0; i<E; i++)
		sorted_edges[i] = edges[i];
	for (int i = 0; i < E; i++)
		for (int j = i + 1; j < E; j++)
			if (sorted_edges[j] < sorted_edges[i])
				swap(sorted_edges[j], sorted_edges[i]);

	Sets d(V);

	for (int i = 0; i < V; i++)
	{
		int first = sorted_edges[i].u;
		int second = sorted_edges[i].v;

		int set_u = d.find(first);
		int set_v = d.find(second);


		if (set_u != set_v)
		{
			MST[i] = sorted_edges[i];
			d.merge(set_u, set_v);
		}
	}
	int cost = 0;

	for (int n = 0; n < E; n++)
		if(MST[n].w>0)
			cout << "the MST edges: " << char(65 + MST[n].u) << " " << char(65 + MST[n].v) << " " << MST[n].w << endl;

	for (int i = 0; i < E; i++)
		if (MST[i].w > 0)
			cost += MST[i].w;

	return cost;

	return 0;
}