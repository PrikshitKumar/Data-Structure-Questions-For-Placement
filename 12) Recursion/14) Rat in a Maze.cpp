#include<bits/stdc++.h>
using namespace std;

// Method 1:-
/* void solve(int i, int j, vector<vector<int>> &arr, int size, string path, 
            vector<vector<int>> &vis, vector<string> &ans) {
    
    if(i == size-1 && j == size-1) {
        ans.push_back(path);
        return;
    }
    
    // Downward
    if(i+1 < size && !vis[i+1][j] && arr[i+1][j] == 1) {
        vis[i][j] = 1;
        solve(i+1, j, arr, size, path+'D', vis, ans);
        vis[i][j] = 0;
    }
    
    // Left
    if(j-1 >= 0 && !vis[i][j-1] && arr[i][j-1] == 1) {
        vis[i][j] = 1;
        solve(i, j-1, arr, size, path+'L', vis, ans);
        vis[i][j] = 0;
    }
    
    // Right
    if(j+1 < size && !vis[i][j+1] && arr[i][j+1] == 1) {
        vis[i][j] = 1;
        solve(i, j+1, arr, size, path+'R', vis, ans);
        vis[i][j] = 0;
    }
    
    // Upward
    if(i-1 >= 0 && !vis[i-1][j] && arr[i-1][j] == 1) {
        vis[i][j] = 1;
        solve(i-1, j, arr, size, path+'U', vis, ans);
        vis[i][j] = 0;
    }
}

vector<string> findPath(vector<vector<int>> &arr, int size) {
    vector<string> ans;
    vector<vector<int>> vis(size, vector<int> (size, 0));
    if(arr[0][0] == 1) solve(0, 0, arr, size, "", vis, ans);
    return ans;
}
*/

// Method 2:- Automatic Direction Change from pre-defined Sides 
void solve(int i, int j, vector<vector<int>> &arr, int size, string path, 
            vector<vector<int>> &vis, vector<string> &ans, int di[], int dj[]) {
    if (i == size-1 && j == size-1) {
        ans.push_back(path);
        return;
    }
    string dir = "DLRU";
    for(int ind = 0; ind < 4; ind++) {
        int nexti = i + di[ind];
        int nextj = j + dj[ind];
        if (nexti >= 0 && nextj >= 0 && nexti < size && nextj < size && !vis[nexti][nextj] && arr[nexti][nextj] == 1) {
            vis[i][j] = 1;
            solve(nexti, nextj, arr, size, path+dir[ind], vis, ans, di, dj);
            vis[i][j] = 0;
        }
    }
}

vector<string> findPath(vector<vector<int>> &arr, int size) {
    vector<string> ans;
    vector<vector<int>> vis(size, vector<int> (size, 0));
    int di[] = {+1, 0, 0, -1};
    int dj[] = {0, -1, +1, 0};
    if(arr[0][0] == 1) solve(0, 0, arr, size, "", vis, ans, di, dj);
    return ans;
}

int main() {
    int size = 4;
    vector<vector<int>> arr = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    vector < string > result = findPath(arr, size);
    if (result.size() == 0) cout<<"Not a single path exists.";
    else {
        cout<<"All Possible Paths are:\n";
        for (int i=0; i<result.size(); i++) {
            cout<<result[i]<<endl;
        }
    }
    return 0;
}