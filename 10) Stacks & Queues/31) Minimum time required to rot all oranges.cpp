#include<bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    if(grid.empty()) return -1;
    int total = 0, ans = 0, cnt = 0;
    queue<pair<int, int>> q;
    for(int i=0; i<grid.size(); i++) {
        for(int j=0; j<grid[i].size(); j++) {
            if(grid[i][j] != 0) total++;
            if(grid[i][j] == 2) q.push({i, j});
        }
    }
    
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    
    while(!q.empty()) {
        int len = q.size();
        cnt += len;
        while(len--) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i=0; i<4; i++) {
                int nx = x+dx[i], ny = y+dy[i];
                if(nx<0 || ny<0 || nx>=grid.size() || ny>=grid[0].size() || grid[nx][ny]!=1) 
                    continue;
                grid[nx][ny] = 2;
                q.push({nx, ny});
            }
        }
        if(!q.empty()) ans++;
    }
    return (cnt==total ? ans : -1);
}

int main() {
    vector<vector<int>> vec {{0,1,2},{0,1,2},{2,1,1}};
    // 0 represents empty cell, 1 represents Fresh Oranges, 2 represents Rotten Oranges.
    cout<<"Oranges in cells are:\n";
    for(int i=0; i<vec.size(); i++) {
        for(int j=0; j<vec[i].size(); j++) {
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Minimum time required to rot all the Oranges is: "<<orangesRotting(vec);
    return 0;
}