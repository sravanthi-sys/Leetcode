class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int j,i=0,count=0;
        while(i<n){
            j=i;
            count=0;
            while(j<n && nums[i]==nums[j] ){
                count++;
                j++;
            }
            if(count==n/2)return nums[i];
            i+=count;
        }
        return -1;
    }
};