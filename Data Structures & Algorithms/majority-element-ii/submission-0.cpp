class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> um;
        for(auto num : nums){
            um[num]++;
        }

        int threshold = nums.size() / 3;
        vector<int> result;
        for(auto [num, freq] : um){
            if(freq > threshold){
                result.push_back(num);
            }
        }

        return result;
    }
};