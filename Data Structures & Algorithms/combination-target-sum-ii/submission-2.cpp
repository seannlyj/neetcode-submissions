class Solution {
    //choices: keep num in or skip to next num (cannot recursive the same element in nums)
    //prune when: sum > target
    //complete when: sum == target

public:
    void backtrack(vector<int>& candidates, int target, int i, vector<int>& curr, vector<vector<int>>& result) {
        int sum = 0;
        for(auto num : curr) { 
            sum += num;
        }

        if(sum > target) return;
        if(sum == target){
            result.push_back(curr);
            return;
        }
        if(i >= candidates.size()) return;

        curr.push_back(candidates[i]);
        backtrack(candidates, target, i + 1, curr, result);
        curr.pop_back();
        
        while(i + 1 < candidates.size() && candidates[i] == candidates[i + 1]) i++;

        backtrack(candidates, target, i + 1, curr, result);

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> curr;
        backtrack(candidates, target, 0, curr, result);
        return result;
    }
};
