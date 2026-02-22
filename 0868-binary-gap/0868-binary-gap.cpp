class Solution {
public:
    int binaryGap(int n) {
       int ans=0,prev=-1,cnt=0;
       while(n){
        if((n & 1)){
            if(prev == -1)
            prev=cnt;
            else{
            ans=max(ans,cnt-prev);
            prev=cnt;
            }
        }
        cnt++;
        n=n>>1;
       } 
       return ans;
    }
};