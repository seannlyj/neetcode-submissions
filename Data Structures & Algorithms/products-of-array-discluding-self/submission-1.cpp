class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        vector<int> postfix(n);
        vector<int> output(n);

        prefix[0] = 1;
        postfix[n - 1] = 1;

        for(int i = 1; i < n; i++) {
            prefix[i] = nums[i - 1] * prefix[i - 1];
        }

        for(int i = n - 2; i >= 0; i--) {
            postfix[i] = nums[i + 1] * postfix[i + 1];
        }

        for(int i = 0; i < n; i++) {
            output[i] = prefix[i] * postfix[i];
        }

        return output;
    }
};
