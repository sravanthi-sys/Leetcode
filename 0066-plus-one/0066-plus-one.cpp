class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size()-1;
        int carry=1;
        vector<int> ans;
        while(carry && n>=0){
            carry=(digits[n]+1)/10;
            digits[n]=(digits[n]+1)%10;
            
            n--;
        }
        
        if(carry)
        ans.push_back(1);
        for(int i=0;i<digits.size();i++){
            ans.push_back(digits[i]);
        }
        return ans;
    }
};