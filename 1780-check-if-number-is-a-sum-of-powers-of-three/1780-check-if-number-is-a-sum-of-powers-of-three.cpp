struct PairHash{
    size_t operator()(const pair<int,int>& p)const{
        return hash<long long>()(((long long)p.first) ^ (((long long)p.second) << 32));
    }
};
class Solution {
    bool solve(int ind, int n, vector<int>& powers, unordered_map<pair<int, int>, int,  
    PairHash>& mpp){
        if(ind == powers.size()){
            return n == 0;
        }
        if(n == 0)return true;
        if(mpp.find({ind, n}) != mpp.end())return mpp[{ind, n}];
        bool pick = false;
        if(powers[ind] <= n){
            pick = solve(ind + 1, n - powers[ind], powers, mpp);
        }
        bool notpick = solve(ind + 1, n, powers, mpp);
        return mpp[{ind, n}] = pick || notpick;
    }
public:
    bool checkPowersOfThree(int n) {
        vector<int> powers;
        for(int curr = 1; curr <= n ; curr *= 3)powers.push_back(curr);
        unordered_map<pair<int, int>, int, PairHash> mpp;
        // cout << powers.size();
        return solve(0, n, powers, mpp);
        return true;
    }
};