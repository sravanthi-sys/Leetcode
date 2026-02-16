class Solution {
public:
    int reverseBits(int n) {
        string bin = "";
        for(int i = 0; i < 32; i++) {
            bin += (n & 1) ? '1' : '0';
            n >>= 1;
        }
        int ans = 0;
        long long mul = 1;
        for(int i = bin.size() - 1 ; i >= 0 ; i --){
            ans = ans + (bin[i] == '1') * mul;
            mul *= 2;
        }
        return ans;
    }
};