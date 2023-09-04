//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Initial Template for C++

class Solution{
public:
    void helper(vector<vector<char>>& mat, int x, int y, int M, int N, char prev, char next){
        if (x < 0 || x >= M || y < 0 || y >= N)
            return;
        if (mat[x][y] != prev)
            return;
     
        mat[x][y] = next;
     
        helper(mat, x+1, y, M, N, prev, next);
        helper(mat, x-1, y, M, N, prev, next);
        helper(mat, x, y+1, M, N, prev, next);
        helper(mat, x, y-1, M, N, prev, next);    
    }
    
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 'O')
                    mat[i][j] = '-';
            }
        }
        for(int i=0; i<n; i++){
            if(mat[i][0] == '-')
                helper(mat, i, 0, n, m, '-', 'O');
        }
        for(int i=0; i<n; i++){
            if(mat[i][m-1] == '-')
                helper(mat, i, m-1, n, m, '-', 'O');
        }
        for(int i=0; i<m; i++){
            if(mat[0][i] == '-')
                helper(mat, 0, i, n, m, '-', 'O');
        }
        for(int i=0; i<m; i++){
            if(mat[n-1][i] == '-')
                helper(mat, n-1, i, n, m, '-', 'O');
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == '-')
                    mat[i][j] = 'X';
            }
        }
        return mat;
    }
};

//{ Driver Code Starts

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends
