class Solution {
//dynamic sliding window
// shrink when: removing front element still satisfies >= target
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int sum = 0;
        int length = INT_MAX;

        for(int r = 0; r < nums.size(); r++){
            sum += nums[r];
            
            while(sum >= target){
                if(sum - nums[l] < target) break;

                sum -= nums[l];
                l++;
            }

            if(sum >= target)
                length = min(length, r-l + 1);
        }

        if(sum < target) return 0;

        return length;
    }
};