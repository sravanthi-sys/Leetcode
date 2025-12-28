class Solution {
public:
int bs(vector<int> a,int n){
    int i;
    for( i=0;i<n;i++){
        if(a[i]<0){
            break;
        } 
    }
   
    return n-i;
}
    int countNegatives(vector<vector<int>>& grid) {
        int ans=0;
        int rows=grid.size();
        int cols=grid[0].size();
        for(int i=0;i<rows;i++){
            ans+=bs(grid[i],cols);
        }
        return ans;
    }
};