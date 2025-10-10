class Solution {
    bool solve(int mid, vector<int>& nums, int th){
        int temp= 0;
        for(int i = 0 ; i < nums.size() ; i ++){
            temp += ceil(nums[i] / (double)mid);
        }
        return temp <= th;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = *max_element(nums.begin(), nums.end()), ans = -1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(solve(mid, nums, threshold)){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};