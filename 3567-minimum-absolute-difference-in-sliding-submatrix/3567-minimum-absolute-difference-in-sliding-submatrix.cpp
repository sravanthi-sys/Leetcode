class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        vector<vector<int>> ans;
        int n = grid.size() ,m =grid[0].size();
        for(int i = 0 ; i <= n - k ;i++){
            vector<int> temp;
            for(int j = 0 ; j <= m - k ;j++){
                map<int ,int> mpp;
                for(int ii = i ; ii < i + k ;ii++){
                    for(int jj = j ; jj < j + k ;jj++){
                        mpp[grid[ii][jj]] ++;
                    }
                }
                if(mpp.size() == 1){
                    temp.push_back(0);
                    continue;
                }
                long long mini = INT_MAX ,prev = INT_MIN;
                bool flag = false;
                for(auto it : mpp){
                    if(flag)
                    mini = min(mini ,it.first - prev);
                    flag = true;
                    prev = it.first; 
                }
                temp.push_back(mini);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};