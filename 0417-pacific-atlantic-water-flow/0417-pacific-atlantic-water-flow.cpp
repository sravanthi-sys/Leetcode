class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int n = heights.size(), m = heights[0].size();
        vector<int> dr = {-1, 0, 1 , 0}, dc = {0, 1, 0, -1};
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < m ; j ++){
                bool flag1 = false, flag2 = false;
                queue<pair<int, int>> q;
                vector<vector<int>> vis(n, vector<int>(m, 0));
                vis[i][j] = 1;
                q.push({i, j});
                while(!q.empty()){
                    int r = q.front().first, c = q.front().second;
                    q.pop();
                    for(int ind = 0 ; ind < 4 ; ind ++){
                        int nr = r + dr[ind], nc = c + dc[ind];
                        if(nr < 0 || nc < 0)flag1 = true;
                        if(nr >= n || nc >= m)flag2 = true;
                        if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && 
                        heights[r][c] >= heights[nr][nc]){
                            vis[nr][nc] = 1;
                            q.push({nr, nc});
                        }
                    }
                    if(flag1 && flag2)break;
                }
                if(flag1 && flag2)ans.push_back({i, j});
            }
        }
        return ans;
    }
};