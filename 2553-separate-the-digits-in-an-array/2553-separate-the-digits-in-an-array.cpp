class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
      vector<int> ans;
      
      for(int i:nums){
        vector<int> v;
        while(i>0){
            v.push_back(i%10);
            i=i/10;
        }
        for(int j=v.size()-1;j>=0;j--)
        ans.push_back(v[j]);
      }  
      return ans;
    }
};