//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int m, n;
    void dfs(vector<vector<int>> &grid, int i, int j){
        
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0)   
            return;
        
        grid[i][j] = 0;
        
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
    }
    
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        m = grid.size();
        n = grid[0].size();
        
        for(int i = 0; i < m; i++){
            if(grid[i][0] == 1){
                dfs(grid, i, 0);
            }
                
            if(grid[i][n - 1] == 1){
                dfs(grid, i, n - 1);
            }
        }
        
        // cover boundary rows
        for(int j = 0; j < n; j++){
            if(grid[0][j] == 1){
                dfs(grid, 0, j);
            }
                
            if(grid[m - 1][j] == 1){
                dfs(grid, m - 1, j);
            }
        }
        
        int count = 0;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){  
                    ++count;
                }
            }
        }
        
        return count;
    }
    
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends
