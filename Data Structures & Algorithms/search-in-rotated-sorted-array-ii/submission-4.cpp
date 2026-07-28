class Solution {
public:
    bool binarySearch(vector<int>& nums, int left, int right, int target){
        while(left <= right){
            int mid = left + (right - left)/2;
            if(nums[mid] == target) return true;
            
            if(nums[left] == nums[mid] && nums[mid] == nums[right]){
                left++;
                right--;
            }
            else if(nums[left] <= nums[mid]) {
                // left half is sorted
                if(nums[left] <= target && target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else {
                //right half is sorted
                if(nums[mid] < target && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }

        }
        return false;
    }

    bool search(vector<int>& nums, int target) {



        return binarySearch(nums, 0, nums.size() - 1, target);
    }
};