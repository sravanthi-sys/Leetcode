class Solution {
public:
    int totalMoney(int n) {
        int ans = 0, cnt = 0;
        while(n >= 7){
            ans += 28 + (cnt * 7);
            cnt += 1;
            n -= 7;
        }
        cnt += 1;
        while(n > 0){
            ans += cnt;
            cnt ++;
            n --;
        }
        return ans;
    }
};