class Solution {
// 1, 2, 2, 3, 3
// 1, 2, 4, 5

public:
    int numRescueBoats(vector<int>& people, int limit) {
        int result = 0;
        sort(people.begin(), people.end());
        int l = 0;
        int r = people.size() - 1;

        while(l <= r){
            int target = limit - people[l];
            if(people[r] <= target){
                result++;
                l++;
                r--;
            } else {
                r--;
                result++;
            }
        }

        return result;
    }
};