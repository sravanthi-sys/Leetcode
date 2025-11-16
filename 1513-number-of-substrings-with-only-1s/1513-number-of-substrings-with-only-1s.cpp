class Solution {
public:
    int numSub(string s) {
        int ones = 0, ans = 0, mod = 1e9 + 7;
        for(int i = 0 ; i < s.length() ; i ++){
            if(s[i] == '1'){
                ones ++;
                ans = (ans + ones) % mod;
            }
            else ones = 0;
        }
        return ans;
    }
};