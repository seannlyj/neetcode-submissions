class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        int pivIndex = 0;
        // Get pivot (aka minimum value)
        while(l <= r){
            if(nums[l] <= nums[r]){
                if(nums[l] < nums[pivIndex]){
                    pivIndex = l;
                } 
                break;
            }

            int m = l + (r - l) / 2;
            if(nums[m] < nums[pivIndex]){
                pivIndex = m;
            }
            
            if(nums[l] <= nums[m]) {
                //pivot in right part
                l = m + 1;
            } else {
                //pivot in left part
                r = m - 1;
            }
        }

        // Binary search using pivot
        // Determine which side of the pivot the target lies on
        if (target >= nums[pivIndex] && target <= nums[nums.size() - 1]) {
            l = pivIndex;
            r = nums.size() - 1;
        } else {
            l = 0;
            r = pivIndex - 1;
        }

        while(l <= r){
            int m = l + (r - l) / 2;

            if(nums[m] == target) return m;
            else if(nums[m] < target) l = m + 1;
            else r = m - 1;
        }

        return -1;
    }
};