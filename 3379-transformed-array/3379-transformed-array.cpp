class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                ans.push_back(nums[(i+nums[i])%n]);
            }
            else if(nums[i]==0){
                ans.push_back(nums[i]);
            }
            else{
                int index=(i+nums[i])%n;
                while(index<0){
                    index+=n;
                }
                ans.push_back(nums[index]);
            }
        }
        return ans;
    }
};