class Solution {
public:
    bool binarySearch(vector<int> nums, int target){
        int l = 0;
        int r = nums.size() - 1;

        while(l <= r){
            int m = l + (r-l)/2;
            
            if(nums[m] == target){
                return true;
            } else if(nums[m] > target){
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i = 0; i < matrix.size(); i++){
            int max = matrix[i][matrix[i].size() - 1];
            int min = matrix[i][0];

            if(target >= min && target <= max) {
                return binarySearch(matrix[i], target);
            }
        }

        return false;
    }
};
