class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;

        while(l < r){
            int m = l + (r-l)/2;

            // m is even, it's pair should be at m + 1
            if(m % 2 == 0){
                // if it is indeed the pair, then the target is on the right
                if(nums[m + 1] == nums[m]) {
                    l = m + 2;
                } 
                // if it is not the pair, then something on the left has messed up the order
                else {
                    r = m;
                }
            } 
            // m is odd, it's pair should be at m - 1;
            else {
                //if same, target should be on right
                if(nums[m - 1] == nums[m]){
                    l = m + 1;
                } else {
                    r = m;
                }
            }
        }
        cout<<nums[l]<<endl;
        cout<<nums[r]<<endl;
        return nums[l];
    }
};