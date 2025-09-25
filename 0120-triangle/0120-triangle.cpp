class Solution {
    int solve(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>& memo,int n){
        if(i==n-1){
            return triangle[i][j];
        }
        if(j> i){
            return 1e9;
        }
        if(memo[i][j] != -1)return memo[i][j];
        int bottom=solve(i+1,j,triangle,memo,n);
        int bottomRight=solve(i+1,j+1,triangle,memo,n);
        return memo[i][j]=min(bottom,bottomRight)+triangle[i][j];
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> memo(n,vector<int>(n,-1));
        return solve(0,0,triangle,memo,n);
    }
};