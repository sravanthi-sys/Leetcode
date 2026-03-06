class Solution {
public:
    bool checkOnesSegment(string s) {
        int ones = 0, cnt = 0;
        for(int i = 0 ; i < s.length() ; i ++){
            if(s[i] == '0'){
                if(ones >= 1)cnt ++;
                ones = 0;
            }
            else ones ++;
        }
        if(ones > 0)cnt ++;
        return cnt <= 1;
    }
};