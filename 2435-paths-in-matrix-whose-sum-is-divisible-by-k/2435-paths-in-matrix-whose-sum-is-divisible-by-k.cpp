class Solution {
    int mod;
    int solve(int i, int j, int sum, int n, int m, int k, vector<vector<int>>& grid, 
    vector<vector<vector<int>>>& dp){
        if(i >= n || j >= m)return 0;
        if(i == n - 1 && j == m - 1)return (sum + grid[i][j]) % k == 0;
        if(dp[i][j][sum] != -1)return dp[i][j][sum];
        int right = solve(i, j + 1, (sum + grid[i][j]) % k, n, m, k, grid, dp);
        int bottom = solve(i + 1, j, (sum + grid[i][j]) % k, n, m, k, grid, dp);
        return dp[i][j][sum] = (right + bottom) % mod;
    }
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        mod = 1e9 + 7;
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k ,-1)));
        return solve(0, 0, 0, n, m, k, grid, dp);
    }
};