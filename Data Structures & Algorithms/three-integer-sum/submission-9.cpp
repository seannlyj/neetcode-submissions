class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size() - 1; i++){
            if(i > 0){
                if(nums[i] == nums[i-1]) continue;
            }

            int target = -nums[i];
            
            int l = i + 1;
            int r = nums.size() - 1;
            while(l < r){
                int sum = nums[l] + nums[r];
                if(sum == target) {
                    result.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;

                    while(l < r && nums[l - 1] == nums[l]) l++;
                    while(l < r && nums[r + 1] == nums[r]) r--;
                } else if(sum > target){
                    r--;
                } else {
                    l++;
                }
            }
        }

        return result;
    }
};
