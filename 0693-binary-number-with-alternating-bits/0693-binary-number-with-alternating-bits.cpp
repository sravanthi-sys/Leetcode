class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev=-1,cnt=0;
        while(n){
            if(( n &1 )==prev)return false;
            if((n & 1))
            prev=1;
            else
            prev=0;

            cnt++;
            n=n>>1;
        }
        return true;
    }
};