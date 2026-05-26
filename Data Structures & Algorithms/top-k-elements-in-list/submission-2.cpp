class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for(int num : nums) {
            count[num]++;
        }

        vector<pair<int, int>> arr;
        for(const auto& p : count) {
            arr.push_back({p.second, p.first});
        }
        sort(arr.rbegin(), arr.rend());

        vector<int> results;
        for(int i = 0; i < k; ++i){
            results.push_back(arr.at(i).second);
        }

        return results;
    }
};
