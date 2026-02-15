class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int carry = 0;
        int i = a.length() - 1, j = b.length() - 1;
        while(i >= 0 || j >= 0){
            int sum = 0;
            sum += (i >= 0 && a[i] == '1');
            sum += (j >= 0 && b[j] == '1');
            sum += carry;
            if(sum > 1)
            carry = 1;
            else carry = 0;
            ans += (sum % 2 == 0) ? '0' : '1';
            i --;
            j --;
        }
        if(carry)ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};