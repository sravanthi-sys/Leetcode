class Solution {
    int solve(int i,int j,int freezes,vector<vector<int>>& coins,vector<vector<vector<int>>>& dp){
        if(i < 0 || j<0)return -1e9;
        if(i==0 && j==0)return (coins[i][j] < 0 && freezes > 0)?0:coins[i][j] ;
        if(dp[i][j][freezes] != -1e9)return dp[i][j][freezes];
        int take=-1e9,nottake=-1e9;
        take = coins[i][j]+max(solve(i-1,j,freezes,coins,dp),solve(i,j-1,freezes,coins,dp));
        if(freezes > 0 && coins[i][j]<0)
            nottake =  max(solve(i-1,j,freezes-1,coins,dp),solve(i,j-1,freezes-1,coins,dp));
        return dp[i][j][freezes]=max(take,nottake);
    }
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n=coins.size(),m=coins[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(3,-1e9)));
        return solve(n-1,m-1,2,coins,dp);
    }
};