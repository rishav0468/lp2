#include <iostream>
#include <limits.h>
using namespace std;

// Number of vertices in the graph


// A utility function to find the vertex with minimum
// distance value, from the set of vertices not yet included
// in shortest path tree
int minDistance(int dist[], bool sptSet[],int v)
{

	// Initialize min value
	int min = INT_MAX, min_index;

	for (int i = 0; i < v; i++)   
		if (sptSet[i] == false && dist[i] <= min)
			min = dist[i], min_index = i;

	return min_index;
}

// A utility function to print the constructed distance
// array
void printSolution(int dist[],int v)
{
	cout << "Vertex \t Distance from Source" << endl;
	for (int i = 0; i < v; i++)
		cout << i+1 << " \t" << dist[i] << endl;
}

// Function that implements Dijkstra's single source
// shortest path algorithm for a graph represented using
// adjacency matrix representation
void dijkstra(int graph[][10], int src,int v)
{
	int dist[v]; // The output array. dist[i] will hold the
				// shortest
	// distance from src to i

	bool sptSet[v]; // sptSet[i] will be true if vertex i is
					// included in shortest
	// path tree or shortest distance from src to i is
	// finalized

	// Initialize all distances as INFINITE and stpSet[] as
	// false
	for (int i = 0; i < v; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	// Distance of source vertex from itself is always 0
	dist[src] = 0;

	// Find shortest path for all vertices
	for (int count = 0; count < v - 1; count++) {
		// Pick the minimum distance vertex from the set of
		// vertices not yet processed. u is always equal to
		// src in the first iteration.
		int u = minDistance(dist, sptSet,v);

		// Mark the picked vertex as processed
		sptSet[u] = true;

		// Update dist value of the adjacent vertices of the
		// picked vertex.
		for (int i = 0; i < v; i++){
            // Update dist[i] only if it is not in sptSet,
            // there is an edge from u to i, and total
            // weight of path from src to i through u is
            // smaller than current value of dist[i]
            if (!sptSet[i] && graph[u][i] && dist[u] != INT_MAX && dist[u] + graph[u][i] < dist[i])
                dist[i] = dist[u] + graph[u][i];
        }
    }

	// print the constructed distance array
	printSolution(dist,v);
}

// driver's code
int main()
{

	int v;
    cout << "Enter the number of vertices in the graph: ";
    cin >> v;

    int graph[10][10];
    cout << "Enter the adjacency matrix representation of the graph:" << endl;
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cin >> graph[i][j];
        }
    }

    int src;
    cout << "Enter the source vertex: ";
    cin >> src;

    // Function call
    dijkstra(graph, src, v);
    return 0;
}



















// Enter the number of vertices in the graph: 5
// Enter the adjacency matrix representation of the graph:
// 0 10 0 5 0
// 0 0 1 2 0
// 0 0 0 0 4
// 0 3 9 0 2
// 7 0 6 0 0
// Enter the source vertex: 0







// Vertex 	 Distance from Source
// 1 	0
// 2 	8
// 3 	9
// 4 	5
// 5 	7



















