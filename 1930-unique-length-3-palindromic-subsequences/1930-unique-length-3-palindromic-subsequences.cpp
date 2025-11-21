class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char, int> mpp, freq;
        unordered_set<string> st;
        for(int i = 0 ; i < s.length() ; i ++){
            if(mpp.find(s[i]) != mpp.end()){
                int l = mpp[s[i]];
                for(int j = l + 1 ; j < i ; j ++){
                    string temp = "";
                    temp += s[l];
                    temp += s[j];
                    temp += s[i];
                    st.insert(temp);
                }
            }
            mpp[s[i]] = i;
            freq[s[i]] ++;
        }
        int ans = st.size();
        for(auto it : freq){
            if(it.second > 2)ans ++;
        }
        return ans;
    }
};