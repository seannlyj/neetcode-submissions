class Solution {
private:
    vector<int> memo;

public:
    int ways(int n){
        if(n <= 2) return n;
        if(memo[n] != -1) return memo[n];
        return memo[n] = ways(n-1) + ways(n-2);
    }

    int climbStairs(int n) {
        memo.assign(n+1, -1);
        return ways(n);
    }
};
