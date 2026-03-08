class Solution {
    string res = "";
    void solve(int ind ,int n ,string curr ,unordered_set<string>& st){
        if(ind == n){
            if(st.find(curr) == st.end()){
                res = curr;
            }
            return ;
        }
        for(char ch = '0' ; ch <= '1' ;ch++){
            solve(ind + 1 ,n ,curr + ch ,st);
            if(res.size() > 0)return ;
        }
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums[0].length();
        unordered_set<string> st(nums.begin() ,nums.end());
        solve(0 ,n ,"" ,st);
        return res;
    }
};