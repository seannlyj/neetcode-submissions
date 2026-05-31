class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;

        int l = 0;
        int r = numbers.size() - 1;

        while(l < r){


            if(numbers[l] + numbers[r] == target){
                break;
            }
            else if(numbers[l] + numbers[r] < target){
                l++;
            } else if(numbers[l] + numbers[r] > target){
                r--;
            }
        }

        res.push_back(l + 1);
        res.push_back(r + 1);
        return res;
    }
};
