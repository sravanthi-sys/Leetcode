class Solution {
    bool bs(int tar, vector<int>& nums){
        int low = 0, high = nums.size() - 1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[mid] == tar)return true;
            else if(nums[mid] < tar)low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        for(int i = 0 ; i < nums1.size() ; i ++){
            if(bs(nums1[i], nums2))return nums1[i];
        }
        return -1;
    }
};