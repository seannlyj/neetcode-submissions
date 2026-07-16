class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while (l < r){
            int m = l + (r-l)/2;

            if(nums[m] > nums[r]) {
                l = m + 1;
            } else {
                r = m;
            }
        }

        int pivot = l;
        int res = binarySearch(nums, target, pivot, nums.size() - 1);

        return res == -1 ? binarySearch(nums, target, 0, pivot - 1) : res;
    }

    int binarySearch(vector<int>& nums, int target, int l, int r){
        while(l <= r){
            int m = l + (r-l)/2;
            if(nums[m] == target){
                return m;
            } else if(nums[m] < target){
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return -1;
    }
};
