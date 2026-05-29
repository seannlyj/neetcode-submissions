class Solution {
public:
    void backtrack(int index, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
        if(index >= nums.size()) {
            result.push_back(current);
            return;
        }
        
        result.push_back(current);

        for(int i = index; i < nums.size(); i++){
            current.push_back(nums[i]); //push in num
            //process 
            backtrack(i + 1, nums, current, result); //backtrack
            current.pop_back(); //pop out num
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(0, nums, current, result);

        return result;
    }
};
