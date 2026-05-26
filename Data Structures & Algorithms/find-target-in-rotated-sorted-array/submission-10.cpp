class Solution {
public:
    int search(vector<int>& nums, int target) {
        // get pivot 
        int l = 0;
        int r = nums.size() - 1;
        int minIndex = 0;

        while(l <= r){
            if(nums[l] <= nums[r]) {
                minIndex = l;
                break;
            }

            int m = l + (r - l) / 2;

            if(nums[m] > nums[r]) {
                l = m + 1;
            } else {
                r = m;
            }
        }

        // using pivot, binary search on left and right subarrays
        int res = binarySearch(nums, target, minIndex, nums.size() - 1);
        if(res == -1) res = binarySearch(nums, target, 0, minIndex - 1);

        return res;
    }

    int binarySearch(vector<int> & nums, int target, int left, int right){
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target){
                return mid;
            } else if(nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return -1;
    }
};
