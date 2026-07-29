class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while(l <= r){
            int m = l + (r-l)/2;

            if(nums[m] == target) return m;

            //if left half is sorted
            if(nums[l] <= nums[m]){
                //check if target is inbetween left and mid
                if(nums[l] <= target && target <= nums[m]) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            } 
            // else right half if sorted
            else {
                // check if target is inbetween mid and right
                if(nums[r] >= target && target >= nums[m]) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
        }

        return -1;
    }
};
