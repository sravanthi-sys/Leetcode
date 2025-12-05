class Solution {
public:
    int countPartitions(vector<int>& nums) {
        vector<int> prefix(nums.size()+1,0);
        for(int i=0;i<nums.size();i++){
            prefix[i+1]=prefix[i]+nums[i];
        }
        int cnt=0,n=nums.size();
        for(int i=1;i<nums.size();i++){
            if(abs(prefix[i]-prefix[0]-(prefix[n]-prefix[i]))%2==0)cnt++;
        }
        return cnt;
    }
};