class Solution {
public:
    int concatenatedBinary(int n) {
        long long ans = 0, two = 1;
        int mod = 1e9 + 7; 
        for(int i = n ; i > 0 ; i --){
            int temp = i;
            while(temp > 0){
                if(temp & 1){
                    ans = (ans + two) % mod;
                }
                temp >>= 1;
                two = (two * 2) % mod;
            }
        }
        return ans;
    }
};