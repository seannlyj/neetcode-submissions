class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int largestSum = nums[0];

        for(int l = 0; l < nums.size(); l++){
            int currentSum = nums[l];
            
            largestSum = max(largestSum, currentSum);
            for(int r = l + 1; r < nums.size(); r++){
                currentSum += nums[r];
                largestSum = max(largestSum, currentSum);
            }
        }

        return largestSum;
    }
};
