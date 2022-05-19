class Solution {
public:
    int dp[201][201];
    int n, m;
    int dfs(vector<vector<int>>& mat, int i, int j, int prev){
        if(i < 0 || j < 0 || i >= n || j >= m || mat[i][j] <= prev) return 0;
        if(dp[i][j]) return dp[i][j];
        
        return dp[i][j] = 1 + max({dfs(mat, i + 1, j, mat[i][j]),
                                   dfs(mat, i - 1, j, mat[i][j]),
                                   dfs(mat, i, j + 1, mat[i][j]),
                                   dfs(mat, i, j - 1, mat[i][j]) 
                                   });       
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans = 0;
        n = matrix.size();
        m = matrix[0].size();
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                ans = max(ans, dfs(matrix, i, j, -1));            
        return ans;
    }
};