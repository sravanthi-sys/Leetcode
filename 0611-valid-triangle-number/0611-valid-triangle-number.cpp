class Solution {
    bool isTriPos(int a,int b,int c){
        return (a+b > c) && (b+c > a) && (c+a > b);
    }
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0,j,k,n=nums.size()-1,ans=0;
        while(i<n-1){
            j=i+1;
            while(j<n){
                int low=j+1,high=n,mid,curr=j;
                while(low<=high){
                    mid=(low+high)/2;
                    if(isTriPos(nums[i],nums[j],nums[mid])){
                        curr=mid;
                        low=mid+1;
                    }
                    else{
                        high=mid-1;
                    }
                    
                }
                ans+=curr-j;
                j++;
            }
            i++;
        }
        return ans;
    }
};