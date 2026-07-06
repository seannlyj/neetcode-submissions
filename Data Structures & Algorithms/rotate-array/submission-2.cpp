class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> result;

        if(k >= nums.size()) k %= nums.size();

        for(int r = nums.size() - k; r < nums.size(); r++){
            result.push_back(nums[r]);
        }

        for(int l = 0; l < nums.size() - k; l++){
            result.push_back(nums[l]);
        }

        nums = result;

        return;
    }
};