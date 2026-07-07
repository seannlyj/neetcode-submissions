class Solution {
// Choice: Increment value by 1
// Complete: add to result when number of values in current combination == k
// Prune: 

public:
    void recurse(int n, int k, int start, vector<int>& combi, vector<vector<int>>& result) {
        //base case
        if(combi.size() == k){
            result.push_back(combi);
            return;
        }

        for(int i = start; i <= n; i++){
            //prune
            if(k - combi.size() > (n - i + 1)) return;

            //push
            combi.push_back(i);
            //recurse
            recurse(n, k, i + 1, combi, result);
            //pop
            combi.pop_back();
        }

    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> combination;
        recurse(n, k, 1, combination, result);
        return result;
    }
};