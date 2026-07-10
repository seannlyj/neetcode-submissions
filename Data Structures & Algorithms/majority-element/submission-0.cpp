class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> um;
        for(auto num : nums){
            um[num]++;
        }

        for(auto [num, freq] : um){
            if(freq > nums.size() / 2) return num;
        }

        return -1;
    }
};