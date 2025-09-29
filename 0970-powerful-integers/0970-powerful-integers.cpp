class Solution {
    bool check(int rem, int y){
        if(y == 1)return rem == 1;
        int i = 1;
        while(i < rem){
            i *= y;
        }
        return i == rem;
    }
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> ans;
        for(int n = 1 ; n <= bound ; n ++){
            if(x == 1){
                if(check(n - 1, y)){
                    ans.push_back(n);
                }
                continue;
            }
            int i = 1;
            while(i < n){
                if(check(n - i, y)){
                    ans.push_back(n);
                    break;
                }
                i *= x;
            }
        }
        return ans;
    }
};