class Solution {
    void sieve(vector<bool>& isPrime, int n){
        isPrime[0] = isPrime[1] = false;
        for(long long i = 2 ; i < n ; i ++){
            if(isPrime[i]){
                for(long long j = i * i ; j < n ; j += i){
                    isPrime[j] = false;
                }
            }
        }
    }
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        vector<bool> isPrime(right + 1, true);
        sieve(isPrime, right + 1);
        for(int i = left ; i <= right ; i ++){
            int cnt = 0, n = i;
            while(n){
                cnt += (n & 1);
                n /= 2;
            }
            if(isPrime[cnt])ans ++;
        }
        return ans;
    }
};