class Solution {
//choice: Pick any element from the array that hasn't been used yet
//complete when: when there are no more elements to use
//prune when: NIL
public:
    void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& curr, vector<vector<int>>& result) {
        // complete
        if(curr.size() == nums.size()) {
            result.push_back(curr);
        }

        for(int i = 0; i < nums.size(); i++){
            if(!used[i]) {
                used[i] = true;
                curr.push_back(nums[i]);
                backtrack(nums, used, curr, result);
                used[i] = false;
                curr.pop_back();
            }
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<bool> used(nums.size(), false);
        vector<int> curr;
        backtrack(nums, used, curr, result);

        return result;
    }
};
