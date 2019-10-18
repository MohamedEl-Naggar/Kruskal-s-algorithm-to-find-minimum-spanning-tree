#pragma once
#include <string>
using namespace std;


typedef int weightType;		// weights are positive integers
const int Vmax = 50;		      // Maximum number of vertices
const int Emax = Vmax*(Vmax - 1) / 2;   // Maximum number of edges

class Graph
{
private:
	class Sets
	{
	public:
		int *p, *r;
		int n;

		Sets(int n)
		{
			this->n = n;
			p = new int[n + 1];
			r = new int[n + 1];

			for (int i = 0; i <= n; i++)
			{
				r[i] = 0;

				p[i] = i;
			}
		}


		int find(int u)
		{
			if (u != p[u])
				p[u] = find(p[u]);
			return p[u];
		}

		void merge(int x, int y)
		{
			x = find(x), y = find(y);

			if (r[x] > r[y])
				p[y] = x;
			else 
				p[x] = y;

			if (r[x] == r[y])
				r[y]++;
		}
	};
	class Edge
	{
	public:
		int u, v;	weightType w;
		bool operator < (const Edge &e) { return (w < e.w); }
		bool operator <= (const Edge &e) { return (w <= e.w); }
	}; // end of class Edge declaration
	int V, E;			// No.of vertices (V) and edges (E) 
	weightType AdjMatrix[Vmax][Vmax];	// Adjacency Matrix
	Edge edges[Emax];		// Array of non-zero edges
	Edge sorted_edges[Emax];        //Sorted edges
	Edge MST[Emax];        //minimum spanning tree
	int order = -1;			// Order of Visit of a node in the DFS
	int val[Vmax];		// Array holding order of traversal void getEdges();	
	void visit(int k);		// Node Visit Function for DFS


public:
	Graph();
	~Graph();
	void getGraph(string fname);	// Get Graph from text File (fname)
	void DFS();		// Depth First Search Traversal (DFS)
	int kruskal();
};

