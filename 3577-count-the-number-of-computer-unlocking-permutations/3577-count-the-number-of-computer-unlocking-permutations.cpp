class Solution {
    int mod;
    int power(long long b, int e){
        long long ans = 1;
        while(e > 0){
            if(e % 2)ans = (ans * b) % mod;
            b = (b * b) % mod;
            e /= 2;
        }
        return ans;
    }
public:
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        mod = 1e9 + 7;
        for(int i = 1 ; i < n ; i ++){
            if(complexity[i] <= complexity[0])return 0;
        }
        int ans = 1;
        for(int i = 1 ; i < n ; i ++){
            ans = (ans * i) % mod;
        }
        return ans;
    }
};