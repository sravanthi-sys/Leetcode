class Solution {
public:
    int jump(vector<int>& nums) {
        int farthestInd = 0, currMax = 0, jumps = 0;
        for(int i = 0 ; i < nums.size() - 1 ; i ++){
            farthestInd = max(farthestInd, i + nums[i]);
            if(currMax == i){
                currMax = farthestInd;
                jumps ++;
            }
        }
        return jumps;
    }
};