class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int cnt = 0, i;
        for(i = 1 ; i< nums.size() ; i ++){
            if(nums[i] == nums[i - 1])return false;
            if(nums[i] < nums[i - 1]){
                break;
            }
        }
        if(i > 1 && i < nums.size()){
            cnt ++;
            for(i ; i < nums.size() ;i ++){
                if(nums[i] == nums[i - 1])return false;
                if(nums[i] > nums[i - 1])break;
            }
        }
        if(i < nums.size()){
            cnt ++;
            for(i ; i < nums.size() ; i ++){
                if(nums[i] == nums[i - 1])return false;
                if(nums[i] < nums[i - 1])break;
            }
        }
        return cnt == 2 && i == nums.size();
    }
};