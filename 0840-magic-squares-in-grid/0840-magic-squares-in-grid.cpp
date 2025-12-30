class Solution {
public:
int helper(vector<vector<int>>& grid,int r,int c){
    vector<int> count(10, 0);
        for (int x = 0; x < 3; ++x) {
            for (int y = 0; y < 3; ++y) {
                int num = grid[r + x][c + y];
                if (num < 1 || num > 9 || count[num] > 0) return false;
                count[num]++;
            }
        }
    //checking row sum
    for(int i=0;i<3;i++){
        if(15 != (grid[i + r][c] + grid[i + r][c + 1] + grid[i + r][c + 2]))return 0;
    }
    //checking column sum
    
       for(int y = 0; y < 3; ++y) {
            if(15 != (grid[r][c + y] + grid[r + 1][c + y] + grid[r + 2][c + y])) 
            return 0;
        }
    
    //checking diagonal sum
    if(grid[r][c]+grid[r+1][c+1]+grid[r+2][c+2] !=15 || 
    grid[r][c+2]+grid[r+1][c+1]+grid[r+2][c] !=15){
        cout<<"diag 0";
        return 0;
    }

    return 1;
}
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size();
        int cnt=0;
        for(int i=0;i<=r-3;i++){
            for(int j=0;j<=c-3;j++){
                cnt+=helper(grid,i,j);
            }
        }
        return cnt;
    }
};