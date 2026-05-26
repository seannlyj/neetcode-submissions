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

        // 3 4 5 6 1 2
        //     ^   p

        int res;
        res = binarySearch(nums, target, 0, pivIndex - 1);

        if(res == -1){
            res = binarySearch(nums, target, pivIndex, nums.size() - 1);
        }

        return res;
    }

    int binarySearch(vector<int>& nums, int target, int left, int right) {
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};