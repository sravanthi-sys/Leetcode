class Solution {
    int solve(int ind, int n, int z, int o, vector<pair<string, pair<int, int>>>& vp, 
    vector<vector<vector<int>>>& dp){
        if(ind == n)return 0;
        if(dp[ind][z][o] != -1)return dp[ind][z][o];
        int pick = 0;
        if(z >= vp[ind].second.first && o >= vp[ind].second.second)
        pick = 1 + solve(ind + 1, n, z - vp[ind].second.first, o - vp[ind].second.second, 
        vp, dp);
        return dp[ind][z][o] = max(pick, solve(ind + 1, n, z, o, vp, dp));
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int s = strs.size();
        vector<pair<string, pair<int, int>>> vp(s); //{"string",{0s, 1s}}
        for(int i = 0 ; i < s ; i ++){
            int zeros = 0, ones = 0;
            for(char ch : strs[i]){
                if(ch == '0')zeros ++;
                else ones ++;
            }
            vp[i] = {strs[i], {zeros, ones}};
        }
        vector<vector<vector<int>>> dp(s, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return solve(0, s, m, n, vp, dp);
    }
};