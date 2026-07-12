class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int totalElementCount = nums.size();
        int removedElementCount = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == val){
                removedElementCount++;
                nums[i] = INT_MAX;
            }
        }

        sort(nums.begin(), nums.end());
        return totalElementCount - removedElementCount;
    }
};