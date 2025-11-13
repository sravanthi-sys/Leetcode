class Solution {
public:
    int maxOperations(string s) {
        int ones = 0, ans = 0;
        bool isOne = false;
        for(int i = 0 ; i < s.length() ; i ++){
            if(s[i] == '1'){
                ones ++;
                isOne = true;
            }
            else{
                if(isOne){
                    while(i < s.length() && s[i] == '0')i ++;
                    ans += ones;
                    i --;
                }
            }
        }
        return ans;
    }
};