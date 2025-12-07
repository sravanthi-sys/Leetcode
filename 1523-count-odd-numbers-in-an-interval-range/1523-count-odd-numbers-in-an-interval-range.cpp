class Solution {
public:
    int countOdds(int low, int high) {
        if(low == high)return low % 2 == 1;        
        int ans = ceil((high - low) / 2.0);
        if(low % 2 && high % 2)ans ++;
        return ans;
    }
};