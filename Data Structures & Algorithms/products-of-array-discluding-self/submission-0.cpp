class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;

        for(int i = 0; i < nums.size(); ++i) {
            int calculated = 0;

            for(int j = 0; j < nums.size(); ++j) {
                if(i == j)
                    continue;
                
                if(nums[j] == 0) {
                    calculated = 0;
                    break;
                }

                if(calculated == 0)
                    calculated = nums[j];
                else
                    calculated *= nums[j];
            }

            result.push_back(calculated);
        }
        return result;
    }
};
