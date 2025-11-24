class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size(), mod = 1e9 + 7;
        vector<bool> ans(n, false);
        long long int temp = 0;
        for(int i = 0 ; i < n ; i ++){
            temp = (temp * 2) + nums[i];
            temp %= 5;
            if(temp % 5 == 0)ans[i] = true;
        }
        return ans;
    }
};