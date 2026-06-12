class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> uset;
        for(auto num : nums){
            if(uset.count(num)) return num;

            uset.insert(num);
        }

        return -1;
    }
};
