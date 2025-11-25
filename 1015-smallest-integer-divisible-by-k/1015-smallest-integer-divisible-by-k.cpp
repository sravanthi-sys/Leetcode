class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k % 2 == 0 || k % 5 == 0)return -1;
        int len = to_string(k).length(), i = 0;
        long long n = 0;
        while(i < len){
            n = (n * 10) + 1;
            i ++;
        }
        while(i){
            if(n % k == 0)return i;
            n %= k;
            i ++;
            n = (n * 10) + 1; 
        }
        return 0;

    }
};