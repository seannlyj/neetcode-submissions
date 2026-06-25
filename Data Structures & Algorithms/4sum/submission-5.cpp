class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size() - 3; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;

            for(int j = i + 1; j < nums.size(); j++){
                if(j > i + 1 && nums[j] == nums[j-1]) continue;
                long innerTarget = (long)target - ((long)nums[i] + (long)nums[j]);
                int innerL = j + 1;
                int innerR = nums.size() - 1;
                
                while(innerL < innerR){
                    long innerSum = (long)nums[innerL] + (long)nums[innerR];
                    if(innerTarget == innerSum) {
                        result.push_back({nums[i], nums[j], nums[innerL], nums[innerR]});
                        innerL++;
                        innerR--;
                        while(innerL < innerR && nums[innerR] == nums[innerR + 1]) innerR--;
                        while(innerL < innerR && nums[innerL] == nums[innerL - 1]) innerL++;
                    } else if(innerSum > innerTarget){
                        innerR--;
                    } else {
                        innerL++;
                    }
                }
            }
        }


        return result;
    }
};