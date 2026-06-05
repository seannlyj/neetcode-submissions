//Choice: the numbers in nums (can be duplicate so recursively put in the same number works)
//Complete when: sum == target
//Prune when: sum > target

class Solution {
public:
    void backtracking(vector<int>& nums, int target,  int i, vector<int>& curr, vector<vector<int>>& result){
        if(i >= nums.size()) return;

        int sum = 0;
        for(int num : curr){
            sum += num;
        }
        // prune if we passed the target
        if(sum > target) return;

        // complete solution is here
        if(sum == target){
            result.push_back(curr);
            return;
        }

        // choice
        curr.push_back(nums[i]);
        backtracking(nums, target, i, curr, result);
        curr.pop_back();
        backtracking(nums, target, i + 1, curr, result);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        backtracking(nums, target, 0, curr, result);

        return result;
    }
};
