class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSoFar = nums[0], maxEndingHere = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            maxEndingHere = max(nums[i], maxEndingHere + nums[i]);
            maxSoFar = max(maxSoFar, maxEndingHere);
        }
        
        return maxSoFar;
    }
};
