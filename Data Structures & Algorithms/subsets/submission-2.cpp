class Solution {
public:
    void backtrack(int i, vector<int>& curr, vector<int>& nums, vector<vector<int>>& result){
        // what are the choices: do we take the num, or skip it
        // when is it complete: when index is == nums.size() - 1 (at the end)
        // when to prune: NIL

        // solution is ocmplete
        if(i >= nums.size()){
            result.push_back(curr);
            return;
        }

        //push
        curr.push_back(nums[i]);
        //recurse
        backtrack(i + 1, curr, nums, result);
        //pop
        curr.pop_back();
        backtrack(i + 1, curr, nums, result);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        backtrack(0, curr, nums, res);

        return res;
    }
};