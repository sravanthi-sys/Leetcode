class Solution {
public:
    bool hasSameDigits(string s) {
        string temp = s;
        while(s.length() > 2){
            temp = "";
            for(int i = 0 ;i < s.length() - 1 ;i++){
                temp += to_string(((int)s[i] + (int)s[i+1]) % 10 ) ;
            }
            s = temp;
        }
        return s[0] == s[1];
    }
};