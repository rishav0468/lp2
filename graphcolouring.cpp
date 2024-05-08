#include <iostream>
using namespace std;
#define V 4

void printSolution(int color[]);

bool isSafe(int v, bool graph[V][V], int color[], int c)
{
	for (int i = 0; i < V; i++)
		if (graph[v][i] && c == color[i])
			return false;

	return true;
}

bool graphColoringUtil(bool graph[V][V], int m, int color[],int v){
	/* base case: If all vertices areassigned a color then return true */
	if (v == V)
		return true;
	/* Consider this vertex v and try different colors */
	for (int c = 1; c <= m; c++) {
		/* Check if assignment of color c to v is fine*/
		if (isSafe(v, graph, color, c)) {
			color[v] = c;
			
			if (graphColoringUtil(graph, m, color, v + 1) == true)   /* recur to assign colors to rest of the vertices */
				return true;
			color[v] = 0;   /* If assigning color c doesn't	lead to a solution then remove it */
		}
	}
	return false; /* If no color can be assigned tot his vertex then return false */
}

bool graphColoring(bool graph[V][V], int m)
{
	int color[V];
	for (int i = 0; i < V; i++)
		color[i] = 0;

	// Call graphColoringUtil() for vertex 0
	if (graphColoringUtil(graph, m, color, 0) == false) {
		cout <<"Solution does not exist";
		return false;
	}
	for(int k=0;k<V;k++){
            // cout<<color_ans[k]<<" ";
            //1==red, 2==green,3==yellow,and son on 
            cout<<"Node "<<k<<": ";
            if(color[k]==1){
                cout<<"red";
            }else if(color[k]==2){
                cout<<"green";
            }else if(color[k]==3){
                cout<<"yellow";
            }else if(color[k]==4){
                cout<<"blue";
            }else if(color[k]==5){
                cout<<"orange";
            }else if(color[k]==6){
                cout<<"white";
            }else{
                cout<<"black";
            }
            cout<<"\n";
        }

	// Print the solution
	printSolution(color);
	return true;
}

void printSolution(int color[])
{
	cout << "Solution Exists:"
		<< " Following are the assigned colors"
		<< "\n";
	
	 for (int i = 0; i < V; i++)
        cout << "Node " << i << ": " << color[i] << endl;

}

int main()
{

	/* Create following graph and test
	whether it is 3 colorable
	(3)---(2)
	|    / |
	|   /  |
	| /    |
	(0)---(1)
	*/
	bool graph[V][V] = {                                   
		{ 0, 1, 1, 1 },
		{ 1, 0, 1, 0 },
		{ 1, 1, 0, 1 },
		{ 1, 0, 1, 0 },
	};
    /*bool graph[V][V];

 cout << "Enter the adjacency matrix of the graph (0 or 1):\n";
 for (int i = 0; i < V; i++)
 {
     cout << "Row " << i + 1 << ": ";
     for (int j = 0; j < V; j++)
     cin >> graph[i][j];
 }*/


	// Number of colors
	int m = 4;

	// Function call
	graphColoring(graph, m);
	return 0;
}

