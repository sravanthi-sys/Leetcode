class Solution {
    int n;
    vector<int> dr = {-1, 0, 1, 0}, dc = {0, 1, 0, -1};
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp, 
    vector<vector<int>>& vis){
        if(i < 0 || i >= n || j < 0 || j >= n || vis[i][j])return INT_MAX;
        if(i == n - 1 && j == n - 1)return grid[i][j];
        if(dp[i][j] != -1)return dp[i][j];
        int mini = INT_MAX;
        vis[i][j] = 1;
        for(int ind = 0 ; ind < 4 ; ind ++){
            int nr = i + dr[ind], nc = j + dc[ind];
            mini = min(mini, solve(nr, nc, grid, dp, vis));
        }
        vis[i][j] = 0;
        return dp[i][j] = max(grid[i][j], mini);
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));
        int ans = INT_MAX;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, 
        greater<>>  pq;
        pq.push({grid[0][0], {0, 0}});
        vis[0][0] = 1;
        while(!pq.empty()){
            int maxi = pq.top().first, r = pq.top().second.first, c = pq.top().second.second;
            pq.pop();
            if(r == n - 1 && c == n - 1)return maxi;
            for(int ind = 0 ; ind < 4 ; ind ++){
                int nr = r + dr[ind], nc = c + dc[ind];
                if(nr >= 0 && nr < n && nc >= 0 && nc < n && !vis[nr][nc]){
                    vis[nr][nc] = 1;
                    pq.push({max(maxi, grid[nr][nc]), {nr, nc}});
                }
            }
        }
        return ans;
    }
};