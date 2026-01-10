class Solution {
    int solve(int i,int j,string s1,string s2,vector<vector<int>>& dp){
        if(i<0 && j<0)return 0;
        if(i < 0){
            int curr=0;
            for(int k=j;k>=0;k--)
            curr+=(int)s2[k];                
            return curr;
        }
        if(j < 0){
            int curr=0;
            for(int k=i;k>=0;k--)
            curr+=(int)s1[k];
            return curr;            
        }

        if(dp[i][j] != -1)return dp[i][j];

        if(s1[i] == s2[j]){
            return dp[i][j] = solve(i-1,j-1,s1,s2,dp);
        }
        return dp[i][j] = min((int)s1[i]+ solve(i-1,j,s1,s2,dp),
        (int)s2[j]+ solve(i,j-1,s1,s2,dp));
    }
public:
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.length(),m=s2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            dp[i][0]=dp[i-1][0]+(int)s1[i-1];
        }
        for(int j=1;j<=m;j++){
            dp[0][j]=dp[0][j-1]+(int)s2[j-1];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]=min((int)s1[i-1]+dp[i-1][j],
                    (int)s2[j-1]+dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};