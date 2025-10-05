class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0 ; i < 2 ; i ++){
            unordered_set<int> curr;
            for(int it : st){
                for(int num : nums){
                    curr.insert(it ^ num);
                }
            }
            st = curr;            
        }
        return st.size();
    }
};