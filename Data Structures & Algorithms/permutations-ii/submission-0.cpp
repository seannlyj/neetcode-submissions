class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& result, vector<int> curr, vector<bool> used){
        // base case
        if(nums.size() == curr.size()) {
            result.push_back(curr);        
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            // prune
            if(i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;

            if(!used[i]){
                // push
                used[i] = true;
                curr.push_back(nums[i]);

                // backtrack
                backtrack(nums, result, curr, used);

                // pop
                used[i] = false;
                curr.pop_back();
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        vector<vector<int>> result;
        vector<int> curr;

        backtrack(nums, result, curr, used);
        return result;
    }
};