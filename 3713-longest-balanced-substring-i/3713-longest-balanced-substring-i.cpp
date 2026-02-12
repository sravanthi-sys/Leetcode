class Solution {
public:
    int longestBalanced(string s) {
        int ans = 1;
        for(int i = 0 ; i < s.length() ; i ++){
            unordered_map<char, int> mpp;
            for(int j = i ; j < s.length() ;j ++){
                mpp[s[j]] ++;
                int st = 0;
                bool flag = true;
                for(auto it : mpp){
                    if(st == 0)st = it.second;
                    if(it.second != st){
                        flag = false;
                        break;
                    }
                }
                if(flag)ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};