// -4, -1, -1, 0, 1, 2
// i = -4, target = 4

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        
        for(int i = 0; i < nums.size(); i++){
            if(i > 0){
                if(nums[i - 1] == nums[i])
                    continue;
            }

            int target = -nums[i];

            int l = i + 1;
            int r = nums.size() - 1;
            while(l < r){
                int sum = nums[l] + nums[r];

                if(sum < target){
                    l++;
                } else if (sum > target){
                    r--;
                } else {
                    result.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while(l < r && nums[l - 1] == nums[l]) l++;
                    while(l < r && nums[r + 1] == nums[r]) r--;
                    //break;
                }
            }
        }

        return result;
    }
};
