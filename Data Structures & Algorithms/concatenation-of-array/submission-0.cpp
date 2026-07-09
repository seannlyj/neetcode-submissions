class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> result;
        for(int i = 0; i < 2; i++){
            for(auto num : nums){
                result.push_back(num);
            }
        }

        return result;
    }
};