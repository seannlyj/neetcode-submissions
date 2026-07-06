class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> result;

        if(k >= nums.size()) k %= nums.size();
        cout<<"k = " << k <<endl;

        int l = 0;
        int r = nums.size() - k;

        for(int r = nums.size() - k; r < nums.size(); r++){
            result.push_back(nums[r]);
        }

        for(int l = 0; l < r; l++){
            result.push_back(nums[l]);
        }

        nums = result;

        return;
    }
};