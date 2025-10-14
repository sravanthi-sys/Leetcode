class Solution {
bool isStrictlyIncreasing(const vector<int>& nums, int start, int k) {
    for (int i = start; i < start + k - 1; ++i) {
        if (nums[i] >= nums[i + 1]) {
            return false;
        }
    }
    return true;
}
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
    if (nums.size() < 2 * k) return false;  
    for (int i = 0; i <= nums.size() - 2 * k; ++i) {
        bool firstIncreasing = isStrictlyIncreasing(nums, i, k);
        bool secondIncreasing = isStrictlyIncreasing(nums, i + k, k);
        
        if (firstIncreasing && secondIncreasing) {
            return true;
        }
    }
    return false;
        
    }
};