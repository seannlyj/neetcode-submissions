class Solution {
    //choice: take the number or don't take
    //prune when: NIL
    //completed when: 
public:
    void backtracking(vector<int>& nums, int i, vector<int>& subset, vector<vector<int>>& result) {
        if(i >= nums.size()){
            result.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        backtracking(nums, i + 1, subset, result);
        subset.pop_back();

        while(i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;

        backtracking(nums, i + 1, subset, result);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> subset;
        backtracking(nums, 0, subset, result);

        return result;
    }
};
