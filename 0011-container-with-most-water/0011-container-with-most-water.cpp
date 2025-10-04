class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0,right=height.size()-1,maxi=0;
        while(left < right){
            maxi=max(maxi,(right-left)*min(height[left],height[right]));
            if(height[left] < height[right]){
                left++;
            }else{
                right--;
            }
        }
        return maxi;
    }
};