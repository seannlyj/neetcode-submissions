class Solution {
// Choice: add element or don't add element
// Complete: when index == nums.size()?
// Prune: 
public:
    void recursion(vector<int>& nums, vector<vector<int>>& result, vector<int>& sub, int index){
        // base case
        //if(index >= nums.size()) return;

        result.push_back(sub);

        for(int i = index; i < nums.size(); i++) {
            //prune


            //push_back
            sub.push_back(nums[i]);
            //recurse
            recursion(nums, result, sub, i + 1);
            //pop_back
            sub.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> sub;
        recursion(nums, result, sub, 0);
        return result;
    }
};
