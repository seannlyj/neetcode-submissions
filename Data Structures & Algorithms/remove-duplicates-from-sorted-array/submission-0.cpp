class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s;
        for(auto num : nums){
            s.insert(num);
        }

        nums.clear();

        for(auto num : s){
            nums.push_back(num);
        }

        return nums.size();
    }
};