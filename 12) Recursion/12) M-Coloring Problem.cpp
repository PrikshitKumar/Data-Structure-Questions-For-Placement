#include<bits/stdc++.h>
using namespace std;

bool isPossible(int painted[], int currNode, int currColor, int n, bool graph[101][101]) {
    for(int i=0; i<n; i++) {
        if(i!=currNode && graph[i][currNode] == 1 && painted[i] == currColor) {
            return false;
        }
    }
    return true;
}

bool solve(int painted[], int m, int n, int currNode, bool graph[101][101]) {
    if(currNode == n) {
        return true;
    }
    
    for(int i=1; i<=m; i++) {
        if(isPossible(painted, currNode, i, n, graph)) {
            painted[currNode] = i;
            if(solve(painted, m, n, currNode+1, graph) == true) return true;
            painted[currNode] = 0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n) {
  int painted[n] = {0};
  if (solve(painted, m, n, 0, graph)) return true;
  return false;
}

int main() {
    int n = 4;
    int m = 3;
    bool graph[101][101];
    memset(graph, false, sizeof(graph));

    // Edges are (0, 1), (1, 2), (2, 3), (3, 0), (0, 2)
    graph[0][1] = 1; graph[1][0] = 1;
    graph[1][2] = 1; graph[2][1] = 1;
    graph[2][3] = 1; graph[3][2] = 1;
    graph[3][0] = 1; graph[0][3] = 1;
    graph[0][2] = 1; graph[2][0] = 1;
    
    cout<<"Can we color the Graph with all conditions satisfied? "<<graphColoring(graph, m, n);
    return 0;
}