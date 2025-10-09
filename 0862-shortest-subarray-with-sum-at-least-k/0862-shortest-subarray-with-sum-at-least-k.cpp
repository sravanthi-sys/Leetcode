class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int l=0,r=0,len=INT_MAX;
        long long sum=0;
        while(r<nums.size()){
            sum+=nums[r];
            if(sum>=k){
                len=min(len,r-l+1);
            
            while(sum>=k){
                sum-=nums[l];
                l++;
            }}
            r++;
        }
        if(len==INT_MAX)return -1;
        return len;
    }
};