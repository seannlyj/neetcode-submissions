class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSum;
        int result = 0;
        prefixSum[0] = 1;

        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            int val = sum - k;
            result += prefixSum[val];
            prefixSum[sum]++;
        }

        return result;
    }
};