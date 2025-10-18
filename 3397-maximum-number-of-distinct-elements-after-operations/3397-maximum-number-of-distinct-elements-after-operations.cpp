class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int next=INT_MIN;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            int curr=max(next,nums[i]-k);
            if(curr <= nums[i]+k){
                cnt++;
                next=curr+1;
            }
        }
        return cnt;
    }
};