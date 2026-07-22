class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int windowMax = nums[0];
        int windowMin = nums[0];

        // build first window
        for(int i = 0; i < k; i++){
            windowMax = max(windowMax, nums[i]);
            windowMin = min(windowMin, nums[i]);
        }

        int diff = windowMax - windowMin;
        int minDiff = diff;

        // sliding window
        for(int i = k; i < nums.size(); i++){
            // if hte value we're removing is considered the max, set it to new val first
            if(windowMax == nums[i - k]) {
                windowMax = nums[i - k + 1];
            }
            windowMax = max(windowMax, nums[i]);
        
            if(windowMin == nums[i-k]){
                windowMin = nums[i-k+1];
            }
            windowMin = min(windowMin, nums[i]);

            diff = windowMax - windowMin;
            minDiff = min(minDiff, diff);
        
        }

        return minDiff;

    }
};