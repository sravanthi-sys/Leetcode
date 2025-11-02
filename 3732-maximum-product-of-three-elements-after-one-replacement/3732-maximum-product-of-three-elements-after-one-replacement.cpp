class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        long long max1 = 0, max2 = 0;
        for(int i = 0 ; i < nums.size() ; i ++){
            if(abs(nums[i]) > max1){
                max2 = max1;
                max1 = abs(nums[i]);
            }
            else if(abs(nums[i]) > max2){
                max2 = abs(nums[i]);
            }
        }
        return max1 * max2 * 1e5;
    }
};