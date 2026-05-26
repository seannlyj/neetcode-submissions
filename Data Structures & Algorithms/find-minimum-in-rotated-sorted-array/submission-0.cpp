class Solution {
public:
    /* 
    Binary Search algorithm
    - left = 0, right  = size() - 1
    - while(left <= right)
    -   middle = left + (right-left) / 2;
    -   if(arr[middle] == target)
    -       return middle;
    -   else if(arr[middle] > target)
    -       right = middle - 1
    -   else if(arr[middle] < target)
    -       left = middle + 1    
    */

    int findMin(vector<int> &nums) {
        int res = nums[0];
        int l = 0;
        int r = nums.size() - 1;

        while(l <= r) { 
            if(nums[l] < nums[r]) {
                res = min(res, nums[l]); 
                break;
            }

            int m = l + (r-l)/2;
            res = min(res, nums[m]);

            if(nums[m] >= nums[l]) {
                // 3 4 5 6 1 2
                // l   m    
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return res;
    }
};
