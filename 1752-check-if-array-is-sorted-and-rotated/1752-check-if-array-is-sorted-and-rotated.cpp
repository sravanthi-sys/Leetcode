class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int maxi=0,cnt=1;
        for(int i=1;i<(2*n);i++){
            if(nums[i%n] >= nums[(i-1)%n] ){
                cnt++;
            }
            else{
                maxi=max(maxi,cnt);
                cnt=1;
            }
        }
        maxi=max(maxi,cnt);
        cout<<maxi;
        return maxi>=n;
    }
};