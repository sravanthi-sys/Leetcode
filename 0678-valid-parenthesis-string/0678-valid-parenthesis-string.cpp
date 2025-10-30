class Solution {
    bool solve(int ind, int n, int open, string& s, vector<vector<int>>& dp){
        if(ind >= n)return open == 0;
        if(dp[ind][open] != -1)return dp[ind][open];
        if(s[ind] == '('){
            return dp[ind][open] = solve(ind + 1, n, open + 1, s, dp);
        }
        else if(s[ind] == ')'){
            if(open <= 0)return dp[ind][open] = false;
            return dp[ind][open] = solve(ind + 1, n, open - 1, s, dp);
        }
        else{
            dp[ind][open] = solve(ind + 1, n, open + 1, s, dp) || solve(ind + 1, n, open, s, dp);
            if(open > 0)
            dp[ind][open] = dp[ind][open] || solve(ind + 1, n, open - 1, s, dp);
            return dp[ind][open];
        }
        return dp[ind][open] = false;
    }
public:
    bool checkValidString(string s) {
        vector<vector<int>> dp(s.length(), vector<int>(s.length(), -1));
        return solve(0, s.length(), 0, s, dp);
    }
};