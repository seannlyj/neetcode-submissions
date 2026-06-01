class Solution {
private:
    unordered_set<int> m;
public:
    bool hasDuplicate(vector<int>& nums) {
        for(int num : nums){
            if(m.find(num) != m.end())
                return true;
            m.insert(num);
        } 

        return false;
    }
};