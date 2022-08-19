#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>nearest(vector<vector<int>>grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<int>> dist(n, vector<int>(m, 0));
    queue<pair<pair<int, int>, int>> q;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(grid[i][j] == 1) {
                q.push({{i, j}, 0});
                vis[i][j] = 1;
            }
        }
    }
    
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    
    while(!q.empty()) {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int steps = q.front().second;
        q.pop();
        dist[row][col] = steps;
        
        for(int i=0; i<4; i++) {
            int nrow = row + dx[i];
            int ncol = col + dy[i];
            if(nrow<0 || ncol<0 || nrow>=n || ncol>=m || vis[nrow][ncol] == 1) 
                continue;
            vis[nrow][ncol] = 1;
            q.push({{nrow, ncol}, steps+1});
        }
    }
    
    return dist;
}

int main() {
    vector<vector<int>> grid {{0,1,1,0},{1,1,0,0},{0,0,1,1}};
    cout<<"Values of Cells are:\n";
    for(int i=0; i<grid.size(); i++) {
        for(int j=0; j<grid[i].size(); j++) {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Binary Matrix of Distance of nearest cell having 1 is:\n";
    grid = nearest(grid);
    for(int i=0; i<grid.size(); i++) {
        for(int j=0; j<grid[i].size(); j++) {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}