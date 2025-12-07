class Solution {
    vector<bool> sieve;
    void build_sieve(int n){
        sieve.resize(n + 1, true);
        sieve[0] = sieve[1] = false;
        for(int i = 2 ; i * i <= n ; i ++){
            if(sieve[i]){
                for(int j = i * i ; j <= n ; j += i){
                    sieve[j] = false;
                }
            }
        }
    }
public:
    int largestPrime(int n) {
        vector<int> primes;
        build_sieve(n);
        for(int i = 0 ; i < sieve.size() ; i ++){
            if(sieve[i])primes.push_back(i);
        }
        int sum = 0, ans = 0;
        for(int i = 0 ; i < primes.size() ; i ++){
            sum += primes[i];
            if(sum <= n){
                if(sieve[sum]){
                    ans = sum;
                }
            }
            else return ans;
        }
        return ans;
    }
};