class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<vector<int>> v(3, vector<int>());
        for(int i = 0 ; i < nums.size() ; i ++){
            v[nums[i] % 3].push_back(nums[i]);
        }
        for(int i = 1 ; i < 3 ; i ++){
            sort(v[i].begin(), v[i].end(), greater<>());
        }
        int sum = 0;
        for(int i = 0 ; i < v[0].size() ; i ++){
            sum += v[0][i];
        }
        int i = 0, j = 0;
        for(i ; i < v[1].size() && v[1].size() >= 3 ; i += 3){
            sum += (v[1][i] + v[1][i + 1] + v[1][i + 2]);
        }
        for(j ; j < v[2].size() && v[2].size() >= 3 ; j += 3){
            sum += (v[2][j] + v[2][j + 1] + v[2][j + 2]);
        }
        for(i, j ; i < v[1].size() && j < v[2].size() ; i ++){
            sum += v[1][i];
            sum += v[2][i];
        }
        return sum;
        return 0;
    }
};