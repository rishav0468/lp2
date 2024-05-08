#include <iostream>
#include <limits.h>
using namespace std;

// #define v 5

int main() {
    int v;
    cout << "Enter the number of vertices in the graph: ";
    cin >> v;

    
    int G[v][v];
    cout << "Enter the adjacency matrix of the graph:" << endl;
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            cin >> G[i][j];
        }
    }

    int selected[v];
    //memset is a function in C++ used to fill a block of memory with a particular value. 
    //It stands for "memory set". It is often used to initialize arrays or to set memory regions to specific values.


    //memset(selected, false, sizeof(selected));


    
    for (int i = 0; i < v; i++) {
        selected[i] = false;
    }


    
    int noedge = 0;
    selected[0] = true;

    cout << "Edge : Weight" << endl;
    while (noedge < v - 1) {
        int min = INT_MAX;
        int x = 0, y = 0;
        for (int i = 0; i < v; i++) {
            if (selected[i]) {
                for (int j = 0; j < v; j++) {
                    if (!selected[j] && G[i][j]) {
                        if (min > G[i][j]) {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        cout << x << " - " << y << " : " << G[x][y] << endl;
        selected[y] = true;
        noedge++;
    }

    return 0;
}










// Enter the number of vertices in the graph: 5
// Enter the adjacency matrix of the graph:
// 0 2 0 6 0
// 2 0 3 8 5
// 0 3 0 0 7
// 6 8 0 0 9
// 0 5 7 9 0





// Edge : Weight
// 0 - 1 : 2
// 1 - 2 : 3
// 0 - 3 : 6
// 1 - 4 : 5


