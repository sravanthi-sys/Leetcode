class Solution {
public:
    int minOperations(string s) {
        int st1 = 0, st2 = 1, ops1 = 0, ops2 = 0;
        for(int i = 0 ; i < s.length() ; i ++){
            if(s[i] - '0' != st1)ops1 ++;
            if(s[i] - '0' != st2)ops2 ++;
            st1 = 1 - st1;
            st2 = 1 - st2;
        }
        return min(ops1, ops2);
    }
};