#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 


class DSU { 
	int* parent; 
	int* rank; 

public: 
	DSU(int n) 
	{ 
		parent = new int[n]; 
		rank = new int[n]; 

		for (int i = 0; i < n; i++) { 
			parent[i] = -1; 
			rank[i] = 1; 
		} 
	} 

	// Find function 
	int find(int i) 
	{ 
		if (parent[i] == -1) 
			return i; 

		return parent[i] = find(parent[i]); 
	} 

	// Union function 
	void unite(int x, int y) 
	{ 
		int s1 = find(x); 
		int s2 = find(y); 

		if (s1 != s2) { 
			if (rank[s1] < rank[s2]) { 
				parent[s1] = s2; 
			} 
			else if (rank[s1] > rank[s2]) { 
				parent[s2] = s1; 
			} 
			else { 
				parent[s2] = s1; 
				rank[s1] += 1; 
			} 
		} 
	} 
}; 

class Graph { 
	vector<vector<int> >edgelist; 
	int V; 

public: 
	Graph(int V) { this->V = V; } 

	// Function to add edge in a graph 
	void addEdge(int x, int y, int w) 
{ 
    vector<int> edge;
    edge.push_back(w);
    edge.push_back(x);
    edge.push_back(y);
    edgelist.push_back(edge); 
}

	void kruskals_mst() 
	{ 
		// Sort all edges 
		sort(edgelist.begin(), edgelist.end()); 

		// Initialize the DSU 
		DSU s(V); 
		int ans = 0; 
		cout << "Following are the edges in the constructed MST"<< endl; 
		for (int i=0;i<edgelist.size();i++) { 
			int w = edgelist[i][0]; 
			int x = edgelist[i][1]; 
			int y = edgelist[i][2]; 

			// Take this edge in MST if it does 
			// not forms a cycle 
			if (s.find(x) != s.find(y)) { 
				s.unite(x, y); 
				ans += w; 
				cout << x << " -- " << y << " == " << w << endl; 
			} 
		} 
		cout << "Minimum Cost Spanning Tree: " << ans<<endl;
	} 
}; 

// Driver code 
int main() 
{ 
    int V, E;
    cout << "Enter the number of vertices in the graph: ";
    cin >> V;
    cout << "Enter the number of edges in the graph: ";
    cin >> E;

    Graph g(V); 

    cout << "Enter the edges (source destination weight):" << endl;
    for (int i = 0; i < E; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        g.addEdge(x, y, w);
    }

    g.kruskals_mst(); 

    return 0; 
}




















// enter no of vertices
// 5
// enter no of edge 
// 6
// enter the edge.  
// 0 1 5
// 0 4 2
// 1 4 3
// 1 2 4 
// 2 3 6